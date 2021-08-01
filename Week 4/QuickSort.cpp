#include <iostream>
#include <vector>
using namespace std;
int partition(vector<int>& A, int l, int r)
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
    swap(A[j], A[l]);
    return j;
}
void QuickSort(vector<int>& A, int l, int r)
{
    if (l >= r)
        return;
    int m = partition(A, l, r);
    QuickSort(A, l, m - 1);
    QuickSort(A, m + 1, r);
}
int main()
{
    vector<int> v = {1, 5, 7, 2, 34, 9, 6};
    QuickSort(v, 0, v.size() - 1);
    for (int x : v)
        cout << x << " ";
    return 0;
}