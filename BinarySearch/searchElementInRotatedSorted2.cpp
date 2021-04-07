#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        while (start <= end){
            int mid = start + (end - start)/2;
            cout<< start << end << endl;
            if (nums[mid] == target){
                return true;
            }
            if (nums[start] == target){
                return true;
            }
            if (nums[end] == target){
                return true;
            }
            if (nums[mid] == nums[end]){
                if (nums[mid] == nums[start]){
                    start += 1;
                }
                else {
                    end = mid;
                }
            }
            else if (nums[mid] < nums[end]){
                if (target >= nums[mid] and target <= nums[end]){
                    start = mid + 1;
                }
                else{
                    end = mid - 1;
                }

            }
            else {
                if (target >= nums[start] and target <= nums[mid]){
                    end = mid - 1;
                }
                else {
                    start = mid + 1;
                }
            }

        }
        return false;
    }
};
int main(){
     vector<int> arr = {5, 6, 7, 2, 2, 2, 2, 2, 2};
     Solution obj;
     cout<< obj.search(arr, 6);
     return 0;
}
