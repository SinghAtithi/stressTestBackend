/*
    कर्मण्येवाधिकारस्ते मा फलेषु कदाचन।
    मा कर्मफलहेतुर्भूर्मा ते सङ्गोऽस्त्वकर्मणि॥

    Karmanye vadhikaraste Ma Phaleshu Kadachana,
    Ma Karmaphalaheturbhurma Te Sangostvakarmani,

    The meaning of the verse is :—
    You have the right to work only but never to its fruits.
    Let not the fruits of action be your motive, nor let your attachment be to
   inaction
*/

#include <math.h>
#include <algorithm>
#include <climits>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <unordered_map>
#include <vector>
#define int int64_t
#define vi vector<int>
#define vii vector<pair<int, int>>
#define vs vector<string>
#define vc vector<char>
#define vb vector<bool>
#define pb emplace_back
#define vvi vector<vector<int>>
#define mii map<int, int>
#define mci map<char, int>
#define pii pair<int, int>
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define vin(x, v)       \
      for (auto &x : v) \
            cin >> x;
#define vout(x, v)     \
      for (auto x : v) \
            cout << x << " ";
#define MEM(a, b) memset(a, (b), sizeof(a))
#define loop(i, j, k) for (int i = j; i < k; i += 1)
#define rloop(i, j, k) for (int i = j; i >= k; i -= 1)
#define rep(i, j) loop(i, 0, j)
#define rrep(i, j) rloop(i, j, 0)
#define MP make_pair
#define endl "\n"
#define INF (int)1e18
#define EPS 1e-18
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define MODD 998244353
// cout <<setprecision(15)
#define NEED_FOR_SPEED_MOST_WANTED      \
      ios_base::sync_with_stdio(false); \
      cin.tie(NULL);                    \
      cout.tie(NULL)
using namespace std;

/*-----------------------------------D-E-B-U-G-----------------------------------------------*/
#ifndef ONLINE_JUDGE
#define deb(x)           \
      cerr << #x << " "; \
      _print(x);         \
      cerr << endl;
#else
#define deb(x)
#endif

void _print(int t)
{
      cerr << t;
}
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
      cerr << "{";
      _print(p.first);
      cerr << ",";
      _print(p.second);
      cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
      cerr << "[ ";
      for (T i : v)
      {
            _print(i);
            cerr << " ";
      }
      cerr << "]";
}
template <class T>
void _print(set<T> v)
{
      cerr << "[ ";
      for (T i : v)
      {
            _print(i);
            cerr << " ";
      }
      cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
      cerr << "[ ";
      for (T i : v)
      {
            _print(i);
            cerr << " ";
      }
      cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
      cerr << "[ ";
      for (auto i : v)
      {
            _print(i);
            cerr << " ";
      }
      cerr << "]";
}
/*-----------------------------------D-E-B-U-G-----------------------------------------------*/
/*
      5 6
      1 2 3 4 5

      5 D
      4 D 4 W 1 L
      3 D 3 W
*/

void solve()
{
      int n, m;
      cin >> n >> m;
      m *= -1;
      int ans = 1;
      vi v(n);
      vin(x, v);
      sort(all(v));
      map<int, int> freq;
      set<int> st;
      for (auto &x : v)
      {
            x *= -1;
            freq[x]++;
            st.insert(x);
      }
      st.insert(INF);
      int low = v[0];
      rep(i, n)
      {
            if (abs(v[i] + v[0]) <= abs(m))
            {
                  low = v[i];
            }
            // deb(low);
      }
      // low = v[n - 1];
      freq[low]--;
      if (freq[low] == 0)
            st.erase(low);
      ans += abs(low);
      while (st.size())
      {
            int need = m - low;
            auto it = *st.lower_bound(need);
            low = it;
            if (it == INF)
            {
                  st.erase(INF);
                  break;
            }
            ans += abs(it);
            freq[it]--;
            if (freq[it] == 0)
            {
                  st.erase(it);
            }
      }
      // deb(st);
      // deb(ans);
      for (auto x : st)
      {
            ans += (freq[x] * (abs(x) + 1));
      }
      cout << ans;
}

signed main()
{
      NEED_FOR_SPEED_MOST_WANTED;
      // cout << setprecision(15);
      int t = 1;
      // cin >> t;
      while (t--)
      {
            solve();
            cout << endl;
      }
}