#include <iostream>

using namespace std;

int change(int money)
{
	int count = 0;

	while (money != 0)
	{
		if (1000 <= money)
		{
			money -= 1000;
		}
		else if (500 <= money)
		{
			money -= 500;
		}
		else if (100 <= money)
		{
			money -= 100;
		}
		else if (50 <= money)
		{
			money -= 50;
		}
		else if (10 <= money)
		{
			money -= 10;
		}

		count++;
	}

	return count;
}

int main()
{
#pragma region 탐욕법
	// 최적의 해를 구하는 데에 사용되는 근사적인 방법으로 여러 경우 중
	// 하나를 검색해야 할 때마다 그 순간에 최적이라고 생각되는 것을
	// 선택해 나가는 방식으로 진행하여 최종적인 해답을 구하는 알고리즘입니다.

	// 1. 탐욕 선택 속성
	// 각 단계에서 '최적의 선택'을 했을 때 전테 문제에 대한
	// 최적의 해를 구할 수 있는 경우입니다.

	// 2. 최적 부분 구조
	// 전체 문제의 최적의 해가 '부분 문제의 최적의 해'로 구성될 수 있는 경우입니다.

	// 탐욕 알고리즘으로 문제를 해결하는 방법

	// 1. 선택 절차 (Selection Procedure)
	// 현재 상태에서의 최적의 해답을 선택합니다.

	// 2. 적절성 검사 (Feasibility Check)
	// 선택된 해가 문제의 조건을 만족하는지 검사합니다.

	// 3. 해답 검사 (Solution Check)
	// 원래의 문제가 해결되었는지 검사하고, 해결되지 않았다면
	// 선택 절차로 돌아가 위의 과정을 반복합니다.

	int n = 1370;
	cout << "count : " << change(n) << endl;

#pragma endregion


	return 0;
}