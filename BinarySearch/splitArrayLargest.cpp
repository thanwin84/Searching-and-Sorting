#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(vector<int> &arr, int m, int _max){
        int count = 1;
        int sum = 0;
        for (int &i: arr){
            sum += i;

            if(sum > _max){
                count += 1;
                sum = i;
            }
        }

       return count <= m;
    }
    int splitArray(vector<int>& nums, int m) {
        int sum = 0;
        int _max = INT_MIN;
        for (auto &i: nums){
            sum += i;
            if (i > _max){
                _max = i;
            }
        }
        int result = _max;
        int start = _max;
        int end = sum;
        while (start < end){
            int mid = start + (end - start)/2;
            if (check(nums, m, mid)){
                end = mid;

            }
            else {

                start = mid + 1;
            }
        }
        return start;

    }
};
int main(){
    vector<int> arr = {7,2,5,10,8};
    Solution obj;
    cout << obj.splitArray(arr, 2);

    return 0;
}
