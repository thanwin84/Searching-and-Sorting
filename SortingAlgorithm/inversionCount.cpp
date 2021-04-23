#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int merge(vector<int> &arr, int start, int end, int mid){
        int count = 0;
        int i = 0, j = 0, k = start;
        int n = mid - start + 1;
        int m = end - mid;
        vector<int> left;
        vector<int> right;
        for(int l = start; l < mid+1; l++ ) left.push_back(arr[l]);
        for (int r = mid+1; r < end+1; r++) right.push_back(arr[r]);
        while (i < n and j < m){
            if (left[i] <= right[j]){
                arr[k++] = left[i++];
            }
            else{
                count += n - i;
                arr[k++] = right[j++];
            }
        }
        while (i < n) arr[k++] = left[i++];
        while (j < m) arr[k++] = right[j++];
        return count;

    }

    int mergeSort(vector<int> &arr, int start,int end){
        int inv = 0;
        if (start < end){
            int mid = start + (end - start)/2;
            inv += mergeSort(arr, start, mid);
            inv += mergeSort(arr, mid+1, end);
            inv+= merge(arr, start, end, mid);

        }
        return inv;
    }
};
