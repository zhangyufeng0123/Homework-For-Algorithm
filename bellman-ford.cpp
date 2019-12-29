#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = INT_MAX;
const int maxn = 100;
int u[maxn], v[maxn], w[maxn], dis[maxn];
int n, m, ck, flag;

void bellman(int s){
    for(int i = 1; i <= n; i++){
        dis[i] = INF;
    }
    dis[s] = 0;
    for(int i = 1; i <= n - 1; i++){
        ck = 0;
        for(int j = 1; j <= m; j++){
            if(dis[v[i]] > dis[u[i]] + w[i]){
                dis[v[i]] = dis[u[i]] + w[i];
                ck = 1;
            }
        }
        if(!ck){
            break;
        }
    }
    for(int i = 1; i <= m; i++){
        if(dis[v[i]] > dis[u[i]] + w[i]){
            flag = 1;
        }
    }
}

void solve(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> u[i] >> v[i] >> w[i];
    }
    int s, t;
    cin >> s >> t;
    bellman(s);
    if(flag){
        cout << "包含负权回路" << endl;
    }else{
        cout << dis[t] << endl;
    }
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