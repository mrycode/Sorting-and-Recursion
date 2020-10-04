#include <iostream>
#include <vector>
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

int main() {
  std::vector<std::string> v;
  std::vector<int> v_int;


  v = {"emma", "dora"};
  v = {"emma", "dora", "ruth"};
  v = {"emma", "dora", "ruth", "ziegellaub", "eichler"};
  v_int = {-6,-4,-23,-7,-9,-5,-3,-8,-6543,-3,-5,-6778,-100};
  //std::cout << "Case 1: ";
  MergeSort(v);
  //print(v);

  //BubbleSort(v);
  //InsertionSort(v_int);
  //std::cout << "output: ";
  //print(v_int);
  //std::cout << "Expected: [dora, eichler, emma, ruth, ziegellaub]" << std::endl;
}