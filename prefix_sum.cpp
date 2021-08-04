//Given an array and query to find sum from index l to r

#include <iostream>

using namespace std;

int main()
{
    int arr[10] = {2,0,7,8,1,6,4,3,7,10},i;

    int l = 3,r = 7,sum = 0;

    //Find prefix sum of above array
    for(i = 1; i < 10; i++)
    {
        arr[i] += arr[i-1];
    }

    for(i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
    sum = arr[r] - arr[l-1];
    cout << sum;
    return 0;
}
