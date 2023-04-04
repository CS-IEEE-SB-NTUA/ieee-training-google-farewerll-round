#include <iostream>
using namespace std;

const int maxK = 10000;
const int infty = maxK + 5;

int dp[maxK][4], A[maxK + 5];

int p(int i, int jj, int j) {
    bool prevPitchHigher = A[i - 1] > A[i];
    bool prevKeyHigher = jj > j;
    bool prevPitchLower = A[i - 1] < A[i];
    bool prevKeyLower = jj < j;
    bool prevPitchEqual = A[i - 1] == A[i];
    bool prevKeyEqual = jj == j;
    if((prevPitchHigher and prevKeyHigher) or (prevPitchLower and prevKeyLower) or (prevPitchEqual and prevKeyEqual)) 
        return 0;    
    else 
        return 1; 
}    

int getMin(int i, int j) {
    int min = infty;  
    for(int jj = 0; jj < 4; jj++) {      
        if(min > (dp[i - 1][jj] + p(i, jj, j))) 
            min = dp[i - 1][jj] + p(i, jj, j);          
    }
    return min;
}

int main() {
    int T; cin >> T;
    for(int t = 0; t < T; t++) {
        int K; cin >> K;
        for(int i = 0; i < K; i++) 
            cin >> A[i];
        for(int j = 0; j < 4; j++)
            dp[0][j] = 0;
        for(int i = 1; i < K; i++) {
            for(int j = 0; j < 4; j++)
                dp[i][j] = getMin(i, j);
        }
        int minBreakingRules = infty;
        for(int j = 0; j < 4; j++) {
            if(minBreakingRules > dp[K - 1][j])
                minBreakingRules = dp[K - 1][j]; 
        }
        cout << "Case #" << (t + 1) << ": " << minBreakingRules << endl; 
    }
}