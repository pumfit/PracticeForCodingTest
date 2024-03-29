/*
10799 �踷���

���� ���� �踷��⸦ �������� �����Ϸ��� �Ѵ�. ȿ������ �۾��� ���ؼ� �踷��⸦ �Ʒ����� ���� ���� ����, �������� ������ �������� �߻��Ͽ� �踷������ �ڸ���. �踷���� �������� ��ġ�� ���� ������ �����Ѵ�.

�踷���� �ڽź��� �� �踷��� ������ ���� �� �ִ�. - �踷��⸦ �ٸ� �踷��� ���� ���� ��� ������ ���Եǵ��� ����, ������ ��ġ�� �ʵ��� ���´�.
�� �踷��⸦ �ڸ��� �������� ��� �ϳ� �����Ѵ�.
�������� � �踷����� �� �������� ��ġ�� �ʴ´�.
�Ʒ� �׸��� �� ������ �����ϴ� ���� �����ش�. �������� �׷��� ���� �Ǽ��� �踷����̰�, ���� �������� ��ġ, �������� �׷��� ���� ȭ��ǥ�� �������� �߻� �����̴�.
https://www.acmicpc.net/problem/10799

��ȣ ���� ������ �ذ��� ������ �̿��� ( �̸� push ) �̸� pop�ؼ�
��Ȳ�� �°� Ǯ����� ���̴�.
�ش� ������ ��� () �� ��츦 �Ǵ��ؼ� ������ ���ϸ� �Ǵ� ������ ()�̸� �ش� ������ �����ŭ ��ü�� �����ְ�
()�� �ƴ�)�� ��� pop�� �Բ� sum�� ������ �ϳ��� �����ش�.
���������� str.size()-1 �� Ž�������Ƿ� ������ )�� ���� ��ü sum+1���� ������ָ� �ȴ�.

재채점으로 틀려서 다시 본 문제 레이저가 지나갈때 몇개의 막대가 나오는지 알아야한다.
*/
#include <iostream>
#include <stack>
using namespace std;

int main() {
	string str;
	cin>>str;
	stack<char> s;
	int sum = 0;
	int remain = 0;
	for (int i = 0; i <str.size(); i++) {
		if (str[i] == '(') 
		{
			s.push(str[i]);
		}
		else if (str[i] == ')') { 
			
			s.pop();  
			
			// 닫히는 괄호인 경우
			if (remain > s.size()) {
				sum += 1; 
			}
			else { //레이저인 경우
				sum += s.size();
			}
			remain = s.size(); 
		}
	}
	cout<<sum;
	return 0;
}
// 이전 풀이
#include <iostream>
#include <stack>
using namespace std;

int main() {
	int sum = 0;
	string str;
	cin >> str;
	stack<int> s;
	for (int i = 0; i < str.size() - 1; i++)
	{
		if (str[i] == ')')
		{
			s.pop();
			sum += 1;
		}
		else {
			if (str[i + 1] == ')')
			{
				i++;
				sum += s.size();
			}
			else {
				s.push(1);
			}
		}
	}
	cout << sum + 1;
	return 0;
}