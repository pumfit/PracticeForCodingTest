/*
* 문자열 게임 2
* https://www.acmicpc.net/problem/20437
* 
* 두번째 테케를 보면서 슬라이딩 윈도우 문제구나 감을 잡았다.
* 제출 후에 세그먼트 에러가 계속났는데 인덱스 때문에 발생하는 줄 알고 1 aaa 1 같이 테케 몇개 더 진행해보았지만
인덱스를 넘거나 음수로 참조하는 경우는 없었다. 

세그먼트 오류가 어떨때 발생하는 지에 대해 더 검색해봤는데
값을 초기화하지 않아 쓰레기 값이 들어가는 경우에도 발생할 수 있다는 것을 알게되었다.
생각해보니 테케 여러개를 while문에서 돌리는데 ch 배열을 초기화하지 않고 있었다.  제시된 테케가 같은 알파벳을 답으로 하지않아서 생각을 못한 부분이었다.
memset(ch, 0, sizeof(ch)); 추가하니 세그먼트 오류를 해결할 수 있었다.

+) Segfault 받을 때 주의할 점
1. 인덱스 확인 조건문의 경우  (ch[index][1] + 1 < s.size() && s[i] != s[ch[index][1]]) 연산자 우선순위를 따르므로 배열의 범위 판단을 먼저 앞에 두기
2. 인덱스로 들어가는 값의 경우 쓰레기값 안들어가도록 주의
(아니더라도 초기화는 제대로 확인하기)
*/
#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int T;
	cin >> T;
	string s;
	int k;
	int minCnt = 2e9, maxCnt = 0;
	int ch[26][2] = { 0, };//0 - 등장회수 ,1 - 첫 인덱스
	while (T--)
	{
		cin >> s;
		cin >> k;
		for (int i = 0; i < s.size(); i++)
		{
			int index = s[i] - 'a';
			ch[index][0]++;
			if (ch[index][0] == 1)
			{
				ch[index][1] = i;
			}
			if (ch[index][0] == k)//어떤 문자를 정확히 K개를 포함
			{
				//cout<<"첫 인덱스 "<<ch[index][1]<<" | "<<i<<" "<<ch[index][1]+1<<endl;
				minCnt = min(i - ch[index][1] + 1, minCnt);
				maxCnt = max(i - ch[index][1] + 1, maxCnt);
				if (ch[index][1] + 1 < s.size())
					ch[index][1]++;
				while (ch[index][1] + 1 < s.size() && s[i] != s[ch[index][1]])//첫 인덱스 위치를 다음 위치로 바꿈
				{
					ch[index][1]++;
				}
				ch[index][0]--;
			}
		}

		if (minCnt == 2e9 && maxCnt == 0)
			cout << -1 << '\n';
		else
			cout << minCnt << " " << maxCnt << '\n';
		minCnt = 2e9; maxCnt = 0;
		memset(ch, 0, sizeof(ch));
	}
	return 0;
}