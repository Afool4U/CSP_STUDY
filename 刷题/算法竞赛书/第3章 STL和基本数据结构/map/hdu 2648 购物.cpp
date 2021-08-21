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
	map<string, int> shop;
	int n;

	while (cin >> n) {
		string name;
		for (int i = 0;i < n;i++)
			cin >> name;
		int m;
		cin >> m;
		while (m--) {
			for (int i = 0;i < n;i++) {
				int sale;
				string name;
				cin >> sale >> name;
				shop[name] += sale;
			}
			int rank = 1;
			int memory = shop["memory"];
			for (auto& i : shop) {
				if (i.second > memory)
					rank++;
			}
			cout << rank << endl;
		}
		shop.clear();
	}
	return 0;
}