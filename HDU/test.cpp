#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
inline ll readLL() {
    static ll n;
    static int ch;
    n = 0, ch = getchar();
    while (!isdigit(ch)) ch = getchar();
    while (isdigit(ch)) n = n * 10 + ch - '0', ch = getchar();
    return n;
}

const int MAX_N = 100000 + 3, MAX_BASE = 60;
int n, zero = false;
ll a[MAX_N], b[MAX_BASE + 3];
vector<ll> mmap;

void prepare() {
    int cnt = 0;
    memset(b, 0, sizeof b);
    for (int i = 0; i < n; ++i)
        for (int j = MAX_BASE; j >= 0; --j)
            if (a[i] >> j & 1) {
                if (b[j]) a[i] ^= b[j];
                else {
                    b[j] = a[i], cnt++;
                    for (int k = j - 1; k >= 0; --k) if (b[k] && ((b[j] >> k) & 1)) b[j] ^= b[k];
                    for (int k = j + 1; k <= MAX_BASE; ++k) if ((b[k] >> j) & 1) b[k] ^= b[j];
                    break;
                }
            }
    zero = cnt != n;

    mmap.clear();
    for (int i = 0; i <= MAX_BASE; ++i)
        if (b[i]) mmap.push_back(b[i]);
}

ll query(ll k) {
    if (zero) k--;
    if (k >= (1LL << (int)mmap.size())) return -1;
    ll ans = 0;
    for (int i = 0; i < (int)mmap.size(); ++i) if ((k >> i) & 1)
        ans ^= mmap[i];
    return ans;
}

int main() {
#ifdef DEBUG
    freopen("test.in", "r", stdin);
#endif
    int caseNum = readLL();
    for (int t = 1; t <= caseNum; ++t) {
        n = readLL();
        for (int i = 0; i < n; ++i) a[i] = readLL();

        prepare();

        printf("Case #%d:\n", t);
        int q = readLL();
        for (int i = 0; i < q; ++i) printf("%lld\n", query(readLL()));
    }
    return 0;
}

