#include "hw5.h"


void print(std::vector<int> &v) {
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

void BubbleSortHelper(std::vector<std::string> &vec, int size, std::string tmp_string) {
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





void InsertionSortHelper(std::vector<int>& v, int left_index, int key_index, int key_int, int tmp_int) {
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