#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::min;
using std::pair;
using std::string;
using std::vector;
bool sortFun(long long &p1, long long &p2)
{
    string s1 = std::to_string(p1), s2 = std::to_string(p2);
    string sum1 = s1+s2,sum2 = s2+s1;
    long long result1=0,result2=0;
    for (int i = sum1.size(); i >=1 ; i--)
    {
        result1 += sum1[sum1.size()-i] * pow(10,i);
        result2 += sum2[sum2.size() - i] * pow(10, i);
    }
    return result1>result2;
}
string maxSalary(vector<long long> &v)
{
    sort(v.begin(), v.end(), sortFun);
    string answer = "";
    for (long long x : v)
        answer += std::to_string(x);
    return answer;
}
int main()
{
    long long n;
    cin >> n;
    vector<long long> v(n);
    for (long long &x : v)
        cin >> x;
    cout << maxSalary(v);
    v.clear();
    return 0;
}
