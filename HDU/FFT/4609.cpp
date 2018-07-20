#include <cstdio>
#include <iostream>
#include <string.h>
#include <string> 
#include <map>
#include <queue>
#include <deque>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <stack>
#include <iomanip>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
const int maxn=400005, inf = 0x3f3f3f3f;
const ll llinf = 0x3f3f3f3f3f3f3f3f;
const ld pi = acos(-1.0L);
ll cnt[maxn],p[maxn],x[maxn/4];

struct complex
{
	double r, i;
	complex(double _r = 0, double _i = 0)
	{
		r = _r; i = _i;
	}
	complex operator +(const complex &b)
	{
		return complex(r + b.r, i + b.i);
	}
	complex operator -(const complex &b)
	{
		return complex(r - b.r, i - b.i);
	}
	complex operator *(const complex &b)
	{
		return complex(r*b.r - i * b.i, r*b.i + i * b.r);
	}
};
complex conj(complex a) {
	return complex(a.r, -a.i);
}
complex a[maxn], b[maxn];

struct fff {
	int n, rev[maxn];
	complex o[maxn], oi[maxn];

	void init(int m) {
		n = 1;
		int k = 0;
		while (n < m) n <<= 1, k++;
		for (int i = 0; i < n; i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (k - 1));
		for (k = 0; k < n; k++) {
			o[k] = complex(cos(2 * pi / n * k), sin(2 * pi / n * k));
			oi[k] = conj(o[k]);
		}
	}

	void fft(complex *a, complex *w) {
		for (int i = 0; i < n; i++)
			if (i < rev[i]) swap(a[i], a[rev[i]]);
		for (int l = 2; l <= n; l <<= 1) {
			int m = l >> 1;
			for (complex *p = a; p != a + n; p += l)
				for (int k = 0; k < m; k++) {
					complex t = w[n / l * k] * p[k + m];
					p[k + m] = p[k] - t;
					p[k] = p[k] + t;
				}
		}
	}

	void dft(complex *a, int f) {
		if (f == 1) fft(a, o); else {
			fft(a, oi);
			for (int i = 0; i < n; i++) a[i].r /= n;
		}
	}

	void mul(complex *a, complex *b, int m) {
		dft(a, 1); dft(b, 1);
		for (int i = 0; i < n; i++) a[i] = a[i] * b[i];
		dft(a, -1);
	}
};
fff f;

int main() {
	int cas;
	scanf("%d", &cas);
	f.init(200000);
	while (cas--) {
		ll n, i, y = -1;
		scanf("%lld", &n);
		mem0(cnt);
		for (i = 1; i <= n; i++) {
			scanf("%lld", &x[i]);
			cnt[x[i]-1]++;
			y = max(y, x[i]);
		}
		mem0(a); mem0(b); mem0(p);
		for (i = 0; i < y*2; i++) {
			a[i].r = b[i].r = cnt[i];
			p[i*2+2] = -cnt[i];
		}
		f.mul(a, b, 2 * y);
		ll ans = 0;
		for (i = 1; i < 2 * y; i++) {
			p[i+1] = ((ll) floor(a[i-1].r + 0.5) +p[i+1])/ 2;
			p[i+1] += p[i];
		}
		sort(x + 1, x + n + 1);
		for (i = 1; i <=n; i++) {
			ans += p[2 * y] - p[x[i]];
			ans -= n - 1;
			ans -= (n - i)*(n - i - 1) / 2;
			ans -= (n - i)*(i-1);
		}
		db pb = 6.0*((db)ans) / ((n - 1)*(n - 2)*n);
		printf("%.7lf\n", pb);
	//	printf("%lld\n", ans);
	}
//	system("pause");
	return 0;
}
