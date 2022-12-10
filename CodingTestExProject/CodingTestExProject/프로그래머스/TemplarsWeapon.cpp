#include <string>
#include <vector>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    int count[100001] = {0,};
    //약수의 개수 구하기
    for (int i = 1; i <= number; i++) 
    {
        for (int j = 1; j * j <= i; j++) 
        {
        if (i % j == 0) {
            count[i]++;
            if (j * j < i) {
                count[i]++;
            }
        }      
        }
    }
    for (int j = 1; j <= number; j++) 
    {
        if(count[j]>limit)
            answer += power;
        else
            answer += count[j];
    }
    return answer;
}