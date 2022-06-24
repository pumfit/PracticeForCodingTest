/*
��ȣ ��ȯ
2020 KAKAO BLIND RECRUITMENT

https://programmers.co.kr/learn/courses/30/lessons/60058

���� ���� ��ü�� ���ؼ� �ϳ� �ɷȰ� �ᱹ �ٸ� Ǯ�� ã�ƺô� ����
���� ����� ������ �ּ���� Ǯ����� �ٷ� Ǯ���� �����̱��ϴ�.

ó���� ���ذ� �Ȱ��� �κ���
//2. ��, u�� "�������� ��ȣ ���ڿ�"�� �� �̻� �и��� �� ����� �ϸ�, v�� �� ���ڿ��� �� �� �ֽ��ϴ�.
�ƴ� �׷��� u�� v�� ��� ������ �װ� ���� ������� �ݺ����� ���µ� �̺κ� ��ü�� ��ͷ� ����� �ذ��� �� �־���.
ó���� �׳� ���� �������� ��ȣ �Ǵܸ��ϸ� �� �� �˾Ҵµ� �������� �����ɸ� ����

+) u ���Ҷ� �ʱ�ȭ�ϴ� ����� �� �� ����� �� ���� �� �����Ѵ�
ó���� �ʱ�ȭ�Ҷ� isBalance���� true�� ��ȯ�Ǿ �׳� . �ֱ��ߴµ�
�׸��� �ε����� 1���� �����ʰ� 2���� �����ص� �� �� ���� �ᱹ �������� ���ڿ��̷��� 2������� �ϴ�
*/

#include <string>
#include <stack>
#include <vector>
#include <iostream>
using namespace std;

bool isBalance(string str)
{
    int cnt = 0;
    for (int i = 0; i < str.size(); i++)
        cnt += str[i] == '(' ? 1 : -1;
    return cnt == 0 ? true : false;
}

bool isCorrect(string str)
{
    stack<int> s;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(')
            s.push(1);
        else
        {
            if (s.empty())
                return false;
            else
                s.pop();
        }
    }
    return true;
}

string func(string p)
{
    //1. �Է��� �� ���ڿ��� ���, �� ���ڿ��� ��ȯ�մϴ�. 
    if (p == "")
        return p;
    //2. ��, u�� "�������� ��ȣ ���ڿ�"�� �� �̻� �и��� �� ����� �ϸ�, v�� �� ���ڿ��� �� �� �ֽ��ϴ�. 
    int idx = 1;
    string u = "."; string v = "";
    while (!isBalance(u))
    {
        u = p.substr(0, idx);
        v = p.substr(idx, p.size() - idx);//���ڿ� ����
        idx++;
    }
    //3. ���ڿ� u�� "�ùٸ� ��ȣ ���ڿ�" �̶�� ���ڿ� v�� ���� 1�ܰ���� �ٽ� �����մϴ�.
    if (isCorrect(u))
    {
        return u + func(v);//v�� ���� 1�ܰ���� �ٽ� �����մϴ�.
    }
    else
    {
        string temp = "(";// 4-1. �� ���ڿ��� ù ��° ���ڷ� '('�� ���Դϴ�.
        // 4-2. ���ڿ� v�� ���� 1�ܰ���� ��������� ������ ��� ���ڿ��� �̾� ���Դϴ�. 
        temp += func(v);
        // 4-3. ')'�� �ٽ� ���Դϴ�. 
        temp += ")";
        // 4-4. u�� ù ��°�� ������ ���ڸ� �����ϰ�, ������ ���ڿ��� ��ȣ ������ ����� �ڿ� ���Դϴ�. 
        for (int i = 1; i < u.size() - 1; i++)
        {
            temp += u[i] == '(' ? ')' : '(';
        }
        return temp;
    }
}

string solution(string p) {
    string answer = "";
    answer = func(p);
    return answer;
}