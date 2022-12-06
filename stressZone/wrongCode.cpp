#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    int T;
    cin>>T;
    while (T--)
    {
        ll n , a , b;
        cin>>n>>a>>b;
        ll a1=n/a;
        if ( n%a!=0)
        {
             a1++;
        }
        ll a2=0;
        if ( b<a)
        {
             a2=(n/(2*a-b));
             if ( n%(2*a-b)!=0)
             {
                 a2++;
             }
             cout<<min(a1 , a2)<<endl;
        }
        else
        {
             cout<<a1<<endl;
        }
        
        
        
    }
    return 0;
}