/*
롤케이크 커팅

https://school.programmers.co.kr/learn/courses/30/lessons/132265

맵 + 슬라이딩윈도우
*/
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    map<int,int> a;
    map<int,int> b;
    for(int i = 0;i<topping.size();i++)
        b[topping[i]]+=1;
    for(int i = 0;i<topping.size();i++)
    {
        a[topping[i]] +=1;
        b[topping[i]] -=1;
        if(b[topping[i]]==0)
            b.erase(topping[i]);
        if(a.size()==b.size())
            answer++;
    }
    return answer;
}