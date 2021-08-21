/**
 * @Author hjl
 * @Date 2021年8月22日00:43:30
 */

#include <bits/stdc++.h>

#define endl '\n'
#define ll long long
#define sstream stringstream
using namespace std;
const double eps = 1e-7;
const auto FAST = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0));

int main() {
	int n;
	while (cin >> n && n) {
		set<string>A, B;
		while (n--) {
			string a, b;
			cin >> a >> b;
			A.insert(a);A.insert(b);
			B.insert(b);
		}
		if (A.size() - B.size() == 1)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}