#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll minval(ll x, ll y) { return (x < y) ? x : y; }
ll getMid(ll s, ll e) { return (s + e) / 2; }

ll construct_st_util(ll arr[], ll ss, ll se, ll *st, ll si)
{
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
    ll mid = getMid(ss, se);
    st[si] = minval(construct_st_util(arr, ss, mid, st, si * 2 + 1), construct_st_util(arr, mid + 1, se, st, si * 2 + 2));
    return st[si];
}

ll *constructST(ll arr[], ll n)
{
    ll x = (ll)(ceil(log2(n))); // height of segment tree
    ll max_size = 2 * (ll)pow(2, x) - 1;
    ll *st = new ll[max_size];
    construct_st_util(arr, 0, n - 1, st, 0);
    return st;
}

ll RMQUtil(ll *st, ll ss, ll se, ll qs, ll qe, ll index)
{
    if (qs <= ss && qe >= se)
        return st[index];
    if (se < qs || ss > qe)
        return INT_MAX;
    ll mid = getMid(ss, se);
    return minval(RMQUtil(st, ss, mid, qs, qe, 2 * index + 1), RMQUtil(st, mid + 1, se, qs, qe, 2 * index + 2));
}

ll RMQ(ll *st, ll n, ll qs, ll qe)
{
    if (qs < 0 || qe > n - 1 || qs > qe)
        return -1;
    return RMQUtil(st, 0, n - 1, qs, qe, 0);
}

int main()
{
    ll n;
    cin >> n;
    ll arr[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ll *st = constructST(arr, n);
    ll t;
    cin >> t;
    ll sum = 0;
    while (t--)
    {
        ll l, r;
        cin >> l >> r;
        sum += RMQ(st, n, l, r);
    }
    cout << sum << endl;
}
