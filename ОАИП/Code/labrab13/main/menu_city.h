using namespace std;

struct city {
    string country;
    string title;
    int people;
    double teens_part; //������ �������� �����, ������ ����� ��������� %

    enum additionalEnum { First, Second };
    union additionalUnion {
        int unsigned natural;
        int intger;
        double rational;
    };
    int additionalBitField : 2;
};