/*
9655 돌게임

https://www.acmicpc.net/problem/9655
*/
#include <iostream>
using namespace std;

int main() {
	int N;
	cin>>N;
	string answer = (N%2==0)?"CY":"SK";
	cout<<answer;
	return 0;
}