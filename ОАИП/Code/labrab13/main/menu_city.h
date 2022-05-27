using namespace std;

struct city {
    string country;
    string title;
    int people;
    double teens_part; //храним числовую часть, выводя число добавляем %

    enum additionalEnum { First, Second };
    union additionalUnion {
        int unsigned natural;
        int intger;
        double rational;
    };
    int additionalBitField : 2;
};