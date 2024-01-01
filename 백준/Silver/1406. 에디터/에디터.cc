#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	stack<char> s1;
	stack<char> s2;
	string str;
	int n;
	string ans;

	cin >> str;
	cin >> n;
	for (int i = 0; i < str.length(); i++) {
		s1.push(str[i]);
	}
	
	
	for (int i = 0; i < n; i++) {
		cin >> ans;
		if (ans == "L") {
			if (s1.empty())
				continue;
			char e = s1.top();
			s1.pop();
			s2.push(e);
		}
		else if (ans == "D") {
			if (s2.empty())
				continue;
			char e = s2.top();
			s2.pop();
			s1.push(e);
		}

		else if (ans == "B") {
			if (s1.empty())
					continue;
			s1.pop();
		}
		else if (ans == "P") {
			char e;
			cin >> e;
			s1.push(e);
			
		}

	}
	while (!s1.empty()) {
		s2.push(s1.top());
		s1.pop();

	}

	while (!s2.empty()) {
		cout << s2.top();
		s2.pop();

	}
	
	

	return 0;
}