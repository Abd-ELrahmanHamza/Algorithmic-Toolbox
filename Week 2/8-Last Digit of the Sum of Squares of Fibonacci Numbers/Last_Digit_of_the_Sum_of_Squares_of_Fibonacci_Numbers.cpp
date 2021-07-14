#include <iostream>
#include <cmath>
#include <utility>
using namespace std;
int periodCalculator(long long m)
{
    int periodCount = 0;

    unsigned long long first = 0;
    unsigned long long second = 1;
    while (true)
    {
        unsigned long long temp = first;
        first = second;
        second = (temp + second) % m;
        periodCount++;
        if (first == 0 && second == 1 && periodCount > 2)
            return periodCount;
    }
    return periodCount;
}
int Fibonacci_Number_Again(unsigned long long num)
{
    if (num <= 1)
        return num;
    int period = periodCalculator(10);
    unsigned long long first = 0;
    unsigned long long second = 1;
    unsigned long long iterations = (num >= 10 ? num % period : num);
    if (iterations == 0)
        return 0;
    for (int i = 0; i < iterations - 1; i++)
    {
        unsigned long long temp = first;
        first = second;
        second = (temp + second) % 10;
    }
    return (second*(first+second))%10 ;
}

int main()
{
    long long n;
    cin >> n;
    cout << Fibonacci_Number_Again(n);
    //cout<<result<<endl;
    //cout<<"NUM = "<<num<<endl;
    return 0;
}