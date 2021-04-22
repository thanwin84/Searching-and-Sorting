#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int maxSum(vector<int> nums1, vector<int> nums2, int n, int m){
        int sum1 = 0, sum2 = 0;
        int i =0, j = 0;
        int total = 0;
        while(i < n and j < m){
            if (nums1[i] < nums2[j]){
                sum1 += nums1[i];
                i++;
            }
            else if(nums2[j] < nums1[i]){
                sum2 += nums2[j];
                j++;
            }
            else {
                total = total +  max(sum1, sum2) + nums1[i];
                sum1 = 0;
                sum2 = 0;
                i++;
                j++;
            }
        }
        while (i < n){
            sum1 += nums1[i];
            i++;
        }
        while (j < m){
            sum2 += nums2[j];
            j++;
        }
        total += max(sum1, sum2);
        return total;

    }
};
int main(){
    while(true){
        int n;
        cin >> n;
        if (n == 0){
            break;
        }
        else {
            vector<int> nums1;
            for(int i = 0; i < n; i++){
                int first;
                cin>> first;
                nums1.push_back(first);
            }
            int m;
            cin>> m;
            vector<int> nums2;
            for(int i =0; i < m; i++){
                int second;
                cin >> second;
                nums2.push_back(second);
            }
            Solution obj;
            int output = obj.maxSum(nums1, nums2, n, m);
            cout << output << endl;
        }
    }
    return 0;
}
