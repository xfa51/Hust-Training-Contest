#include <bits/stdc++.h>
#define next Next
using namespace std;

const int N = 2e6 + 5;
string s;
int z[N], n, q, dp[N];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    n = s.size();
    int L = 0, R = 0;
    z[0] = n;
    for (int i = 1; i < n; ++i)
    {
        if (i > R)
        {
            L = R = i;
            while (R < n && s[R] == s[R - L]) R++;
            z[i] = R - L; R--;
        }
        else
        {
            int k = i - L;
            if (z[k] < R - i + 1) z[i] = z[k];
            else
            {
                L = i;
                while (R < n && s[R] == s[R - L]) R++;
                z[i] = R - L; R--;
            }
        }
    }
    for(int i = n - 1; i >= 0; --i)
    {
        dp[i] = max(dp[i + 1], z[i]);
    }
    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;
        cout << dp[x - 1] << '\n';
    }
}
