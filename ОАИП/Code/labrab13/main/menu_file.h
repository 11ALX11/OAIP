#include <fstream>
#include <string>
#include "menu_idx.h"

 using namespace std;

void saveToFile(string fileName, struct city* cities, int& arr_length);
void saveToFileOne(fstream& file, struct city city);

void saveToFile(string fileName, struct city* cities, int& arr_length) {
    fstream file;
    file.open(fileName, ios::out);

    if (!file.is_open()) {
        cerr << "Error while creating file!\n";
        throw exception();
    }

    for (int i = 0; i < arr_length; i++) {
        saveToFileOne(file, cities[i]);
    }
    file.close();
}

void saveToFileOne(fstream& file, struct city city) {
    file << city.country << endl;
    file << city.title << endl;
    file << city.people << endl;
    file << city.teens_part << endl;
}