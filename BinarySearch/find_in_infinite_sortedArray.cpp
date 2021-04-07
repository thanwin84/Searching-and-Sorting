#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstPositionOfinfiniteSorted(vector<int> &arr, int target){
        int start = 0;
        int end = 1;
        while (target > arr[end]){
            start = end;
            end = end * 2;
        }
        int mid = start + (end - start)/2;
        if (arr[mid] == target){
            return mid;
        }
        else if (target < arr[mid]){
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
        return -1;
    }
};
int main(){
     vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
     Solution obj;

     cout<< obj.firstPositionOfinfiniteSorted(arr, 7);
     return 0;
}
