#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <utility>
#include <iomanip>
#include <map>
using namespace std;
void merge(vector<int> &v, int begin, int middle, int end)
{
    vector<int> v1, v2;
    for (int i = begin; i <= middle; i++)
        v1.push_back(v[i]);
    for (int i = middle + 1; i <= end; i++)
        v2.push_back(v[i]);
    int i = 0, j = 0,k=begin;
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
        }
        k++;
    }
    while(i<v1.size())
    {
        v[k] = v1[i];
        k++;i++;
    }
    while(j<v2.size())
    {
        v[k]=v2[j];
        k++;j++;
    }
}
void merge_sort(vector<int> &v, int begin, int end)
{
    if (end > begin)
    {
        int middle = begin + (end - begin) / 2;
        merge_sort(v, begin, middle);
        merge_sort(v, middle + 1, end);
        merge(v, begin, middle, end);
    }
}
int main()
{
    vector<int> v = {1,9,8,12,6,4,6,9,855,6,245};
    merge_sort(v,0,v.size()-1);
    for(auto x:v)
    cout<<x<<" ";
    return 0;
}
