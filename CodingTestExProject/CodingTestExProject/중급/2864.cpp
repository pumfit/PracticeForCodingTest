/*
2864 5와 6의 차이

내 풀이 :
해당 문제는 최소값과 최대값만 찾으면 되므로
최소값의 경우 6만 찾아서 5로 바꿔주면 되고 최대값의 경우 5만 찾아서 6으로 바꿔주면 된다.

빠르게 풀기위해서 string과 stoi()함수를 사용했다.
*/

#include<iostream>
#include<string>
using namespace std;

int min(string n)
{
	for (int i = 0; i < n.length(); i++)
	{
		if (n[i] == '6')
			n[i] = '5';
	}
	return 	stoi(n);
}

int max(string n)
{
	for (int i = 0; i < n.length(); i++)
	{
		if (n[i] == '5')
			n[i] = '6';
	}
	return 	stoi(n);
}

int main()
{
	string A,B;
	cin >> A >> B;
	cout << min(A) + min(B) << " " << max(A) + max(B)<<endl;
}