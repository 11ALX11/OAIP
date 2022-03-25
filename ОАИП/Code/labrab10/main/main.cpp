#include <stdio.h>

using namespace std;

struct city {
    char *country;
    char *title;
    int people;
    double teens_part; //храним числовую часть, выводя число добавляем %
};

char *getCountryWithMaxTeens(struct city *cities);

void UI();
char *arrayToString(struct city cities[]);

void deleteByCountry(char *country);
void deleteByTitle(char *title);
void deleteByPeople(int people);
void deleteByTeens_part(double teens_part);

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

    char *ans = getCountryWithMaxTeens(cities);

    printf("%s", ans);

    return 0;
}

char *getCountryWithMaxTeens(struct city *cities) {
    int ans = 0;
    for (int i=0; i<3; i++)
        if (cities[i].teens_part > cities[ans].teens_part)
            ans = i;

    return cities[ans].country;
};
