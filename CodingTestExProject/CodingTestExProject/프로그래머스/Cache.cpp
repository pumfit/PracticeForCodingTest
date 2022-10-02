/*
ĳ��

https://school.programmers.co.kr/learn/courses/30/lessons/17680

ĳ�� ��ü �˰����� LRU(Least Recently Used)�� ����Ѵ�.
���͸� ����ؼ� �����ϴ� ����� ����ϰ� ĳ�� ���� �߻����� ������ ĳ�÷� �ְ�
ĳ������ �߻��� ��쿡�� �ش� ĳ�� ������ ��ġ�� �� �ڷ� ��ü�ϴ� ������� �����Ͽ���.

���� Ǯ�鼭 LRU �˰��� ��ü�� ���� ������ �ʿ��� �� ���ٰ� ������.

+) �Ʒ� �ΰ��� ����ó���� ���� ó���� �ʾ�����.

- ĳ�� ����� 0 �� ��쿡 erase ����ó��

- ==�� ������ ������ �־ ĳ�� �ִ� ����� 0�� ��쿡 ����ó�� (7,17 �� ����)
*/
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<string> cach;

bool isCaching(int cacheSize, string str)
{
    bool cached = false;
    if (cacheSize == 0)
        return cached;
    auto iter = find(cach.begin(), cach.end(), str);
    if (iter == cach.end())//step 1. ĳ�̵Ǿ����� �ʴٸ�
    {
        if (cacheSize == cach.size() && cach.size() > 0)
            cach.erase(cach.begin());//step 2. ĳ�ð� �� ���ִٸ� �� �� ����

    }
    else //step3.ĳ�̵Ǿ� �ִٸ�
    {
        cached = true;
        //step4.��Ͽ��� �����ϰ� �ǵڷ� �ű��.
        cach.erase(iter);
    }
    cach.push_back(str);
    return cached;
}

string to_lower(string str)
{
    for (int i = 0; i < str.size(); i++)
        str[i] = tolower(str[i]);
    return str;
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;

    for (int i = 0; i < cities.size(); i++)
    {
        //��ҹ��� ���� �����Ƿ� 
        string str = to_lower(cities[i]);
        if (isCaching(cacheSize, str))
            answer++;
        else
            answer += 5;

    }
    return answer;
}