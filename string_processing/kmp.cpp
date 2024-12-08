#include<bits/stdc++.h>
using namespace std;
string s;  
vector<int>pie;
bool flag;
string pattern;

void mass()
{
    int j=0;

  for(int i=0;i<s.length();)
  {
    if(s[i]==pattern[j+1])
    {
      j++;i++;
    }
    else if(j!=0)   j=pie[j];
    else   if(j==0)  {j=0;i++;}
    if(j==pattern.length()-1){flag=true;return;}
  }

  if(j==pattern.length()-1){flag=true;}
}

int main()
{
      cin>>s;
      cin>>pattern;    pattern=" "+pattern;   

  int n=pattern.length();
    pie.resize(n+1,0);
     
     int j=0;

    for(int i=1;i<=n;i++)
    {
       if(pattern[i]==pattern[j]){
        pie[i]=j++;
       }
       else j=0;
    }

    flag=false;
   mass();

   cout<<(flag?"YES":"NO")<<endl;
}