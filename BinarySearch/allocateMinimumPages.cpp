#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPossible(int arr[], int n, int m, int max){
        int student = 1;
        int sum = 0;
        for (int i = 0; i < n; i++){
            sum += arr[i];
            if (sum > max){
                student += 1;
                sum = 0;
                sum += arr[i];
            }
            if (student > m){
                return false;
            }
        }
        return true;
    }
    int findPages(int arr[], int n, int m) {
        if (m > n){
            return -1;
        }
        int _max = arr[0];
        int sum = 0;
        for (int i = 0; i < n; i++){
            sum += arr[i];
            if (arr[i] > _max){
                _max = arr[i];
            }
        }
        int start = _max;
        int end = sum;
        int result = INT_MAX;
        while (start <= end){
            int mid = start + (end - start)/2;
            if (isPossible(arr, n, m, mid)){
                result = min(result, mid);
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        return result;

    }
};
int main(){
     Solution obj;
     int a[] = {15,17,20};
     cout <<obj.findPages(a, 3, 2);
     return 0;
}
