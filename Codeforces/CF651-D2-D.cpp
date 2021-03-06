#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <climits>
#include <cctype>
#include <bitset>
using namespace std;

#define PI 3.14159265359
#define all(v) v.begin(),v.end()
#define sortva(v) sort(all(v))
#define sortvd(v) sort(v.rbegin(),v.rend())
#define sortaa(a,n) sort(a,a+n)
#define sortad(a,n) sort(a,a+n),reverse(a,a+n)
#define sfi1(v) scanf("%d",&v)
#define sfi2(v1,v2) scanf("%d %d",&v1,&v2)
#define sfi3(v1,v2,v3) scanf("%d %d %d",&v1,&v2,&v3)
#define sfll1(v) scanf("%I64d",&v);
#define sfll2(v1,v2) scanf("%I64d %I64d",&v1,&v2)
#define sfll3(v1,v2,v3) scanf("%I64d %I64d %I64d",&v1,&v2,&v3)
#define sfstr(v) scanf("%s", v);
#define sz(v) (int)v.size()
#define ndl puts("")
#define flush fflush(stdout)
#define SS stringstream
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };

ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

void PLAY() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cout << fixed << setprecision(10);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}


int main() {
	PLAY();
	
	int n, a, b, t;
	cin >> n >> a >> b >> t;
	string s;
	cin >> s;
	vector<int> l(n, 0);
	vector<int> r(n, 0);
	for (int i = 0; i < n; i++)
		l[i] = r[i] = 1 + (i == 0 ? 0 : a) + (s[i] == 'w' ? b : 0);
	for (int i = 1; i < n; i++)
		l[i] += l[i - 1];
	for (int i = n - 2; i >= 0; i--)
		r[i] += r[i + 1];

	int res = 0;
	for (int i = 0; i < n && l[i] <= t; i++)
		res = i + 1;
	for (int i = n - 1; i >= 0 && (l[0] + r[i]) <= t; i--)
		res = max(res, n - i);
	
	sortva(r);
	vector<int>::iterator it;

	for (int i = 0; i < n; i++) {
		int cur_cost = l[i];
		cur_cost += a * i;
		if (cur_cost > t) break;
		it = upper_bound(all(r), t - cur_cost);
		int total_cnt = i + 1;
		total_cnt += it - r.begin();
		res = max(res, total_cnt);
	}
	sortvd(r);
	for (int i = n - 1; i >= 1; i--) {
		int cur_cost = r[i];
		cur_cost += a * (n - i);
		if (cur_cost > t) break;
		it = upper_bound(all(l), t - cur_cost);
		int total_cnt = n - i;
		total_cnt += it - l.begin();
		res = max(res, total_cnt);
	}

	cout << min(res, n) << endl;


	return 0;
}
