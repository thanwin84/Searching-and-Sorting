#include <bits/stdc++.h>
#define int long long
using namespace std;
class Solution{
public:
    pair<int, int> solve(vector<int> powers, int bp){
        int count = 0;
        int total = 0;
        for (int i = 0; i < powers.size(); i++){
            if (powers[i] <= bp){
                total += powers[i];
                count++;
            }
            
        }
        return {count, total};

    }

};
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin>> N;
    vector<int> powers;
    int p;
    while (N--){
        cin >> p;
        powers.push_back(p);
    }
    int q;
    cin >> q;
    while (q--){
        int bp;
        cin >> bp;
        Solution obj;
        pair<int, int> p = obj.solve(powers, bp);
        cout << p.first<< " " << p.second<< endl;
    }
    return 0;
}
