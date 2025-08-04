#include <iostream>
using namespace std;

int main()
{
#pragma region 완전 탐색
    // 가능한 모든 경우의 수를 탐색하면서 결과를 찾아내는 알고리즘입니다.

    int password[3] = { 3, 5, 9 };
    int guess[3] = { 0, 0, 0 };

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (password[i] == j)
            {
                guess[i] = j;

                cout << guess[i] << " ";

                break;
            }
        }
    }
#pragma endregion


    int N, M;

    cin >> N >> M;

    int* card = new int[N];

    for (int i = 0; i < N; i++)
    {
        cin >> card[i];
    }

    int max = 0;

    // 카드가 모두 같은 경우를 제외해야 함

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                if (card[i] + card[j] + card[k] > max && card[i] + card[j] + card[k] <= M)
                {
                    max = card[i] + card[j] + card[k];
                }
            }
        }
    }

    cout << max;

    delete[] card;

    return 0;
}