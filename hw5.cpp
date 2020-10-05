#include "hw5.h"



/*
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
}*/

void BubbleSort(std::vector<std::string> &vec) {
  if (vec.size() <= 1) {
    return;
  }
  
  int arr_end = vec.size()-1;
  std::string tmp_string;
  
  while (arr_end!=0) {
    std::cout << arr_end << std::endl;
    for (int index = 0; index < arr_end; index++) {
      if (vec[index].compare(vec[index+1]) >= 0) {
        tmp_string = vec[index];
        vec[index] = vec[index+1];
        vec[index+1] = tmp_string;
      }
    }
    arr_end--;
  }
  return;
}



static void InsertionSortHelper(std::vector<int>& v, int left_index, int key_index, int key_int, int tmp_int) {
  if (key_index == v.size() && left_index == 0) {
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




static void MergeHelper(std::vector<std::string> &vec, std::vector<std::string> first_half, std::vector<std::string> second_half) {

  std::vector<std::string> tmp_vector (vec.size());
  int tmp_index = 0;
  int first_start = 0;
  int first_end = first_half.size()-1;
  int second_start = 0;
  int second_end = second_half.size()-1;
  
  while (first_start<=first_end && second_start<=second_end) {
    if (first_half[first_start].compare(second_half[second_start]) <= 0) {
      tmp_vector[tmp_index] = first_half[first_start];
      first_start++;
    }
    else {
      tmp_vector[tmp_index] = second_half[second_start];
      second_start++;
    }
    tmp_index++;
  }

  while (first_start <= first_end) {
    tmp_vector[tmp_index] = first_half[first_start];
    tmp_index++;
    first_start++;
  }
  while (second_start <= second_end) {
    tmp_vector[tmp_index] = second_half[second_start];
    second_start++;
    tmp_index++;
  }

  for (int index = 0; index < first_half.size() + second_half.size(); index++) {
    vec[index] = tmp_vector[index];
  }
}
 
void MergeSort(std::vector<std::string> &vec) {
  
  if (vec.size() <= 1) {
    return;
  }
  
  int input_start = 0;
  int input_end = vec.size()-1;
  int mid = input_start + (input_end-input_start)/2;
  int left_start = input_start;
  int left_end = mid;
  int right_start = mid+1;
  int right_end = input_end;
  
  int right_arr_size;
  if (mid == 0) {
    right_arr_size = 1;
  }
  else {
    right_arr_size = (right_end+1) - right_start;
  }
  std::vector<std::string> first_half (mid+1);
  std::vector<std::string> second_half (right_arr_size);

  for (int left_index = left_start; left_index <= left_end; left_index++) {
    first_half[left_index] = vec[left_index];
  }

  int index = 0;
  for (int right_index = right_start; right_index <= right_end; right_index++) {
    second_half[index] = vec[right_index];
    index++;
  }

  MergeSort(first_half);
  MergeSort(second_half);
  MergeHelper(vec, first_half, second_half);
}