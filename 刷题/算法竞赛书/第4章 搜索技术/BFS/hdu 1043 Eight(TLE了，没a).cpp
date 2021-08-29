/**
 * @Author hjl
 * @Date 2021年8月30日03:21:53
 */

#include <bits/stdc++.h>

#define endl '\n'
#define ll long long
#define sstream stringstream
using namespace std;
const double eps = 1e-7;
const auto FAST = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0));

const int dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
const char DIR[4] = { 'u','d','r','l' };

struct node {
	int state[9];
	char opt;
	bool operator<(const node& o)const {
		return memcmp(state, o.state, sizeof(state)) < 0;
	}
	bool operator==(const node& o) {
		return !memcmp(state, o.state, sizeof(state));
	}
};

int main() {
	node start, end{ 1, 2, 3, 4, 5, 6, 7, 8, 0 };
	string line;
	while (getline(cin, line))
	{
		map<node, node> m;
		line.replace(line.find('x'), 1, "0");
		sstream ss(line);
		for (int i = 0; i < 9; i++) {
			ss >> start.state[i];
		}
		node head = start, next;
		m[head] = { -1 };

		queue<node> q;
		q.push(head);
		while (!q.empty()) {
			head = q.front(), q.pop();
			if (head == end)
				break;
			int x, y;
			for (int i = 0;i < 9;i++) {
				if (head.state[i] == 0) {
					x = i / 3;
					y = i % 3;
					break;
				}
			}
			for (int i = 0;i < 4;i++) {
				int newx = x + dir[i][0];
				int newy = y + dir[i][1];
				if (newx >= 0 && newx < 3 && newy >= 0 && newy < 3) {
					next = head;
					swap(next.state[newx * 3 + newy], next.state[x * 3 + y]);
					if (m.find(next) == m.end()) {
						next.opt = DIR[i];
						m[next] = head;
						q.push(next);
					}
				}
			}
		}
		if (head == end) {
			stack<node> s;
			for (node n = head;!(n == start);n = m[n]) {
				s.push(n);
			}
			while (!s.empty()) {
				cout << s.top().opt;
				s.pop();
			}
			cout << endl;
		}
		else
			cout << "unsolvable"<< endl;
	}
	return 0;
}