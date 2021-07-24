#include <iostream>
using namespace std;
int binarySearch(long long low, long long high)
{
    long long middle;
    while (low <= high)
    {
        middle = low + (high - low) / 2;
        cout << "is it equal(0) or less(1) or greater(2) than " << middle << "     ?" << endl;
        int c;
        cin >> c;
        if (c == 0)
            return middle;
        else if (c == 1)
            high = middle - 1;
        else
            low = middle + 1;
    }
    return middle;
}
int main()
{

    cout << binarySearch(1, 2097151);
    return 0;
}