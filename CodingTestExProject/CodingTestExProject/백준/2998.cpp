/*
2998 8진수

창영이는 여러 가지 진법을 공부하고 있다. 창영이는 어제 2진법을 배웠고, 오늘은 8진법을 배웠다. 이제, 2진법 수를 8진법 수로 변환하려고 한다.

창영이가 사용한 방법은 다음과 같다.

2진수의 길이가 3으로 나누어 떨어질 때 까지 수의 앞에 0을 붙인다.
그 다음, 3자리씩 그룹을 나눈다.
아래의 표를 참고해 8진수로 바꾼다.
2진수가 주어졌을 때, 창영이가 사용한 방법을 이용해 8진수로 바꾸는 프로그램을 작성하시오.

구현 문제라 문제 그대로 풀이하려고 노력했다.
string 과 map 모두 쓸 수 있었던 문제로
stritng substr은 시작위치와 반환할 개수를 매개변수로 넣어야하고
map접근 방식은 iterator가 반환되므로 -> 포인터안에 접근하기위한 화살표연산자로 second값에 접근해주면 된다.
*/
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {

	map<string, string> m = { {"000","0"},{"001","1"},{"010","2"},{"011","3"},
		{"100","4"},{"101","5"},{"110","6"},{"111","7"}
	};
	string s;
	string answer = "";
	cin >> s;
	for (int i = 0; i < s.size() % 3; i++)
	{
		s = "0" + s;
	}
	for (int i = 0; i < s.size(); i += 3)
	{
		answer += m.find(s.substr(i, 3))->second;
	}
	cout << answer;
	return 0;
}