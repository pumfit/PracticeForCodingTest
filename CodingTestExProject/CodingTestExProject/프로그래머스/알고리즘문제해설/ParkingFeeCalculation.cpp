/*
주차 요금 계산

https://school.programmers.co.kr/learn/courses/30/lessons/92341#

map auto 쓸때 키값은 first,값은 second로 쓸 수 있다는 점을 잊고 있어서 이번 문제풀면서 다시 써보았다.
카카오 코테 1번 문제들이 대부분 이런 문자열 문제인데 쉬운데 은근 조건 빼먹고 테케 하나 정도 틀려서 애먹는 경우가 있는 것 같다.
주어진 문제대로 푸는게 가장 좋은 방식인 것 같다.

+)
풀면서 생각한 풀이 중 하나가 차번호가 0부터 9999까지 진행되니까 배열로 만들고 값이 있는 경우만 answer에 넣을까 하다가
비효율적인 것 같아서 그냥 맵으로 풀긴했는데 배열로 푼 풀이들도 꽤 많은 것 같았다.
*/
#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string,int> m;
    map<string,int> times;
    for(int i = 0;i<records.size();i++)
    {
        int hour = stoi(records[i].substr(0,2));
        int minute = stoi(records[i].substr(3,2));
        string number = records[i].substr(6,4);
        string inOut = records[i].substr(11,records[i].size()-11);
        if(inOut=="IN")
        {
            m[number] = 60*hour+minute;
        }else
        {
            int time = 60*hour+minute - m[number];
            times[number] += time;
            m[number] = -1;//예외처리를 위해 Out인 경우 -1로 변경
        }
    }
    for(auto i:m)//입차만 있는 경우 예외처리
    {
        if(i.second!=-1)// in만 존재하는 경우 23:59에서 따로 계산
            times[i.first] += 23*60+59 - i.second;
    }
    for(auto i:times)// 모든 시간 계산
    {
        int pay = i.second-fees[0]>0?((i.second-fees[0])/fees[2])*fees[3]+((i.second-fees[0])%fees[2]==0?0:fees[3]):0;
        answer.push_back(fees[1]+pay);
    }
    return answer;
}