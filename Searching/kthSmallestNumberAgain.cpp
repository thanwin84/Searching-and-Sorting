#include <bits/stdc++.h>
#define int long long int
using namespace std;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--){
        int n, q;
        cin>> n >> q;
        vector<vector<int>> intervals;
        while(n--){
            int a, b;
            cin >> a >> b;
            intervals.push_back({a, b});
        }
        sort(intervals.begin(), intervals.end());
        int index = 0;
        for(int i = 1; i < intervals.size(); i++){
            if (intervals[index][1] >= intervals[i][0]){
                intervals[index][1] = max(intervals[index][1], intervals[i][1]);

            }
            else{
                index++;
                intervals[index] = intervals[i];

            }

        }
        while (q--){
            int k;
            cin >> k;
            int ans = -1;
            for (int i = 0; i <= index; i++){
                int diff = intervals[i][1] - intervals[i][0]+1;
                if (k > diff){
                    k = k - diff;

                }
                else{
                    ans =intervals[i][0] + k -1;
                    break;
                }

            }
            cout << ans << endl;
        }

    }

}
