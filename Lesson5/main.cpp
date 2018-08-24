
//  Lesson5
//  Created by Nhật Hoàng  on 3/13/18.

#include <iostream>

using namespace std;
char toantu[10000];
int sz=-1;
stack<double> st;
int DoUuTien(char c)
{
    if(c=='(') return 0;
    if(c=='*' || c=='/') return 2;
    return 1;
}
int Cal(char toantu)
{
    double x,y,tmp;
    y=st.top();st.pop();
    x=st.top();st.pop();
    if(toantu=='+') tmp=x+y;
    else if(toantu=='-') tmp=x-y;
    else if(toantu=='*') tmp=x*y;
    else tmp=x/y;
    st.push(tmp);
}
bool mark=false;
int main()
{
    string s2,s="";
    getline(cin,s2);
    for(int i=0;i<s2.size();i++) if(s2[i]!=' ') s.push_back(s2[i]);
    if(s[0]=='-') mark=true;
    for(int i=mark; i<s.size(); i++)
        if('0'<=s[i] && s[i]<='9')
        {
            int t=0;
            while('0'<=s[i] && s[i]<='9') t=(t*10+s[i]-'0'),i++;
            i--;
            if(!mark) st.push(t);
            else mark=false,st.push(-t);
        }
        else if(s[i]=='(') toantu[++sz]='(';
        else if(s[i]==')') {while(toantu[sz]!='(') Cal(toantu[sz--]);sz--;}
        else
        {
            if(s[i]=='-' && i>0 && s[i-1]!=')' && (s[i-1]<'0' ||s[i-1]>'9'))
            {
                mark^=1;
                continue;
            }
            while(sz>=0 && DoUuTien(toantu[sz])>=DoUuTien(s[i])) Cal(toantu[sz--]);
            toantu[++sz]=s[i];
        }
    while(sz>=0) Cal(toantu[sz--]);
    cout<<fixed<<setprecision(0)<<st.top();
    return 0;
}\
int main()
{
    
    
    system("pause");
    return 0;
}
