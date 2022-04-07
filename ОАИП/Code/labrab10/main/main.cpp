#include <stdio.h>

using namespace std;

struct city {
    char *country;
    char *title;
    int people;
    double teens_part; //храним числовую часть, выводя число добавляем %
};

char *getCountryWithMaxTeens(struct city *cities, int arr_length);

char *arrayToString(struct city *cities, int arr_length);

void addByField(char *field, int people, struct city *cities, int *arr_length);
void addByField(char *field, char *title, struct city *cities, int *arr_length);
void addByField(char *field, double teens_part, struct city *cities, int *arr_length);

void sortByField(char *field, struct city *cities, int arr_length);

void deleteByField(char *field, int people, struct city *cities, int *arr_length);
void deleteByField(char *field, double teens_part, struct city *cities, int *arr_length);
void deleteByField(char *field, char *title, struct city *cities, int *arr_length);

int main()
{
    struct city cities[] = {
        {
            .country = "RU",
            .title = "Moscow",
            .teens_part = 17.78,
        },
        {
            .country = "EN",
            .title = "London",
            .teens_part = 15.58,
        },
        {
            .country = "BEL",
            .title = "Minsk",
            .teens_part = 18.78,
        }
    };
    int arr_length=3;

    char input[255];
    while (/* compare str's */) {
        if (input == "1") {
            printf("Secret!");
        }

        printf("Working with menu:\n0 - exit\n");
        scanf("%s", &input);
    }

    return 0;
}

char *getCountryWithMaxTeens(struct city *cities, int arr_length) {
    int ans=0;
    for (int i=1; i<arr_length; i++)
        if (cities[i].teens_part > cities[ans].teens_part)
            ans = i;

    return cities[ans].country;
};
