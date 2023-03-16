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
        if (atoi("A") <= ch_num && atoi("Z") >= ch_num)
            return false;
    }
    return true;
}

int main()
{
    string s = "a234";//"1234";
    bool ret = solution(s);
}