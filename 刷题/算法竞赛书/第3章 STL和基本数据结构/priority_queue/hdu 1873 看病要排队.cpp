/**
 * @Author hjl
 * @Date 2021年8月18日05:14:56
 */

#include <bits/stdc++.h>

#define endl '\n'
#define ll long long
#define sstream stringstream
using namespace std;
const double eps = 1e-7;
const auto FAST = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0));


struct node {
	int p, k;
	bool operator < (const node& other) const { // 这里必须定义为常成员函数
		if (p < other.p)
			return true;
		else if (p == other.p)
			return k > other.k;
		else
			return false;
	}
};

int main() {

	int n;
	while (cin >> n) {
		priority_queue<node> pq[3];
		int k = 0;
		while (n--) {
			string type;
			cin >> type;
			if ("IN" == type) {
				int doc_id, p;
				cin >> doc_id >> p;
				k++;
				pq[doc_id - 1].push(node{ p,k });
			}
			else {
				int doc_id;
				cin >> doc_id;
				if (pq[doc_id - 1].empty())
					cout << "EMPTY" << endl;
				else {
					cout << pq[doc_id - 1].top().k << endl;
					pq[doc_id - 1].pop(); // 取了top后，不要忘记pop
				}
			}
		}
	}
	return 0;
}