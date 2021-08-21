/**
 * @Author hjl
 * @Date 2021年8月22日02:31:06
 */

#include <bits/stdc++.h>

#define endl '\n'
#define ll long long
#define sstream stringstream
using namespace std;
const double eps = 1e-7;
const auto FAST = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0));

int a[4];

// 这题输出格式真坑。。好几次都是PE，唉ε=(´ο｀*)))
int main() {
	int flag3 = 1;
	while (1) {
		for (auto& i : a)
			cin >> i;
		sort(a, a + 4);
		if (a[3] == 0)
			break;
		int old = a[0];
		int flag2 = 1;
		int flag = 1;
		if (flag3) {
			flag3 = 0;
		}
		else {
			cout << endl;
		}
		do {
			if (a[0] == 0)
				continue;
			else
				if (flag2) {
					old = a[0];
					flag2 = 0;
				}
			if (a[0] != old) {
				old = a[0];
				cout << endl;
				flag = 1;
			}
			if (flag) {
				flag = 0;
				for (auto& i : a)
					cout << i;
			}
			else {
				cout << " ";
				for (auto& i : a)
					cout << i;
			}

		} while (next_permutation(a, a + 4));
		cout << endl;
	}
	return 0;
}