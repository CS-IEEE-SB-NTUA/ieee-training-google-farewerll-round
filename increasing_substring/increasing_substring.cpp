#include <bits/stdc++.h>

using namespace std;

int main(){
    int T; cin >> T;
    for(int w = 0; w<T; w++) {
        int n; cin >> n;
        string str; cin >>  str;
        vector<int> dp(n , 0);
        dp[0] = 1;
        for(int i = 1; i<n; i++){
            if(str[i - 1] < str[i]){
                dp[i] = dp[i-1] + 1;
            }
            else{
                dp[i] = 1;
            }
        }
        cout << "Case #" << w + 1 << ": ";
        for(auto & x : dp) {
            cout << x << " ";
        }
        cout << '\n';
    }
}
