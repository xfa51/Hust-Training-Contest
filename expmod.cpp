#include <bits/stdc++.h>
using namespace std;
unsigned long long a, b, a1, b1, a2, b2, c, co;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> a >> b;
    a1 = a / 10; a2 = a % 10;
    b1 = b / 10; b2 = b % 10;
    c = (a2 + b2) % 10;
    co = (a2 + b2) / 10;
    if (a1 + b1 + co != 0) cout << a1 + b1 + co;
    cout << c;
}
