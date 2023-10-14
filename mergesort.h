#ifndef MERGESORT_H
#define MERGESORT_H
struct WordFrequency {
    char word[100];
    int frequency;
};
void merge(struct WordFrequency arr[], int l, int m, int r);
void mergeSort(struct WordFrequency arr[], int l, int r) ;
int mergesort_();
#endif