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

string convert(char str, bool big)
{
    string complete_value = "";
    char str_compare = str;
       
    if (big && str_compare >= 97 && str_compare <= 122) // 소문자
        str_compare -= 32; //대문자

    if (!big && str_compare >= 65 && str_compare <= 90) // 대문자
        str_compare += 32; //소문자
        
    complete_value = str_compare;
    return complete_value;
}

string solution(string s) {
    string answer = "";
    int arr_size = s.length();
    char* str = new char(arr_size);
    str = (char*)s.c_str();
    //strcpy(str, s.c_str());
    int letter_cnt = 0;
    for(int i = 0; i < arr_size; i++)
    {
        if (s[i] == ' ')
        {
            letter_cnt = 0;
            answer += " ";
        }
        else
        {
            letter_cnt++;
            if (letter_cnt % 2 == 0)
                //answer += tolower(s[i]);
                answer += convert(str[i], false);
            else 
                //answer += toupper(s[i]);
                answer += convert(str[i], true);
        }
    }
    return answer;
}

int main()
{
    string str = "  abc de   fghi   ";
    string ret = solution(str);
}