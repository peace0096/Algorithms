#include <iostream>
#include <stack>

using namespace std;
int P;


int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> P;

	for (int i = 0; i < P; i++)
	{
		int N;
		cin >> N;
		stack<int> s1;
		stack<int> s2;

		int a;
		cin >> a;
		s1.push(a);
		int cnt = 0;
		for (int j = 0; j < 19; j++)
		{
			cin >> a;
			
			// 앞 사람 키가 더 크다면
			while (!s1.empty() && s1.top() > a)
			{
				int t = s1.top();
				s1.pop();
				s2.push(t);
				cnt++;
			}
			s1.push(a);
			while (!s2.empty())
			{
				int t = s2.top();
				s2.pop();
				s1.push(t);
			}
		}

		cout << N << " " << cnt << '\n';


	}


	return 0;
}
