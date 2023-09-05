/*
17478 재귀함수가 뭔가요?

https://www.acmicpc.net/problem/17478

이 문제 정답률이 낮은건 큰 따옴표 빼먹어서 아닐까 싶은 문제
근데 정작 나는 처음에 "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다." 출력안해서 한번 틀렸다.
재귀는 이해가 너무 어려운 것 같다,
반복되는 부분을 파악하고 재귀호출을 진행했다. 라인에 대한 출력은 어떻게 재귀적으로 처리가 가능한지 생각해봐야겠다.

*/
#include <iostream>
using namespace std;

int N = 0;

void PrintLine(int lineCount)
{
	for(int i=0;i<lineCount;i++)
		cout<<"____";
}

void Print(int depth)
{
	PrintLine(N-depth);
	cout<<"\"재귀함수가 뭔가요?\""<<'\n';
	if(depth==0)
	{
		PrintLine(N-depth);
		cout<<"\"재귀함수는 자기 자신을 호출하는 함수라네\""<<'\n';
		PrintLine(N-depth);
		cout<<"라고 답변하였지."<<'\n';
		return;
	}
	PrintLine(N-depth);
	cout<<"\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어."<<'\n';
	PrintLine(N-depth);
	cout<<"마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지."<<'\n';
	PrintLine(N-depth);
	cout<<"그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\""<<'\n';
	Print(depth-1);
	PrintLine(N-depth);
	cout<<"라고 답변하였지."<<'\n';
	
}

int main() {
	cin>>N;
	cout<<"어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다."<<'\n';
	Print(N);
	return 0;
}