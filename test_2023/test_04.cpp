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

string convert(char str, bool big)
{
    string complete_value = "";
    char str_compare = str;
       
    if (big && str_compare >= 97 && str_compare <= 122) // �ҹ���
        str_compare -= 32; //�빮��

    if (!big && str_compare >= 65 && str_compare <= 90) // �빮��
        str_compare += 32; //�ҹ���
        
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