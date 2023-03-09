#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> run_queue(vector<int> _queue, int add_num)
{
    vector<int> vec;
    for (int i = 0; i < _queue.size()-1; i++)
    {
        vec.push_back(_queue[i+1]);
    }
    vec.push_back(add_num);
    return vec;
}


vector<int> count_num(vector<int> _queue)
{
    vector<int> count = {0,0,0};
    for (int i = 0; i < _queue.size(); i++)
    {
        switch (_queue[i])
        {
        case 1:
            count[0]++;
            break;
        case 2:
            count[1]++;
            break;
        case 3:
            count[2]++;
            break;
        default:
            break;
        }
    }
    return count;
}

vector<int> solution(vector<int> _queue) {
    vector<int> temp_queue = _queue;
    vector<int> answer{ 0,0,0 };
    for (int i = 0; i < _queue.size(); i++)
    {
        vector<int> count = count_num(temp_queue);
        vector<int>::iterator iter = min_element(count.begin(), count.end());
        int min_index = min_element(count.begin(), count.end())-count.begin();
        if (count[0] == count[1] && count[1] == count[2])
            break;
        temp_queue = run_queue(temp_queue, min_index+1);
        answer[min_index]++;
    }
    return answer;
}


//int main()
//{
//    vector<int> histogram = {2,1,3,1,2,1};
//    vector<int>  ret = solution(histogram);
//    return 0;
//}