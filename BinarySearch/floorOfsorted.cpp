#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> v, long long n, long long x){

        // Your code here
        int start = 0;
        int end = n - 1;
        int location = -1;
        long long value = 0;
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
};
int main(){
     vector<long long> arr = {1, 2, 8, 10, 11, 12, 19};
     Solution obj;

     cout<< obj.findFloor(arr, 7, 0);
     return 0;
}
