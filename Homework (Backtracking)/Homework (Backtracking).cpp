#include <iostream>
#include <vector>

using namespace std;

class Backtracking
{
private:
    int N, M;
    bool visited[20];
    vector<int> sequence;

public:
    Backtracking(int n, int m)
    {
        N = n;
        M = m;

        for (int i = 0; i <= N; i++)
        {
            visited[i] = false;
        }
    }

    void list(int count)
    {
        if (count == M)
        {
            for (int i = 0; i < sequence.size(); i++)
            {
                cout << sequence[i] << " ";
            }
            cout << endl;
            return;
        }

        for (int i = 1; i <= N; i++)
        {
            if (visited[i] == false)
            {
                visited[i] = true;

                sequence.push_back(i);

                list(count + 1);

                sequence.pop_back();

                visited[i] = false;
            }
        }
    }

};


int main()
{
#pragma region 퇴각 검색
	// 퇴각 검색, 혹은 Back tracking 알고리즘이라고 불립니다.
	// DFS(깊이 우선 탐색)를 기반으로 합니다.

	// 해를 찾기 위해 후보군을 DFS(깊이 우선 탐색) 방식으로 체크하다가,
	// 해당 후보군이 제약 조건을 만족할 수 없다고 판단되는 즉시
	// backtrack (다시는 이 후보군을 체크하지 않을 것을 표기)하고,
	// 바로 다른 후보군으로 넘어가며, 결국 최적의 해를 찾는 방법입니다. 

	// Promising : 해당 루트가 조건에 맞는지를 검사하는 기법
	// Pruning(가지치기) : 조건에 맞지 않으면 포기하고 다른 루트로 바로 돌아서서, 탐색의 시간을 절약하는 기법

    Backtracking backtracking(4, 2);
    backtracking.list(0);

#pragma endregion

	return 0;
}