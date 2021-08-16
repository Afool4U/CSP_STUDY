/**
 * @Author hjl
 * @Date 2021年8月17日03:15:38
 */

#include <bits/stdc++.h>

#define endl '\n'
#define ll long long
#define sstream stringstream
using namespace std;
const double eps = 1e-7;
const auto FAST = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0));

int main() {

	vector<int> T;
	int n, m;
	while (cin >> n >> m) {
		T.clear();
		for (size_t i = 1; i <= 2 * n; i++) {
			T.push_back(i);
		}
		int pos = 0;
		for (size_t i = 1; i <= n; i++) {

			pos = (pos + m - 1) % T.size();
			T.erase(T.begin() + pos);
		}
		int j = 0;
		for (size_t i = 1; i <= 2 * n; i++) {

			if (i != 1 && (i - 1) % 50 == 0)
				cout << endl;
			if (j < T.size() && i == T[j]) {
				cout << "G";
				j++;
			}
			else
				cout << "B";
		}
		cout << endl << endl;
	}


	return 0;
}