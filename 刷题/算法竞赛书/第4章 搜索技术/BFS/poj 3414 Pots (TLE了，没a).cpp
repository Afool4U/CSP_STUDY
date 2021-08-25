/**
 * @Author hjl
 * @Date 2021年8月26日04:30:53
 */

 // #include <bits/stdc++.h>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <stack>

#define Swap(a,b) {int t=a;a=b;b=t;}
#define endl '\n'
#define ll long long
#define sstream stringstream
using namespace std;
const double eps = 1e-7;
//const auto FAST = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0));

int A, B, C;
bool vis[105][105];

struct node {
	int a, b;
	string opt;
	int step;
	bool operator!=(const node o) {
		return a != o.a || b != o.b;
	}
}fd[105][105];

node neighbor(node n, int i) {  // 0-5 一共6个“可能”邻居 
	n.step++;
	switch (i) {
	case 0:  // FILL(1)
		n.opt = "FILL(1)";
		n.a = A;
		break;
	case 1:  // FILL(2)
		n.opt = "FILL(2)";
		n.b = B;
		break;
	case 2:  // DROP(1)
		n.opt = "DROP(1)";
		n.a = 0;
		break;
	case 3:  // DROP(2)
		n.opt = "DROP(2)";
		n.b = 0;
		break;
	case 4:  // POUR(1,2) 
		n.opt = "POUR(1,2)";
		if (B - n.b <= n.a) {
			n.a -= B - n.b;  // 一定要注意赋值的先后顺序!!!
			n.b = B;
		}
		else {
			n.b += n.a;
			n.a = 0;
		}
		break;
	case 5:  // POUR(2,1) 
		n.opt = "POUR(2,1)";
		if (A - n.a <= n.b) {
			n.b -= A - n.a;
			n.a = A;
		}
		else {
			n.a += n.b;
			n.b = 0;
		}
		break;
	}
	return n;
}

node BFS() {
	queue<node> q;
	node start, next;
	q.push({ 0,0,"NULL",0 });
	vis[0][0] = 1;
	while (!q.empty()) {
		start = q.front();
		q.pop();
		if (start.a == C || start.b == C) {
			return start;
		}
		for (int i = 0;i < 6;i++) {
			next = neighbor(start, i);
			if (!vis[next.a][next.b] && next != start) {
				vis[next.a][next.b] = 1;
				fd[next.a][next.b] = start;
				q.push(next);
			}
		}
	}
	return { 0,0,"NULL",0 };
}

int main() {
	while (cin >> A >> B >> C) {
		memset(vis, 0, sizeof(vis));
		if (!C) {
			cout << "FILL(1)"<< endl;
			continue;
		}
		node end = BFS();
		if (end.opt == "NULL") {
			cout << "impossible"<<endl;
			continue;
		}
		cout << end.step << endl;
		stack<node> st;
		while (end.a != 0 || end.b != 0) {
			st.push(end);
			end = fd[end.a][end.b];
		}
		while (!st.empty()) {
			node cur = st.top();
			st.pop();
			cout << cur.opt << endl;
		}
	}
	return 0;
}