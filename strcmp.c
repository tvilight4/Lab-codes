#include <stdio.h>
#include <string.h>
void findLength(char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    if (str[length - 1] == '\n') {
        length--;
    }
    printf("Length of the string '%s' is: %d\n", str, length);
}
void compareStrings(char str1[], char str2[]) {
    int result = strcmp(str1, str2);
    if (result == 0) {
        printf("The strings '%s' and '%s' are equal.\n", str1, str2);
    } else {
        printf("The strings '%s' and '%s' are not equal.\n", str1, str2);
    }
}
int main() {
    char str1[100], str2[100];
    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    findLength(str1);
    findLength(str2);
    compareStrings(str1, str2);
    return 0;
}