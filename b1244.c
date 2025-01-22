#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(char **str1, char **str2) {
    char *temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}

void sort_words_by_length(char **words, int word_count) {
    for(int i = 0; i < word_count - 1; i++) {
        for(int j = 0; j < word_count - i - 1; j++) {
            if(strlen(words[j]) < strlen(words[j + 1])) {
                swap(&words[j], &words[j + 1]);
            }
        }
    }
}

int main() {
    int num_strings;
    scanf("%d", &num_strings);
    getchar();
    char input[1000];
    char *words[100];
    for(int str = 0; str < num_strings; str++) {
        int word_count = 0;
        fgets(input, sizeof(input), stdin);
        if(input[strlen(input) - 1] == '\n') {
            input[strlen(input) - 1] = '\0';
        }
        char *word = strtok(input, " ");
        while(word != NULL && word_count < 100) {
            words[word_count] = strdup(word);
            word_count++;
            word = strtok(NULL, " ");
        }
        sort_words_by_length(words, word_count);
        for(int i = 0; i < word_count; i++) {
            printf("%s", words[i]);
            if(i < word_count - 1) {
                printf(" ");
            }
        }
        printf("\n");
        for(int i = 0; i < word_count; i++) {
            free(words[i]);
        }
    }
    return 0;
}