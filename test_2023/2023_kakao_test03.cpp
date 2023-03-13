

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> perm;
void repeated_Permutation(vector<int> vec, vector<int> tmp, int depth) { 
    if (depth == tmp.size()) {
        perm.push_back(tmp);
        return;
    }
    for (int i = 0; i < vec.size(); i++) {
        tmp[depth] = vec[i];
        repeated_Permutation(vec, tmp, depth + 1);
    }
}


vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    vector<int> vec;
    vector<int> total;
    

    /*
    for (int i =0; i < users.size(); i++)
    {
        vec.push_back(users[i][1]);
    }

    //sort(vec.begin(), vec.end());
    vector<int> tmp(vec.size());
    repeated_Permutation(vec, tmp, 0);

    for (auto it = perm.begin(); it != perm.end(); ++it)
    {
        int sum = 0;
            
        for (int i = 0; i < it->size(); i++)
        {
            vector<int> pay = (*it);
            for (int j = 0; j < vec.size(); j++)
            {
                double value = 100LL - pay[i];
                value *= emoticons[j] / 100LL;
                sum += value; 
            }
        }
        total.push_back(sum);
    }  */
    return answer;
}

int main()
{
    int m = 2;//구매수
    int n = 2;//사용자
    vector<vector<int>> users = {{40, 10000 },{25, 10000 }};
    vector<int> emoticons = { 7000, 9000 };
    vector<int> ret = solution(users, emoticons);
}