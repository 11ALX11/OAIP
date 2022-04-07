#include <stdio.h>
#include <stdlib.h>

void NMinmax(float* A, int& N, int& NMin, int& NMax);

int main() {

    int NA=0, NB=0, NC=0, NMin, NMax;
    int &arrOfNs[3] = {NA, NB, NC};

    scanf("%d %d %d", &NA, &NB, &NC);

    float A[NA];
    float B[NB];
    float C[NC];
    float** arrOfArrs = {A, B, C};

    for (int j=0; j<3; j++) {
        for (int i=0; i<=arrOfNs[j]; i++) scanf("%f", &(arrOfArrs[j][i]));
    }

    for (int i=0; i<3; i++) {
        NMinmax(arrOfArrs[i], &NA, &NMin, &NMax);
        printf("%d %d\n", NMin, NMax);
    }
    NMinmax(B, NB, &NMin, &NMax);
    printf("%d %d\n", NMin, NMax);
    NMinmax(C, NC, &NMin, &NMax);
    printf("%d %d\n", NMin, NMax);

    return 0;
}

void NMinmax(float* A, int& N, int& NMin, int& NMax) {
    NMin=1;
    NMax=1;
    for (int i=1; i<=N; i++) {
        if (A[NMin] > A[i]) NMin=i;
        if (A[NMax] < A[i]) NMax=i;
    }
}
