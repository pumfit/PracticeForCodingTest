/*
2018 KAKAO BLIND RECRUITMENT
[3차] 압축
https://programmers.co.kr/learn/courses/30/lessons/17684

문제에서 요구되는 대로 풀어가면 되는 문제로 키를 색인 단어로 지정하고 색인 번호를 값으로 지정해서
해당되는 키가 있으면 값을 답에 추가하는 방식으로 진행했다.

현재 인덱스부터 마지막 인덱스까지의 s 값을 가지고 키를 찾고 키가 존재하지 않는 경우에는 끝 인덱스를 줄여가는 방식을 사용했다.
이 경우에 너무 시간이 많이 걸리지 않을까 했는데 시간내 통과가 되었다.

i값보다 키값이 클 수는 없으므로 substr에서 i+1 크기부터 시작하도록 변경하였다.
뭔가 위 과정에서 단축할 수 있는 방법이 더 있을 것 같아서 해당 알고리즘에 대한 정리가 필요할 것 같다.

" LZW(Lempel–Ziv–Welch) 압축을 구현하기로 했다. LZW 압축은 1983년 발표된 알고리즘으로, 이미지 파일 포맷인 GIF 등 다양한 응용에서 사용되었다."
LZW알고리즘 정리 : https://www.notion.so/LZW-ebde4f23d5084bf790cb3f87815d01eb
*/
#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> m;
    int size = msg.size();
    for (int i = 0; i < 27; i++)
    {
        string s = "";
        s += (i + 'A');
        m.insert({ s,i + 1 });
    }
    int idx = 27;
    for (int i = 0; i < size; i++)
    {
        string s = msg.substr(i, i + 1);
        int length = 0;
        while (s.size() > 0)
        {
            if (m.find(s) != m.end())//존재하는 경우
            {
                answer.push_back(m[s]);//색인 번호 출력
                i += s.size() - 1;
                if (i + 1 < size)
                    s += msg[i + 1];//사전등록용
                m.insert({ s,idx });
                idx++;
                break;
            }//존재하지 않는 경우
            length++;
            s = msg.substr(i, i + 1 - length);
        }

    }
    return answer;
}