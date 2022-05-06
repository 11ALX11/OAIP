#include <iostream>
#include <map>
#include <math.h>

using namespace std;

struct city {
    string country;
    string title;
    int people;
    double teens_part; //храним числовую часть, выводя число добавляем %

    enum additionalEnum {First, Second};
    union additionalUnion {
        int unsigned natural;
        int intger;
        double rational;
    };
    int additionalBitField : 2;
};

string getCountryWithMaxTeens(struct city *cities, int arr_length);

void menu(struct city *cities, int arr_length);

void displayCity(struct city &city);

void addCity(string &country, string &title, int people, double teens_part, struct city *cities, int &arr_length);

void sortByField(string field, struct city *cities, int arr_length);

int findIdByField(string field, string value, struct city *cities, int arr_length, int pos=0);
int findIdByField(string field, int value, struct city *cities, int arr_length, int pos=0);
int findIdByField(string field, double value, struct city *cities, int arr_length, int pos=0);

void deleteById(int key, struct city *cities, int &arr_length);

int main()
{
    struct city cities[100];
    int arr_length=0;

    menu(cities, arr_length);

    return 0;
}

void menu(struct city *cities, int arr_length) {
    string input;
    cout << "Working with menu:\n0 - exit\t1 - get country with max teens\n2 - input new city\t3 - display cities\n4 - sorting\t5 - delete city\n";
    while (input != "0") {
        getline(cin, input);

        if (input == "1") {
            if (arr_length>0)
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

            addCity(country, title, people, teens_part, cities, arr_length);
        }

        if (input == "3") {
            for (int i=0; i<arr_length; i++) {
                displayCity(cities[i]);
            }
            if (arr_length<=0) {
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
            sortByField(field, cities, arr_length);
            cout << "Done!\n";
        }

        if (input == "5") {
            if (arr_length<=0) {
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
                    deleteById(key, cities, arr_length);
                }
                else cout << "Value not found!\n";
            }
        }
    }
}

string getCountryWithMaxTeens(struct city *cities, int arr_length) {
    map<string, int> countries;

    for (int i=0; i<arr_length; i++) {
        countries[cities[i].country] += round(cities[i].people * cities[i].teens_part);
    }

    string ans;
    int teens = -1;
    for (auto country=countries.begin(); country!=countries.end(); country++) {
        if (country->second > teens) {
            ans = country->first;
            teens = country->second;
        }
    }

    return ans;
}

void displayCity(struct city &city) {
    cout << "Country: " << city.country << ", City: "<< city.title <<", People: " << city.people << ", Teens: " << city.teens_part << "%\n";
}

void addCity(string &country, string &title, int people, double teens_part, struct city *cities, int &arr_length) {
    arr_length++;

    cities[arr_length-1].country = country;
    cities[arr_length-1].title = title;
    cities[arr_length-1].people = people;
    cities[arr_length-1].teens_part = teens_part;
}

void sortByField(string field, struct city *cities, int arr_length) {
    for (int i=0; i<arr_length; i++) {
        for (int j=0; j<arr_length-1; j++) {
                if (field == "country")
                    if (cities[j].country > cities[j+1].country) {
                        swap(cities[j], cities[j+1]);
                    }

                if (field == "title")
                    if (cities[j].title > cities[j+1].title) {
                        swap(cities[j], cities[j+1]);
                    }

                if (field == "people")
                    if (cities[j].people > cities[j+1].people) {
                        swap(cities[j], cities[j+1]);
                    }

                if (field == "teens_part")
                    if (cities[j].teens_part > cities[j+1].teens_part) {
                        swap(cities[j], cities[j+1]);
                    }
        }
    }
}

int findIdByField(string field, string value, struct city *cities, int arr_length, int pos) {
    for (int pos; pos<arr_length; pos++) {
            if (field == "country")
                if (cities[pos].country == value) return pos;

            if (field == "title")
                if (cities[pos].title == value) return pos;
    }
    return -1;
}

int findIdByField(string field, int value, struct city *cities, int arr_length, int pos) {
    for (int pos; pos<arr_length; pos++) {
            if (field == "people")
                if (cities[pos].people == value) return pos;
    }
    return -1;
}

int findIdByField(string field, double value, struct city *cities, int arr_length, int pos) {
    for (int pos; pos<arr_length; pos++) {
            if (field == "teens_part")
                if (abs(cities[pos].teens_part - value) < 0.001) return pos;
    }
    return -1;
}

void deleteById(int key, struct city *cities, int &arr_length) {
    for (int i=key; i<arr_length; i++) {
        cities[i] = cities[i+1];
    }
    arr_length--;
}
