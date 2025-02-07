#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    int ans = 1;
    char last = s[0];
    for (int i = 1; i < n; i++)
    {
        if (s[i] != last)
        {
            ans++;
            last = s[i];
        }
    }

    cout << ans;
}