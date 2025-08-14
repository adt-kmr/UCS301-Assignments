#include <iostream>
using namespace std;

/*Question 1: Menu driven array operations*/

#define SIZE 100

void createArray(int arr[], int &n) {
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

void displayArray(int arr[], int n) {
    if (n == 0) {
        cout << "Array is empty\n";
        return;
    }
    cout << "Array elements: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

void insertElement(int arr[], int &n) {
    int pos, val;
    cout << "Enter position (1 to " << n + 1 << "): ";
    cin >> pos;
    cout << "Enter value: ";
    cin >> val;
    if (pos < 1 || pos > n + 1) {
        cout << "Invalid position!\n";
        return;
    }
    for (int i = n; i >= pos; i--)
        arr[i] = arr[i - 1];
    arr[pos - 1] = val;
    n++;
}

void deleteElement(int arr[], int &n) {
    int pos;
    cout << "Enter position to delete (1 to " << n << "): ";
    cin >> pos;
    if (pos < 1 || pos > n) {
        cout << "Invalid position!\n";
        return;
    }
    for (int i = pos - 1; i < n - 1; i++)
        arr[i] = arr[i + 1];
    n--;
}

void linearSearch(int arr[], int n) {
    int key;
    cout << "Enter element to search: ";
    cin >> key;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Element found at position " << i + 1 << "\n";
            return;
        }
    }
    cout << "Element not found\n";
}

/*Question 2: Remove duplicate elements*/
void removeDuplicates(int arr[], int &n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n;) {
            if (arr[i] == arr[j]) {
                for (int k = j; k < n - 1; k++)
                    arr[k] = arr[k + 1];
                n--;
            } else {
                j++;
            }
        }
    }
}

/*Question 3: Predict output
Output will be: 1 0 0 0 0
Explanation: Only arr[0] = 1 is initialized, others default to 0.
*/

/*Question 4a: Reverse elements of an array*/
void reverseArray(int arr[], int n) {
    int start = 0, end = n - 1;
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

/*Question 4b: Matrix multiplication*/
void matrixMultiplication() {
    int r1, c1, r2, c2;
    cout << "Enter rows and cols for first matrix: ";
    cin >> r1 >> c1;
    cout << "Enter rows and cols for second matrix: ";
    cin >> r2 >> c2;

    if (c1 != r2) {
        cout << "Matrix multiplication not possible\n";
        return;
    }

    int A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE] = {0};

    cout << "Enter elements of first matrix:\n";
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            cin >> A[i][j];

    cout << "Enter elements of second matrix:\n";
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            cin >> B[i][j];

    // Multiply matrices
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            C[i][j] = 0;
            for (int k = 0; k < c1; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
    }

    cout << "Resultant Matrix:\n";
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++)
            cout << C[i][j] << " ";
        cout << "\n";
    }
}

/*Question 4c: Transpose of a matrix*/
void transposeMatrix() {
    int r, c;
    cout << "Enter rows and cols of matrix: ";
    cin >> r >> c;
    int A[SIZE][SIZE];
    cout << "Enter elements:\n";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> A[i][j];

    cout << "Transpose:\n";
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++)
            cout << A[j][i] << " ";
        cout << "\n";
    }
}

/*Question 5: Sum of rows and columns*/
void sumRowsAndCols() {
    int r, c;
    cout << "Enter rows and cols: ";
    cin >> r >> c;
    int A[SIZE][SIZE];
    cout << "Enter elements:\n";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> A[i][j];

    // Row sums
    cout << "Sum of rows:\n";
    for (int i = 0; i < r; i++) {
        int sum = 0;
        for (int j = 0; j < c; j++)
            sum += A[i][j];
        cout << "Row " << i + 1 << ": " << sum << "\n";
    }

    // Column sums
    cout << "Sum of columns:\n";
    for (int j = 0; j < c; j++) {
        int sum = 0;
        for (int i = 0; i < r; i++)
            sum += A[i][j];
        cout << "Column " << j + 1 << ": " << sum << "\n";
    }
}


