/*
*이상한 문자 만들기 
https://school.programmers.co.kr/learn/courses/30/lessons/12930?language=cpp

이전에 풀이 기록 남아있는데 못푼 문제라서 sstream로 다시 풀어봤는데 또 틀렸다.
테케에는 없지만 공백이연속으로 들어오는 경우가 있어서 아래와 같이 라이브러리 사용하는 경우에는 4,5,8,9,11 통과를 못하는 것 같았다.
인덱스 두개로 푸는 방식으로 변경하고 통과했다.
*/
//테케 4,5,8,9,11 실패풀이
#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string s) {
        string answer = "";
        istringstream ss(s);
        string str;
        vector<string> v;
        while(getline(ss,str,' '))
        {
            for(int i = 0;i<str.size();i++)
                str[i] = i%2==0? toupper(str[i]) : tolower(str[i]);
            v.push_back(str);
        }
        for(int i = 0;i<v.size();i++)
            answer += i==v.size()-1? v[i]:v[i]+" ";
        return answer;
}

#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int strIdx = 0; int idx = 0;
    while (strIdx < s.size())
    {
        if (s[strIdx] == ' ')
        {
            idx = 0;
        }
        else
        {
            s[strIdx] = idx % 2 == 0 ? toupper(s[strIdx]) : tolower(s[strIdx]);
            idx++;
        }
        strIdx++;
    }
    return s;
}