#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(vector<int> &arr, int threshold, int mid){
        int sum = 0;
        for (auto &i: arr){
            sum += ceil((double)i/mid);
            if (sum > threshold){
                return false;
            }
        }
        return true;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int start = 1;
        int end = 10e6;
        int result = 10e6;
        while (start <= end){
            int mid = start + (end - start)/2;
            if (check(nums, threshold, mid)){
                result = min(result, mid);
                end = mid -1;
            }
            else {
                start = mid + 1;
            }
        }
        return result;

    }
};
int main(){
    vector<int> arr = {2,3,5,7,11};
    Solution obj;
    cout << obj.smallestDivisor(arr, 11);

    return 0;
}
