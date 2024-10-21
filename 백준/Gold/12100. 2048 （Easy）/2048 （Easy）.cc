#include <iostream>
#include <vector>
using namespace std;

int N;
int board[20][20];
int dir[5];

// 상:1 하:2 좌:3 우:4
// 반환 값 : DFS 시행 결과 블록들 중, 가장 큰 숫자
int DFS(int move_cnt)
{
	int max_block = 0;

	if (move_cnt == 5)
	{
		// 5번 모두 움직였다면, 깊은 복사 ㄱㄱ
		int new_board[20][20];
		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
		{
			new_board[i][j] = board[i][j];
			max_block = max(new_board[i][j], max_block);
		}

		// 움직인다.
		for (auto direct : dir)
		{
			if (direct == 1)
			{
				bool merged[20][20] = { false, };
				// 위로
				for (int i = 1; i < N; i++)
				{
					for (int j = 0; j < N; j++)
					{
						if (new_board[i][j] != 0)
						{
							int temp = new_board[i][j];
							// 블록 합체
							for (int k = i - 1; k >= 0; k--)
							{
								if (new_board[k][j] == 0)
								{
									// 만약 0이면 위로 블록 이동
									new_board[k][j] = temp;
									new_board[k + 1][j] = 0;
								}
								else
								{
									// 블록 발견
									if (!merged[k][j] && new_board[k][j] == temp)
									{

										// 같은 블록이면 합친다.
										merged[k][j] = true;
										new_board[k][j] *= 2;
										new_board[k + 1][j] = 0;
										max_block = max(new_board[k][j], max_block);
										//temp = new_board[k][j];
									}
									else
									{
										break;
									}
								}
							}
						}
					}
				}
			}
			else if (direct == 2)
			{
				bool merged[20][20] = { false, };
				// 아래로
				for (int i = N - 2; i >= 0; i--)
				{
					for (int j = 0; j < N; j++)
					{
						if (new_board[i][j] != 0)
						{
							int temp = new_board[i][j];
							// 블록 합체
							for (int k = i + 1; k < N; k++)
							{
								if (new_board[k][j] == 0)
								{
									// 만약 0이면 위로 블록 이동
									new_board[k][j] = temp;
									new_board[k - 1][j] = 0;
								}
								else
								{
									// 블록 발견
									if (!merged[k][j] && new_board[k][j] == temp)
									{

										// 같은 블록이면 합친다.
										merged[k][j] = true;
										new_board[k][j] *= 2;
										new_board[k - 1][j] = 0;
										max_block = max(new_board[k][j], max_block);
										//temp = new_board[k][j];
									}
									else
									{
										break;
									}
								}
							}
						}
					}
				}
			}
			else if (direct == 4)
			{
				bool merged[20][20] = { false, };
				// 오른쪽으로
				for (int i = 0; i < N; i++)
				{
					for (int j = N - 2; j >= 0; j--)
					{
						if (new_board[i][j] != 0)
						{
							int temp = new_board[i][j];
							// 블록 합체
							for (int k = j + 1; k < N; k++)
							{
								if (new_board[i][k] == 0)
								{
									// 만약 0이면 위로 블록 이동
									new_board[i][k] = temp;
									new_board[i][k - 1] = 0;
								}
								else
								{
									// 블록 발견
									if (!merged[i][k] && new_board[i][k] == temp)
									{
										// 같은 블록이면 합친다.
										merged[i][k] = true;
										new_board[i][k] *= 2;
										new_board[i][k - 1] = 0;
										max_block = max(new_board[i][k], max_block);
										//temp = new_board[i][k];
									}
									else
									{
										break;
									}
								}
							}
						}
					}
				}
			}
			else if (direct == 3)
			{
				bool merged[20][20] = { false, };
				// 왼쪽으로
				for (int i = 0; i < N; i++)
				{
					for (int j = 1; j < N; j++)
					{
						if (new_board[i][j] != 0)
						{
							int temp = new_board[i][j];
							// 블록 합체
							for (int k = j - 1; k >= 0; k--)
							{
								if (new_board[i][k] == 0)
								{
									// 만약 0이면 위로 블록 이동
									new_board[i][k] = temp;
									new_board[i][k + 1] = 0;
								}
								else
								{
									// 블록 발견
									if (!merged[i][k] && new_board[i][k] == temp)
									{

										// 같은 블록이면 합친다.
										merged[i][k] = true;
										new_board[i][k] *= 2;
										new_board[i][k + 1] = 0;
										max_block = max(new_board[i][k], max_block);
										//temp = new_board[i][k];
									}
									else
									{
										break;
									}
								}
							}
						}
					}
				}
			}
		}

		return max_block;
	}

	// 위로
	dir[move_cnt] = 1;
	max_block = max(max_block, DFS(move_cnt + 1));
	dir[move_cnt] = 0;

	// 아래로
	dir[move_cnt] = 2;
	max_block = max(max_block, DFS(move_cnt + 1));
	dir[move_cnt] = 0;

	// 왼쪽
	dir[move_cnt] = 3;
	max_block = max(max_block, DFS(move_cnt + 1));
	dir[move_cnt] = 0;

	// 오른쪽
	dir[move_cnt] = 4;
	max_block = max(max_block, DFS(move_cnt + 1));
	dir[move_cnt] = 0;

	return max_block;


}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
	{
		cin >> board[i][j];
	}

	cout << DFS(0);


	return 0;
}


