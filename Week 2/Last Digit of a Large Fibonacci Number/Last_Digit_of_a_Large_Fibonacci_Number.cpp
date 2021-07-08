#include <iostream>
#include <assert.h>
using namespace std;
// fast iterative solution
int Fibonacci_Number(int n)
{
    if(n<=1) return n;
     
    long long first = 0;
    long long second = 1;

    for(int i=0;i<n-1;i++)
    {
        long long temp = first;
        first = second;
        second = (temp + second)%10;
    }
    return second%10;
}
// slow test solution
long long Fibonacci_Number_test(int n)
{
    if (n <= 1)
        return n;
    int *fibArr = new int[n + 1];
    fibArr[0] = 0;
    fibArr[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        fibArr[i] = (fibArr[i - 1] + fibArr[i - 2]) % 10;
    }
    return fibArr[n];
}
// testing
void test_Fib()
{
    for (int i = 0; i < 200; i++)
        assert(Fibonacci_Number(i) == Fibonacci_Number_test(i)%10);
}
int main()
{
    int num;
    cin >> num;
    cout << Fibonacci_Number(num);
    //test_Fib();
    return 0;
}