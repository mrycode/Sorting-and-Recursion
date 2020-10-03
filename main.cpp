#include <iostream>
#include <vector>
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

int main() {
  std::vector<std::string> v;

  v = {"emma", "dora", "ruth", "ziegellaub", "eichler"};
  //std::cout << "Case 1: ";
  //MergeSort(v);
  BubbleSort(v);
  //print(v);
  //std::cout << "Expected: [dora, eichler, emma, ruth, ziegellaub]" << std::endl;
}