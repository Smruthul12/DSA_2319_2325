#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mergesort.h"
int mergesort_()
{  
    FILE *inputFile, *outputFile;
    char word[100];
    struct WordFrequency *words = NULL;
    int wordCount = 0;
    int capacity = 1000; 

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("File not found.\n");
        return 1;
    }

    words = (struct WordFrequency *)malloc(capacity * sizeof(struct WordFrequency));
    if (words == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    while (fscanf(inputFile, "%s", word) != EOF) {
        int found = 0;
        for (int i = 0; i < wordCount; i++) {
            if (strcmp(words[i].word, word) == 0) {
                words[i].frequency++;
                found = 1;
                break;
            }
        }
        if (!found) {
            if (wordCount == capacity) {
                capacity *= 2;
                words = (struct WordFrequency *)realloc(words, capacity * sizeof(struct WordFrequency));
                if (words == NULL) {
                    printf("Memory allocation failed.\n");
                    return 1;
                }
            }
            strcpy(words[wordCount].word, word);
            words[wordCount].frequency = 1;
            wordCount++;
        }
    }

    fclose(inputFile);

    mergeSort(words, 0, wordCount - 1);

    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    for (int i = wordCount - 1; i >= 0; i--) {
        fprintf(outputFile, "%s %d\n", words[i].word, words[i].frequency);
    }

    fclose(outputFile);

    free(words);

    printf("Sorted output written to 'output.txt'.\n");
    return 0; 
}
void merge(struct WordFrequency arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    struct WordFrequency L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i].frequency > R[j].frequency) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }
}

void mergeSort(struct WordFrequency arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}