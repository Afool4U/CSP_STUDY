/**
 * @Author hjl
 * @Date 2021年8月30日01:32:36
 */

#include <bits/stdc++.h>

#define endl '\n'
#define ll long long
#define sstream stringstream
using namespace std;
const double eps = 1e-7;
const auto FAST = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0));

int factory[] = { 1,1,2,6,24,120,720,5040,40320,362880 };
const int LEN = 362800;
bool vis[LEN];
int dir[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };

bool Cantor(int str[]) {  // 查重并标记
	unsigned result = 0;
	for (int i = 0; i < 9; i++) {
		unsigned counted = 0;
		for (int j = i + 1; j < 9; j++) {
			if (str[j] < str[i])
				counted++;
		}
		result += counted * factory[9 - i - 1];
	}
	if (vis[result])
		return true;
	else {
		vis[result] = 1;
		return false;
	}

}

struct node {
	int state[9];
	int dis;
	bool operator==(const node& o) {
		return !memcmp(state, o.state, sizeof(state));
	}
};

int main() {
	node start, final;
	for (int i = 0; i < 9; i++) {
		cin >> start.state[i];
	}
	for (int i = 0; i < 9; i++) {
		cin >> final.state[i];
	}
	start.dis = 0;

	node head = start, next;
	head.dis = 0;
	queue<node> q;
	q.push(head);

	while (!q.empty()) {
		head = q.front(), q.pop();
		if (head == final)
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
				if (!Cantor(next.state)) {
					next.dis++;
					q.push(next);
				}

			}
		}
	}
	if (head == final)
		cout << head.dis;
	else
		cout << "impossible!";
	return 0;
}
/*

1 2 3 0 8 4 7 6 5
1 0 3 8 2 4 7 6 5
*/