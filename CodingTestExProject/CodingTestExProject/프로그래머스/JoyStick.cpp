
/*
* ���̽�ƽ
* https://programmers.co.kr/learn/courses/30/lessons/42860#

Ž���(Greedy)���� �з��� �Ǿ��־��µ� ã�ƺ��� ���Ŀ� ���� ���ɴþ�鼭 �׸��� ������ ���� �ƴ� �� ���Ҵ�.

��¥ �Ķ������ߴ� ����.. ���� ������ �߰��ϰ� ���� 2�ð� �Ѱ� ��ƸԴٰ� �𸣰ھ Ǯ�� �ôµ��� ??�����̱��ؼ�
���߿� �ٽ��ѹ� ���°� ���� �� ����.

�ش� ������ ũ�� ���̽�ƽ�� ���� ���۰� �¿� �������� ������. ���� ������ ���� ����� �����ѵ�
�¿������� ��� �ּҰ� �Ǵ� ���� ���̽����� �ټ� �����Ѵ�.

ó������ for�� ������ �������۸� �صΰ� ���� �� A �迭�� ã�Ƽ� �ش� ���� ���ְ� �ش� �迭�� 0�� �ε����� �ִٸ� ����ó���ϴ� �������� �����ߴµ�
�̿� ���� Ǯ�̷� �����ϸ� ����ó���� ��Ȳ�� ���� ���� �߻��ߴ�.

���� �׸����� ���� �з��� ���� �ٸ� ���ڷ� ���� �ּ� ȸ���� ���ϴ� ������� 2.1. ���� �̵��� ȸ�� 2.2. ������ �̵��� ȸ�� �� ������ �ּҰ��� ���ذ��µ�
�� ��ĵ� 81.5�� �ۿ� ������ �ʾҰ� �ش� ��� ���ܰ� �Ǵ� ��Ȳ�� ���� ȸ������ ��� ������ �����ϴ��Ŀ� ���� ��ü �ּ�ȸ���� �޶��� �ٴ� ���̾���. (���⼭ �׸��� Ż��)

+)
�¿� ���۰��� Ǯ�� ����
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
        //1. ���� ����
        int idx = name[i] - 'A';
        int curIdx = idx > 26 - idx ? 26 - idx : idx;
        answer += curIdx;

        //2. �¿� ����
        index = i + 1;

        // ���� i���� �������� A�� ���ӵǴ� ������ �� �ε����� ����Ѵ�.
        while (index < length && name[index] == 'A') {
            index++;
        }

        move = min(move, i * 2 + length - index);//�ش� �ε������� ���������� ���� �Ͱ� �������� ���� �� �� �̵����� ���� ���� ����
        //����, ó������ �������� ����ϴ� ���
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
        //1. ���� ����
        int idx = name[i] - 'A';
        int curIdx = idx > 26 - idx ? 26 - idx: idx;
        answer += curIdx;
        name[i] = 'A';
        //2. �¿� ����
        if(name==pass)
            break;
        //rIdx�� ���������� A�� �ƴ� ���� ���ö� ���� �̵�
        int rIdx = i; int rCnt = 0;
        while(name[rIdx]=='A')
        {
            rCnt++;
            rIdx = (rIdx+1)%name.size();
        }
        //lIdx�� �������� A�� �ƴ� ���� ���ö� ���� �̵�
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