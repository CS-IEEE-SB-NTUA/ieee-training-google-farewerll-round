#include <iostream>
#include <algorithm>
using namespace std;

const int maxN = 1000;
int coins[maxN + 5][maxN + 5];

long long rightDiagonals(int N) {
    long long maxCoins = 0;
    for(int j = 0; j < N; j++) {
        long long currDiagonal = coins[0][j]; 
        int i = 1;
        for(int k = (j + 1); k < N; k++) {
            currDiagonal+= coins[i][k];
            i++;
        }
        maxCoins = max(maxCoins, currDiagonal);
    }
    return maxCoins;
}

long long leftDiagonals(int N) {
    long long maxCoins = 0;
    for(int j = (N - 1); j >= 0; j--) {
            long long currDiagonal = coins[N - 1][j];
            int i = N - 2;
            for(int k = (j - 1); k >= 0; k--) {
                currDiagonal+= coins[i][k];
                i--;
            }
            maxCoins = max(maxCoins, currDiagonal);
        }
        return maxCoins;
} 

int main() {
    int T;
    cin >> T;
    for(int t = 0; t < T; t++) {
        int N; 
        cin >> N;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++)
                cin >> coins[i][j]; 
        }
        long long maxCoins = max(leftDiagonals(N), rightDiagonals(N));
        cout << "Case #" << (t+1) << ": " << maxCoins <<endl;
    }
}

