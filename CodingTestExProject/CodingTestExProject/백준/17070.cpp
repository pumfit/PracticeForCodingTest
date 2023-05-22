/*
17070 파이프 옮기기 1

https://www.acmicpc.net/problem/17070

bfs 풀이, dp 로 다시 풀기
구조체 관련해서 다시 학습하기 구조체 선언 어떻게 하는지, 생성자와 차이점 확인

- 구조체와 클래스 차이
1. 접근 지정자가 생략되었을 때 기본적으로 설정되는 키워드가 다름 (class - private )
2. 구조체는 상속 불가
3. 구조체는 매개변수가 없는 생성자를 가지고 있음 

제일 중요한 점은 구조체는 값 타입 이고 클래스는 참조 타입이라는 점이다.
https://mentum.tistory.com/481


- 구조체
c++의 구조체 내에서 함수선언도 가능하다
*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Pipe
{
	int x;
	int y;
	int rot;

	Pipe(int x,int y,int rot)
	{
		this->x = x;
		this->y = y;
		this->rot = rot;
	}
};

int main() {
	int N;
	cin>>N;
	int arr[N][N] = {0,};int answer = 0;// y , x
	int dy[3] = { 0,1,1 };
	int dx[3] = { 1,1,0 };
	for(int i = 0;i<N; i++)
	{
		for(int j = 0;j<N;j++)
		{
			cin>>arr[i][j];
		}
	}
	arr[0][0] = 1; arr[0][1] = 0; // y,x
	
	queue<Pipe> q;
	Pipe p = Pipe(1,0,0);
	q.push(p);
	
	while(!q.empty())
	{
		Pipe cur = q.front();
		q.pop();

		if(cur.x == N-1 && cur.y == N-1 )
			answer++;
		
		for(int i = 0;i<3;i++)
		{
			if (cur.rot == 0 && i == 2) 
				continue;
            if (cur.rot == 2 && i == 0) 
            	continue;

            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];

            if (ny < 0 || nx < 0 || ny >= N || nx >= N) 
            	continue;
            if (arr[ny][nx] == 1) 
            	continue;
            if (i == 1 && (arr[ny - 1][nx] == 1 || arr[ny][nx - 1] == 1)) 
            	continue;

            q.push({nx,ny,i });
		}
	}

	cout<<answer;
	
	return 0;
}