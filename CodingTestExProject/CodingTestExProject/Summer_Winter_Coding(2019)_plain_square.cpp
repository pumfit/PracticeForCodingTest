/*
https://programmers.co.kr/learn/courses/30/lessons/62048

�и� ������ �´µ� ��Ʋ������??�ߴ� ���� �̹����� ������ ���� ������ Ǯ�̸� �� �� �־���.
Ÿ��ĳ��Ʈ�� ���� �߰��� �޶����� ���� �����ؾ��Ѵ� �����ؼ� �����÷ο� �ȳ��� �ϴ� ����� ���� �����غ���
�и� long long�����ε� �߰��� �����÷ο찡 �� ���� �Ǵ��� �߰����� Ȯ���غ��� �˾Ҵ�.

gcd�� �̿��� ����Ǯ�̴� ����������...���� ���������
*/
using namespace std;

long long gcd(int x, int y)
{
	return y == 0 ? x : gcd(y, x%y);
}

long long solution(int w, int h) {
	long long answer = 1;
	long long g = w > h ? gcd(w, h) : gcd(h, w);
	long long mw = w / g, mh = h / g;
	answer = (long)w*h - (long)(mw + mh - 1)*g;
	return answer;
}