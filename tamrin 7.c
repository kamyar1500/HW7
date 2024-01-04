#include <stdio.h>
int stringLength(char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

int stringCompare(char str1[], char str2[]) {
    int i = 0;
    while (str1[i] != '\0' || str2[i] != '\0') {
        if (tolower(str1[i]) != tolower(str2[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}

int main() {
    char words_lang1[50][50];
    char words_lang2[50][50];
    int num_words;

    printf("Enter the number of words in each language: ");
    scanf("%d", &num_words);

    printf("Enter %d words in language 1: \n", num_words);
    for (int i = 0; i < num_words; ++i) {
        scanf("%s", words_lang1[i]);
    }

    printf("Enter %d words in language 2: \n", num_words);
    for (int i = 0; i < num_words; ++i) {
        scanf("%s", words_lang2[i]);
    }

    char sentence[1000];
    printf("Enter a sentence in language 1: \n");
    scanf(" %[^\n]s", sentence);

    char *token = strtok(sentence, " ");
    printf("Equivalent sentence in language 2: \n");
    while (token != NULL) {
        for (int i = 0; i < num_words; ++i) {
            if (stringCompare(token, words_lang1[i])) {
                printf("%s ", words_lang2[i]);
                break;
            }
        }
        token = strtok(NULL, " ");
    }

    return 0;
}