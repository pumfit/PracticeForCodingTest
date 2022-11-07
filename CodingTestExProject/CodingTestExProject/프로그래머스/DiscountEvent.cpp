#include <string>
#include <vector>
#include <map>
using namespace std;

bool CheckCanRegister(vector<string>& want,vector<int>& number,map<string,int>& discountList)
{
    for(int i = 0;i<want.size();i++)
    {
        if(discountList[want[i]]<number[i])
            return false;
    }
    return true;
}

//슬라이딩 윈도우 n  100,000 x 10 시간 복잡도
int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string,int> discountList;
    for(int i =0;i<10;i++)
    {
        discountList[discount[i]]++;
    }
    if(CheckCanRegister(want,number,discountList))
            answer++;
    for(int i =0;i<discount.size()-10;i++)
    {
        discountList[discount[i]]--;
        discountList[discount[i+10]]++;
        if(CheckCanRegister(want,number,discountList))
            answer++;
    }
    return answer;
}