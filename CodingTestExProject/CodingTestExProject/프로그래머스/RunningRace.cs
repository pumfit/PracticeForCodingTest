/*
달리기 경주
https://school.programmers.co.kr/learn/courses/30/lessons/178871

다시 풀어보기
*/
using System;
using System.Collections.Generic;

public class PlayerNode
{
    public string front;
    public string cur;
    public string back;
    
    public PlayerNode(string cur,string front,string back)
    {
        this.front = front;
        this.cur = cur;
        this.back = back;
    }
}

public class Solution {
    
    public Dictionary<string,int> playerIndexDictionary = new Dictionary<string,int>();
    
    public int FindPlayer(string target)
    {
        return playerIndexDictionary[target];
    }
    
    public string[] solution(string[] players, string[] callings) {
        string[] answer = new string[players.Length];
        List<PlayerNode> list = new List<PlayerNode>();
        
        for(int i = 0;i<players.Length;i++)
        {
            playerIndexDictionary[players[i]] = i;
            
            if(i-1>=0 && i+1<players.Length)
            {
                list.Add(new PlayerNode(players[i],players[i-1],players[i+1]));
            }else if(i-1<0)
            {
                list.Add(new PlayerNode(players[i],null,players[i+1]));
            }else{
                list.Add(new PlayerNode(players[i],players[i-1],null));
            }
        }
        
        for(int i = 0;i<callings.Length;i++)
        {
            int index = FindPlayer(callings[i]);
            if(index != 0)
            {
                list[index-1].back = list[index-1].cur;
                list[index].front = list[index].cur;
                list[index-1].cur = list[index].front;
                list[index].cur = list[index-1].back;

                playerIndexDictionary[list[index].cur] = index;
                playerIndexDictionary[list[index-1].cur] = index-1;
            }
            
        }
        
        for(int i = 0;i<list.Count; i++)
            answer[i] = list[i].cur;
        
        return answer;
    }
}