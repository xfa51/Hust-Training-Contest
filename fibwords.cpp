#include <bits/stdc++.h>
using namespace std;
#define next Next
const int N = 1e5 + 5;
int n, st, base;
string s, sa, sb, sc;
int next[N];
void init()
{
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
}
int check(string t)
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
void solve(int number)
{
	sa = " 0"; sb = " 1";
	int P = s.size() - 2;
	int i = 2;
	for (; i <= 4; ++i)
	{
		sa.erase(0, 1);
		sc = sb + sa;
		sa = sb;
		sb = sc;
	}
	while (sa.size() < s.size())
	{
		i++;
		sa.erase(0, 1);
		sc = sb + sa;
		sa = sb;
		sb = sc;
	}
	long long c = check(sa), d = check(sb);
	int tmp[2];
	sc = " " + sb.substr(sb.size() - P, P) + sb.substr(1, P);
	tmp[0] = check(sc);
	sc = " " + sa.substr(sa.size() - P, P) + sb.substr(1, P);
	tmp[1] = check(sc);
	for (; i <= n; ++i)
	{
		long long t = d;
		d += c + tmp[1 - i % 2];
		c = t;
	}
	cout << "Case " << number << ": " << d << '\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    int cn = 0;
    while (cin >> n >> s)
    {
        if (!cin) break;
        cn++;
        init();
        solve(cn);
    }
}
