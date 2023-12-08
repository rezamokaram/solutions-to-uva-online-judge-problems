/* cSpell: disable */
#include <bits/stdc++.h>
using namespace std;
//
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, pii> edge;
const int maxn = 100;
int n;
int parent[maxn], sub[maxn];
double sum[maxn];
double x[maxn], y[maxn], m[maxn];
priority_queue<edge, vector<edge>, greater<edge>> pq;
int findp(int i) {
    return (parent[i] == i? i : parent[i] = findp(parent[i]));
}
int main()
{
   	ios_base::sync_with_stdio(0);
   	cin.tie(0);
   	cout.tie(0);
   	//
    int cases = 1;
    while (cin >> n && n)
    {
        // memset(parent, 0, sizeof(parent));
        // memset(sub, 1, sizeof(sub));
        double div = 0, sumall = 0;
        for (int i = 0; i < n; i++)
        {
            sub[i] = 1;
            parent[i] = i;
            cin >> x[i] >> y[i] >> m[i];
            sum[i] = m[i];
            div += m[i];
            for (int j = 0; j < i; j++)
            {
                pq.push(edge(hypot(x[j] - x[i], y[j] - y[i]), pii(j, i) ));
            }
        }
        // minimum spaning tree
        while (!pq.empty())
        {
            edge tp = pq.top();
            pq.pop();
            int ip = findp(tp.second.first);
            int jp = findp(tp.second.second);
            if(ip == jp) continue;
            //
            int mainRoot = findp(0);
            if (ip == mainRoot) sumall += sum[jp] * tp.first;
            if (jp == mainRoot) sumall += sum[ip] * tp.first;
            // joint
            if (sub[ip] > sub[jp]) {
                parent[jp] = ip;
                sub[ip] += sub[jp];
                sum[ip] += sum[jp];
            } else {
                parent[ip] = jp;
                sub[jp] += sub[ip];
                sum[jp] += sum[ip];
            }
        }
        cout << "Island Group: " << cases++ << " Average ";
        cout << fixed << setprecision(2) << sumall / div << "\n\n";
    }
    //
    return 0;
}
