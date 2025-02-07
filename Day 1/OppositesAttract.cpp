#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> count(11);
    int zeros = 0;
    for (int i = 1; i <= 10; i++)
    {
        count[i].first = 0;
        count[i].second = 0;
    }

    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;

        if (temp > 0)
        {
            ans += count[temp].first;
            count[temp].second++;
        }
        else if (temp == 0)
        {
            ans += zeros;
            zeros++;
        }
        else
        {
            ans += count[abs(temp)].second;
            count[abs(temp)].first++;
        }
    }

    cout << ans << endl;
}