#include <iostream>
using namespace std;


void sieve(int n)
{
	int* arr = new int[n + 1];

	for (int i = 0; i <= n; i++)
	{
		arr[i] = i;
	}

	for (int i = 2; i <= sqrt(n); i++)
	{
		if (arr[i] == 0)
		{
			continue;
		}

		for (int j = i * 2; j <= n; j += i)
		{
			arr[j] = 0;
		}
	}

	for (int i = 2; i <= n; i++)
	{
		if (arr[i] != 0)
		{
			cout << arr[i] << " ";
		}
	}

	delete[] arr;
}

int main()
{
#pragma region 에라토스테네스의 체

	sieve(50);

#pragma endregion




	return 0;
}