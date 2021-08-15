#include <bits/stdc++.h>

#define endl '\n';
using namespace std;
typedef long long ll;
typedef stringstream sstream;
const double eps = 1e-7;
const auto FAST = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0));

int main() {
	int k = 0, n = 1e7;
	clock_t start, end;
	start = clock();
	for (int i = 0;i < n;i++) k++;
	end = clock();
	cout << (double)(end - start) / CLOCKS_PER_SEC << endl;

	return 0;
}