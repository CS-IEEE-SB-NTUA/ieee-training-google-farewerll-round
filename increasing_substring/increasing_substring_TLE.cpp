#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vector_ll vecor<long long>
#define MOD 1000000007

int main() {
  ll T;
  cin >> T;
  for (ll p = 0; p < T; p++) {
    int N;
    cin >> N;
    string str;
    cin >> str;
    vector<int> ans(N, 1);
    for (int i = 0; i < N; i++) {
      for (int j = i; j < N; j++) {
        bool check = 1;
        for (int w = i; w < j; w++) {
          check &= (str[w] < str[w + 1]);
        }
        if (check) {
          ans[j] = max(ans[j], j - i + 1);
        }
      }
    }
    cout << "Case #" << p + 1 << ": ";
    for (auto &x : ans) {
      cout << x << " ";
    }
    cout << '\n';
  }
}
