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
	cin.get();

	while (T--) {
		stack<char>s;
		while (1) {
			char ch = cin.get();
			if (ch == ' ' || ch == '\n' || ch == EOF) {
				while (!s.empty()) {
					cout << s.top();
					s.pop();
				}
				if (ch == '\n' || ch == EOF)
					break;
				cout << " ";
			}
			else
				s.push(ch);
		}
		cout << endl;
	}
	return 0;
}