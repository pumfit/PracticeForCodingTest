
/*
https://www.acmicpc.net/problem/10973
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool getPrevPermutation(vector<int> &arr) {
    int n = arr.size();
    int i = n - 1;

    while (i > 0 && arr[i-1] <= arr[i])
        i--;

    if (i <= 0)
        return false;

    int j = n - 1;
    while (arr[j] >= arr[i-1])
        j--;

    swap(arr[i-1], arr[j]);

    reverse(arr.begin() + i, arr.end());

    return true;
}

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);

    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    if (getPrevPermutation(arr)) {
        for (int i = 0; i < N; ++i) {
            cout << arr[i] << " ";
        }
        
    } else {
        cout << -1;
    }

    return 0;
}
