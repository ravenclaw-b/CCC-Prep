#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int realsum = 0;
    for (int i = 1; i <= n; i++)
    {
        realsum += i;
    }

    int givensum = 0;
    for (int i = 0; i < n-1; i++)
    {
        int temp;
        cin >> temp;
        givensum += temp;
    }

    cout << realsum-givensum << endl;
}