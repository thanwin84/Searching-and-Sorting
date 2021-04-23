//mergesort with extraa space
#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    vector<int> merge(vector<int> &arr, vector<int> &left, vector<int> &right){
        int i = 0, j = 0, k = 0;
        while (i < left.size() and j < right.size()){
            if (left[i] <= right[j]){
                arr[k++] = left[i++];
            }
            else{
                arr[k++] = right[j++];
            }
        }
        while (i < left.size()) arr[k++] = left[i++];
        while (j < right.size()) arr[k++] = right[j++];
        return arr;
    }
    vector<int> mergeSort(vector<int> &arr){
        if (arr.size() < 2){
            return arr;
        }
        else {
            int mid = arr.size()/2;
            vector<int> left;
            vector<int> right;
            for(int i = 0; i < mid; i++) left.push_back(arr[i]);
            for(int j = mid; j < arr.size(); j++) right.push_back(arr[j]);
            vector<int> l = mergeSort(left);
            vector<int> r = mergeSort(right);
            merge(arr, l, r);
            return arr;
        }
    }
};
