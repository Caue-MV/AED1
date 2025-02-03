#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 5000
#define MAX_WORD_LENGTH 201

int compare(const void *a, const void *b) {
    return strcmp((char *)a, (char *)b);
}

int main() {
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    char word[MAX_WORD_LENGTH];
    int word_count = 0;
    int unique_words = 0;
    int i, j;
    char ch;

    while ((ch = getchar()) != EOF) {
        if (isalpha(ch)) {
            word[word_count] = tolower(ch);
            word_count++;
        } else if (word_count > 0) {
            word[word_count] = '\0';
            
            int is_unique = 1;
            for (i = 0; i < unique_words; i++) {
                if (strcmp(words[i], word) == 0) {
                    is_unique = 0;
                    break;
                }
            }
            
            if (is_unique && unique_words < MAX_WORDS) {
                strcpy(words[unique_words], word);
                unique_words++;
            }
            
            word_count = 0;
        }
    }
    
    if (word_count > 0) {
        word[word_count] = '\0';
        
        int is_unique = 1;
        for (i = 0; i < unique_words; i++) {
            if (strcmp(words[i], word) == 0) {
                is_unique = 0;
                break;
            }
        }
        if (is_unique && unique_words < MAX_WORDS) {
            strcpy(words[unique_words], word);
            unique_words++;
        }
    }
    qsort(words, unique_words, MAX_WORD_LENGTH, compare);
    for (i = 0; i < unique_words; i++) {
        printf("%s\n", words[i]);
    }
    return 0;
}