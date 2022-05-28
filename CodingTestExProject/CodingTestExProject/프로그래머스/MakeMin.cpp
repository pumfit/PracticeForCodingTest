/*
최솟값 만들기
BOJ 15577과 비슷한 그리디 문제
*/
#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
	int answer = 0;
	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), greater<int>());
	for (int i = 0; i < A.size(); i++)
		answer += A[i] * B[i];
	return answer;
}