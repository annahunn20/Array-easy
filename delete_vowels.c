#include <stdio.h>
#include <string.h>

int isVowel(char ch) {
    ch = tolower(ch);
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

void deleteVowels(char str[]) {
    int i, j = 0;
    int n = strlen(str);
    char result[n + 1];

    for (i = 0; i < n; i++) {
        if (!isVowel(str[i])) {
            result[j++] = str[i];
        }
    }
    result[j] = '\0';
    strcpy(str, result);
}

int main() {
    char str[] = "Hello World";
    deleteVowels(str);
    printf("String after removing vowels: %s\n", str);
    return 0;
}
