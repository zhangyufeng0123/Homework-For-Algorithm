#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = (int) 1e3 + 100;
int dp[maxn][maxn];
int len, n;

void lcs(string a, string b){
    len = 0;
    int lena = a.length(), lenb = b.length();
    for(int i = 1; i <= lena; i++){
        for(int j = 1; j <= lenb; j++){
            if(a[i - 1] == b[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    len = dp[lena][lenb];
}

int main(void) {
#ifdef ACM_LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string a, b;
    cin >> a >> b;
    lcs(a, b);
    cout << len << endl;
}