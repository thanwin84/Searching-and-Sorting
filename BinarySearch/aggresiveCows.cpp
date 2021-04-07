#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPossible(vector<int> &arr, int c, int mid){
        int cows  = 1;
        int left = arr[0];
        for (int i = 1; i < arr.size(); i++){
            if (arr[i] - left >= mid){
                cows += 1;
                left = arr[i];
            }
        }
        if (cows >= c){
            return true;
        }
        return false;
    }
    int findMinDistance(vector<int> &arr, int N, int C){
        sort(arr.begin(), arr.end());
        int start = arr[0];
        int end = arr[N-1];
        int result = 1;
        while (start <= end){
            int mid = start + (end - start)/2;
            if (isPossible(arr, C, mid)){
                result = max(result, mid);
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        return result;
    }
};
int main()
{
    int T;
    cin>> T ;
    while(T--){
        int n, c;
        cin >> n>> c;
        vector<int> arr;
        int k;
        for (int i = 0; i < n; i++){
            cin >> k;
            arr.push_back(k);

        }
        Solution obj;
        int result = obj.findMinDistance(arr, n, c);
        cout<< result << endl;
    }
}
