/*
광물 캐기
https://school.programmers.co.kr/learn/courses/30/lessons/172927#

광물이 5개 단위로 나뉘는데 문제가 착하게 어렵지말라고 피로도 * 5 만큼 씩  다음 단계 피로도를 설정했다.
- 한 번 사용하기 시작한 곡괭이는 사용할 수 없을 때까지 사용합니다. (5개씩)
- 광물은 주어진 순서대로만 캘 수 있습니다. 광산에 있는 모든 광물을 캐거나, 더 사용할 곡괭이가 없을 때까지 광물을 캡니다. (곡괭이가 없는 경우 + 광물이 없는 경우 고려)

*/
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    
    int pickCount = 0;
    for(int idx = 0; idx<picks.size(); idx++)
        pickCount += picks[idx];
    
    // 1. 광물 피로도 별로 정렬
    vector<pair<int,int>> scores;
    
    int score = 0;
    for(int index = 0;index<minerals.size();index++)
    {
        if(index/5>=pickCount)
            break;
        
        if(index%5==0)
            score = 0;
        
        if(minerals[index]=="diamond")
        {
            score += 25;
        }else if(minerals[index]=="iron"){
            score += 5;
        }else{
            score += 1;
        }
        
        if(index%5==4 || index == minerals.size()-1)
        {
            int startIdx = scores.size() == 0 ? 0 : scores.size()*5;
            scores.push_back({score,startIdx});
        }
    }
    
    // 높은 피로도 부터 좋은 곡괭이를 쓰도록 정렬
    sort(scores.begin(),scores.end(),greater<>());
    
    int scoresIdx = 0;
    for(int picksIdx = 0;picksIdx<picks.size();picksIdx++)
    {
        while(picks[picksIdx]!=0)
        {
            // 이미 모든 광물을 캔 경우
            if(scoresIdx*5>=minerals.size())
                break;

            picks[picksIdx]--;

            for(int index = scores[scoresIdx].second; index< scores[scoresIdx].second+5;index++)
            {
                if(index>=minerals.size())
                    break;
                
                if(picksIdx == 0)
                {
                    answer += 1;
                }else if(picksIdx == 1)
                {
                    if(minerals[index]=="diamond")
                        answer += 5;
                    else
                        answer += 1;
                }else{
                    answer += scores[scoresIdx].first;
                    break;
                }
            }
            scoresIdx++;
        }
    }
    
    return answer;
}