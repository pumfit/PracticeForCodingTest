/*
스킬 트리
https://school.programmers.co.kr/learn/courses/30/lessons/49993#fnref1


스킬이 찍히는 순서를 인덱스로 비교하며 순서가 올바른지 반환해주는 방식으로 풀이를 진행했다.,
*/
#include <string>
#include <vector>

using namespace std;

bool GetIsPossible(string& skill,string& tree)
{
    int i = -1;
    for(int j = 0;j<tree.size();j++)
    {
        for(int k = 0;k<skill.size(); k++)
        {
            if(skill[k]==tree[j])
            {
                if(i+1==k)
                    i = k;
                else
                    return false;
            }
                    
        }
    }

    return true;
}

int solution(string skill, vector<string> skill_trees) {
    
    int answer = 0;
    for(int i =0;i<skill_trees.size();i++)
    {
        if(GetIsPossible(skill,skill_trees[i]))
            answer++;
    }
    return answer;
}