/*
19583 싸이버개강총회

https://www.acmicpc.net/problem/19583

맵을 활용해서 문제풀이를 진행했다.
처음에는 셋 두개로 확인하면 되겠다 생각헀는데 두셋에 대해 비교해야하니 맵으로 하면 어떨까 생각하게되었다.
시작시간 전에 채팅이 있다면 맵에 1로 지정한다. 중복이 있을 수 있으므로 1로 지정하고 다음에 끝나고 인정기간 내에 채팅을 치면 값을 증가 시켜 2이상이면 출석으로 판단했다.

해당 풀이 이후 다른 풀이를 보니, 출석을 해야 이후에 추가가 가능하니 두번째 조건문에 m[nickname] 를 추가해서 판단하는 풀이도 보았다.

c++ 에서 EoF 확인하는 방법
	while(cin>>time>>nickname)
	{
        //...
	}
원래 스트림 연산을 한 뒤에는 스트림 객체를 반환하게되는데 이때 조건문안에서는 EOF에 false 를 반환한다.
+)
시간 범위 계산할 때 string 정렬 순서 대로 확인
*/
#include <iostream>
#include <map>
using namespace std;

int main() {
	string startTime,endTime,streamingEndTime;
	cin>>startTime>>endTime>>streamingEndTime;
    map<string,int> m;
	string time,nickname;
	int answer = 0;
	while(cin>>time>>nickname)
	{
		if(time<=startTime)
			m[nickname] = 1;
		
		if(endTime<=time && time<=streamingEndTime )
		{
			if(m[nickname]>0)
				m[nickname]++;
		}
		
	}
	for (const auto& kvPair : m) {
    	if(kvPair.second>=2)
    		answer++;
	}
	cout<<answer;
	return 0;
}