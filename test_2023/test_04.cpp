#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <string.h>
#include <iostream>
#include <stdio.h>

using namespace std;

/*문제 설명
문자열 s는 한 개 이상의 단어로 구성되어 있습니다. 각 단어는 하나 이상의 공백문자로 구분되어 있습니다. 각 단어의 짝수번째 알파벳은 대문자로, 홀수번째 알파벳은 소문자로 바꾼 문자열을 리턴하는 함수, solution을 완성하세요.

제한 사항
문자열 전체의 짝/홀수 인덱스가 아니라, 단어(공백을 기준)별로 짝/홀수 인덱스를 판단해야합니다.
첫 번째 글자는 0번째 인덱스로 보아 짝수번째 알파벳으로 처리해야 합니다.

"try hello world"는 세 단어 "try", "hello", "world"로 구성되어 있습니다. 각 단어의 짝수번째 문자를 대문자로, 홀수번째 문자를 소문자로 바꾸면 "TrY", "HeLlO", "WoRlD"입니다. 따라서 "TrY HeLlO WoRlD" 를 리턴합니다.
*/
/*if (input[count] >= 65 && input[count] <= 90) // 대문자
input[count] += 32; //소문자 치환
else if (input[count] >= 97 && input[count] <= 122) // 소문자
input[count] -= 32; //대문자 치환
*/

string convert(char& str)
{
    string complete_value = "";
    const char* ch = &str;
    for (int i = 1; i <= strlen(ch); i++)
    {
        char str_compare = ch[i-1];
        if (i % 2 == 0)
        {
            if (str_compare >= 97 && str_compare <= 122) // 소문자
                str_compare -= 32;
        }
        else if (i % 2 == 1)
        {
            if (str_compare >= 65 && str_compare <= 90) // 대문자
                str_compare += 32;
        }
        complete_value += str_compare;
    }
    return complete_value;
}

string solution(string s) {
    string answer = "";
    char* str = new char(s.length());
    strcpy(str, s.c_str());
    char* token = strtok(str, " ");
    answer += (convert(*token) + " ");
    while (token != NULL)
    {
        token = strtok(NULL, " ");
        if (token == NULL)
        {
            answer = answer.substr(0, answer.length()-1);
            break;
        }
        answer += convert(*token) + " ";
    }
    return answer;
}

int main()
{
    string str = "try hello world";
    string ret = solution(str);
}