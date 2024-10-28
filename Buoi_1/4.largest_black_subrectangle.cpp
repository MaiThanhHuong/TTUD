#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maximalRectangle(vector<vector<int>> &matrix)
{
    if (matrix.empty() || matrix[0].empty())
    {
        return 0;
    }

    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> left(n, 0);
    vector<int> right(n, n);
    vector<int> height(n, 0);
    int maxArea = 0;

    for (const auto &row : matrix)
    {
        int curLeft = 0, curRight = n;

        // Update height array
        for (int j = 0; j < n; j++)
        {
            if (row[j] == 1)
            {
                height[j]++;
            }
            else
            {
                height[j] = 0;
            }
        }

        // Update left boundary array
        for (int j = 0; j < n; j++)
        {
            if (row[j] == 1)
            {
                left[j] = max(left[j], curLeft);
            }
            else
            {
                left[j] = 0;
                curLeft = j + 1;
            }
        }

        // Update right boundary array
        for (int j = n - 1; j >= 0; j--)
        {
            if (row[j] == 1)
            {
                right[j] = min(right[j], curRight);
            }
            else
            {
                right[j] = n;
                curRight = j;
            }
        }

        // Calculate maximum area for each cell
        for (int j = 0; j < n; j++)
        {
            maxArea = max(maxArea, (right[j] - left[j]) * height[j]);
        }
    }

    return maxArea;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }

    cout << maximalRectangle(v) << endl;

    return 0;
}
