#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int maxW = 100000;
const ll inf = 100000000000000;;
const int maxN = 1000000000;

int X[maxW + 5]; 
ll pre[maxW + 6] = {0};

ll getSum(int i, int j) {
    return pre[j] - pre[i - 1]; 
}

int binSearchLeft(int i, int N) {
    int left = 0, right = i;
    while(left <= right) {
        int mid = (left + right) / 2;
        if((X[i] - X[mid]) <= (N - X[i] + X[mid])) 
            right = mid - 1;
        else 
            left = mid + 1;    
    }
    return right;
}

int binSearchRight(int i, int N) {
    int left = i, right = N - 1;
    while(left <= right) {
        int mid = (left + right) / 2;
        if( (X[mid] - X[i]) <= (N - X[i] + X[mid])) 
            left = mid + 1;
        else 
            right = mid - 1;    
    }
    return right;
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    for(int t = 0; t < T; t++) {
        int N, W; cin >> W >> N;
        for(int i = 0; i < W; i++)
            cin >> X[i];
        for(int i = 1; i <= N; i++) 
           pre[i] = pre[i - 1] + X[i - 1];
        ll minVal = inf; 
        for(int i = 0; i < W; i++) {
            int p = binSearchLeft(i, N);
            int b = binSearchRight(i, N);
            ll val = (i - p + 1) * X[i] - getSum(p + 1, i + 1) + (p - 1) * (N - X[i]) + getSum(1, p);
            val += getSum(i + 2, b + 1) -(b - i) * X[i] + (W - 1 -b)*(N + X[i]) - getSum(b+2, W);
            minVal = min(minVal, val);
        }
        cout<< "Case #" << (t + 1) <<": " << minVal << endl;    
    }    
}