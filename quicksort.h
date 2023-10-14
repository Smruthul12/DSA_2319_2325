#ifndef QUICKSORT_H
#define QUICKSORT_H
struct WordFrequency {
    char word[100];
    int frequency;
};
void swap(WordFrequency* a, WordFrequency* b);
int partition(WordFrequency arr[], int low, int high);
void quickSort(WordFrequency arr[], int low, int high);
#endif