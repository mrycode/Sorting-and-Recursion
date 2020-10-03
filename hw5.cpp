#include "hw5.h"


void BubbleSortHelper(std::vector<std::string> &vec, int size) {
  std::cout << size << std::endl;
  if (size==0) {
    return;
  }
  std::string tmp_string;
  for (int index = 0; index <= size; index++) {
    if (vec[index].compare(vec[index+1]) >= 0) {
      tmp_string = vec[index];
      vec[index] = vec[index+1];
      vec[index+1] = tmp_string;
    }
  }
  BubbleSortHelper(vec, size-1);
}

void BubbleSort(std::vector<std::string> &vec) {
  BubbleSortHelper(vec, vec.size());
}