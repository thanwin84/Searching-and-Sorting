#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    long long totalCutWood(vector<long long> &arr, long long mid){
        long long sum = 0;
        for (long long i: arr){
            if (i>= mid){
                sum += (i - mid);
            }

        }
        return sum;

    }
    long long findMaxHeaight(vector<long long> &arr, int N, long long M){
        long long _max = arr[0];
        for (long long i: arr){
            if (i > _max){
                _max = i;
            }
        }
        long long start = 0;
        long long end = _max;
        long long result = -1;
        while (start <= end){
            long long mid = start + (end - start)/2;
            long long gotWood = totalCutWood(arr, mid);

            if (gotWood >= M){
                cout << gotWood << " " << mid<< endl;
                start = mid + 1;
                result = max(result, mid);
            }
            else {
               end = mid -1;
           }
        }
        return result;
    }
};

int main()
{
    vector<long long> arr;
    long long N, M;
    cin >> N>> M;
    long long i;
    long long k = 0;
    for (int j = 0; j < N; j++){
        cin >> i;
        arr.push_back(i);
    }
    Solution obj;
    long long output = obj.findMaxHeaight(arr, N, M);
    cout << output << endl;

    return 0;
}
