/*
옹알이(2)
https://school.programmers.co.kr/learn/courses/30/lessons/133499

비트마스킹으로 다시 풀기
*/
#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    string words[4] = {"aya","ye","woo","ma"};
    
    for(int i = 0;i<babbling.size();i++)
    {
        int sIdx = 0;
        int prev = -1;
        while(true)
        {
            bool isChecked = false;
            for(int j = 0;j<4;j++)
            {
                if(babbling[i].substr(sIdx,words[j].size())==words[j])
                {
                    sIdx += words[j].size();
                    if(prev == j)
                        break;
                    prev = j;
                    isChecked = true;
                    break;
                }
            }
            if(!isChecked)
                break;
            if(sIdx==babbling[i].size())
                answer++;
        }
        
    }
    return answer;
}