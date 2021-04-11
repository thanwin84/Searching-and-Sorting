#include <bits/stdc++.h>
#define ll long long
using namespace std;
class Solution{
public:
    // Function to return maximum of sum without adjacent elements
    ll FindMaxSum(ll arr[], ll n)
    {
        // Your code here
        if (n == 1){
            return arr[0];
        }
        if (n == 2){
            return max(arr[0], arr[1]);

        }
        ll v1 = arr[0];
        ll v2 = max(arr[0], arr[1]);
        ll _max = 0;
        for (int i = 2; i < n; i++){
            _max = max(v1 + arr[i], v2);
            v1 = v2;
            v2 = _max;

        }
        return _max;
    }
};

int main() {
    ll arr[] = {7, 6, 1, 3, 8, 2, 4};
    Solution obj;
    cout << obj.FindMaxSum(arr, 7);
    return 0;
}
