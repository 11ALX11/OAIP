#include <stdio.h>

int IsIndent(char* s);

int main() {

    const int MAX_LENGTH = 10000;

    int ArrayOfCodes[5];
    char str[MAX_LENGTH];
    
    for (int i=0; i<5; i++) {
        gets(str);
        ArrayOfCodes[i] = IsIndent(str);
 }

    for (int i=0; i<5; i++) printf("%d\n", ArrayOfCodes[i]);
        
    return 0;
}

int IsIndent(char* s) {

    if (s[0] == '\0') return -1;
    if (s[0] > '0' && s[0] < '9') return -2;
    
    int i=-1;
    while (s[++i]!='\0') {
        if ((s[i] >= '0' && s[i] <= '9') ||
            (s[i] >= 'A' && s[i] <= 'Z') ||
            (s[i] >= 'a' && s[i] <= 'z') ||
            (s[i] == '_')) continue;
    
        return i+1;
    }

    return 0;
}
