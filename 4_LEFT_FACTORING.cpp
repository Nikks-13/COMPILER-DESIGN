#include <bits/stdc++.h>
using namespace std;
string helper(string a, string b) {
    int n=a.length();
    int m=b.length();
    string pref="";
    for(int i=0;i<min(n, m);i++) {
        if(a[i]!=b[i]) {
            return pref;
        }
        pref+=a[i];
    }
    return pref;}
string prefixFinder(vector<string> v) {
    int n=v.size();
    string prefix = v[0];
    for(int i=1;i<n;i++) {
        prefix = helper(prefix, v[i]);
    }
    return prefix;}
int main() {
    cout<<"enter input :";
    string s;
    getline(cin, s);
    char A = s[0];
    if(!(A>='A' && A<='Z')) {
        cout<<"Invalid Input"<<endl;
        return 0;}
    cout<<"\n output  : \n";
    int i=1, n=s.length();
    vector<string> v;
    string t="";
    while(i<n) {
        if(isalpha(s[i])==false) {
            i++;
            continue;}
        if(s[i]==' ') {
            continue;
        }
        while(i<n && s[i]!='/') {
            if(s[i]==' ') {
                continue;
            }
            t+=s[i];
            i++;
        }
        v.push_back(t);
        t="";
        i++;}
    string pref = prefixFinder(v);
    cout<<A<<" -> "<<pref<<A<<"\'"<<endl;
    cout<<A<<"\' -> ";
    bool flag=false, last=false;
    for(int i=0;i<v.size();i++) {
        string t = v[i];
        for(int j=pref.length(); j<t.length();j++) {
            cout<<t[j];}
        if(pref.length()==t.length()) {
            flag=true;
            if(i==v.size()-1) {
                last=true;
            }
            continue;}
        if(i!=v.size()-1) {
            cout<<"/ ";
        }}
    char ch = char(238);
    if(flag) {
        if(last==false) {
            cout<<"/ ";
        }
        cout<<ch;
    }
    return 0;}
