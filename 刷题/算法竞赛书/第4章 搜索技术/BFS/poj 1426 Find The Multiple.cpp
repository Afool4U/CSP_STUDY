/**
 * @Author hjl
 * @Date 2021年8月25日14:06:53
 */

//#include <bits/stdc++.h>

#include <iostream>
#include <queue>

#define Swap(a,b) {int t=a;a=b;b=t;}
#define endl '\n'
#define ll long long
#define sstream stringstream
using namespace std;
const double eps = 1e-7;
//const auto FAST = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0));

struct node {
	ll n;
	int i;
};

void BFS(int n) {
	queue<node> q;
	node start, next;
	q.push({1,0});

	while (!q.empty()) {
		start = q.front();
		if (start.n && start.n % n == 0) {
			cout << start.n << endl;
			return;
		}
		q.pop();
		next = { start.n * 10,start.i + 1 };
		if (next.n && next.i < 19) {
			q.push(next);
		}
		next = { start.n * 10 + 1,start.i + 1 };
		if (next.n && next.i < 19) {
			q.push(next);
		}
	}
}

int main() {
	int n;
	while (cin >> n && n) {
		BFS(n);
	}
	return 0;
}