/**
 * @Author hjl
 * @Date 2021年8月26日04:30:53
 */

#include <bits/stdc++.h>

#define Swap(a,b) {int t=a;a=b;b=t;}
#define endl '\n'
#define ll long long
#define sstream stringstream
using namespace std;
const double eps = 1e-7;
const auto FAST = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0));

struct Data {
	int x, y; string s;
	bool operator <(Data b) const {
		if (x != b.x) return x < b.x;
		return y < b.y;
	}
};

int main() {
	int A, B, C, sum;
	Data t, temp;
	cin >> A >> B >> C;
	t.x = t.y = 0; temp.x = -1;
	queue<Data> Q;
	map<Data, Data> M;

	Q.push(t); M[t] = temp;
	while (!Q.empty()) {
		t = Q.front(); Q.pop();
		if (t.x == C || t.y == C) break;
		temp.x = A; temp.y = t.y; temp.s = "FILL(1)";
		if (M.find(temp) == M.end()) Q.push(temp), M[temp] = t;

		temp.x = t.x; temp.y = B; temp.s = "FILL(2)";
		if (M.find(temp) == M.end()) Q.push(temp), M[temp] = t;

		temp.x = 0; temp.y = t.y; temp.s = "DROP(1)";
		if (M.find(temp) == M.end()) Q.push(temp), M[temp] = t;

		temp.x = t.x; temp.y = 0; temp.s = "DROP(2)";
		if (M.find(temp) == M.end()) Q.push(temp), M[temp] = t;

		temp.x = min(t.x + t.y, A);
		temp.y = max(0, t.y - A + t.x); temp.s = "POUR(2,1)";
		if (M.find(temp) == M.end()) Q.push(temp), M[temp] = t;

		temp.x = max(0, t.x - B + t.y);
		temp.y = min(t.x + t.y, B); temp.s = "POUR(1,2)";
		if (M.find(temp) == M.end()) Q.push(temp), M[temp] = t;
	}
	if (t.x == C || t.y == C) {
		string ans = ""; sum = 0;
		/* 好好记忆 */
		for (temp = t; temp.x || temp.y; temp = M[temp]) ans += temp.s + "\n", sum++;
		cout << sum << endl << ans;
	}
	else cout << "impossible" << endl;
	
	return 0;
}