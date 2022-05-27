#include <fstream>
#include <string>
#include "menu_city.h"

 using namespace std;

void getArrayOfIdxByField(string field, int* ArrayOfIdx, int arr_length);
void updateIdx(struct city* cities, int arr_length);

void updateIdx(struct city* cities, int arr_length) {
    fstream country, title;
    country.open("idx_country.txt", ios::out);
    title.open("idx_title.txt", ios::out);

    if (!title.is_open() && !country.is_open()) {
        cerr << "Error while creating file!\n";
        throw exception();
    }

    int idx[1000];
    for (int i = 0; i < arr_length; i++) {
        idx[i] = i;
    }
    for (int i = 0; i < arr_length; i++) {
        for (int j = 0; j < arr_length - 1; j++) {
            if (cities[j].country > cities[j + 1].country) {
                swap(cities[j], cities[j + 1]);
                swap(idx[j], idx[j + 1]);
            }
        }
    }
    for (int i = 0; i < arr_length; i++) {
        country << idx[i] << endl;
    }

    for (int i = 0; i < arr_length; i++) {
        idx[i] = i;
    }
    for (int i = 0; i < arr_length; i++) {
        for (int j = 0; j < arr_length - 1; j++) {
            if (cities[j].title > cities[j + 1].title) {
                swap(cities[j], cities[j + 1]);
                swap(idx[j], idx[j + 1]);
            }
        }
    }
    for (int i = 0; i < arr_length; i++) {
        title << idx[i] << endl;
    }

    country.close();
    title.close();
}

void getArrayOfIdxByField(string field, int* ArrayOfIdx, int arr_length) {
    fstream file;
    if (field == "country") {
        file.open("idx_country.txt", ios::in);
    }
    if (field == "title") {
        file.open("idx_title.txt", ios::in);
    }

    if (field != "country" && field != "title") {
        cerr << "Field " << field << " doesnt have indexes!\n";
        throw exception();
    }
    if (!file.is_open()) {
        cerr << "Error while creating file!\n";
        throw exception();
    }

    for (int i = 0; i < arr_length; i++) {
        file >> ArrayOfIdx[i];
    }

    file.close();
}