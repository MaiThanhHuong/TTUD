#include <bits/stdc++.h>
using namespace std;
const int maxN = 50;
int n, M, a[maxN], x[maxN];
int f, t[maxN] = {0};
int cnt = 0;

void Try(int k)
{
    for (int v = 1; v <= (M - f - (t[n] - t[k]) / a[k]); v++)
    {
        x[k] = v;
        f = f + a[k] * x[k];
        if (k < n)
        {
            Try(k + 1);
        }
        else if (f == M)
            cnt++;
        f = f - a[k] * x[k];
    }
}

int main()
{
    cin >> n >> M;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        t[i] = t[i - 1] + a[i];
    }
    Try(1);
    cout << cnt;
    return 0;
}