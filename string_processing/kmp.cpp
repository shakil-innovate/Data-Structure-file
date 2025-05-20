#include<bits/stdc++.h>
using namespace std;

vector<int>pie;
string pattern,s;
bool flag=false;

void mos()
{

    int j=0;
     for(int i=0;i<s.size();)
     {
        if(s[i]==pattern[j+1])
        {
            i++,j++;
        }
        else
        {
           if(j!=0) j=pie[j];
           else i++;
        }

        if(j==pattern.size()-1)
        {
            cout<<"index no : "<<i-j<<endl;
            flag=true;return;
        }

     }
}

int main()
{
    cin>>s>>pattern;

    pattern=" "+pattern;
    pie.resize(pattern.length()+1,0);

    int j=1;

    for(int i=2;i<pattern.size();i++)
    {
        if(pattern[i]==pattern[j])
        {
            pie[i]=j;
            j++;
        }
        else
        {
             j=1;
        }
    }

    mos();

    cout<<(flag?"YES":"NO")<<endl;


}
