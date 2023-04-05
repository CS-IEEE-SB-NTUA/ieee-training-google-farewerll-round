#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
  ll T;
  cin >> T;
  for (ll p = 0; p < T; p++) {
    ll N;
    cin >> N;
    vector<int> v(N);
    for (auto &x : v) {
      cin >> x;
    }
    cout << "Case #" << p + 1 << ": ";
    for (int i = 0; i < N; i++) {
      int current = INT_MIN;
      for (int j = 0; j < N; j++) {
        if (i != j && v[j] <= 2 * v[i]) {
          current = max(current, v[j]);
        }
      }
      cout << ((current != INT_MIN) ? current : -1) << " ";
    }
    cout << '\n';
  }
}
