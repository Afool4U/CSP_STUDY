/**
 * @Author hjl
 * @Date 2021年8月17日15:23:44
 */

#include <bits/stdc++.h>

#define endl '\n'
#define ll long long
#define sstream stringstream
using namespace std;
const double eps = 1e-7;
const auto FAST = (ios::sync_with_stdio(0), cin.tie(0), cout.tie(0));

int getPr(char ch) {
	if (ch == '+' || ch == '-')
		return 0;
	else if (ch == '*' || ch == '/')
		return 1;
}

int main() {

	string line;

	while (getline(cin, line)) {
		if (line == "0")
			break;
		int index = 0;
		while ((index = line.find(' ', index)) != line.npos) {
			line.erase(index, 1);
		}
		stack<char> opt;
		deque<string> rpn;
		sstream ss(line);
		while (!ss.eof()) {
			if (isdigit(ss.peek())) {
				int n;
				ss >> n;
				rpn.push_back(to_string(n));
			}
			else {
				char op = ss.get();
				if (!opt.empty())
					while (!opt.empty() && getPr(op) <= getPr(opt.top())) {
						char temp[2] = { opt.top() };
						rpn.push_back(string(temp));
						opt.pop();
					}
				opt.push(op);
			}
		}
		while (!opt.empty()) {
			char temp[2] = { opt.top() };
			rpn.push_back(string(temp));
			opt.pop();
		}

		stack<double>num;
		while (!rpn.empty()) {
			string str = *rpn.begin();
			rpn.pop_front();
			if (isdigit(str[0]))
				num.push(atoi(str.c_str()));
			else {
				double b = num.top();
				num.pop();
				double a = num.top();
				num.pop();
				switch (str[0]) {
				case '+':
					num.push(a + b);
					break;
				case '-':
					num.push(a - b);
					break;
				case '*':
					num.push(a * b);
					break;
				case '/':
					num.push(a / b);
					break;
				}
			}
		}
		cout << fixed << setprecision(2) << num.top() << endl;
	}
	return 0;
}