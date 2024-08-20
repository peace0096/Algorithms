#include <iostream>

using namespace std;

int N;
int nums[11];
int operators[4];

int cal_min;
int cal_max;

int Cal_Max(int result, int idx, int plus, int minus, int multiple, int divide)
{

	if (idx >= N)
	{
		return result;
	}

	int result_cal = -1000000000;
	
	if (plus > 0)
	{
		int result_plus = Cal_Max(result + nums[idx], idx + 1, plus - 1, minus, multiple, divide);
		result_cal = max(result_plus, result_cal);
	}
	if (minus > 0)
	{
		int result_plus = Cal_Max(result - nums[idx], idx + 1, plus, minus - 1, multiple, divide);
		result_cal = max(result_plus, result_cal);
	}
	if (multiple > 0)
	{
		int result_plus = Cal_Max(result * nums[idx], idx + 1, plus, minus, multiple - 1, divide);
		result_cal = max(result_plus, result_cal);
	}
	if (divide > 0)
	{
		int result_plus = Cal_Max(result / nums[idx], idx + 1, plus, minus, multiple, divide-1);
		result_cal = max(result_plus, result_cal);
	}

	return result_cal;
}

int Cal_Min(int result, int idx, int plus, int minus, int multiple, int divide)
{

	if (idx >= N)
	{
		return result;
	}

	int result_cal = 1000000000;
	
	if (plus > 0)
	{
		int result_plus = Cal_Min(result + nums[idx], idx + 1, plus - 1, minus, multiple, divide);
		result_cal = min(result_plus, result_cal);
	}
	if (minus > 0)
	{
		int result_plus = Cal_Min(result - nums[idx], idx + 1, plus, minus - 1, multiple, divide);
		result_cal = min(result_plus, result_cal);
	}
	if (multiple > 0)
	{
		int result_plus = Cal_Min(result * nums[idx], idx + 1, plus, minus, multiple - 1, divide);
		result_cal = min(result_plus, result_cal);
	}
	if (divide > 0)
	{
		int result_plus = Cal_Min(result / nums[idx], idx + 1, plus, minus, multiple, divide-1);
		result_cal = min(result_plus, result_cal);
	}

	return result_cal;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
	}

	for (int i = 0; i < 4; i++)
	{
		cin >> operators[i];
	}

	cout << Cal_Max(nums[0], 1, operators[0], operators[1], operators[2], operators[3]) << '\n';
	cout << Cal_Min(nums[0], 1, operators[0], operators[1], operators[2], operators[3]);
	

	return 0;
}
