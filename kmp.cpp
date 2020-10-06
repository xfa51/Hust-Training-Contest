#include <bits/stdc++.h>
#define next Next
using namespace std;

const int MN = 2e6 + 5;
string s, t;
int next[MN], n;
int solve()
{
    int j = 0, cnt = 0;
    for(int i = 1; t[i]; ++i)
    {
        while(j > 0 && s[j + 1] != t[i])
        {
            j = next[j];
        }
        if (s[j + 1] == t[i]) j++;
        if (s[j + 1] == 0)
        {
            cnt++;
            j = next[j];
        }
    }
    return cnt;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    s = " " + s;
    int j;
    j = next[1] = 0;
    for(int i = 2; s[i]; ++i)
    {
        while (j > 0 && s[j + 1] != s[i])
        {
            j = next[j];
        }
        if (s[j + 1] == s[i]) j++;
        next[i] = j;
    }
    cin >> n;
    while (n--)
    {
        cin >> t;
        t = " " + t;
        cout << solve() << '\n';
    }
}
