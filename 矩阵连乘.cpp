#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = int(1e3 + 100);

int p[maxn];
int matrix[maxn][maxn], s[maxn][maxn];
int n;

void matrixchain() {
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= n - i + 1; j++) {
            int k = i + j - 1;
            matrix[j][k] = matrix[j + 1][k] + p[j - 1] * p[j] * p[k];
            s[j][k] = j;
            for (int e = j + 1; e < k; e++) {
                int t = matrix[j][e] + matrix[e + 1][k] + p[j - 1] * p[j] * p[k];
                if (t < matrix[j][k]) {
                    matrix[j][k] = t;
                    s[j][k] = e;
                }
            }
        }
    }
}

void print(int i, int j) {
    if (i == j) {
        cout << "A[" << i << "]";
        return;
    }
    cout << "(";
    print(i, s[i][j]);
    print(s[i][j] + 1, j);
    cout << ")";
}

int main(void) {
#ifdef ACM_LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i <= n; i++) {
        cin >> p[i];
    }
    matrixchain();
    print(1, n);
    cout << endl;
    cout << matrix[1][n] << endl;
}