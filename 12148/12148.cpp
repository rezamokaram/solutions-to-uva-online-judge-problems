#include <bits/stdc++.h>
using namespace std;
#define F            first
#define S            second
#define Fin          freopen("input.txt","r",stdin)
#define Fout         freopen("output.txt","w",stdout)
#define Precision(a) cout << fixed << setprecision(a)
#define FasterIO     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define Test         int test;cin >> test;for(int tc = 1; tc <= test; tc++)

#define INF9         2147483647
#define INF18        9223372036854775806
#define eps          1e-8

const double pi = 2 * acos(0.0);
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template <typename T> T Sqr(T x) { T n = x * x ; return n ;}
template <typename T> T Pow(T B,T P){ if(P==0) return 1; if(P&1) return B*Pow(B,P-1);  else return Sqr(Pow(B,P/2));}
template <typename T> T Abs(T a) {if(a<0)return -a;else return a;}
template <typename T> T Gcd(T a,T b){if(a<0)return Gcd(-a,b);if(b<0)return Gcd(a,-b);return (b==0)?a:Gcd(b,a%b);}
template <typename T> T Lcm(T a,T b) {if(a<0)return Lcm(-a,b);if(b<0)return Lcm(a,-b);return a*(b/Gcd(a,b));}
template <typename T> T Exgcd(T a,T b,T &x,T &y) {if(a<0){T d=Exgcd(-a,b,x,y);x=-x;return d;}   if(b<0){T d=Exgcd(a,-b,x,y);y=-y;return d;}   if(b==0){x=1;y=0;return a;}else{T d=Exgcd(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}}
template <typename T> T BigMod (T b,T p,T m){if (p == 0) return 1;if (p%2 == 0){T s = BigMod(b,p/2,m);return ((s%m)*(s%m))%m;}return ((b%m)*(BigMod(b,p-1,m)%m))%m;}
template <typename T> T ModInvPrime (T b,T m){return BigMod(b,m-2,m);}
template <typename T> T ModInvNotPrime(T a , T m) {T x , y ;Exgcd(a , m , x , y) ;x %= m ;if(x < 0) x += m ;return x ;}
template <typename T> typename std::vector<T>::iterator Insert_sorted (std :: vector<T> & vec, T const& item) {return vec.insert (std::upper_bound( vec.begin(), vec.end(), item ), item);}
template <typename T> inline string ToBinary(T n) {string r ;while(n != 0) {r = ( n % 2 == 0 ? "0" : "1" ) + r ; n >>= 1;} return r ;}
long long BinaryToDecimal(string s) {int len = s.size();long long n = 0, p = 1;for (int i = len - 1; i >= 0; i-- , p *= 2) n += p * (s[i] - '0');return n;}

char Uplowch(char ch){if(ch >= 'A' &&  ch <= 'Z') ch += 32; return ch;}
char Lowupch(char ch){if(ch >= 'a' &&  ch <= 'z') ch -= 32; return ch;}
bool Isalpha(char ch){if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) return true; return false;}
int Strtoint(string str){stringstream ss(str);int x = 0;ss >> x ;return x ;}
string Intostr(int x){stringstream ss; ss << x; string str = ss.str(); return str;}
vector<string> Linetostr(string str){string s; vector <string> v ;istringstream is(str); while(is >> s)v.push_back(s);return v;}
template <typename T> void Print(T ar[] , int a , int b) {for (int i = a; i + 1 <= b ; i++)cout << ar[i] << " ";cout << ar[b] << "\n";}
template <typename T> void Print(T ar[] , int n) {for (int i = 0; i + 1 < n; i++)cout << ar[i] << " ";cout << ar[n - 1] << "\n";}
template <typename T> void Print(const vector<T> &v) {for (int i = 0; i + 1 < v.size() ; i++) cout << v[i] << " ";cout << v.back() << "\n";}

//int dx[] = {0 , 0 , -1 , 1 , -1 , -1 , 1 , 1 , 0} ;  // right , left , up , down
//int dy[] = {1 ,-1 , 0 , 0 , -1 , 1 , -1 , 1 , 0} ;

int days[] = {31 , 28 , 31 , 30 , 31 , 30, 31 , 31 , 30 , 31 , 30 , 31};
struct node{
    ll d, m, y;
    bool operator == (const node &a) {
        if (d == a.d & m == a.m && y == a.y) return 1;
        return 0;
    }
};
bool IsLeapYear(ll year) {
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}
node NextDate(node a) {
    if (a.m == 12) {
        if (a.d == 31) {
            a.d = 1;
            a.m = 1;
            a.y++;
        } else {
            a.d++;
        }
    } else if (a.m == 2) {
        if (IsLeapYear(a.y)) {
            if (a.d == 29) {
                a.d = 1;
                a.m++;
            } else {
                a.d++;
            }
        } else {
            if (a.d == 28) {
                a.d = 1;
                a.m++;
            } else {
                a.d++;
            }
        }
    } else {
        if (days[a.m - 1] == a.d) {
            a.d = 1;
            a.m++;
        } else {
            a.d++;
        }
    }
    return a;
}
int main() {
    FasterIO
    int n;
    while (cin >> n) {
        if (n == 0) break;
        vector <pair <node , ll>> v;
        for (int i = 0; i < n; i++) {
            ll d , m , y , c;
            cin >> d >> m >> y >> c;
            node tmp;
            tmp.d = d;
            tmp.m = m;
            tmp.y = y;
            v.emplace_back(tmp , c);
        }
        ll sum = 0 , cnt = 0;
        for (int i = 0; i + 1 < n; i++) {
            if (NextDate(v[i].first) == v[i + 1].first) {
                sum += v[i + 1].second - v[i].second;
                cnt++;
            }
        }
        cout << cnt << " " << sum << "\n";
    }
    return 0;
}
