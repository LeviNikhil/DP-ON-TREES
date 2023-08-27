#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl

const ll N=100005;

ll n;
vector<ll>adj[N];

//https://www.desiqna.in/11504/uber-oa-hard-tree-coding-questions-and-solutions-kumar-k

vector<bool> isprime(N,true);
vector<bool> visited(N,false);
vector<ll> subtree_size(N,0);
vector<ll> upsubtree_size(N,0);

void sieve()
{
    ll i,j;
    isprime[0]=false;
    isprime[1]=false;

    for(ll i=2;i<=1e5;i++)
    {
        if(isprime[i])
        {
            for(ll j=i*i;j<=1e5;j+=i)
            {
                isprime[j]=false;
            }
        }
    }
}


int dfs(ll node,ll par)
{

    if(!isprime[node]) subtree_size[node]=1;
 
    for(auto it:adj[node])
    {
        if(it==par) continue;
        subtree_size[node]+=dfs(it,node);    
    }
    
    if(!isprime[node])
    {
        return  subtree_size[node];
    }
    else
    {
        return 0;
    }
}

void dfs2(ll node,ll par)
{
     int check=(isprime[node])? 0:subtree_size[node];

     upsubtree_size[node]=subtree_size[par]-check+upsubtree_size[par];

     if(isprime[par]) upsubtree_size[node]=0;

     for(auto it:adj[node])
     {
        if(it==par) continue;

        dfs2(it,node);    
     }
}


void solve()
{
    cin>>n;
    for(ll i=0;i<n-1;i++)
    {
        ll x,y;cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    dfs(1,0);
    subtree_size[0]=subtree_size[1];
    dfs2(1,0);
    ll ans=0;
    for(ll i=1;i<=n;i++)
    {
        if(isprime[i])
        {
             ans+=(subtree_size[i]+upsubtree_size[i]+upsubtree_size[i]*subtree_size[i]);
        }
    }
    cout<<ans<<"\n";
    visited.clear();
    subtree_size.clear();
}



int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    

    IOS;
    ll T;
    T=1;
    sieve();
    // cin >> T;
    while(T--){
    solve();
    }

    return 0;
}
