#ifndef __HW5_H__
#define __HW5_H__

#include <iostream>
#include <vector>
#include <string>


static void BubbleSortHelper(std::vector<std::string> &vec, int size, std::string tmp_string);
void BubbleSort(std::vector<std::string> &vec);
// For this problem, implement the Bubble Sort (optimized so best case is O(n)) algorithm iteratively. 
// Hint: given two strings str1 and str2, we can use str1.compare(str2). compare() returns 0 if the strings are equal,
// < 0 if str1 comes first alphabetically, and > 0 if str2 comes first alphabetically.

static void InsertionSortHelper(std::vector<int>& v, int left_index, int key_index, int key_int, int tmp_int);
void InsertionSort(std::vector<int>& v);
// For this problem, re-implement the Insertion Sort algorithm recursively.
// Rather than use a loop to go through each position we must insert into, use a recursive call. We want to insert the smallest element into the first position first and continue until we insert the largest element into the last position last. Remember that the last recursive call (the base case) finishes executing first and that the first recursive call finishes executing last.

static void Merge(std::vector<std::string> &vec, int low, int mid, int high);
static void MergeSortHelper(std::vector<std::string> &vec, int low, int high);
void MergeSort(std::vector<std::string> &vec);
// Complete the functions to implement MergeSort on a vector of strings to sort it in alphabetical order.
// Merge merges two already sorted sub-vectors: begin is the first element of the left-hand sub-vector; mid is the last
// of the left-hand sub-vector (and therefore mid + 1 is the first element of the right-hand sub-vector); and end is the
// last element of the right-hand sub-vector.
// Hint: MergeSort (with a single parameter, the vector to be sorted) makes a single call to its helper function.




#endif /* __HW5_H__ */