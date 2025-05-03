#include <iostream>
#include <climits>
using namespace std;

int sum(int frequency[], int i, int j) {
    int total = 0;
    for (int x = i; x <= j; x++)
        total += frequency[x];
    return total;
}

int optimalSearchTree(int keys[], int frequency[], int n) {

    int dp[n][n];

    for (int i = 0; i < n; i++) {
        dp[i][i] = frequency[i];
    }

    for (int length = 2; length <= n; length++) {
        for (int i = 0; i <= n - length; i++) {
            int j = i + length - 1;
            int frequencySum = sum(frequency, i, j);

            dp[i][j] = INT_MAX;

            for (int r = i; r <= j; ++r) {
                int cost = ((r > i) ? dp[i][r - 1] : 0) + ((r < j) ? dp[r + 1][j] : 0);
                dp[i][j] = min(dp[i][j], cost + frequencySum);
            }
        }
    }
    return dp[0][n - 1];
}

int main() {
    int n;
    cout << "Enter the number of keys: ";
    cin >> n;
    
    int keys[n], frequency[n];
    
    cout << "Enter the keys: ";
    for (int i = 0; i < n; i++) {
        cin >> keys[i];
    }
    
    cout << "Enter the frequencies: ";
    for (int i = 0; i < n; i++) {
        cin >> frequency[i];
    }
    
    cout << "Cost of Optimal BST is " << optimalSearchTree(keys, frequency, n) << endl;
    return 0;
}
