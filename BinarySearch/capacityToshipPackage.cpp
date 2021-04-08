#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPossible(vector<int> &weights, int D, int max_capacity){
        int countDays = 1;
        int countWeights = 0;
        for (int &i: weights){
            countWeights += i;
            if (i > max_capacity){
                return false;
            }
            else if (countDays > D){
                return false;
            }
            else if (countWeights > max_capacity){
                countDays += 1;
                countWeights = i;
            }

        }
        if (countDays <= D){
            return true;
        }
        else {
            return false;
        }
    }
    int shipWithinDays(vector<int>& weights, int D) {
        int sum = 0;
        for (int &i: weights){
            sum += i;
        }
        int start = 0;
        int end = sum;
        int result = INT_MAX;
        while (start <= end){
            int mid = start + (end - start)/2;
//            cout << start << " " << mid << " "<< end << " "<<isPossible(weights, D, mid)<< endl;
            if (isPossible(weights, D, mid)){
                result = min(result, mid);
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        return result;

    }
};
int main(){
    vector<int> arr = {3};
    Solution obj;
    cout << obj.shipWithinDays(arr, 3);

    return 0;
}
