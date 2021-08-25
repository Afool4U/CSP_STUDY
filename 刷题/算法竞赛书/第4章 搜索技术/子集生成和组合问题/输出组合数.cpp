/**
 * @Author hjl
 * @Date 2021年8月25日04:58:53
 */

#include <bits/stdc++.h>

#define Swap(a,b) {int t=a;a=b;b=t;}
#define endl '\n'
#define ll long long
#define sstream stringstream
using namespace std;
const double eps = 1e-7;
const auto FAST = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0));

void print_subset(int n,int k) {
	for (int i = 0; i < (1 << n); i++) {
		int num = 0, kk = i;
		while (kk) {
			kk &= kk - 1;
			num++;
		}
		if (num != k)
			continue;
		for (int j = 0;j < n;j++) {
			if (i & (1 << j))
				cout << j + 1 << " ";
		}
		cout <<endl;
	}
}

int main() {

	print_subset(10,4);
	return 0;
}