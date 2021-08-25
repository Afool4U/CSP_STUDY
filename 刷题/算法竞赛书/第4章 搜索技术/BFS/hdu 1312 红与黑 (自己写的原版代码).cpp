/**
 * @Author hjl
 * @Date 2021年8月25日05:39:43
 */

#include <bits/stdc++.h>

#define Swap(a,b) {int t=a;a=b;b=t;}
#define endl '\n'
#define ll long long
#define sstream stringstream
using namespace std;
const double eps = 1e-7;
const auto FAST = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0));

int Wx, Hy, num = 0;

struct node {
	int x;
	int y;
};

int dir[4][2] = {
	{-1,0},  // 左
	{0,-1},  // 上
	{1, 0},  // 右
	{0, 1},  // 下
};

class maze {
public:
	char& operator[](node n) {
		return maze[n.y][n.x];
	}
	char maze[25][25];
}maze;

bool isIn(node n) {
	return n.x >= 0 && n.x < Wx&& n.y >= 0 && n.y < Hy;
}

void dfs(int dx, int dy) {
	num++;
	queue <node> q;
	node start, next;
	start = { dx,dy };
	q.push(start);
	while (!q.empty()) {
		start = q.front();
		q.pop();
		for (int i = 0;i < 4;i++) {
			next = { start.x + dir[i][0], start.y + dir[i][1] };
			if (isIn(next) && maze[next] == '.') {
				q.push(next);
				num++;
				maze[next] = '#';
			}
		}
	}
}

int main() {
	int dx, dy;
	while (cin >> Wx >> Hy && Wx) {
		for (int i = 0;i < Hy;i++) {
			for (int j = 0; j < Wx; j++) {
				cin >> maze.maze[i][j];
				if (maze.maze[i][j] == '@') {
					dx = j;
					dy = i;
				}
			}
		}
		dfs(dx, dy);
		cout << num << endl;
		num = 0;
	}

	return 0;
}