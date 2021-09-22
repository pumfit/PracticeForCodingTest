﻿/*
10709 기상캐스터

JOI시는 남북방향이 H 킬로미터, 동서방향이 W 킬로미터인 직사각형 모양이다. 
JOI시는 가로와 세로의 길이가 1킬로미터인 H × W 개의 작은 구역들로 나뉘어 있다. 북쪽으로부터 i 번째, 서쪽으로부터 j 번째에 있는 구역을 (i, j) 로 표시한다.

각 구역의 하늘에는 구름이 있을 수도, 없을 수도 있다. 
모든 구름은 1분이 지날 때마다 1킬로미터씩 동쪽으로 이동한다. 오늘은 날씨가 정말 좋기 때문에 JOI시의 외부에서 구름이 이동해 오는 경우는 없다.

지금 각 구역의 하늘에 구름이 있는지 없는지를 알고 있다. 기
상청에서 일하고 있는 여러분은 각 구역에 대해서 지금부터 몇 분뒤 처음으로 하늘에 구름이 오는지를 예측하는 일을 맡았다.

각 구역에 대해서 지금부터 몇 분뒤 처음으로 하늘에 구름이 오는지를 구하여라.

출력은 H 행으로, 각 행에는 공백으로 구분된 W 개의 정수를 출력한다. 
출력의 i 번째 행 j 번째 정수 (1 ≦ i ≦ H, 1 ≦ j ≦ W) 는, 지금부터 몇 분후에 처음으로 구역 (i, j) 에 구름이 뜨는지를 표시한다. 단, 처음부터 구역 (i, j) 에 구름이 떠 있었던 경우에는 0을, 
몇 분이 지나도 구름이 뜨지 않을 경우에는 -1을 출력한다.

+) 올초에 봤던 삼성코테 첫문제 시작부분과 비슷한 시뮬레이션문제
그당시 코테 준비 자체를 안하고 이렇게 하면서 비슷한 문제를 보니 역시 문제풀이를 많이하는게 가장 중요한 것 같다.
시뮬레이션 문제들도 여러가지 풀어보고 다른 답들을 보면서 어떻게 풀어나가야하는지 익히면 좋을 것 같다.
*/
#include<iostream>
using namespace std;

char curMap[101][101];
int map[101][101];

int main()
{
	int H, W;
	cin >> H >> W;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			char x;
			cin >> x;
			curMap[i][j] = x;
		}
	}
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			map[i][j] = -1;
		}
	}
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (curMap[i][j] == 'c')
			{
				map[i][j] = 0;
				for (int k = 1; j+k < W; k++)
				{
					if (map[i][j + k] == 0)
					{
						break;
					}
					else
					{
						map[i][j + k] = map[i][j+k-1] + 1;
					}

				}

			}
		}
	}
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			cout << map[i][j]<<" ";
		}
		cout << endl;
	}
}