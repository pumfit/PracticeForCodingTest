/*
둘만의 암호

https://school.programmers.co.kr/learn/courses/30/lessons/155652

num 이 index 20에 skip 이 많으면 두바퀴 넘어가는 경우가 생겨 이부분도 고려해줘야하는 문제이다.
27번 라인 정리하기
*/
#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

string solution(string s, string skip, int count) {
    string answer = "";
    map<char,int> m;
    for(int i = 0;i<skip.size();i++)
        m[skip[i]] = 1;
    
    for(int i = 0;i<s.size(); i++)
    {
        int num = 0, idx = 1;
        for(int j = 0;j<count;j++)
        {
            num = ((s[i]+idx)-'a')/26>0?'a'+((s[i]+idx)-'a')%26:s[i]+idx;
            if(m[num]==1)
                j--;
            idx++;
        }
        answer.push_back((char)(num));
    }
    return answer;
}