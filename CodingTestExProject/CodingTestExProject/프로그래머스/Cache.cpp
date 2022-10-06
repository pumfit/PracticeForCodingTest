/*
캐시

https://school.programmers.co.kr/learn/courses/30/lessons/17680

캐시 교체 알고리즘은 LRU(Least Recently Used)를 사용한다.
벡터를 사용해서 저장하는 방식을 사용하고 캐시 힛이 발생하지 않으면 캐시로 넣고
캐시힛이 발생한 경우에는 해당 캐싱 원소의 위치를 맨 뒤로 교체하는 방식으로 진행하였다.

문제 풀면서 LRU 알고리즘 자체에 대한 정리가 필요한 것 같다고 느꼈다.

+) 아래 두가지 예외처리에 대해 처리가 늦었었다.

- 캐시 사이즈가 0 인 경우에 erase 예외처리

- ==로 사이즈 비교히고 있어서 캐시 최대 사이즈가 0인 경우에 예외처리 (7,17 번 테케)
*/
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<string> cach;

bool isCaching(int cacheSize, string str)
{
    bool cached = false;
    if (cacheSize == 0)
        return cached;
    auto iter = find(cach.begin(), cach.end(), str);
    if (iter == cach.end())//step 1. 캐싱되어있지 않다면
    {
        if (cacheSize == cach.size() && cach.size() > 0)
            cach.erase(cach.begin());//step 2. 캐시가 꽉 차있다면 맨 앞 제거

    }
    else //step3.캐싱되어 있다면
    {
        cached = true;
        //step4.목록에서 제거하고 맨뒤로 옮긴다.
        cach.erase(iter);
    }
    cach.push_back(str);
    return cached;
}

string to_lower(string str)
{
    for (int i = 0; i < str.size(); i++)
        str[i] = tolower(str[i]);
    return str;
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;

    for (int i = 0; i < cities.size(); i++)
    {
        //대소문자 구분 없으므로 
        string str = to_lower(cities[i]);
        if (isCaching(cacheSize, str))
            answer++;
        else
            answer += 5;

    }
    return answer;
}