#include "sort.h"
#include <vector>

// constructor, used to initialize class variables
Sorting::Sorting(){
}

//deconstructor
Sorting::~Sorting(){
}

void Sorting::quicksort(vector<int>& data, int low_idx, int high_idx){
//uses quicksort_partition to get the pivot index, this function is recursive
    if(low_idx >= high_idx){
        return;
    }
        
    int lp_idx = quicksort_partition(data, low_idx, high_idx);
    quicksort(data, low_idx, lp_idx);
    quicksort(data, lp_idx + 1, high_idx);
}

int Sorting::quicksort_partition(vector<int>& data, int low_idx, int high_idx){
//helper function for quicksort, return the pivot index
    int midpoint = low_idx + ((high_idx - low_idx) / 2);
    int pivot = data[midpoint];
    bool done = false;
    while(!done){
        while(data[low_idx] < pivot){
            low_idx += 1;
        }
        while(pivot < data[high_idx]){
            high_idx -= 1;
        }
        if(low_idx >= high_idx){
            done = true;
        }
        else{
            int swap = data[low_idx];
            data[low_idx] = data[high_idx];
            data[high_idx] = swap;
            low_idx += 1;
            high_idx -= 1;
        }
    }
    return high_idx;
}

void Sorting::bubblesort(vector<int>& data){
//no helper function, not efficient
    for(int i = 0; i < data.size()-1; i++){
        for(int j = 0; j < data.size()-i-1; j++){
            if(data[j] > data[j+1]){
                int num = data[j];
                data[j] = data[j+1];
                data[j+1] = num;
            }
        }
    }
}

void Sorting::mergesort(vector<int>& data){
//will use merge helper function
    int j = 0;
    int r = 0;
    int i = 0;
    int k = data.size()-1;
    if(k > 0){
        j = (i + k)/2;
        //create temp left and right to pass into mergesort then merge
        vector<int> l_data;
        vector<int> r_data;
        vector<int> result;
        for(i = 0; i < j + 1; i++){
            l_data.push_back(data[i]);
        }
        for(r = j + 1; r <= k; r++){
            r_data.push_back(data[r]);
        }
        mergesort(l_data);
        mergesort(r_data);
        merge(l_data, r_data, result); 
        for(i = 0; i <= k; i++){
            data[i] = result[i];
        }
    }
}

void Sorting::merge(vector<int>& left, vector<int>& right, vector<int>& result){
//returns merge of left and right vectors to result vector
    int leftPos = 0;
    int rightPos = 0;
    int l_size = left.size()-1;
    int r_size = right.size()-1;
    
    while(leftPos <= l_size && rightPos <= r_size){
        if(left[leftPos] <= right[rightPos]){
            result.push_back(left[leftPos]);
            leftPos += 1;
        } 
        else{
            result.push_back(right[rightPos]);
            rightPos += 1;
        }
    }
    //if left isn't empty
    while(leftPos <= l_size){
        result.push_back(left[leftPos]);
        leftPos += 1;
    }
    //if right isn't empty
    while(rightPos <= r_size){
        result.push_back(right[rightPos]);
        rightPos += 1;
    }
}

//Selection Sort
void Sorting::mystery_sort(vector<int>& data){
    int i = 0;
    int j = 0;
    for(i = 0; i < data.size(); i++){
        int jMin = i;
        for(j = i+1; j <data.size(); j++){
            if(data[j] < data[jMin]){
                jMin = j;
            }
        }
        if(jMin != i){
            int num = data[i];
            data[i] = data[jMin];
            data[jMin] = num;
        }
    }
}
