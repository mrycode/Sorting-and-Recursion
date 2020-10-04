#include "hw5.h"



static void BubbleSortHelper(std::vector<std::string> &vec, int size, std::string tmp_string) {
  if (size==0) {
    return;
  }
  for (int index = 0; index < size; index++) {
    if (vec[index].compare(vec[index+1]) >= 0) {
      tmp_string = vec[index];
      vec[index] = vec[index+1];
      vec[index+1] = tmp_string;
    }
  }
  BubbleSortHelper(vec, size-1, "");
}

void BubbleSort(std::vector<std::string> &vec) {
  if (vec.size() <= 1) {
    return;
  }
  BubbleSortHelper(vec, vec.size()-1, "");
}




static void InsertionSortHelper(std::vector<int>& v, int left_index, int key_index, int key_int, int tmp_int) {
  if (key_index == v.size()-1 && left_index == 0) {
    return;
  }
  else if (left_index == 0) {
    if (v[left_index] > key_int) {
      tmp_int = v[left_index];
      v[left_index] = key_int;
      v[left_index+1] = tmp_int;
    }
    InsertionSortHelper(v, key_index, key_index+1, v[key_index], 0);
  }
  else {
    if (v[left_index] > key_int) {
      v[left_index+1] = v[left_index];
      v[left_index] = key_int;
    }
    InsertionSortHelper(v, left_index-1, key_index, key_int, 0);
  }
}

void InsertionSort(std::vector<int>& v) {
  InsertionSortHelper(v, 0, 1, v[1], 0);
}





static void Merge(std::vector<std::string> &vec, int low, int mid, int high) {
  
  std::vector<std::string> tmp_vec(vec.size(), " ");
  int tmp_index = low;
  int left_side_start = low;
  int left_side_end = mid;
  int right_side_start = mid + 1;
  int right_side_end = high;
  
  while ((left_side_start <= left_side_end) && (right_side_start <= right_side_end)) {
    if (vec[left_side_start].compare(vec[right_side_start]) <= 0) {
      tmp_vec[tmp_index] = vec[left_side_start];
      left_side_start++;
    }
    else {
      tmp_vec[tmp_index] = vec[right_side_start];
      right_side_start++;
    }
    tmp_index++;
  }
  while (left_side_start <= left_side_end) {
    tmp_vec[tmp_index] = vec[left_side_start];
    left_side_start++;
    tmp_index++;
  }
  
  while (right_side_start <= right_side_end) {
    tmp_vec[tmp_index] = vec[right_side_start];
    right_side_start++;
    tmp_index++;
  }
  
  for (int return_index=low; return_index <= high; return_index++) {
    vec[return_index] = tmp_vec[return_index];
  }
}

static void MergeSortHelper(std::vector<std::string> &vec, int low, int high) {
  if (low < high) {
    int mid = low + (high-low)/2;
    MergeSortHelper(vec, low, mid);
    MergeSortHelper(vec, mid+1, high);
    Merge(vec, low, mid, high);
  }
}

void MergeSort(std::vector<std::string> &vec) {
  if (vec.size()<=1) {
    return;
  }
  MergeSortHelper(vec, 0, vec.size()-1);
}