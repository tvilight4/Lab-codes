#include <stdio.h>
#include <ctype.h>
void countAlphabetsAndWords(char str[], int*alphabetCount, int *wordCount) {
    int inWord = 0;
    *alphabetCount = 0;
    *wordCount = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalpha(str[i])) {
            (*alphabetCount)++;
        }
        if (isspace(str[i])) {
            if (inWord) {
                inWord = 0;
                (*wordCount)++;
            }
        } else {
            inWord = 1;
        }
    }

    if (inWord) {
        (*wordCount)++;
    }
}
int main() {
char str[1000];
int alphabetCount, wordCount;

printf("Enter a string: ");
fgets(str, sizeof(str), stdin);

countAlphabetsAndWords(str, &alphabetCount, &wordCount);

printf("Number of alphabets: %d\n", alphabetCount);
printf("Number of words: %d\n", wordCount);

return 0;

}