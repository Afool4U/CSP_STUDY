/**
 * @Author hjl
 * @Date 2021年8月25日06:55:48
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
	{-1,0},  // 上
	{0,-1},  // 左
	{1, 0},  // 下
	{0, 1},  // 右
};

class maze {
public:
	char& operator[](node n) {
		return maze[n.x][n.y];  // 不要再用这种方式了：看似很省事，实则浪费了更多答题时间
	}
	char maze[25][25];
}maze;

inline bool CHECK(node n) {  // 声明成内联函数执行更快
	return n.x >= 0 && n.x < Wx&& n.y >= 0 && n.y < Hy;
}

void BFS(int dx, int dy) {
	num = 1;
	queue <node> q;
	node start, next;
	start = { dx,dy };
	q.push(start);
	while (!q.empty()) {
		start = q.front();
		q.pop();
		//cout << "out: " << start.x << " " << start.y << endl;
		for (int i = 0;i < 4;i++) {
			next = { start.x + dir[i][0], start.y + dir[i][1] };
			if (CHECK(next) && maze[next] == '.') {
				q.push(next);
				num++;
				maze[next] = '#';
			}
		}
	}
}

int main() {
	int dx, dy;
	auto& room = maze.maze;
	while (cin >> Wx >> Hy && Wx) {
		for (int y = 0;y < Hy;y++) {
			for (int x = 0; x < Wx; x++) {
				cin >> room[x][y];
				if (room[x][y] == '@') {
					dx = x;
					dy = y;
				}
			}
		}
		BFS(dx, dy);
		cout << num << endl;
	}

	return 0;
}