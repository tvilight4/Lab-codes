#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int main() {
    char str[50];
    scanf("%[^\n]s", str);
    int len = strlen(str);
    char str2[len];
    for (int i=0; i<len; i++) {
        str2[i] = str[len-i-1];
    }
    str2[len] = '\0';
    printf("%s", str2);
    return 0;
}

//palindrome checker

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int main() {
    char str[50];
    scanf("%[^\n]s", str);
    int len = strlen(str);
    char str2[len];
    for (int i=0; i<len; i++) {
        str2[i] = str[len-i-1];
    }

    int cnt = 1;
    
    for (int i=0; i<len; i++) {
        if (str2[i] != str[i]) {
            cnt = 0;
        }
    }
    if (cnt == 0) {
    printf("not a palindrome");
    } else printf("is a palindrome");
    return 0;
}