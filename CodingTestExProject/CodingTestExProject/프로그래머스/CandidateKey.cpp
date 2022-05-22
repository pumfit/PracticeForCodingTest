/*
후보키 

이전에 풀어보려다가 벽느끼고 요즘 순위검색 문제풀면서 이것도 조합 문제구나 싶어서 풀이 찾아본 문제
아래 방식은 비트마스크를 통해 모든 조합의 경우의 수를 구하고 해당 조합에 맞는 경우에만 검색해 이를 키로 만들어서 최소성을 판단한다.
유일성의 경우도 비트마스킹을 사용해 부분 집합을 가지는 지 판단한다.
(answer[i] & bit) == answer[i]이부분이 부분 집합인지 확인하는 부분 인데
비트 a,b 가 있다면 a & b 는 a와 b의 교집합을 의미한다. 즉 a & b == a은 b가 a의 교집합인지 확인하는 과정이 된다.
*/

#include <string>
#include <map>
#include <vector>

using namespace std;

vector<int> answer;

//유일성 판단 이때 anwer에 들어오는 조합의 원소의 개수는 1부터 들어오므로 이미 유일성 판단에 통과된 경우 부분집합이 된다.
bool checkMin(int bit)
{
    for (int i = 0; i < answer.size(); i++)
    {
        if ((answer[i] & bit) == answer[i])//최소성을 만족하지 못함
            return false;
    }
    return true;
}

int solution(vector<vector<string>> relation) {
    //비트마스킹을 통해 모든 조합을 구한다.
    for (int i = 0; i < 1 << relation[0].size(); i++)
    {
        map<string, int> m; // 조합 
        for (int j = 0; j < relation.size(); j++)
        {
            string s;
            for (int k = 0; k < relation[0].size(); k++)
            {
                // 조합 i에 포함되는 행이라면 추가한다. 
                if (i & (1 << k))
                    s += relation[j][k];
            }
            m[s] += 1;
        }
        //m.size() == relation.size() 유일성 판단
        if (m.size() == relation.size() && checkMin(i))
        {
            answer.push_back(i);
        }
    }
    return answer.size();
}