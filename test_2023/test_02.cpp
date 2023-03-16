#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

bool solution(string s) {
    char const* c = s.data();

    for (int i = 0; i < s.size(); i++)
    {
        char ch = c[i];
        int ch_num = atoi(&ch);
        string str(1, ch);
        if (atoi(str.c_str()) == 0)
            return false;
    }
    return true;
}

int main()
{
    string s = "234";//"1234";
    bool ret = solution(s);
}