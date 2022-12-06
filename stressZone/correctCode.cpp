                                  /* Just chill and give your best ,krma will pay you back soon !! */                                                                     
#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
#include <math.h>
#include <climits>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <list>
#include <bitset>
#include <iomanip>
#include <utility>
#define ll long long int
#define endl "\n"
#define A ll t;cin >> t;while (t--)
#define fn for (ll i = 0; i < n; i++)
#define loop(i,j,k) for (ll i = j; i <=k; i++)
#define rloop(i,j,k) for (ll i=j;i>=k;i--)
const ll M=1000000007;
const ll K=998244353;
const ll N=1e10+10;
using namespace std;

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

A{
    ll n,a,b;
    cin>>n>>a>>b;
    if(a>b){
        cout<<1<<endl;
    }else{
        cout<<(n+a-1)/a<<endl;
    }
}   
return 0;
}
