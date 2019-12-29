#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int INF = INT_MAX;
const int maxn = int(1e4);

struct edge{
    int to, cost;
};

int num_v;
vector<edge> G[maxn];
int d[maxn];
bool used[maxn];

int n, m, S, T;
int dijkstra(int s, int t){
    priority_queue<P,vector<P>, greater<P>> que;
    fill(d + 1, d + num_v + 1, INT_MAX);
    d[s] = 0;
    que.push(P(0, s));
    while(!que.empty()){
        P p = que.top();
        que.pop();
        int v = p.second;
        if(d[v] < p.first || used[v]){
            continue;
        }
        used[v] = true;
        for(int i = 0; i < G[v].size(); i++){
            edge e = G[v][i];
            if(d[e.to] > d[v] + e.cost){
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
    return d[t];
}

void solve(){
    cin >> n >> m;
    //n是点的数量，m是边的数量
    if(!n || !m){
        cout << "error" << endl;
    }
    num_v = n;
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        G[a].push_back(edge{b, c});
        G[b].push_back(edge{a, c});
    }
    int ans = dijkstra(1, n);
    if(ans == INT_MAX){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
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