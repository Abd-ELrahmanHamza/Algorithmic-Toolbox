#include<iostream>
#include<vector>
#include<limits>
#include<cmath>
using namespace std;

long long MaximumPairwiseProduct(vector<int>& Data)
{
    int maxIndex = 0;
    int secMaxIndex = -1;
    maxIndex = (Data[0]>Data[1]?0:1);
    secMaxIndex = abs(maxIndex-1);
    for(int i=2;i<Data.size();i++)
    {
        if(Data[i]>=Data[maxIndex])
        {
            secMaxIndex = maxIndex;
            maxIndex = i;
        }
        else if(Data[i]>Data[secMaxIndex])
            secMaxIndex = i;
    } 
    long long result = static_cast<long long>(Data[maxIndex]) * Data[secMaxIndex];
    return result;
}

int main()
{
    int size;
    cin>>size;
    vector<int> data(size);
    for(int i=0;i<size;i++)
        cin>>data[i];
    cout<<MaximumPairwiseProduct(data);
    return 0;
}