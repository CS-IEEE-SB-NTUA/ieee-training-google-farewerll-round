#include <iostream>
using namespace std;

int main() {
    int T; cin >> T;
    for(int t = 0; t < T; t++) {
        int K; cin >> K;
        int A[K];
        for(int i = 0; i < K; i++) 
            cin >> A[i];
        int minBreakingRules = 0, upCount = 0, downCount = 0;
        for(int i = 1; i < K; i++) {
            if(A[i] == A[i - 1])
                continue;
            else if (A[i] > A[i - 1]) {
                upCount++;
                downCount = 0;
            }
            else {
                downCount++;
                upCount = 0;
            }
            if(upCount > 3 || downCount > 3) {
                minBreakingRules++;
                upCount = downCount = 0;
            }
        }
        cout << "Case #" << (t + 1) << ": " << minBreakingRules << endl; 
    }
}

