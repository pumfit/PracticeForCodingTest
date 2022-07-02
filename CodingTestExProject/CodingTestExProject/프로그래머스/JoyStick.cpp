
/*
* 조이스틱
* https://programmers.co.kr/learn/courses/30/lessons/42860#

탐욕법(Greedy)으로 분류가 되어있었는데 찾아보니 이후에 예외 테케늘어나면서 그리디 문제가 더는 아닌 것 같았다.

진짜 파란만장했던 문제.. 테케 여러개 추가하고 거의 2시간 넘게 잡아먹다가 모르겠어서 풀이 봤는데도 ??상태이긴해서
나중에 다시한번 보는게 좋을 것 같다.

해당 문제는 크게 조이스틱의 상하 조작과 좌우 조작으로 나뉜다. 상하 조작은 쉽게 계산이 가능한데
좌우조작의 경우 최소가 되는 예외 케이스들이 다수 존재한다.

처음에는 for문 내에서 상하조작만 해두고 가장 긴 A 배열을 찾아서 해당 값만 빼주고 해당 배열에 0번 인덱스가 있다면 예외처리하는 방향으로 진행했는데
이와 같은 풀이로 진행하면 예외처리할 상황이 끝도 없이 발생했다.

이후 그리디라는 문제 분류를 보고 다른 글자로 가는 최소 회수를 구하는 방식으로 2.1. 왼쪽 이동시 회수 2.2. 오른쪽 이동시 회수 를 구한후 최소값을 더해갔는데
이 방식도 81.5점 밖에 나오지 않았고 해당 경우 예외가 되는 상황이 같은 회수더라도 어느 방향을 설정하느냐에 따라 전체 최소회수가 달라진 다는 점이었다. (여기서 그리디 탈락)

+)
좌우 조작관련 풀이 참조
https://velog.io/@jeeseob5761/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%EC%A1%B0%EC%9D%B4%EC%8A%A4%ED%8B%B1

*/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(string name) {
    int answer = 0;
    int length = name.length();
    int index;
    int move = length - 1;
    for (int i = 0; i < name.size(); i++)
    {
        //1. 상하 조작
        int idx = name[i] - 'A';
        int curIdx = idx > 26 - idx ? 26 - idx : idx;
        answer += curIdx;

        //2. 좌우 조작
        index = i + 1;

        // 현재 i기준 오른쪽의 A가 연속되는 구간의 끝 인덱스를 계산한다.
        while (index < length && name[index] == 'A') {
            index++;
        }

        move = min(move, i * 2 + length - index);//해당 인덱스까지 오른쪽으로 가는 것과 왼쪽으로 가는 것 중 이동수가 적은 것을 선택
        //예외, 처름부터 왼쪽으로 출발하는 경우
        move = min(move, (length - index) * 2 + i);
    }
    answer += move;
    return answer;
}
/**
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(string name) {
    int answer = 0;
    string pass = "";
    for(int i = 0;i<name.size();i++)
        pass+="A";
    int i = 0;
    while(name!=pass)
    {
        //1. 상하 조작
        int idx = name[i] - 'A';
        int curIdx = idx > 26 - idx ? 26 - idx: idx;
        answer += curIdx;
        name[i] = 'A';
        //2. 좌우 조작
        if(name==pass)
            break;
        //rIdx가 오른쪽으로 A가 아닌 수가 나올때 까지 이동
        int rIdx = i; int rCnt = 0;
        while(name[rIdx]=='A')
        {
            rCnt++;
            rIdx = (rIdx+1)%name.size();
        }
        //lIdx가 왼쪽으로 A가 아닌 수가 나올때 까지 이동
        int lIdx = i; int lCnt = 0;
        while(name[lIdx]=='A')
        {
            lCnt++;
            lIdx = lIdx-1<0?name.size()-1:lIdx-1;
        }
        if(lCnt>rCnt)
        {
            answer += rCnt;
            i = rIdx;
        }else
        {
            answer += lCnt;
            i = lIdx;
        }
    }
    return answer;
}
*/