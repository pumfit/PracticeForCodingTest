/*
개인정보 수집 유효기간
https://school.programmers.co.kr/learn/courses/30/lessons/150370

첫 번째 문제인데 테케 하나 통과 안되어서 멘탈 나가게 했던 문제
12월에 대한 예외처리가 부족해서 였고 34,45 라인으로 12월 예외를 처리하면 통과할 수 있다.
+) 기간 관련 문제 DataTime 도 잘 사용할 수 있게 계속 풀어보자
*/
#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map<char,int> m;
    for(int i = 0; i < terms.size();i++)
    {
        m[terms[i][0]] = stoi(terms[i].substr(2));
    }
    int todayYear = stoi(today.substr(0,4));
    int todayMonth = stoi(today.substr(5,2));
    int todayDay = stoi(today.substr(8,2));
    for(int i = 0; i<privacies.size(); i++)
    {
        string str = privacies[i];
        int term = m[str[str.size()-1]];

        int year = stoi(str.substr(0,4));
        int month = stoi(str.substr(5,2));
        int day = stoi(str.substr(8,2));

        year += (month + term)%12==0?((month + term)/12)-1:(month + term)/12;
        month = (month + term)%12==0?12:(month + term)%12;
        

        if(year<todayYear)
        {
            answer.push_back(i+1);
            continue;
        }else if(year==todayYear){
            if(month<todayMonth)
            {
                answer.push_back(i+1);
                continue;
            }else if(month == todayMonth){
                if(day<=todayDay)
                {
                    answer.push_back(i+1);
                    continue;
                }
            }
        }
    }
    
    return answer;
}