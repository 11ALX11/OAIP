#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <math.h>
#include "menu_file.h"

using namespace std;

string getCountryWithMaxTeens(struct city* cities, int arr_length);

void displayCity(struct city& city);

void addCity(string& country, string& title, int people, double teens_part, struct city* cities, int& arr_length, string fileName);

void sortByField(string field, struct city* cities, int arr_length, string fileName);
void quickSortByField(string field, struct city* cities, int arr_length, string fileName);

int findIdByField(string field, string value, struct city* cities, int arr_length, int pos = 0);
int findIdByField(string field, int value, struct city* cities, int arr_length, int pos = 0);
int findIdByField(string field, double value, struct city* cities, int arr_length, int pos = 0);

void deleteById(int key, struct city* cities, int& arr_length, string fileName);

void loadFromFile(string fileName, struct city* cities, int& arr_length);

void menu(struct city* cities, int arr_length) {
    cout << "Type file name:" << endl;
    string fileName;
    getline(cin, fileName);

    loadFromFile(fileName, cities, arr_length);

    string input;
    cout << "Working with menu:\n0 - exit\t1 - get country with max teens\n2 - input new city\t3 - display cities\n4 - sorting\t5 - delete city\n6 - load from file\n";
    while (input != "0") {
        getline(cin, input);

        if (input == "1") {
            if (arr_length > 0)
                cout << "Country with max teens: " << getCountryWithMaxTeens(cities, arr_length) << endl;
            else
                cout << "There's no city yet.\n";
        }

        if (input == "2") {
            cout << "Country:\n";
            string country;
            getline(cin, country);

            printf("City:\n");
            string title;
            getline(cin, title);

            cout << "Amount of people:\n";
            int people;
            cin >> people;

            cout << "Teens in %:\n";
            double teens_part;
            cin >> teens_part;

            addCity(country, title, people, teens_part, cities, arr_length, fileName);
        }

        if (input == "3") {
            for (int i = 0; i < arr_length; i++) {
                displayCity(cities[i]);
            }
            if (arr_length <= 0) {
                cout << "There's no city yet.\n";
            }
        }

        if (input == "4") {
            cout << "Type field for sorting (country, title, people, teens_part):\n";
            string field;
            getline(cin, field);
            while (!(field == "country" || field == "title" || field == "people" || field == "teens_part")) {
                cout << "Theres no such field!\n";
                getline(cin, field);
            }
            if (field == "country" || field == "title") {
                quickSortByField(field, cities, arr_length, fileName);
            }
            else {
                sortByField(field, cities, arr_length, fileName);
            }
            cout << "Done!\n";
        }

        if (input == "5") {
            if (arr_length <= 0) {
                cout << "There's no city yet.\n";
            }
            else {
                cout << "Type field for deleting (country, title, people, teens_part):\n";
                string field;
                getline(cin, field);
                while (!(field == "country" || field == "title" || field == "people" || field == "teens_part")) {
                    cout << "Theres no such field!\n";
                    getline(cin, field);
                }

                cout << "Type value:\n";
                int key;
                if (field == "country" || field == "title") {
                    string value;
                    getline(cin, value);
                    key = findIdByField(field, value, cities, arr_length, 0);
                }
                if (field == "people") {
                    int value;
                    cin >> value;
                    key = findIdByField(field, value, cities, arr_length, 0);
                }
                if (field == "teens_part") {
                    double value;
                    cin >> value;
                    key = findIdByField(field, value, cities, arr_length, 0);
                }

                if (key >= 0) {
                    displayCity(cities[key]);
                    cout << "Got deleted!\n";
                    deleteById(key, cities, arr_length, fileName);
                }
                else cout << "Value not found!\n";
            }
        }
        if (input == "6") {
            loadFromFile(fileName, cities, arr_length);
        }
        if (input == "7") {

        }
    }
}


string getCountryWithMaxTeens(struct city* cities, int arr_length) {
    map<string, int> countries;

    for (int i = 0; i < arr_length; i++) {
        countries[cities[i].country] += (int)round(cities[i].people * cities[i].teens_part);
    }

    string ans;
    int teens = -1;
    for (auto country = countries.begin(); country != countries.end(); country++) {
        if (country->second > teens) {
            ans = country->first;
            teens = country->second;
        }
    }

    return ans;
}

void displayCity(struct city& city) {
    cout << "Country: " << city.country << ", City: " << city.title << ", People: " << city.people << ", Teens: " << city.teens_part << "%\n";
}

void addCity(string& country, string& title, int people, double teens_part, struct city* cities, int& arr_length, string fileName = "") {
    cities[arr_length].country = country;
    cities[arr_length].title = title;
    cities[arr_length].people = people;
    cities[arr_length].teens_part = teens_part;

    if (fileName != "") {
        fstream file;
        file.open(fileName, ios::app);
        saveToFileOne(file, cities[arr_length]);
        file.close();

        updateIdx(cities, arr_length+1);
    }

    arr_length++;
}

void sortByField(string field, struct city* cities, int arr_length, string fileName) {
    for (int i = 0; i < arr_length; i++) {
        for (int j = 0; j < arr_length - 1; j++) {
            if (field == "country")
                if (cities[j].country > cities[j + 1].country) {
                    swap(cities[j], cities[j + 1]);
                }

            if (field == "title")
                if (cities[j].title > cities[j + 1].title) {
                    swap(cities[j], cities[j + 1]);
                }

            if (field == "people")
                if (cities[j].people > cities[j + 1].people) {
                    swap(cities[j], cities[j + 1]);
                }

            if (field == "teens_part")
                if (cities[j].teens_part > cities[j + 1].teens_part) {
                    swap(cities[j], cities[j + 1]);
                }
        }
    }

    saveToFile(fileName, cities, arr_length);
}

void quickSortByField(string field, struct city* cities, int arr_length, string fileName) {
    struct city tmp[1000];
    for (int i = 0; i < arr_length; i++) {
        tmp[i] = cities[i];
    }

    int ArrayOfIdx[1000];
    getArrayOfIdxByField(field, ArrayOfIdx, arr_length);

    for (int i = 0; i < arr_length; i++) {
        cities[i] = tmp[ArrayOfIdx[i]];
    }

    saveToFile(fileName, cities, arr_length);
}

int findIdByField(string field, string value, struct city* cities, int arr_length, int pos) {
    for (; pos < arr_length; pos++) {
        if (field == "country")
            if (cities[pos].country == value) return pos;

        if (field == "title")
            if (cities[pos].title == value) return pos;
    }
    return -1;
}

int findIdByField(string field, int value, struct city* cities, int arr_length, int pos) {
    for (; pos < arr_length; pos++) {
        if (field == "people")
            if (cities[pos].people == value) return pos;
    }
    return -1;
}

int findIdByField(string field, double value, struct city* cities, int arr_length, int pos) {
    for (; pos < arr_length; pos++) {
        if (field == "teens_part")
            if (abs(cities[pos].teens_part - value) < 0.001) return pos;
    }
    return -1;
}

void deleteById(int key, struct city* cities, int& arr_length, string fileName) {
    for (int i = key; i < arr_length; i++) {
        cities[i] = cities[i + 1];
    }
    arr_length--;

    saveToFile(fileName, cities, arr_length);
    updateIdx(cities, arr_length);
}

void loadFromFile(string fileName, struct city* cities, int& arr_length) {
    fstream file;
    file.open(fileName, ios::in);

    if (!file.is_open()) {
        saveToFile(fileName, cities, arr_length);
    }
    else {
        arr_length = 0;

        string country;
        string title;
        int people;
        double teens_part;

        getline(file, country);
        while (country != "") {
            getline(file, title);
            file >> people;
            file >> teens_part;

            string tmp;
            getline(file, tmp);

            addCity(country, title, people, teens_part, cities, arr_length);

            getline(file, country);
        }
        updateIdx(cities, arr_length);
        file.close();
    }
}