#include <iostream>
#include <map>
#include <math.h>
#include <fstream>
#include <string>
#include "../menu.h"

using namespace std;

void menu(struct city* cities, int arr_length);

int main()
{
    struct city cities[1000];
    int arr_length = 0;

    menu(cities, arr_length);

    return 0;
}
