/**
 * @Author hjl
 * @Date 2021年8月17日15:23:44
 */

#include <bits/stdc++.h>

#define endl '\n'
#define ll long long
#define sstream stringstream
using namespace std;
const double eps = 1e-7;
const auto FAST = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0));

int main() {

	int T;
	cin >> T;
	string s;
	while (cin >> s) {
		reverse(s.begin(), s.end());
		cout << s;
		while (' ' == cin.peek() || '\n' == cin.peek()) {
			cout << char(cin.get());
		}
	}

	return 0;
}