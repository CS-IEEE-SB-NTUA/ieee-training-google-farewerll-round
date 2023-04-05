#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
  ll T;
  cin >> T;
  for (ll p = 0; p < T; p++) {
    ll N;
    cin >> N;
    vector<ll> v(N);
    for (auto &x : v) {
      cin >> x;
    }
    vector<ll> w = v;
    vector<ll> ans;
    sort(w.begin(), w.end());
    for (auto &x : v) {
      auto it = upper_bound(w.begin(), w.end(), 2 * x);
      it--;
      if (*it != x) {
        ans.push_back(*it);
      } else if (it == w.begin()) {
        ans.push_back(-1);
      } else {
        it--;
        ans.push_back(*it);
      }
    }
    cout << "Case #" << p + 1 << ": ";
    for (auto &x : ans) {
      cout << x << " ";
    }
    cout << '\n';
  }
}
