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
#include <sstream>
#include <limits.h>
#include <float.h>
#include <stack>
using namespace std;
int edit_distance(vector<int> &vec_A, vector<int> &vec_B, vector<int> &vec_C)
{
    vector<vector<vector<int>>> Distance(vec_A.size() + 1, vector<vector<int>>(vec_B.size() + 1, vector<int>(vec_C.size() + 1)));
    //Longest common subsequence with empty string is zero

    for (int i = 0; i <= vec_A.size(); i++)
        Distance[i][0][0] = 0;
    for (int j = 0; j <= vec_B.size(); j++)
        Distance[0][j][0] = 0;
    for (int k = 0; k <= vec_C.size(); k++)
        Distance[0][0][k] = 0;

    for (int i = 1; i <= vec_A.size(); i++)
    {
        for (int j = 1; j <= vec_B.size(); j++)
        {
            for (int k = 1; k <= vec_C.size(); k++)
            {
                if ((vec_A[i - 1] == vec_B[j - 1]) && (vec_B[j - 1] == vec_C[k - 1]))
                    Distance[i][j][k] = Distance[i - 1][j - 1][k - 1] + 1;
                else
                {
                    int Max = INT_MIN, tempMax = INT_MIN;
                    for (int i1 = 0; i1 < 2; i1++)
                        for (int j1 = 0; j1 < 2; j1++)
                            for (int k1 = 0; k1 < 2; k1++)
                                if (!(i == 1 && j == 1 && k == 1))
                                    Max = max(Max, Distance[i - i1][j - j1][k - k1]);
                    Distance[i][j][k] = Max;
                }
            }
        }
    }
    return Distance[vec_A.size()][vec_B.size()][vec_C.size()];
}
int main()
{
    int sizeA, sizeB, sizeC;

    cin >> sizeA;
    vector<int> vec_A(sizeA);
    for (int &x : vec_A)
        cin >> x;

    cin >> sizeB;
    vector<int> vec_B(sizeB);
    for (int &x : vec_B)
        cin >> x;

    cin >> sizeC;
    vector<int> vec_C(sizeC);
    for (int &x : vec_C)
        cin >> x;
    cout << edit_distance(vec_A, vec_B, vec_C);
    return 0;
}