#include <bits/stdc++.h>
using namespace std;
// iterative binary search
int binarySearch(vector<int> &arr, int element){
    int start = 0;
    int end = arr.size() - 1;
    while (start <= end){
        int mid = start + (end - start) / 2;
        if (arr[mid] == element){
            return mid;
        }
        else if (element < arr[mid]){
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
    return -1;
}
// recurive binary search
int recursiveBinarySearch(vector<int> &arr, int start, int end, int element){
    if (start > end){
        return -1;
    }
    else {
        int mid = start + (end - start)/2;
        if (arr[mid] == element){
            return mid;
        }
        else if (element < arr[mid]){
            return recursiveBinarySearch(arr,start, mid -1, element);
        }
        else {
            return recursiveBinarySearch(arr, mid+1, end, element);
        }
    }
}
// search element in a reverse sorted array
int bs_on_reverse_sorted(vector<int> &arr, int element){
    int start = 0;
    int end = arr.size() - 1;
    while (start <= end){
        int mid = start + (end - start)/2;
        if (element  == arr[mid]){
            return mid;
        }
        else if (element < arr[mid]){
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    return -1;
}
int main(){
    vector <int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    cout<< binarySearch(arr, 8) << endl;
    cout << recursiveBinarySearch(arr, 0, 7, 4) << endl;
}
