/**
 * @Author hjl
 * @Date 2021年8月17日23:52:03
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
	while (T--) {
		int n;
		string type;
		cin >> n >> type;
		if ("FIFO" == type) {
			queue<int> q;
			while (n--) {
				string opt;
				int num;
				cin >> opt;
				if ("IN" == opt) {
					cin >> num;
					q.push(num);
				}
				else {
					if (q.empty())
						cout << "None" << endl;
					else {
						cout << q.front() << endl;
						q.pop();
					}
				}
			}
		}
		else {
			stack<int> s;
			while (n--) {
				string opt;
				int num;
				cin >> opt;
				if ("IN" == opt) {
					cin >> num;
					s.push(num);
				}
				else {
					if (s.empty())
						cout << "None" << endl;
					else {
						cout << s.top()<< endl;
						s.pop();
					}
				}
			}
		}
	}

	return 0;
}