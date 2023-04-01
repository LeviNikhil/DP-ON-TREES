#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x) cout << #x << "=" << x << "\n"
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << "\n"

const ll mod=1e9+7;

vector<vector<ll>>tree(200005);

vector<ll>max_depth(200005);
vector<ll>max_up(200005);

void dfs_maxdepth(ll node)
{
     max_depth[node]=0;
     for(ll child:tree[node])
     {
        tree[child].erase(find(tree[child].begin(),tree[child].end(),node));
        dfs_maxdepth(child);
        max_depth[node]=max(max_depth[node],max_depth[child]+1);
     }
}

void dfs_max_up(ll node)
{
    sort(tree[node].begin(),tree[node].end(),[&](auto u,auto v)
    {
        return max_depth[u]<max_depth[v];
    });

    for(ll child:tree[node])
    {
        max_up[child]=max(max_up[child],1+max_up[node]);

        if(child!= end(tree[node])[-1])
        {
            max_up[child]=max(max_up[child],2+max_depth[end(tree[node])[-1]]);
        }
        else if(tree[node].size()>1)
        {
            max_up[child]=max(max_up[child],2+max_depth[end(tree[node])[-2]]);
        }

        dfs_max_up(child);
    }
}

void solve(){
      ll n;cin>>n;
      
      for(ll i=0;i<n-1;i++)
      {
         ll u,v;cin>>u>>v;
         tree[u].push_back(v);
         tree[v].push_back(u);
      }

      dfs_maxdepth(1);

      max_up[1]=0;

      dfs_max_up(1);

      // for(ll i=1;i<=n;i++)
      // {
      //     cout<<i<<" "<<max_depth[i]<<endl;
      // }
      // for(ll i=1;i<=n;i++)
      // {
      //     cout<<i<<" "<<max_up[i]<<endl;
      // }

      for(ll i=1;i<=n;i++)
      {
          cout<<max(max_up[i],max_depth[i])<<endl;
      }


    }




int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    

    IOS;
    // pre();
    ll T;
    T=1;
    // cin >> T;
    while(T--){
    solve();
    }

    return 0;
}
