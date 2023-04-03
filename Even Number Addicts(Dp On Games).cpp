#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x) cout << #x << "=" << x << "\n"
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << "\n"

const ll mod=1e9+7;

bool fun(ll even, ll odd, bool alice, bool e, vector<vector<vector<vector<ll>>>> &dp){
    if (dp[even][odd][alice][e] != -1)
    {
        return dp[even][odd][alice][e];
    }
    if (alice)
    {
        bool found = false;
        bool ans1 = false, ans2 = false;
        if (even){
            found = true;
            ans1 = (!fun(even - 1, odd, !alice, e, dp));
        }
        if (odd){ 
            found = true;
            ans2 = (!fun(even, odd - 1, !alice, !e, dp));
        }
        if (!found){
            return dp[even][odd][alice][e]=e;
        }
        else{
            return dp[even][odd][alice][e]=(ans1 || ans2);
        }
    }
    else{
        bool found = false;
        bool ans1 = false, ans2 = false;
        if (even){
            found = true;
            ans1 = (!fun(even - 1, odd, !alice, e, dp));
        }
        if (odd){ 
            found = true;
            ans2 = (!fun(even, odd - 1, !alice, e, dp));
        }
        if (!found){
            return dp[even][odd][alice][e]=!e;
        }
        else{
            return dp[even][odd][alice][e]=(ans1 || ans2);
        }
    }
}


void solve(){

    ll n; cin >> n;
    ll even = 0, odd = 0;
 
    for(ll i=0;i<n;i++){
        ll a; cin >> a;
        if (a%2){
            odd++;
        }
        else{
            even++;
        }
    }

    vector<vector<vector<vector<ll>>>> dp(even + 1, vector<vector<vector<ll>>>(odd + 1, vector<vector<ll>>(2, vector<ll>(2, -1))));
    bool ans = fun(even, odd, true, true, dp);
    // deb(dp[0][0][true][true]);
    // deb(dp[0][0][true][false]);
    // deb(dp[0][0][false][true]);
    // deb(dp[0][0][false][false]);
    if (ans){
        cout << "Alice" << endl;
    }
    else{
        cout << "Bob" << endl;
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
    cin >> T;
    while(T--){
    solve();
    }

    return 0;
}
