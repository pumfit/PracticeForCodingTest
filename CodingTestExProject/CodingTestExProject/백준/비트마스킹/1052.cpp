/*
1052 ¹°º´

https://www.acmicpc.net/problem/1052

*/
#include <iostream>
#include <bitset>

using namespace std;

int MergeBottle(int n) {
    int count = 0;
    while (n > 0) {
        if (n & 1) 
			count++;
        n >>= 1;
    }
    return count;
}

int main() {
    int N, K;
    std::cin >> N >> K;

    int bottles = 0;

    while (MergeBottle(N) > K) {
        N++;
        bottles++;
    }

    cout << bottles;

    return 0;
}