#include <iostream>
#include <vector>
using namespace std;
pair<int, int> partition3(vector<int> &A, int l, int r)
{
    int j = l;
    for (int i = l + 1; i <= r; i++)
    {
        if (A[i] <= A[l])
        {
            j++;
            swap(A[i], A[j]);
        }
    }
    int m2 = j;
    j = l;
    for (int i = l + 1; i <= m2; i++)
    {
        if (A[i] < A[l])
        {
            j++;
            swap(A[i], A[j]);
        }
    }
    swap(A[j], A[l]);
    return make_pair(j, m2);
}
void RandomizedQuickSort(vector<int> &A, int l, int r)
{
    if (l >= r)
        return;
    swap(A[l], A[l + (rand() % (r-l))]);
    pair<int, int> m = partition3(A, l, r);
    RandomizedQuickSort(A, l, m.first - 1);
    RandomizedQuickSort(A, m.second + 1, r);
}
int main()
{
    vector<int> v = {1, 5, 7,34,34, 2, 34, 9, 6, 6, 6, 1, 1, 2, 2, 2};
    RandomizedQuickSort(v, 0, v.size() - 1);
    for (int x : v)
        cout << x << " ";
    return 0;
}