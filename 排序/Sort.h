#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void PrintArray(int* a, int n);
// ²åÈëÅÅÐò
void InsertSort(int* a, int n);
// Ï£¶ûÅÅÐò
void ShellSort(int* a, int n);

// Ö±½ÓÑ¡ÔñÅÅÐò
void SelectSort(int* a, int n);

// ¶ÑÅÅÐò
void AdjustDwon(int* a, int n, int root);
void HeapSort(int* a, int n);

// Ã°ÅÝÅÅÐò
void BubbleSort(int* a, int n);

// ¿ìËÙÅÅÐò
void QuickSort1(int* a, int begin, int end);
void QuickSort2(int* a, int begin, int end);

// ·ÇµÝ¹é
void QuickSort3(int* a, int begin, int end);

void MergeSort(int* a, int n);
// ·ÇµÝ¹é
void MergeSortNonR(int* a, int n);

void CountSort(int* a, int n);