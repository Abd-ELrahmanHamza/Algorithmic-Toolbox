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
    if (sum > n)
    {
        v.pop_back();
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