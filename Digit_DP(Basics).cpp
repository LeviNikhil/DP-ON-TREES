#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define deb(x) cout << #x << "=" << x << "\n"
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << "\n"

const int mod=1e9+7;

// here 1st state representing the position, then restriction & then handling cases of starting zeros
ll dp[20][2][2];


ll func(ll idx,bool tight,bool zeros,string &s)
{
    if(idx==s.size()) return 1;

    if(dp[idx][tight][zeros]!=-1) return dp[idx][tight][zeros];
    
    ll ans=0;
    ll limit=0;

    if(tight==1) limit=s[idx]-'0';
    else limit=9;

    for(ll i=0;i<=limit;i++)
    {
        if(i==0 && zeros) 
        {
            ans+=func(idx+1,(i==limit)&&tight,1,s);
        }
        else
        {
            if(i==4) continue;

            ans+=func(idx+1,(i==limit)&&tight,0,s);
        }
    }

    return dp[idx][tight][zeros]=ans;
}

ll check(ll mid)
{
    for(ll i=0;i<20;i++)
    {
        for(ll j=0;j<2;j++)
        {
            dp[i][j][0]=-1;
            dp[i][j][1]=-1;
        }
    }

    string m=to_string(mid);

    ll cnt_of_4=(mid)-(func(0,1,1,m)-1);

    ll idx=(mid-cnt_of_4);
    return idx;
}


void solve()
{
    ll k;cin>>k;
    ll low=0; ll high=8272646349127;
    ll ans=0;
    while(low<=high)
    {
        ll mid = (low + (high - low) / 2LL);
        if(check(mid)>=k)
        {
            ans=mid;
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    cout<<ans<<endl;

} 


int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    

    IOS;
    // pre();
    int T;
    T=1;
    cin >> T;
    while(T--){
     solve();
    }

    return 0;
}
