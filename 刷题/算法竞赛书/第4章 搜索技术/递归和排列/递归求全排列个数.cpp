/**
 * @Author hjl
 * @Date 2021年8月22日11:44:28
 */

#include <bits/stdc++.h>

#define Swap(a,b) {int t=a;a=b;b=t;}
#define endl '\n'
#define ll long long
#define sstream stringstream
using namespace std;
const double eps = 1e-7;
const auto FAST = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0));

int a[] = { 0,1,2,3,4,5,6,7,8,9,10,11 };

int num = 0;


void Perm(int begin, int end) {
	int i;
	if (begin == end)
		num++;
	else {
		for (i = begin;i <= end;i++) {
			Swap(a[begin], a[i]);
			Perm(begin + 1, end);
			Swap(a[begin], a[i]);
		}
	}
}

int main() {
	clock_t s, e;
	s = clock();
	Perm(0, 11);
	e = clock();
	cout << double(e - s) / CLOCKS_PER_SEC << endl;
	return 0;
}