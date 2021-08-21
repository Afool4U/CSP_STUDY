/**
 * @Author hjl
 * @Date 2021年8月22日02:05:26
 */

#include <bits/stdc++.h>

#define endl '\n'
#define ll long long
#define sstream stringstream
using namespace std;
const double eps = 1e-7;
const auto FAST = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0));

int a[1005];
int main() {
	int n, m;
	while (cin >> n >> m) {
		for (int i = 1;i <= n;i++)
			a[i] = i;
		while (--m)
			next_permutation(a, a + n + 1);
		cout << a[1];
		for (int i = 2;i <= n;i++)
			cout << " " << a[i];
		cout << endl;
	}
	return 0;
}