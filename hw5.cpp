#include "hw5.h"

void print(std::vector<std::string> &v) {
  std::cout << "[";
  bool first = true;
  for (auto x : v) {
    if (!first) {
      std::cout << ", ";
    }
    std::cout << x;
    first = false;
  }
  std::cout << "]";
  std::cout << std::endl;
}

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




/*
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
*/

static void MergeHelper(std::vector<std::string> &vec, std::vector<std::string> first_half, std::vector<std::string> second_half) {
  std::cout << "in 1st half: ";print(first_half);
  std::cout << "in 2nd half: ";print(second_half);

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

  std::cout << "tmp: ";print(tmp_vector);
  int max = first_half.size() + second_half.size();
  std::cout << max << std::endl;

  for (int index = 0; index < max; index++) {
    vec[index] = tmp_vector[index];
  }
  std::cout << "vec: ";print(vec);
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
  
  int right_side;
  if (mid == 0) {
    right_side = 1;
  }
  else {
    right_side = mid;
  }
  std::vector<std::string> second_half (right_side);
  std::vector<std::string> first_half (mid+1);

  for (int left_index = left_start; left_index <= left_end; left_index++) {
    first_half[left_index] = vec[left_index];
  }
  
  int index = 0;
  for (int right_index = right_start; right_index <= right_end; right_index++) {
    second_half[index++] = vec[right_index];
  }

  MergeSort(first_half);
  MergeSort(second_half);
  MergeHelper(vec, first_half, second_half);
}