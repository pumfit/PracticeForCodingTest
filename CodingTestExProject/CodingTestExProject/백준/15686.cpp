/*
15686 치킨 배달
https://www.acmicpc.net/problem/15686

next_permutation 쓰기전에 오름차순으로 정렬이 되어있어야하므로 0부터 넣어줘야 정상적으로 조합을 뽑아낼 수 있다.

조합을 통해 어떤 가게가 최소 거리의 합을 가졌는지 확인하는 문제
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_INT 2e9;
using namespace std;

int N,M,n;
vector<pair<int,int>> house,chicken;
vector<int> lived;
int minDistance = MAX_INT;

void CountDistance()
{
	int cityDistance = 0;
    for (int i=0; i<house.size(); i++) {
        int minHouseDistance = MAX_INT;
        for (int j=0; j<chicken.size(); j++) {
            if (lived[j] == 1) {
                int houseDistance = abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second);
                if (houseDistance < minHouseDistance) {
                    minHouseDistance = houseDistance;
                }
            }
        }
        cityDistance += minHouseDistance;
    }
    if (cityDistance < minDistance) {
        minDistance = cityDistance;
    }
}
	
void SelectChicken()
{
	// 선택할 가게 수만 큼(N) 1 추가 해서 조합 생성하기
	for(int i =0;i< chicken.size() - N;i++)
		lived.push_back(0);	
	for(int i =0;i<N;i++)
		lived.push_back(1);
	do{
		CountDistance();
	}while(next_permutation(lived.begin(),lived.end()));
}

int main() {
	cin>>M>>N;
	for(int y = 0;y<M;y++)
	{
		for(int x = 0;x<M;x++)
		{
			cin>>n;
			if(n==1)
			{
				house.push_back({x,y});
			}else if(n==2)
			{
				chicken.push_back({x,y});
			}
		}
	}
	SelectChicken();
	cout<<minDistance;
	
	return 0;
}