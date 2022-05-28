/*
https://programmers.co.kr/learn/courses/30/lessons/62048

분명 로직은 맞는데 왜틀린거지??했던 문제 이번에도 질문의 힘을 빌려서 풀이를 할 수 있었다.
타입캐스트가 연산 중간에 달라지는 점을 주의해야한다 관련해서 오버플로우 안나게 하는 방법은 뭔지 생각해보자
분명 long long연산인데 중간에 오버플로우가 왜 나게 되는지 중간연산 확인해보고 알았다.

gcd를 이용한 로직풀이는 좋긴했으나...끝이 슬펐던문제
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