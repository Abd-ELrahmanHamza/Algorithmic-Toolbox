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
int main()
{
    int n;
    cin >> n;
    int sum = 0, i = 1;
    vector<int> v;
    while (sum < n)
    {
        sum += i;
        v.push_back(i);
        i++;
    }
    //cout << v[i - 3] << endl;
    if (sum > n)
    {
        v.pop_back();
        //cout << (n ) << endl;
        //cout << sum<<" "<<i << endl;
        v[i - 3] += (n - (sum - (i - 1)));
    }
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i];
        if (i != v.size() - 1)
            cout << " ";
    }
    return 0;
}

// #include <iostream>
// #include <vector>
// using namespace std;
// int main()
// {
//     long long sum;
//     cin >> sum;
//     int i = 1;
//     vector<int> v;
//     long long n = sum;
//     while (sum > 0)
//     {
//         if (sum - i >= 0)
//         {
//             v.push_back(i);
//             sum -= i;
//         }
//         else
//             break;
//         i++;
//     }
//     if (n != sum)
//         v.push_back((n - sum) * 2);
//     for (int i = 0; i < v.size(); i++)
//     {
//         if (v[i] != (n - sum) )
//         {
//             cout << v[i];
//             if (i != v.size() - 1)
//                 cout << " ";
//         }
//     }
//     return 0;
// }