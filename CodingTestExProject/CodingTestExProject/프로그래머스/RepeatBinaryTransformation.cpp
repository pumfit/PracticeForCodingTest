/*
* 이진 변환 반복하기
* 월간 코드 챌린지 시즌1
https://programmers.co.kr/learn/courses/30/lessons/70129

문제에서 제시한 그대로 수행하면 되는 문제 

다른 풀이 보다보니 반복문으로 이진수 만드는 방식이 특이했다.
        for(int i=length; i>0; i=i/2){
            s.push_back(i%2+'0');
        }
2진수를 구하는 방법이 2를 나눈 나머지를 더하는 방식이다보니 위와 같이도 표현 가능하다는 것을 알았다.
0 + '0' 이 00이 아닌 0임을 
*/
#include <string>
#include <vector>

using namespace std;

string toBinary(int s)
{
    string r;
    while (s != 0) {
        r += (s % 2 == 0 ? "0" : "1");
        s /= 2;
    }
    return r;
}

vector<int> solution(string s) {
    vector<int> answer;
    int cnt = 0;
    int idx = 0;
    while (s != "1")
    {
        idx++;
        int len = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1')
                len++;
            else
                cnt++;
        }
        s = toBinary(len);
    }
    answer.push_back(idx);
    answer.push_back(cnt);
    return answer;
}