#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <utility>
#include <iomanip>
#include <map>
#include <limits>
#include <float.h>
#include <ctime>
using namespace std;
bool compareX(const pair<int, int> &p1, const pair<int, int> &p2)
{
    return p1.first < p2.first;
}
bool compareY(const pair<int, int> &p1, const pair<int, int> &p2)
{
    return p1.second < p2.second;
}
pair<int, int> partition3(vector<pair<int, int>> &v, int l, int r, bool (*compare)(const pair<int, int> &, const pair<int, int> &))
{
    int j = l;
    for (int i = l + 1; i <= r; i++)
    {
        if (compare(v[i], v[l]))
        {
            j++;
            swap(v[i], v[j]);
        }
    }
    int m2 = j;
    j = l;
    for (int i = l + 1; i <= m2; i++)
    {
        if (compare(v[i], v[l]))
        {
            j++;
            swap(v[i], v[j]);
        }
    }
    swap(v[j], v[l]);
    return make_pair(j, m2);
}

void QuickSort(vector<pair<int, int>> &v, int l, int r, bool (*compare)(const pair<int, int> &, const pair<int, int> &))
{
    if (l >= r)
        return;
    pair<int, int> m = partition3(v, l, r, compare);
    QuickSort(v, l, m.first - 1, compare);
    QuickSort(v, m.second + 1, r, compare);
}
double calculateDistance(pair<int, int> &p1, pair<int, int> &p2)
{
    return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}
double getMinDistance(vector<pair<int, int>> points)
{
    double minD = DBL_MAX;
    for (auto it1 = points.begin(); it1 != points.end(); it1++)
        for (auto it2 = it1 + 1; it2 != points.end(); it2++)
            minD = min(calculateDistance(*it1, *it2), minD);
    return minD;
}
double getMinDistanceOverlap(vector<pair<int, int>> points, double D)
{
    double minD = DBL_MAX;
    for (auto it1 = points.begin(); it1 != points.end(); it1++)
        for (auto it2 = it1+1; it2 != points.end() && it2 !=it1+8 && abs((*it2).second - (*it1).second) < D; it2++)
            minD = min(calculateDistance(*it1, *it2), minD);
    return minD;
}
double closestPoints(vector<pair<int, int>> points)
{
    if (points.size() <= 3)
        return getMinDistance(points);
    int midIndex = points.size() / 2;
    int middle = points[midIndex].first;

    double minLeft = closestPoints(vector<pair<int, int>>(points.begin(), points.begin() + midIndex));
    double minRight = closestPoints(vector<pair<int, int>>(points.begin() + midIndex + 1, points.end()));

    double MinDistance = min(minLeft, minRight);

    vector<pair<int, int>> middleSecion;
    for (auto it = points.begin(); it != points.end(); it++)
        if (abs((*it).first - middle) < MinDistance)
            middleSecion.push_back(*it);
    QuickSort(middleSecion, 0, middleSecion.size() - 1, compareY);
    double middleMinDistance = getMinDistanceOverlap(middleSecion, MinDistance);
    return min(middleMinDistance, MinDistance);
}
int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> points(n);
    for (auto &p : points)
        cin >> p.first >> p.second;
    QuickSort(points, 0, n - 1, compareX);
    cout.precision(5);
    cout << fixed << closestPoints(points);
    return 0;
}
