#include <stdio.h>
#include <string.h>
void concatenateStrings(char str1[], char str2[], char result[]) {
    strcpy(result, str1);
    strcat(result, str2);
}
int main() {
    char str1[100], str2[100], result[200];
    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);

    concatenateStrings(str1, str2, result);
    printf("Concatenated string: %s", result);
    return 0;
}