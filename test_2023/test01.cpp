#include <string>
#include <vector>

using namespace std;

int check_line(vector<int> line)
{
    int answer = 1;
    bool check_empty = false;
    vector<int> empty_index;
    for (int i = line.size()-1; i > 0; i--)
    {
        if (line[i] == 2)
        {
            empty_index.push_back(i + 1);
            check_empty = true;
        }
        if (line[i] == 1 && check_empty == true)
        {
            return answer;
        }
    }

    if (!empty_index.empty())
    {
        answer = empty_index.size() + 1;
    }
    return answer;
}


int make_line(vector<vector<int>> histogram)
{
    vector<int> line;
    int i= 0;
    int Cnt = 1;
    vector<int> vec = histogram[i];
    for (int j = 0; j < vec.size(); j++)
    {
        for (i = 0; i < histogram.size(); i++)
        {
            line.push_back(histogram[i][j]);
            
        }
        Cnt *= check_line(line);
        line.clear();
    }
    return Cnt;
}



int solution(vector<vector<int>> histogram) {
    int sum = 0;
    int answer = make_line(histogram);
    return answer;
}


//int main()
//{
//    vector<vector<int>> histogram = { {0,0,0,0,0}, {0,0,0,0,0}, {2,2,0,0,0},{1,0,1,0,0}, {2,1,2,2,2}, {2,1,2,2,2}};
//    int ret = solution(histogram);
//}