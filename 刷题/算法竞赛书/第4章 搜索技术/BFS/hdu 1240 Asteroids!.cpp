/**
 * @Author hjl
 * @Date 2021年8月27日03:59:16
 */

#include <bits/stdc++.h>

#define endl '\n'
#define ll long long
#define sstream stringstream
using namespace std;
const double eps = 1e-7;
const auto FAST = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0));

int N;
char a[15][15][15];
struct node {
	int x, y, z;
	bool operator<(const node& b)const {
		if (x != b.x)
			return x < b.x;
		else if (y != b.y)
			return y < b.y;
		return z < b.z;
	}
	bool operator==(const node &b)const {
		return x == b.x && y == b.y && z == b.z;
	}
	operator bool() const {
		return a[x][y][z] != 'X' && x >= 0 && x < N&& y >= 0 && y < N&& z >= 0 && z < N;
	}
};

int main() {
	node START, END, start, next;
	string temp;
	while (cin >> temp >> N) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < N; k++) {
					cin >> a[i][j][k];
				}
			}
		}
		cin >> START.x >> START.y >> START.z;
		a[START.x][START.y][START.z] = 'O';
		cin >> END.x >> END.y >> END.z;
		a[END.x][END.y][END.z] = 'O';
		cin >> temp;

		start = START;
		map<node, node> M;
		queue<node> Q;
		Q.push(start);
		M[start] = { -1,-1,-1 };
		while (!Q.empty()) {
			start = Q.front(); Q.pop();
			if (start == END)
				break;
			next = start, next.x++;
			if (next && M.find(next) == M.end()) Q.push(next), M[next] = start;

			next = start, next.x--;
			if (next && M.find(next) == M.end()) Q.push(next), M[next] = start;

			next = start, next.y++;
			if (next && M.find(next) == M.end()) Q.push(next), M[next] = start;

			next = start, next.y--;
			if (next && M.find(next) == M.end()) Q.push(next), M[next] = start;

			next = start, next.z++;
			if (next && M.find(next) == M.end()) Q.push(next), M[next] = start;

			next = start, next.z--;
			if (next && M.find(next) == M.end()) Q.push(next), M[next] = start;
		}
		if (start == END) {
			int cnt = 0;
			for (node t = END; !(t == START); t = M[t]){
				cnt++;
			}
			cout << N << " " << cnt << endl;
		}
		else
			cout << "NO ROUTE" <<endl;
	}
	return 0;
}