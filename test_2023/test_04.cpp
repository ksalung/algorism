#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <string.h>
#include <iostream>
#include <stdio.h>

using namespace std;

/*���� ����
���ڿ� s�� �� �� �̻��� �ܾ�� �����Ǿ� �ֽ��ϴ�. �� �ܾ�� �ϳ� �̻��� ���鹮�ڷ� ���еǾ� �ֽ��ϴ�. �� �ܾ��� ¦����° ���ĺ��� �빮�ڷ�, Ȧ����° ���ĺ��� �ҹ��ڷ� �ٲ� ���ڿ��� �����ϴ� �Լ�, solution�� �ϼ��ϼ���.

���� ����
���ڿ� ��ü�� ¦/Ȧ�� �ε����� �ƴ϶�, �ܾ�(������ ����)���� ¦/Ȧ�� �ε����� �Ǵ��ؾ��մϴ�.
ù ��° ���ڴ� 0��° �ε����� ���� ¦����° ���ĺ����� ó���ؾ� �մϴ�.

"try hello world"�� �� �ܾ� "try", "hello", "world"�� �����Ǿ� �ֽ��ϴ�. �� �ܾ��� ¦����° ���ڸ� �빮�ڷ�, Ȧ����° ���ڸ� �ҹ��ڷ� �ٲٸ� "TrY", "HeLlO", "WoRlD"�Դϴ�. ���� "TrY HeLlO WoRlD" �� �����մϴ�.
*/
/*if (input[count] >= 65 && input[count] <= 90) // �빮��
input[count] += 32; //�ҹ��� ġȯ
else if (input[count] >= 97 && input[count] <= 122) // �ҹ���
input[count] -= 32; //�빮�� ġȯ
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
            if (str_compare >= 97 && str_compare <= 122) // �ҹ���
                str_compare -= 32;
        }
        else if (i % 2 == 1)
        {
            if (str_compare >= 65 && str_compare <= 90) // �빮��
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