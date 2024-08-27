#include <iostream>
using namespace std;

int main()
{
    int n, m, p, q;
    cout << "Enter number of rows and columns for 1st matrix: ";
    cin >> n >> m;

    cout << "Enter number of rows and columns for 2nd matrix: ";
    cin >> p >> q;

    if (m != p) {
        cout << "Matrix multiplication not possible. Number of columns in 1st matrix must be equal to number of rows in 2nd matrix." << endl;
        return 1;
    }

    int matrix1[20][20], matrix2[20][20], result[20][20] = {0};

    cout << "Enter elements for 1st matrix:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix1[i][j];
        }
    }

    cout << "Enter elements for 2nd matrix:" << endl;
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < q; j++)
        {
            cin >> matrix2[i][j];
        }
    }

    // Perform matrix multiplication
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < q; ++j) {
            result[i][j] = 0; // Initialize result matrix element to 0
            for (int k = 0; k < m; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    cout << "The resulting matrix is:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < q; ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
