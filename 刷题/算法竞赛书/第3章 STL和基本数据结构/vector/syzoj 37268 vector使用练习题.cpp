/**
 * @Author hjl
 * @Date 2021年8月17日04:45:30
 */

#include <bits/stdc++.h>

#define endl '\n'
#define ll long long
#define sstream stringstream
using namespace std;
const double eps = 1e-7;
const auto FAST = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0));

int main() {

	int n, m, q;
	cin >> n >> m;
	vector<vector<int>> vec(n, vector<int>(m));
	for (auto& i : vec)
		for (auto& j : i)
			cin >> j;
	cin >> q;
	while (q--) {
		int i, j;
		cin >> i >> j;
		cout << vec[i - 1][j - 1] << endl;
	}

	return 0;
}