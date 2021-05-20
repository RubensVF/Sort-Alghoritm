#ifndef SORT_H_   /* Include guard */
#define SORT_H_

#include <stdio.h>
void swap(float *xp, float *yp);
 
// A function to implement bubble sort
void bubbleSort(float arr[], int n, void display(float*,int));

void selectionSort(float arr[], int n, void display(float*,int));

void insertionSort(float arr[], int n, void display(float*,int));

void shellSort(float arr[], int n, void display(float*,int));

int partition (float arr[], int low, int high, int n,void display(float*,int));

void quickSortaux(float arr[], int low, int high,int n,void display(float*,int));

void quickSort(float arr[], int n,void display(float*,int));

void merge(float arr[], int l, int m, int r,int n, void display(float*,int));

void mergeSortaux(float arr[], int l, int r,int n, void display(float*,int));

void mergeSort(float arr[], int n, void display(float*,int));

void heapify(float arr[], int n, int i,void display(float*,int));

void heapSort(float arr[], int n,void display(float*,int));



#endif // FOO_H_