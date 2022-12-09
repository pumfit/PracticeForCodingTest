#include <string>
#include <cstring>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int alphabet[26] = {0,};
    memset(alphabet,-1,sizeof(alphabet));
    for(int i = 0;i<s.size();i++)
    {
        if(alphabet[s[i]-'a']==-1)
        {
            answer.push_back(-1);
        }else{
            answer.push_back(i-alphabet[s[i]-'a']);
        }
        alphabet[s[i]-'a'] = i;
    }
    return answer;
}