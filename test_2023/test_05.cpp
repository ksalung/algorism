#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <sstream>
#include <cmath>
/*���� ���� n�� �־����ϴ�. �� ���ڸ� k������ �ٲ��� ��, ��ȯ�� �� �ȿ� �Ʒ� ���ǿ� �´� �Ҽ�(Prime number)�� �� ������ �˾ƺ��� �մϴ�.

0P0ó�� �Ҽ� ���ʿ� 0�� �ִ� ���
P0ó�� �Ҽ� �����ʿ��� 0�� �ְ� ���ʿ��� �ƹ��͵� ���� ���
0Pó�� �Ҽ� ���ʿ��� 0�� �ְ� �����ʿ��� �ƹ��͵� ���� ���
Pó�� �Ҽ� ���ʿ� �ƹ��͵� ���� ���
��, P�� �� �ڸ����� 0�� �������� �ʴ� �Ҽ��Դϴ�.
���� ���, 101�� P�� �� �� �����ϴ�.
���� ���, 437674�� 3������ �ٲٸ� 211020101011�Դϴ�. ���⼭ ã�� �� �ִ� ���ǿ� �´� �Ҽ��� ���ʺ��� ������� 211, 2, 11�� ������, �� 3���Դϴ�. (211, 2, 11�� k�������� ������ ���� �ƴ�, 10�������� ������ �� �Ҽ����� �Ѵٴ� ���� �����մϴ�.) 211�� P0 ���¿��� ã�� �� ������, 2�� 0P0����, 11�� 0P���� ã�� �� �ֽ��ϴ�.

���� n�� k�� �Ű������� �־����ϴ�. n�� k������ �ٲ��� ��, ��ȯ�� �� �ȿ��� ã�� �� �ִ� �� ���ǿ� �´� �Ҽ��� ������ return �ϵ��� solution �Լ��� �ϼ��� �ּ���.

����� ��
n	k	result
437674	3	3
110011	10	2
*/
using namespace std;

stack<int> nums;
void make_numbers(int n, int k)
{
    nums.push(n % k);
    int value = n / k;
    if (value < k)
    {
        nums.push(value);
        return;
    }
    make_numbers(value, k);
}

bool count_prime_num(string n)
{
    int prime_cnt = 0;
    stringstream temp_str;
    int num = 0;
    temp_str << n;
    temp_str >> num;
    for (int i = 1; i <= num; i++)
    {
        if (num % i == 0)
            prime_cnt++;
    }
    if (prime_cnt == 2)
        return true;
    else
        return false;
}

bool isPrime(long long num) {
    if (num < 2) return false;

    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) return false;
    }
    return true;

}

int solution(int n, int k) {

    int answer = 0;
    make_numbers(n, k);
    string all_num;
    vector<string> value;
    if (n < 1 || n > 1000000)
        return -1;
    if (k < 3 || k > 10)
        return -1;
    while(!nums.empty())
    {
        if (nums.top() == 0)
        {
            if (!all_num.empty())
            {
                if (isPrime(stoull(all_num)) == true)
                {
                    if (all_num[0] == '0')
                        all_num = all_num.substr(1, all_num.length());
                    value.push_back(all_num);
                    all_num = "";
                    continue;
                }
            }
        }
        all_num += to_string(nums.top());
        nums.pop();
    }
    if (isPrime(stoull(all_num)) == true)
    {
        if (all_num[0] == '0')
            all_num = all_num.substr(1, all_num.length());
        value.push_back(all_num);
    }
    for (string v : value)
    {
        while (v[0] == '0')
            v = v.substr(1, v.length());
        if (v.find('0') != string::npos)
            continue;
        if (isPrime(stoull(v)))
            answer++;
    }
    return answer;
}

int main()
{
    int n = 437674;
    int k = 3;
    int ret = solution(n, k);
}