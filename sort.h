#ifndef SORTING_H__
#define SORTING_H__

#include <string>
#include <vector>

using namespace std;

// This file defines various sorting functions and their helper functions.
// These functions return the input in non decreasing order.

//  input:  9, 5, 4, 1, 10, 9, 3
//  output: 1, 3, 4, 5, 9, 9, 10 
//

class Sorting {
public:
  // constructor
  Sorting();

  // deconstructor
  // I use shared_pointers so I don't use this
  ~Sorting();

  // this function is recursive
  void quicksort(vector<int>& data, int low_idx, int high_idx);

  // quicksort_partition is the helper function for quicksort
  int quicksort_partition(vector<int>& data, int low_idx, int high_idx);

  // bubblesort is not efficient
  void bubblesort(vector<int>& data);

  // This uses the helper function merge(vector<int>& left, vector<int>& right, vector<int>& result).
  void mergesort(vector<int>& data);

  // mystery_sort is a selection sort algorithm
  void mystery_sort(vector<int>& data);

private:
  // merge is the helper function for mergesort. It returns a vector
  // containing the merged contents of the two input vectors, the 'result' vector.
  void merge(vector<int>& left, vector<int>& right, vector<int>& result);

};

#endif  // SORTING_H__
