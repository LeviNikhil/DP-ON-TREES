#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x) cout << #x << "=" << x << "\n"
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << "\n"

const ll mod=1e9+7;

vector<vector<ll>>tree(200005);
// jump[i][j]= i se 2^j jumps pe kya hai?
vector<vector<ll>> jump(200005,vector<ll>(__lg(200005)+1,0));


void dfs(ll node)
{
    for(ll child:tree[node])
    {
        jump[child][0]=node;
        for(ll j=1;j<=__lg(200005);j++)
        {
            jump[child][j] = jump[jump[child][j-1]][j-1];
        }
        dfs(child);
    }
}

void solve(){
      ll n,q;cin>>n>>q;

      for(ll i=2;i<=n;i++)
      {
         ll parent;cin>>parent;
         tree[parent].push_back(i);
      }

      dfs(1);

      while(q--)
      {
         ll x,k; cin>>x>>k;

         for(ll bit=__lg(200005);bit>=0;bit--)
         {
            if(k>>bit & 1) x=jump[x][bit];
         }

         if(x<=0) cout<<-1<<endl;
         else cout<<x<<endl;
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
