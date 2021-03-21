 #include<bits/stdc++.h>
//define method
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define f first
#define s second
#define mp make_pair
#define inf 1e9

//using
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<int,int>;
using namespace std;


const int mx = 1e5+123;
bool vis[mx];
int col[mx];
vector<int> adj[mx];

bool dfs ( int node,int c )
{
    vis[node] =  true;
    col[node]=c;
    for ( auto neighbour : adj[node] ) {
        if ( !vis[neighbour] ) {

          bool res =  dfs ( neighbour, c ^ 1);
           if(res == false) return false;
        }
        else {
            if(col[node]==col[neighbour])return false;
        }
    }
    return true;

}

int main( ){
    int t,n,m,a,b;
    cin>>t;
    for(int tc=1;tc<=t;tc++){
        cin>>n>>m;
        for(int i=1;i<=n;i++)adj[i].clear(),vis[i]=0;
        for(int i=1;i<=m;i++)
        cin>>a>>b, adj[a].pb(b), adj[b].pb(a);

        bool flag = true;
        for(int i=1;i<=n;i++)
        if(vis[i] == 0){
            bool res = dfs(i, 0);
            if(res==false)flag=false;
        }
        cout<<"Scenario #"<<tc<<":"<<endl;
        if(flag == false)cout<<"Suspicious bugs found!"<<endl;
        else cout<<"No suspicious bugs found!"<<endl;
    }

    return 0;
}
