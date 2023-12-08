#include <iostream>
#include <cstdlib>
#include <vector> 
#include <iterator>
#include <algorithm>

using namespace std;
const int maxn = 30000 + 100;
int main()
{
  int a,n,b,B[maxn], A[maxn];
  bool ch;
    
  while(cin>>n)
  {
    int tmp = a;
    ch = false;
    for(int i=0;i<n;i++)
    {
        cin>>B[i];
    }
    for(int i=0;i<n-1;i++){
        A[i] = (abs(B[i+1]-B[i]));
    }
    sort(A, A+n-1);
    for(int i=0;i<n-1;i++){
        if(A[i] != i+1) {
            ch = true;
            break;
        }
    }
    if(ch==true){
       cout<<"Not jolly\n";
    }
    else if(ch==false){
       cout<<"Jolly\n";
    }
  }
  return 0;
}
