/*
https://www.acmicpc.net/user/slew61
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int K;
        cin >> K;

        vector<int> fileSizes(K);
        for (int i = 0; i < K; ++i) {
            cin >> fileSizes[i];
        }

        vector<vector<int>> minCost(K, vector<int>(K, 0));
        vector<vector<int>> costSum(K, vector<int>(K, 0));

        for (int i = 0; i < K; ++i) {
            costSum[i][i] = fileSizes[i];
            for (int j = i + 1; j < K; ++j) {
                costSum[i][j] = costSum[i][j - 1] + fileSizes[j];
            }
        }

        for (int length = 2; length <= K; ++length) {
            for (int i = 0; i <= K - length; ++i) {
                int j = i + length - 1;
                
                minCost[i][j] = 1e9;
                for (int k = i; k < j; ++k) {
                    minCost[i][j] = min(minCost[i][j], minCost[i][k] + minCost[k + 1][j] + costSum[i][j]);
                }
            }
        }

        cout << minCost[0][K - 1] << endl;
    }

    return 0;
}