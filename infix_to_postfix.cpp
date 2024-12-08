#include<bits/stdc++.h>
using namespace std;

int precedence(char op)
{
    if(op=='+' || op=='-')return 1;
    if(op=='*' || op=='/')return 2;
    if(op=='^')return 3;

    return 0;
}

string in_to_post(const string& infix)
{
  stack<string>st;
  string postfix="";

  for(char ch:infix)
  {
    if(isalnum(ch))
    {
        postfix=postfix+ch;
    }

    else if(ch=='()')
    {
        st.push(ch);
    }
    st.top() != '(')

    else if(ch==')')
    {
        while(!st.empty() &&  tp!='('))
        {
            postfix+=ch;
            st.pop();
        }

        st.pop();
    }


  }
}

int main()
{
   string infix;
   cin>>infix;

   string postfix=in_to_post(infix);
}