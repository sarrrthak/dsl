#include <iostream>
#include <stack>
using namespace std;
int prec(char c){
if(c=='^'){
return 3;
}
else if(c=='*'||c=='/'){
return 2;
}
else if(c=='+'||c=='-'){
return 1;
}
else{
return -1;
}
}
string intopost(string a){
stack<char>s;
string result;
double i;
for(i=0;i<a.length();i++){
if((a[i]>='a'&&a[i]<='z')||(a[i]>='A'&&a[i]<='Z')){
result+=a[i];
}
else if(a[i]=='('){
s.push(a[i]);
}
else if(a[i]==')'){
while(!s.empty() && s.top()!='('){
result+=s.top();
s.pop();
} if(!s.empty() && s.top()=='('){
s.pop();
}}
else{
while(!s.empty()&&prec(s.top())>=prec(a[i])){
result+=s.top();
s.pop();
}
s.push(a[i]);
}}
while(!s.empty()){
result+=s.top();
s.pop();
} return result;
}
int main() {
string input = "(a-b/c)*(a/k-l)";
cout << intopost(input) << endl;
return 0;
}
