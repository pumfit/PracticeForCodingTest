/*
1919 애너그램 만들기

두 영어 단어가 철자의 순서를 뒤바꾸어 같아질 수 있을 때, 그러한 두 단어를 서로 애너그램 관계에 있다고 한다. 예를 들면 occurs 라는 영어 단어와 succor 는 서로 애너그램 관계에 있는데,
occurs의 각 문자들의 순서를 잘 바꾸면 succor이 되기 때문이다.

한 편, dared와 bread는 서로 애너그램 관계에 있지 않다. 하지만 dared에서 맨 앞의 d를 제거하고, bread에서 제일 앞의 b를 제거하면, ared와 read라는 서로 애너그램 관계에 있는 단어가 남게 된다.

두 개의 영어 단어가 주어졌을 때, 두 단어가 서로 애너그램 관계에 있도록 만들기 위해서 제거해야 하는 최소 개수의 문자 수를 구하는 프로그램을 작성하시오. 문자를 제거할 때에는 아무 위치에 있는 문자든지 제거할 수 있다.

alphabet 배열이 두개면 더 쉽게 풀이 가능한 문제 인데 그걸 생각을 못했다.
그래서 첫 문장에서 있는 글자가 아닌경우 결과를 더하는 방식으로 풀이를 진행했다.
*/

#include <iostream>
using namespace std;

int main() {
	string strOne;
	string strTwo;
	int alpha[26] = { 0, };

	cin >> strOne >> strTwo;
	int num = 0;
	for (int i = 0; i < strOne.size(); i++)
		alpha[strOne[i] - 'a']++;

	for (int j = 0; j < strTwo.size(); j++)
	{
		if (alpha[strTwo[j] - 'a'] > 0)
		{
			alpha[strTwo[j] - 'a']--;
		}
		else
		{
			num++;
		}
	}
	for (int j = 0; j < 26; j++)
		num += alpha[j];
	cout << num;
	return 0;
}