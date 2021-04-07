//https://youtu.be/3RhGdmoF_ac
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMinimumDifferenceElement(vector<int> &arr, int target){
        int ceilNum = findCeil(arr, arr.size(), target);
        int floorNum = findFloor(arr, arr.size(), target);
        int result = arr[ceilNum];
        if (abs(arr[floorNum] - target) < result){
            result = arr[floorNum];
        }
        return result;
    }
    int findFloor(vector<int> v, int n, int x){

        // Your code here
        int start = 0;
        int end = n - 1;
        int location = -1;
        int value = 0;
        while (start <= end){
            int mid = start + (end - start)/2;
            if (x >= v[mid] and v[mid] > value){
                value = v[mid];
                location = mid;
            }
            else if(x < v[mid]){
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        return location;

    }
    int findCeil(vector<int> v, int n, int x){

        // Your code here
        int start = 0;
        int end = n - 1;
        int location = -1;
        int value = 0;
        while (start <= end){
            int mid = start + (end - start)/2;
            if (v[mid] == x){
                return mid;
            }
            if (v[mid] >= x){
                location = mid;
                if (v[mid] < value){
                    value = v[mid];
                }
            }
            if(x < v[mid]){
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        return location;

    }
};
int main(){
     vector<int> arr = {11, 3, 8, 10, 15};
     Solution obj;

     cout<< obj.findMinimumDifferenceElement(arr, 15);
     return 0;
}
