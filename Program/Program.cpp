#include <iostream>
#include <cmath>
using namespace std;


void sieve(int n)
{


	int* arr = new int[n];

	for (int i = 0; i < n; i++)
	{
		arr[i] = i + 1;

		if (i == 0)
		{
			arr[i] = 0;
		}
		else
		{
			for (int j = 2; j < sqrt(n); j++)
			{
				if (arr[i] == j)
				{
					break;
				}
				if (arr[i] % j == 0)
				{
					arr[i] = 0;
				}
			}
		}
	}
	
	for (int i = 0; i < n; i++)
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