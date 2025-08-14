#include <iostream>
#include <string>

using namespace std;

/*Question 1: Binary Search*/
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

/*Question 2: Bubble Sort*/
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

/*Question 3: Missing Number*/
int findMissingNumber(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i + 1] - arr[i] != 1)
            return arr[i] + 1;
    }
    return -1;
}

/*Question 4: String Operations*/
// (a) Concatenate
string concatenateStrings(string s1, string s2) {
    return s1 + s2;
}
// (b) Reverse
string reverseString(string s) {
    string rev = s;
    reverse(rev.begin(), rev.end());
    return rev;
}
// (c) Remove vowels
string removeVowels(string s) {
    string result = "";
    for (char c : s) {
        if (!(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
              c=='A'||c=='E'||c=='I'||c=='O'||c=='U'))
            result += c;
    }
    return result;
}
// (d) Sort strings
void sortStrings(vector<string> &arr) {
    sort(arr.begin(), arr.end());
}
// (e) Uppercase to lowercase
char toLowerChar(char c) {
    if (c >= 'A' && c <= 'Z')
        return c + 32;
    return c;
}

/*Question 5: Space Efficient Matrix Storage*/
// a) Diagonal Matrix
class DiagonalMatrix {
    int n;
    int *arr; // store only diagonal elements
public:
    DiagonalMatrix(int size) {
        n = size;
        arr = new int[n];
        for (int i = 0; i < n; i++) arr[i] = 0;
    }
    void set(int i, int j, int value) {
        if (i == j) arr[i - 1] = value;
    }
    int get(int i, int j) {
        if (i == j) return arr[i - 1];
        return 0;
    }
    ~DiagonalMatrix() { delete[] arr; }
};

// b) Tri-diagonal Matrix
class TriDiagonalMatrix {
    int n;
    int *arr; // size = 3n - 2
public:
    TriDiagonalMatrix(int size) {
        n = size;
        arr = new int[3*n - 2];
        for (int i = 0; i < 3*n - 2; i++) arr[i] = 0;
    }
    void set(int i, int j, int value) {
        if (i - j == 1) arr[i - 2] = value;         // lower diagonal
        else if (i - j == 0) arr[n - 1 + i - 1] = value; // main diagonal
        else if (i - j == -1) arr[2*n - 1 + i - 1] = value; // upper diagonal
    }
};

// c) Lower triangular Matrix
class LowerTriangularMatrix {
    int n;
    int *arr; // size = n*(n+1)/2
public:
    LowerTriangularMatrix(int size) {
        n = size;
        arr = new int[n*(n+1)/2];
    }
    void set(int i, int j, int value) {
        if (i >= j) arr[(i*(i-1))/2 + (j-1)] = value;
    }
};

// d) Upper triangular Matrix
class UpperTriangularMatrix {
    int n;
    int *arr;
public:
    UpperTriangularMatrix(int size) {
        n = size;
        arr = new int[n*(n+1)/2];
    }
    void set(int i, int j, int value) {
        if (i <= j) arr[(j*(j-1))/2 + (i-1)] = value;
    }
};

// e) Symmetric Matrix
class SymmetricMatrix {
    int n;
    int *arr;
public:
    SymmetricMatrix(int size) {
        n = size;
        arr = new int[n*(n+1)/2];
    }
    void set(int i, int j, int value) {
        if (i >= j) arr[(i*(i-1))/2 + (j-1)] = value;
        else arr[(j*(j-1))/2 + (i-1)] = value;
    }
};

/*Question 6: Sparse Matrix (Triplet)*/
struct Term {
    int row, col, value;
};
class SparseMatrix {
    vector<Term> terms;
    int rows, cols;
public:
    SparseMatrix(int r, int c) {
        rows = r;
        cols = c;
    }
    void addTerm(int r, int c, int val) {
        if (val != 0) {
            terms.push_back({r, c, val});
        }
    }
    void display() {
        for (auto &t : terms) {
            cout << "(" << t.row << "," << t.col << "," << t.value << ") ";
        }
        cout << "\n";
    }
    // a) Transpose
    SparseMatrix transpose() {
        SparseMatrix trans(cols, rows);
        for (int i = 0; i < cols; i++) {
            for (auto &t : terms) {
                if (t.col == i)
                    trans.addTerm(t.col, t.row, t.value);
            }
        }
        return trans;
    }
    // b) Addition
    static SparseMatrix add(SparseMatrix &A, SparseMatrix &B) {
        SparseMatrix result(A.rows, A.cols);
        int i = 0, j = 0;
        while (i < A.terms.size() && j < B.terms.size()) {
            if (A.terms[i].row == B.terms[j].row && A.terms[i].col == B.terms[j].col) {
                result.addTerm(A.terms[i].row, A.terms[i].col, A.terms[i].value + B.terms[j].value);
                i++; j++;
            } else if (A.terms[i].row < B.terms[j].row || (A.terms[i].row == B.terms[j].row && A.terms[i].col < B.terms[j].col)) {
                result.addTerm(A.terms[i].row, A.terms[i].col, A.terms[i].value);
                i++;
            } else {
                result.addTerm(B.terms[j].row, B.terms[j].col, B.terms[j].value);
                j++;
            }
        }
        while (i < A.terms.size()) {
            result.addTerm(A.terms[i].row, A.terms[i].col, A.terms[i].value);
            i++;
        }
        while (j < B.terms.size()) {
            result.addTerm(B.terms[j].row, B.terms[j].col, B.terms[j].value);
            j++;
        }
        return result;
    }
};

/*Question 7: Count Inversions*/
int countInversions(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j])
                count++;
        }
    }
    return count;
}

/*Question 8: Count Distinct*/
int countDistinct(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                found = true;
                break;
            }
        }
        if (!found)
            count++;
    }
    return count;
}


