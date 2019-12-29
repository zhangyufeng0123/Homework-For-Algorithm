#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = INT_MAX;

int mapp[7][7], ans[7][7];
int judge[7];
int dis[7];
int n = 6;

void init(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            mapp[i][j] = INF;
        }
    }
    mapp[1][2] = mapp[2][1] = 10;
    mapp[1][4] = mapp[4][1] = 30;
    mapp[1][5] = mapp[5][1] = 45;
    mapp[2][5] = mapp[5][2] = 40;
    mapp[2][6] = mapp[6][2] = 25;
    mapp[4][6] = mapp[6][4] = 20;
    mapp[5][3] = mapp[3][5] = 35;
    mapp[5][6] = mapp[6][5] = 55;
    mapp[3][6] = mapp[6][3] = 15;
    mapp[2][3] = mapp[3][2] = 50;
}

int prim(){
    int sum = 0;
    for(int i = 1; i <= n; i++){
        dis[i] = INF;
    }
    for(int i = 1; i <= n; i++){
        dis[i] = mapp[i][1];
    }
    dis[1] = 0;
    judge[1] = 1;
    int i;
    for(i = 1; i <= n; i++){
        int now = INF;
        int min1 = INF;
        for(int j = 1; j <= n; j++){
            if(!judge[j] && dis[j] < min1){
                now = j;
                min1 = dis[j];
            }
        }
        if(now == INF){
            break;
        }
        judge[now] = 1;
        sum += min1;
        for(int j = 1; j <= n; j++){
            if(!judge[j] && dis[j] > mapp[now][j]){
                dis[j] = mapp[now][j];
            }
        }
    }
    if(i < n){
        return -1;
    }else{
        return sum;
    }
}

void solve(){
    init();
    cout << prim() << endl;
}

int main(void) {
#ifdef ACM_LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
}