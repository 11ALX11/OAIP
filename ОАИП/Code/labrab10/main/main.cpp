#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct city {
    char *country;
    char *title;
    int people;
    double teens_part; //храним числовую часть, выводя число добавляем %
};

char *getCountryWithMaxTeens(struct city *cities, int arr_length);

void displayCity(struct city &city);

void addCity(char *country, char *title, int people, double teens_part, struct city *cities, int &arr_length);

void sortByField(char *field, struct city *cities, int arr_length);

void deleteById(int key, struct city *cities, int &arr_length);

int main()
{
    struct city cities[100];
    int arr_length=0;

    char input[256];
    while (strcmp(input, "0") != 0) {
        printf("Working with menu:\n0 - exit\t1 - get country with max teens\n2 - input new city\t3 - get cities\n4 - \t5 - \n");
        scanf("%s", &input);
        
        if (strcmp(input, "1") == 0) {
            printf("Country with max teens: %s\n", getCountryWithMaxTeens(cities, arr_length));
        }
        if (strcmp(input, "2") == 0) {
            printf("Country:\n");
            char country[256];
            scanf("%s", &country);
            
            printf("City:\n");
            char title[256];
            scanf("%s", &title);
            
            printf("Amount of people:\n");
            int people;
            scanf("%d", &people);
            
            printf("Teens in %%:\n");
            double teens_part;
            scanf("%lf", &teens_part);
            
            addCity(country, title, people, teens_part, cities, arr_length);
        }
        if (strcmp(input, "3") == 0) {
            for (int i=0; i<arr_length; i++) {
                displayCity(cities[i]);
            }
        }
        if (strcmp(input, "4") == 0) {
            printf("Secret!\n");
        }
    }

    return 0;
}

char *getCountryWithMaxTeens(struct city *cities, int arr_length) {
    int ans=0;
    for (int i=1; i<arr_length; i++)
        if (cities[i].teens_part > cities[ans].teens_part)
            ans = i;

    if (arr_length>0) return cities[ans].country;
    else return "There's no city yet.";
}

void displayCity(struct city &city) {
    printf("Country: %s, City: %s, People: %d, Teens: %f%%\n", city.country, city.title, city.people, city.teens_part);
}

void addCity(char *country, char *title, int people, double teens_part, struct city *cities, int &arr_length) {
    arr_length++;
        
    cities[arr_length-1].country = country;
    cities[arr_length-1].title = title;
    cities[arr_length-1].people = people;
    cities[arr_length-1].teens_part = teens_part;
}
