#include <iostream>
#include <vector>
using namespace std;
vector<long long> v;
int merge(int left, int middle, int right)
{
    int inversionsNum = 0;
    vector<int> v1(middle - left + 1), v2(right - middle);
    for (int i = left; i <= middle; i++)
        v1[i - left] = v[i];
    for (int i = middle + 1; i <= right; i++)
        v2[i - middle - 1] = v[i];
    int i = 0, j = 0, k = left;
    while (i < v1.size() && j < v2.size())
    {
        if (v1[i] <= v2[j])
        {
            v[k] = v1[i];
            i++;
        }
        else
        {
            v[k] = v2[j];
            j++;
            inversionsNum += (middle - i - left + 1);
        }
        k++;
    }
    while (i < v1.size())
    {
        v[k] = v1[i];
        i++, k++;
    }
    while (j < v2.size())
    {
        v[k] = v2[j];
        j++;
        k++;
    }
    return inversionsNum;
}
int mergeSort(int left, int right)
{
    int inversionsNum = 0;
    if (right > left)
    {
        int middle = left + (right - left) / 2;
        inversionsNum += mergeSort(left, middle);
        inversionsNum += mergeSort(middle + 1, right);
        inversionsNum += merge(left, middle, right);
    }
    return inversionsNum;
}
int main()
{
    int size;
    cin >> size;
    v = vector<long long>(size);
    for (long long &x : v)
        cin >> x;
    cout << mergeSort(0, size - 1);
    return 0;
}