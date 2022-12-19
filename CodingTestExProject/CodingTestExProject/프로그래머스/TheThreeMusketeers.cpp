/*
https://school.programmers.co.kr/learn/courses/30/lessons/131705/solution_groups?language=cpp

조합 문제 + bitMask 로 풀기

비트마스킹 bitset 정리하기
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> number) {
    
    int answer = 0;
    vector<int> v;

    for(int i = 0;i<3;i++)
        v.push_back(1);
    for(int i = 0;i<number.size()-3;i++)
        v.push_back(0);

    sort(number.begin(),number.end());
    sort(v.begin(),v.end());

    do
    {
        int sum = 0;
        for(int i = 0;i<number.size();i++ )
        {
            if(v[i]==1)
                sum += number[i];
        }
        if(sum==0)
            answer++;
    }while(next_permutation(v.begin(),v.end()));

    return answer;
}
//bitmask
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

int solution(vector<int> number) {
    int answer = 0;
    sort(number.begin(),number.end());
    bitset<13> bit;
    for(int i = 0;i < 1<<number.size();i++)
    {
        bit = i;
        if(bit.count() == 3)
        {
            int sum = 0;
            for(int j = 0;j<number.size();j++)
            {
                if((i & (1<<j)) > 0)
                {
                    sum += number[j];
                }
            }
            if(sum==0)
                answer++;
        }
    }
    return answer;
}