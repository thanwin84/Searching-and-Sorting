#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPossible(vector<int> &arr, int mid, int painters){
        int countPainter = 1;
        int sum = 0;
        for (int i: arr){
            sum += i;
            if (i > mid){
                return false;
            }
            if (sum > mid){
                countPainter += 1;
                sum = 0;
                sum += i;
            }
            if (countPainter > painters){
                return false;
            }
        }
        return true;
    }
    int findMinTime(vector<int> & arr, int painters){
        int result = INT_MAX;
        int _min = arr[0];
        int total = 0;
        for (int &i: arr){
            total += i;
            if (i < _min){
                _min = i;
            }
        }
        int start = _min;
        int end = total;
        while (start <= end){

            int mid = start + (end - start)/2;
//            cout << start << " "<< end << " " << mid << " "<< isPossible(arr, mid, painters)<< endl;
            if (isPossible(arr, mid, painters)){
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

int main()
{
    int T;
    cin >> T;
    vector<int> result;
    while (T--){
        int k, n;
        vector<int> arr;
        cin>> k >> n;
        int item;
        for (int i = 0; i < n; i++){
            cin >> item;
            arr.push_back(item);
        }
        Solution obj;
        int output = obj.findMinTime(arr, k);
        result.push_back(output);

    }
    for (int i: result){
        cout << i << endl;
    }

    return 0;
}
