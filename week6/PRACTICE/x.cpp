#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> matrix;

int maxPathSum(int i, int j)
{
    
    if (i == N - 1 && j == M - 1)
    {
        return matrix[i][j];
    }

    int max_sum = -INT_MAX;

    if (i + 1 < N)
    {
        max_sum = max(max_sum, maxPathSum(i + 1, j));
    }

    if (j + 1 < M)
    {
        max_sum = max(max_sum, maxPathSum(i, j + 1));
    }

    max_sum += matrix[i][j];

    return max_sum;
}

int main()
{
    cin >> N >> M;
    matrix.resize(N, vector<int>(M));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> matrix[i][j];
        }
    }


    int result = maxPathSum(0, 0);
    cout << result << endl;

    return 0;
}
