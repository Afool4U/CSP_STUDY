/**
 * @Author hjl
 * @Date 2021年8月22日12:31:32
 */

#include <bits/stdc++.h>

#define Swap(a,b) {int t=a;a=b;b=t;}
#define endl '\n'
#define ll long long
#define sstream stringstream
using namespace std;
const double eps = 1e-7;
const auto FAST = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0));

int a[15];
int m;

void Perm(int begin, int end) {
	int i;
	if (begin == m) {
		for (int i = 0;i < m;i++) {
			cout << a[i];
		}
		cout << endl;
	}
	else {
		for (i = begin;i <= end;i++) {
			Swap(a[begin], a[i]);
			Perm(begin + 1, end);
			Swap(a[begin], a[i]);
		}
	}
}

int main() {

	int n;
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> a[i];
	}
	cin >> m;
	Perm(0, n - 1);

	return 0;
}