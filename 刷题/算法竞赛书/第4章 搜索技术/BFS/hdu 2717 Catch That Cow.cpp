/**
 * @Author hjl
 * @Date 2021年8月25日07:55:52
 */

#include <bits/stdc++.h>

#define Swap(a,b) {int t=a;a=b;b=t;}
#define endl '\n'
#define ll long long
#define sstream stringstream
using namespace std;
const double eps = 1e-7;
const auto FAST = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0));
const int maxn = 1e5 + 5;

bool vis[maxn];

struct node {
	int x;
	int step;
};

inline int CHECK(node n) {
	return n.x >= 0 && n.x <= maxn;
}

node neighbor(node cur, int i) {
	switch (i) {
	case 0:
		return { cur.x - 1,cur.step + 1 };
	case 1:
		return { cur.x + 1,cur.step + 1 };
	case 2:
		return { cur.x * 2,cur.step + 1 };
	}
}

void BFS(int N, int K) {
	node start, next;
	queue<node> q;
	q.push({N,0});
	while (!q.empty()) {
		start = q.front();
		if (start.x == K)
			break;
		q.pop();
		for (int i = 0;i < 3;i++) {
			next = neighbor(start, i);
			if (CHECK(next) && !vis[next.x]){
				q.push(next);
				vis[next.x] = 1;
			}
		}
	}
	cout << start.step << endl;
}

int main() {
	int N, K;
	while (cin >> N >> K) {
		BFS(N, K);
		memset(vis, 0, sizeof(vis));
	}
	return 0;
}