/**
 * @Author hjl
 * @Date 2021年8月16日
 */

#include <bits/stdc++.h>

#define endl '\n'
#define ll long long
#define sstream stringstream
using namespace std;
const double eps = 1e-7;
const auto FAST = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0));

int main()
{
	int T, n, B;
	int i = 0;
	cout << setiosflags(ios::fixed) << setprecision(2);
	while (cin >> T >> n >> B)
	{
		i++;
		if (T && n && B)
		{
			double sum = 0;
			double S;
			int P;
			while (T--)
			{
				cin >> S >> P;
				sum += S * (100 - P) / 100;
			}
			cout << "Case " << i << ": " << sum / B << endl << endl;
		}
	}
	return 0;
}