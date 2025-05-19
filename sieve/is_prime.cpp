#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;  cin>>n;
    bool f=1;        

    for(int i=2; i*i<=n ; i++)       //complexity is 0(root(n));
    {
       if(n%i==0){f=0;break;}
    }

    cout<<n;
    cout<<(f?" is prime" : " isn't prime")<<endl;
}
