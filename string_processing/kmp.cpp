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

        int j=0;  // note: also fix the starting index/convention
        pie[1] = 0;
        for(int i=2;i<pattern.size();i++)
        {
            while(j > 0 && pattern[i] != pattern[j+1])
                j = pie[j];
            if(pattern[i] == pattern[j+1])
                j++;
            pie[i] = j;
        }

    mos();

    cout<<(flag?"YES":"NO")<<endl;


}
