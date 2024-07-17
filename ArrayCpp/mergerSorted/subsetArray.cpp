#include <iostream>
using namespace std;

void solve(int nums[], int numsSize, int output[], int outputSize, int index, int ans[][100], int &ansIndex) {
    if (index >= numsSize) {
        for (int i = 0; i < outputSize; i++) {
            ans[ansIndex][i] = output[i];
        }
        ans[ansIndex][outputSize] = -1; // Using -1 as a marker for the end of the subset
        ansIndex++;
        return;
    }

    // Exclude the current element and move to the next
    solve(nums, numsSize, output, outputSize, index + 1, ans, ansIndex);

    // Include the current element in the subset and move to the next
    output[outputSize] = nums[index];
    solve(nums, numsSize, output, outputSize + 1, index + 1, ans, ansIndex);
}

void subsets(int nums[], int numsSize, int ans[][100], int &ansIndex) {
    int output[100]; // Temporary array to store current subset
    solve(nums, numsSize, output, 0, 0, ans, ansIndex);
}

int main() {
    int nums[] = {1, 2, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int ans[100][100]; // Array to store all subsets
    int ansIndex = 0; // Index to keep track of the number of subsets

    subsets(nums, numsSize, ans, ansIndex);

    // Printing all subsets
    for (int i = 0; i < ansIndex; i++) {
        cout << "{ ";
        for (int j = 0; ans[i][j] != -1; j++) {
            cout << ans[i][j] << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}
