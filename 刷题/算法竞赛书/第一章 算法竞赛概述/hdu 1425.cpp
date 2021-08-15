#include <bits/stdc++.h>

#define endl '\n';
using namespace std;
typedef long long ll;
typedef stringstream sstream;
const double eps = 1e-7;
const auto FAST = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0));

int main() {
	int n, m;
	while (cin >> n >> m) {
		int a[n];

		for (auto& i : a) {
			cin >> i;
		}
		sort(a, a + n, greater<int>());
		for (size_t i = 0; i < m; i++) {
			if (i)
				cout << " ";
			cout << a[i];
		}
		cout << endl;
	}


	return 0;
}