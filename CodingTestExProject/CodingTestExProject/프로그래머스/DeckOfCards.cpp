#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
     int i = 0,j = 0;
    for(int k = 0;k<goal.size();k++)
    {
        if(i==goal.size()||j==goal.size())
            return "No";
        if(cards1[i]==goal[k])
        {
            i++;
        }else if(cards2[j]==goal[k])
        {
            j++;
        }else{
            return "No";
        }
    }
    return "Yes";
}