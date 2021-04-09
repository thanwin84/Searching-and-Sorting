//time:O(nlongn)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int getIndex(vector<int> &arr, int target, int start){
        if (start >= arr.size()){
            return 0;
        }
        int end = arr.size()-1;
        int location = -1;
        while (start <= end){
            int mid = start + (end - start)/2;
            if (arr[mid] == target){
                location = mid;
                break;
            }
            else if (arr[mid] > target){
                end = mid -1;
            }
            else {
                start = mid  + 1;
            }
        }
        return location;
    }
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        int first, second;
        int toSearch = 0;
        for (int i = 0; i < numbers.size(); i++){
            toSearch = target - numbers[i];
            int index = getIndex(numbers, toSearch, i+1);
            if (index >= 0){
                result.push_back(i+1);
                result.push_back(index+1);
                break;
            }
        }
        return result;
    }
};
int main() {
    vector<int> arr = {2, 3, 4};
    Solution obj;
    vector<int> output = obj.twoSum(arr, 6);
    cout << output[0] << " " << output[1] <<endl;
//    cout << obj.getIndex(arr, 7, 1);




    return 0;
}
