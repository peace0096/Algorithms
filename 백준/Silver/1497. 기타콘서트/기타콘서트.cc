#include <iostream>
#include <string>
using namespace std;

int N, M;

long long guita[50] = { 0, };

int bit_cnt(long long result)
{
	int ret = 0;

	for (int i = 0; i < max(N, M); i++)
	{
		ret += (result >> i) & 1;
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		string l, content;
		cin >> l >> content;

		for (int j = M - 1; j >= 0; j--)
		{
			guita[i] = (guita[i] << 1) | (content[j] == 'Y');
		}

	}

	pair<int, int> ans = { 0, -1 };
	for (int now = 0; now < (1 << N); now++)
	{
		long long result = 0;
		for (int i = 0; i < M; i++)
		{
			if ((now & (1LL << i)) == 0) 
				continue;
			result |= guita[i];
		}
		int song = bit_cnt(result);
		int guita_num = bit_cnt(now);

		if (ans.first < song)
		{
			ans = { song, guita_num };
		}
		
		else if (ans.first == song && ans.second > guita_num)
		{
			ans = { song, guita_num };
		}

	}
	cout << ans.second;


	return 0;
}


