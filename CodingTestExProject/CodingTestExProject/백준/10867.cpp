/*
10867 중복 빼고 정렬하기

https://www.acmicpc.net/problem/10867

iteeator : https://learn.microsoft.com/ko-kr/cpp/standard-library/iterator?view=msvc-170
http://www.tcpschool.com/cpp/cpp_operator_cpp

:: - 범위 지정 연산자 , 다양한 범위에서 사용되는 식별자를 식별하고 명확하게 식별하는 데 사용한다.
C++에서 가장 우선순위가 높은 연산자
범위 지정 연산자를 변수의 이름 앞에 붙이면 해당 변수는 전역으로 사용하라는 의미로 쓰이게 된다.
또한, 클래스에 이 연산자를 사용하면 네임스페이스 멤버를 식별하거나, 클래스의 정적 멤버를 호출할 수 있다.

1. ::식별자
2. 클래스이름::식별자
3. 네임스페이스::식별자
4. 열거체::식별자
*/
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
	int N,n;
	set<int> s;
	cin>>N;
	for(int i = 0 ; i<N;i++)
	{
		cin>>n;
		s.insert(n);
	}
    // c++ set container 탐색 시에는 iteeator 를 통해 순회한다.
	set<int>::iterator iter;
	for(iter = s.begin();iter!=s.end();iter++)
		cout<<*iter<<" ";
	return 0;
}