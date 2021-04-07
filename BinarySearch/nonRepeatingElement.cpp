//1: boundary check
// 2: unique element: nums[mid] != nums[mid-1] and nums[mid] != nums[mid+1]
// pair property: if non repeating character doesn't exist first repeating charater index is even and second repeating character index is odd
// after non repeating character first repeating characted index will be odd
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if (nums.size() == 1){
            return nums[0];
        }
        int start = 0;
        int end = nums.size() - 1;
        int result = -1;
        // checking boundary
        if (nums[start] != nums[start + 1]){
            return nums[start];
        }
        else if (nums[end] != nums[end - 1]){
            return nums[end];
        }
        while (start <= end){
            int mid = start + (end - start) / 2;
            if (nums[mid] != nums[mid-1] and nums[mid] != nums[mid+1]){
                return nums[mid];
            }
            if (nums[mid] == nums[mid-1] and mid % 2 != 0||
                nums[mid] == nums[mid+1] and mid % 2== 0){
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        return result;


    }
};

int main(){
     vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 5, 5};
     Solution obj;
     cout << obj.singleNonDuplicate(arr);
     return 0;
}
