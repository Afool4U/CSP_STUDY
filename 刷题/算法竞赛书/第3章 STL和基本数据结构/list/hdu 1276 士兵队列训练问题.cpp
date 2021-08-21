#include <bits/stdc++.h>

#define endl '\n'
#define ll long long
#define sstream stringstream
using namespace std;
const double eps = 1e-7;
const auto FAST = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0));

int main() {
	int n;
	cin >> n;
	while (n--) {
		int m;
		cin >> m;
		list<int> p;
		for (int i = 1;i <= m;i++) {
			p.push_back(i);
		}
		int type = 1;
		while (p.size() > 3) {
			int num = 1;
			if (type == 1) {
				for (auto it = p.begin();it != p.end();) {
					if (num++ % 2 == 0)
						it = p.erase(it);
					else
						it++;
				}
			}
			else {
				for (auto it = p.begin();it != p.end();) {
					if (num++ % 3 == 0)
						it = p.erase(it);
					else
						it++;
				}
			}
			type *= -1;
		}
		for (auto it = p.begin();it != p.end();it++) {
			if (it == p.begin())
				cout << *it;
			else
				cout << " " << *it;
		}
		cout << endl;
	}
	return 0;
}