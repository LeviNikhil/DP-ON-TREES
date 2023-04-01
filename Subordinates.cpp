#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x) cout << #x << "=" << x << "\n"
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << "\n"

const ll mod=1e9+7;

vector<vector<ll>>tree(200005);
vector<ll>subtree_size(200005);

void dfs(ll node)
{
     subtree_size[node]=1;
     for(ll child: tree[node])
     {
        dfs(child);
        subtree_size[node]+=subtree_size[child];
     }

}

void solve(){
      ll n;cin>>n;
      for(ll i=2;i<=n;i++)
      {
          ll parent;cin>>parent;
          tree[parent].push_back(i);
      }

      dfs(1);

      for(ll i=1;i<=n;i++)
      {
        cout<<subtree_size[i]-1<<" ";
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
