/*
1063 킹
https://www.acmicpc.net/submit/1063/67473876

커맨드 이름 하나 스펠링 틀려서 10분 정도 버린 문제...
이런 경우에 찾기 정말 어려운 것 같다.
맵이다보니 인덱스가 0으로 반환되어서 진행이 안되는 것도 아니라 찾는데 오래걸렸던 것 같다.
*/
#include <iostream>
#include <map>
using namespace std;
int m[8][8] = {0,};
map<string,int> command = {{"R",0},{"L",1},{"B",2},{"T",3},{"RT",4},{"LT",5},
	{"RB",6},{"LB",7}};
int dx[8] = {1,-1,0,0,1,-1,1,-1};
int dy[8] = {0,0,-1,1,1,1,-1,-1};
int main() {
	string K,S,D;
	int N;
	cin>>K>>S>>N;
	int kx = K[0] - 'A',ky = K[1] - '1';
	m[kx][ky] = 1;
	int sx = S[0] - 'A',sy = S[1] - '1';
	m[sx][sy] = 2;
	while(N--)
	{
		cin>>D;
		int dirIdx = command[D];
		int nkx = kx + dx[dirIdx] ,nky = ky + dy[dirIdx];
	
		if(nkx<0||nky<0||nkx>=8||nky>=8)
			continue;
		
		if(m[nkx][nky]==2)
		{
			int nsx = sx + dx[dirIdx] ,nsy = sy + dy[dirIdx];
		
			if(nsx<0||nsy<0||nsx>=8||nsy>=8)
				continue;
				
			m[sx][sy] = 0;
			m[nsx][nsy] = 2;
			sx = nsx; sy = nsy;
		}
		
		m[kx][ky] = 0;
		m[nkx][nky] = 1;
		kx = nkx; ky = nky;
	}
	cout<<(char)('A'+kx)<<ky+1<<'\n'<<(char)('A'+sx)<<sy+1;
	return 0;
}