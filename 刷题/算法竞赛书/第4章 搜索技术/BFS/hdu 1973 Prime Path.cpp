/**
 * @Author hjl
 * @Date 2021年8月26日02:29:43
 */

#include <bits/stdc++.h>

#define Swap(a,b) {int t=a;a=b;b=t;}
#define endl '\n'
#define ll long long
#define sstream stringstream
using namespace std;
const double eps = 1e-7;
const auto FAST = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0));

map<string, bool> table;
bool vis[10000];

struct node {
	string s;
	int step;
};

bool isPrime(string s) {
	int n = atoi(s.c_str());
	for (int i = 2; i <= n / 2; i++) {
		if (n % i == 0)
			return 0;
	}
	return 1;
}

// 下次可以改变思路，int当参数，然后在函数里转成string类处理
node neighbor(node n,int i) {  // 0-39 一共40个“可能”邻居 
		n.s[i / 10] = i % 10 + '0';
		n.step++;
		return n;
}

void BFS(string begin, string end) {
	queue<node> q;
	node start, next;
	q.push({ begin,0 });
	while (!q.empty()) {
		start = q.front();
		if (start.s == end) {
			cout << start.step << endl;
			return;
		}
		q.pop();
		for (int i = 0;i < 40;i++) {
			next = neighbor(start, i);
			int num = atoi(next.s.c_str());
			if (!vis[num] && next.s[0] && next.s != start.s && table[next.s]) {
				vis[num] = 1;
				q.push(next);
			}
		}
	}
}

int main() {
	for (size_t i = 1000; i <= 9999; i++) {
		string s = to_string(i);
		table[s] = isPrime(s);
	}
	int T;
	cin >> T;
	string begin, end;
	while (T--) {
		memset(vis, 0, sizeof(vis));
		cin >> begin >> end;
		BFS(begin, end);
	}
	
	return 0;
}