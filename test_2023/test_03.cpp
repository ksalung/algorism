#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> find_reserver(vector<int> get_cloth, vector<int>& reserve, int l, int insert)
{
    auto find_iter = find(reserve.begin(), reserve.end(), l);
    if (find_iter != reserve.end()) {
        if (*find_iter == l)
        {
            auto iter = find(get_cloth.begin(), get_cloth.end(), insert);
            if (iter == get_cloth.end())
            {
                get_cloth.push_back(insert);
                reserve.erase(find_iter);
            }
        }
    }
    return get_cloth;
}

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> get_cloth;
    vector<int>* _reserve = &reserve;
   
    if (n < 2 || n > 30)
        return 0;

    for (int i = 1; i <= n; i++)   
        get_cloth.push_back(i);

    for (int i : lost)
    {
        auto del_iter = find(_reserve->begin(), _reserve->end(), i);
        if (del_iter != _reserve->end())
        {
            _reserve->erase(del_iter);
            get_cloth.push_back(i);
        }
        auto iter = find(get_cloth.begin(), get_cloth.end(), i);
        if (iter != get_cloth.end())
            get_cloth.erase(iter);
    }

    for (int l : lost)
    {
            get_cloth = find_reserver(get_cloth, *_reserve, l + 1, l);
            get_cloth = find_reserver(get_cloth, *_reserve, l - 1, l);
    }
    answer = get_cloth.size();
    return answer;
}

int main()
{
    int n = 4;
    vector<int> lost{ 1, 3, 4 };
    vector<int> reserve{ 1, 3 };
    int ret = solution(n, lost, reserve);
}