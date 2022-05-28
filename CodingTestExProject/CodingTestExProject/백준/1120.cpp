/*
1120 문자열

# https://www.acmicpc.net/problem/1120
길이가 N으로 같은 문자열 X와 Y가 있을 때, 두 문자열 X와 Y의 차이는 X[i] ≠ Y[i]인 i의 개수이다. 예를 들어, X=”jimin”, Y=”minji”이면, 둘의 차이는 4이다.
두 문자열 A와 B가 주어진다. 이때, A의 길이는 B의 길이보다 작거나 같다. 이제 A의 길이가 B의 길이와 같아질 때 까지 다음과 같은 연산을 할 수 있다.

A의 앞에 아무 알파벳이나 추가한다.
A의 뒤에 아무 알파벳이나 추가한다.
이때, A와 B의 길이가 같으면서, A와 B의 차이를 최소로 하는 프로그램을 작성하시오.


처음에 어렵지 않을까 생각했는데 생각보다 쉬운 문제였다. 역시 실버
B의 문자열 크기내에서(A의 끝이 B의 끝에 닿을 때 까지) 시작 인덱스를 증가시키면서 A의 문자가 매칭되지 않는 수를 구하면 된다.
어차피 빈 공간은 맞는 문자로 채워넣게 되니 차이가 최소인 구간 그자체만 구한면 된다.
*/
#include <iostream>
using namespace std;

int main() {
	string A, B;
	int answer = 2e9;
	cin >> A >> B;
	for (int i = 0; i < B.size(); i++)
	{
		int match = 0;
		if (i + A.size() == B.size() + 1)
			break;
		for (int j = 0; j < A.size(); j++)
		{
			if (B[i + j] != A[j])
				match++;
		}
		answer = min(match, answer);
	}
	cout << answer;
	return 0;
}