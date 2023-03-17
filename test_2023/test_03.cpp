#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> get_cloth;
   
    for (int i = 1; i <= n; i++)   
        get_cloth.push_back(i);

    for (int i : lost)
    {
        auto iter = find(get_cloth.begin(), get_cloth.end(), i);
        if (iter != get_cloth.end())
            get_cloth.erase(iter);
    }

    for (int i : lost)
    {
        for(int j : reserve)
        {
            if (j == n)
            {
                if (i == j - 1)
                {
                    auto iter = find(get_cloth.begin(), get_cloth.end(), j + 1);
                    if (iter == get_cloth.end())
                        get_cloth.push_back(j - 1);
                }
            }
            else if (j == 1)
            {
                if (i == j + 1)
                {
                    auto iter = find(get_cloth.begin(), get_cloth.end(), j + 1);
                    if (iter == get_cloth.end())
                        get_cloth.push_back(j + 1);
                }
            }
            if (j < i) {
                auto iter = find(lost.begin(), lost.end(), j + 1);
                if (iter != lost.end()) {
                    auto iter = find(get_cloth.begin(), get_cloth.end(), j + 1);
                    if (iter == get_cloth.end())
                        get_cloth.push_back(j+1);
                }
            }
       
        }
    }
    answer = get_cloth.size();
    return answer;
}

int main()
{
    int n = 4;
    vector<int> lost{ 2, 3 };
    vector<int> reserve{ 3, 4 };
    int ret = solution(n, lost, reserve);
}