#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int element1 = nums[0];
        int count1 = 1;
        int element2 = 0;
        int count2 = 0;
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] == element1){
                count1 += 1;
            }
            else if (nums[i] == element2){
                count2 += 1;
            }
            else if (count1 == 0){
                element1 = nums[i];
                count1 = 1;
            }
            else if (count2 == 0){
                element2 = nums[i];
                count2 = 1;
            }
            else {
                count1--;
                count2--;
            }
        }
        count1 = count2 = 0;
        for (auto &i: nums){
            if (i == element1){
                count1 += 1;
            }
            else if (i == element2){
                count2 += 1;
            }
        }
        vector<int> result;
        if (count1 > nums.size()/3){
            result.push_back(element1);
        }
        if (count2 > nums.size()/3){
            result.push_back(element2);
        }
        return result;

    }
};
int main(){
    vector<int>  arr={2, 2, 2, 1, 1, 3, 3};
    Solution obj;
    vector<int> result =  obj.majorityElement(arr);
    for (auto i: result){
        cout << i << " ";
    }



    return 0;
}
