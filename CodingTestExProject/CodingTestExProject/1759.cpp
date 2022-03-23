/*
1759 암호 만들기

바로 어제 최백준 조교가 방 열쇠를 주머니에 넣은 채 깜빡하고 서울로 가 버리는 황당한 상황에 직면한 조교들은, 702호에 새로운 보안 시스템을 설치하기로 하였다. 이 보안 시스템은 열쇠가 아닌 암호로 동작하게 되어 있는 시스템이다.

암호는 서로 다른 L개의 알파벳 소문자들로 구성되며 최소 한 개의 모음(a, e, i, o, u)과 최소 두 개의 자음으로 구성되어 있다고 알려져 있다. 또한 정렬된 문자열을 선호하는 조교들의 성향으로 미루어 보아 암호를 이루는 알파벳이 암호에서 증가하는 순서로 배열되었을 것이라고 추측된다. 즉, abc는 가능성이 있는 암호이지만 bac는 그렇지 않다.

새 보안 시스템에서 조교들이 암호로 사용했을 법한 문자의 종류는 C가지가 있다고 한다. 이 알파벳을 입수한 민식, 영식 형제는 조교들의 방에 침투하기 위해 암호를 추측해 보려고 한다. C개의 문자들이 모두 주어졌을 때, 가능성 있는 암호들을 모두 구하는 프로그램을 작성하시오.


https://www.acmicpc.net/problem/1759

로또 문제에서 모음의 개수에 대한 처리만 진행하면 되는 문제이다.
로또 문제에서는 크기 비교하고 제외하는 방법이 떠오르지않아 오래걸렸지만
이번 문제에는 그런 어려움없이 진행되어서 쉽게 풀 수 있었다.
*/
#include <iostream>
#include <algorithm>
using namespace std;

int L, C;
char arr[15];
int num[15] = { 0, };
int visited[15] = { 0, };

void bf(int idx)
{
	if (idx == L)
	{
		bool isPass = true;
		int prev = arr[num[0]];
		int cnt = 0;
		for (int i = 0; i < L; i++)
		{
			if (arr[num[i]] == 'i' || arr[num[i]] == 'a' || arr[num[i]] == 'e' || arr[num[i]] == 'o' || arr[num[i]] == 'u')
				cnt++;
			if (prev > arr[num[i]])
			{
				isPass = false;
				break;
			}
			prev = arr[num[i]];
		}
		if (cnt == 0)
			isPass = false;
		if (L - cnt <= 1)
			isPass = false;
		if (isPass)
		{
			for (int i = 0; i < L; i++)
			{
				cout << arr[num[i]];
			}
			cout << endl;
		}
		return;
	}
	for (int i = idx; i < C; i++)
	{
		if (!visited[i])
		{
			visited[i] = 1;
			num[idx] = i;
			bf(idx + 1);
			visited[i] = 0;
		}
	}
}

int main() {
	cin >> L >> C;
	for (int i = 0; i < C; i++)
		cin >> arr[i];
	sort(arr, arr + C);
	bf(0);
	return 0;
}