#include <stdio.h>

void NMinmax(float* A, int* N, int& NMin, int& NMax);

int main() {

    int NA=0, NB=0, NC=0, NMin, NMax;
    int* arrOfNs[3] = {&NA, &NB, &NC};

    scanf("%d %d %d", &NA, &NB, &NC);

    float A[NA];
    float B[NB];
    float C[NC];
    float* arrOfArrs[3] = {A, B, C};

    for (int j=0; j<3; j++) {
        for (int i=0; i<*(arrOfNs[j]); i++) scanf("%f", &(arrOfArrs[j][i]));
    }

    for (int i=0; i<3; i++) {
        NMinmax(arrOfArrs[i], arrOfNs[i], NMin, NMax);
        printf("%d %d\n", NMin+1, NMax+1);
    }

    return 0;
}

void NMinmax(float* A, int* N, int& NMin, int& NMax) {
    NMin=0;
    NMax=0;
    for (int i=0; i<*N; i++) {
        if (A[NMin] > A[i]) NMin=i;
        if (A[NMax] < A[i]) NMax=i;
    }
}
