#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findCeil(vector<long long> v, long long n, long long x){

        // Your code here
        int start = 0;
        int end = n - 1;
        int location = -1;
        long long value = 0;
        while (start <= end){
            int mid = start + (end - start)/2;
            cout << start << end << endl;
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
     vector<long long> arr = {1, 2, 8, 10, 10, 12, 19};
     Solution obj;

     cout<< obj.findCeil(arr, 7, 20);
     return 0;
}
