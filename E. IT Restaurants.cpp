#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x) cout << #x << "=" << x << "\n"
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << "\n"

const int mod=1e9+7;
const int N=5e5+9;
 
vector<int> adj[5001];
int subtreeSize[5001];

int dfs(int node,int par)  // to calculate subtree size
{
    int ans=1;
    for(auto &child:adj[node])
    {
        if(child!=par) ans+=dfs(child,node);
    }
    return subtreeSize[node]=ans;
}

int subset_sum(int n,int tgt,vector<int>&a,vector<vector<int>>&dp) //to check subset sum exist or not
{
    if(tgt==0) return 1;

    if(n==0) return 0;

    if(dp[n][tgt]!=-1) return dp[n][tgt];

    int ans=0;
    
    //Not taking current element into account
    ans|=subset_sum(n-1,tgt,a,dp);

    //taking current element
    if(tgt>=a[n-1]) ans|=subset_sum(n-1,tgt-a[n-1],a,dp);

    return dp[n][tgt]=ans;
}
 
 
void solve(){
    int n;cin>>n;
   for(int i=0;i<n-1;i++)
   {
      int x,y;
      cin>>x>>y;
      adj[x].push_back(y);
      adj[y].push_back(x);
   }
   set<int>every;
   set<int>poss;
   for(int i=1;i<=(n-1)/2;i++)
   {
      every.insert(i);
   }
   for(int i=1;i<=n;i++)  //Check for every single node 
   {
      vector<int> arr;
      for(auto &child: adj[i])
      {
         arr.push_back(dfs(child,i));  // pushing aint subtree size into arr
      }

      vector<vector<int>> dp(arr.size()+1, vector<int>(n,-1));
      stack<int> bucket; // to store element to remove (Optimisation)
      
      for(auto it=every.begin(); it!=every.end();it++) 
      {
            if(subset_sum(arr.size(),*it,arr,dp))
            {
                poss.insert(*it);
                bucket.push(*it);
            }
      }

      while(bucket.size()!=0)
      {
         every.erase(bucket.top());
         bucket.pop();
      }
      dp.clear();arr.clear();
   }

   set<pair<int,int>> ans;
   for(auto &it: poss)
   {
       ans.insert({n-1-it,it});
       ans.insert({it,n-1-it});
   }

   cout<<ans.size()<<"\n";
   for(auto &it:ans)
   {
      cout<<it.first<<" "<<it.second<<endl;
   }

   
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    

    IOS;
    int T;
    T=1;
    // cin >> T;
    while(T--){
     solve();
    }

    return 0;
}
