// jaii shree radhe;

#include <bits/stdc++.h>
using namespace std;
// simulate using an ordered set

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
void run()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
    freopen("input1.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
// template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using max_heap = priority_queue<T>;
#define ull unsigned long long
#define ll long long
#define lld long double
#define endl "\n"
#define M 1000000007LL
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define mpr make_pair
#define pb push_back
#define fi first
#define se second
#define ceilof(x, y) (x + y - 1) / y
#define midof(l, r) l + ((r - l) / 2)
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
#define input(v, n) \
    fr(i, 0, n)     \
    {               \
        int x;      \
        cin >> x;   \
        v.pb(x);    \
    }
#define print(v, n) \
    inc(i, 0, n) { cout << v[i] << " "; }
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define fr(i, a, n) for (int i = a; i < n; i++)
#define rfr(i, a, n) for (int i = n - 1; i >= a; i--)
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;
typedef vector<vi> vvi;
struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // designed by Sebastiano Vigna and found on Neal's blog
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
typedef unordered_map<int, int, custom_hash> u_mp;
typedef map<int, int> mp;
typedef multimap<int, int> m_mp;
typedef unordered_set<int> u_seti;
typedef set<int> seti;
typedef multiset<int> m_seti;
long long binpow(long long base, long long exp)
{
    int mod = M;
    long long res = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            res = (res * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return res;
}

long long mod(long long x)
{
    return ((x % M + M) % M);
}

long long add(long long a, long long b)
{
    return mod(mod(a) + mod(b));
}

long long mul(long long a, long long b)
{
    return mod(mod(a) * mod(b));
}
bool isPrime(int n)
{
    // Corner case
    if (n <= 1)
        return false;

    // Check from 2 to n-1
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;

    return true;
}
const int N = (int)1e6;
void sieve(int N)
{
    // Create a boolean array
    // "prime[0..n]" and initialize
    // all entries it as true.
    // A value in prime[i] will
    // finally be false if i is
    // Not a prime, else true.
    bool prime[N + 1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= N; p++)
    {
        // If prime[p] is not changed,
        // then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples
            // of p greater than or
            // equal to the square of it
            // numbers which are multiple
            // of p and are less than p^2
            // are already been marked.
            for (int i = p * p; i <= N; i += p)
                prime[i] = false;
        }
    }
}
// for factorial
int fact(int n)
{
    int res = 1;
    for (int i = 1; i <= n; i++)
    {
        res = res * 1ll * i % M;
    }
    return res;
}
int C(int n, int k)
{
    return fact(n) * 1ll * binpow(fact(k), M - 2) % M * 1ll * binpow(fact(n - k), M - 2) % M;
}
// lower_bound if x not present points to next greater element
// upper_bound return first element in the range which has value greater than given value
//  ye dekhlena

ll solve(ll n)
{
    ll z = (n & (~(n - 1)));
    return log2(z);
}
#ifndef ONLINE_JUDGE
#define debug(x)       \
    cerr << #x << " "; \
    _print(x);         \
    cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t)
{
    cerr << t;
}
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(lld t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(ull t) { cerr << t; }

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
    _print(p.ff);
    cerr << ",";
    _print(p.ss);
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
    cerr << "]" << endl;
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

// int f(int i, int j, string &s, string &t, vector<vector<int>> &dp)
// {
//     if (i == 0 || j == 0)
//     {
//         return 0;
//     }

//     if (dp[i][j] != -1)
//         return dp[i][j];
//     if (s[i] == t[j])
//     {
//         return dp[i][j] = 1 + f(i - 1, j - 1, s, t, dp);
//     }

//     return dp[i][j] = max(f(i - 1, j, s, t, dp), f(i, j - 1, s, t, dp));
// }


int32_t main()
{
    run();

    int t;
    t = 1;
    // cin >> t;

    while (t--)
    {
        int n,W;
        cin>>n>>W;
        int w[n];
        int price[n];
        vector<vector<int>>dp(n+1,vector<int>(W+1,0));
        for(int i=0;i<n;i++)
        {
            cin>>w[i];
        } 
        for(int i=0;i<n;i++){
            cin>>price[i];
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=W;j++)
            {
                
                dp[i][j]=dp[i-1][j];
                int x=j-w[i-1];
                if(x>=0)
                {
                    dp[i][j]=max(dp[i][j],dp[i-1][x]+price[i-1]);
                }
            }
        }
        cout<<dp[n][W];
        debug(dp);


       
    }

    // debug(dp);

    return 0;
}

