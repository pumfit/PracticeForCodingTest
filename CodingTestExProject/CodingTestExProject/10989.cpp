/*
10989 수 정렬하기 3 

N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.

첫째 줄에 수의 개수 N(1 ≤ N ≤ 10,000,000)이 주어진다. 둘째 줄부터 N개의 줄에는 수가 주어진다. 이 수는 10,000보다 작거나 같은 자연수이다.

범위가 짧고 갯수가 많은 점을 고려하면 쉽게 풀 수 있는 문제이다.
테스트 케이스가 힌트인 문제
*/
#include <iostream>
using namespace std;

int n, num;
int arr[10001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        arr[num]++;
    }
    for (int i = 1; i <= 10000; i++) {
        while (arr[i] > 0) {
            cout << i << '\n';
            arr[i]--;
        }
    }
    return 0;
}