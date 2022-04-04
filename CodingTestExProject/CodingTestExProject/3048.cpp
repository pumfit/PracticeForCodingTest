/*
3048 개미

insert 어떻게 썼더라..? 했던 문제 insert(idx,char) 형식으로 썼다가 찾아보고 고쳤다.
직접 써가면서 풀어보았는데 B를 고정적으로 두고 A만 움직이는 방식으로 인덱스를 적어가며 풀었다.
A의 첫 글자는 T만큼 움직인다. 그 이후로는 1씩 적어지면서 움직이고 해당값이 인덱스 범위를 넘어가지 않도록 처리해준다.
+
생각보다 짧게 풀었다했는데 숏코딩 10위권 내라서 신기했던 문제
짧은게 모두 좋은 풀이인 것은 아니지만 생각했던 다른풀이보다 빠르게 풀었을 것은 확실한 문제
*/
#include <iostream>
using namespace std;

int main() {
	int A, B, T, idx;
	string a, b;
	cin >> A >> B >> a >> b >> T;
	string answer = b;
	for (int i = 0; i < A; i++)
	{
		if (T - i < 0)
			idx = 0;
		else if (T - i > B)
			idx = B;
		else
			idx = T - i;
		answer.insert(idx, 1, a[i]);
	}
	cout << answer;
	return 0;
}