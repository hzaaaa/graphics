#include <iostream>
#include <string>
#include <vector>
#include "a.hpp"
using namespace std;

using f = int(int);
void sTox(string &s);
void sTox2(string &s)
{
    int l = s.length();
    for (int i = 0; i < l; i++)
    {
        s[i] = 'x';
    }
}
void sTox3(string &s)
{
    int l = s.length();
    while (l)
    {
        /* code */
        s[l - 1] = 'x';
        l--;
    }
}
string cinsTos(string &s)
{
    string s2 = "";
    for (char c : s)
    {
        if ((c <= 'Z' && c >= 'A') || (c <= 'z' && c >= 'a'))
        {
            s2 += c;
        }
    }
    return s2;
}
void cinIntVector()
{
    vector<int> vi = {};
    int n;
    while (cin >> n)
    {
        vi.push_back(n);
    }
    for (int i : vi)
    {
        cout << i << endl;
    }
}

int ifunc(int a)
{
    a++;
    cout << a << endl;
    return a;
}

f* returnRef( )
{
    // f* f1 = returnRef();
    // (*f1)(1);
    return ifunc;
}

vector<string> vs2vS(vector<string> vs){
    // vector<string> vs ={"qwe","sdf"};
    // vs = vs2vS(vs);
    // for(string &s : vs){
    //    cout<<s<<endl;
    // }
    for(string &s : vs){
        for(char &c :s){
            c=toupper(c);
        }
    }
    return vs;
}
void threeMethod(){
    vector<int> vi1 ={42,42,42};
    vector<int> vi2(3,42);
    for(int i :vi1){
        cout<<i<<endl;
    }
    for(int i :vi2){
        cout<<i<<endl;
    }

}
void coutVectorHeadTail(){
    vector<int>vi={1,2,3,4,5,6,7,8};
    auto h = vi.begin();
    auto p1 = h;

    auto t = vi.end();
    auto p2 = t-1;

    while (p1!=t)
    {
        int sum = *p1+*p2;
        cout<<"1:"<<*p1<<endl;
        cout<<sum<<endl;
        p1++;
        p2--;
        
    }
    
    
}

void testError(){
    int n1,n2;
    cin>>n1>>n2;
    
}
// AC o2 =  AC();
//     cout<<o2.t<<endl;
class AC{
    public:
        int t=5;
};

int testf1(int a){
    // cout<<testf1(1)<<endl;
    // cout<<testf1(1)<<endl;
    // cout<<testf1(1)<<endl;
    // cout<<testf1(1)<<endl;
    // cout<<testf1(1)<<endl;
    static int c = 0;
    
    return c++;
    
    
}
void sTox(string &s)
{
    // string s ="qwe";
    // cout<<s<<endl;
    // sTox(s);
    // cout<<s<<endl;
    for (char &c : s)
    {
        c = 'x';
    }
}
int ah = 123;
// af();
// bf();
void swapValue(int &a,int &b){
    // int a = 1;
    // int b=2;
    // swapValue(a,b);
    // cout<<"a:"<<a<<endl;
    // cout<<"b:"<<b<<endl;
    int c =a;
    a=b;
    b=c;
}
int returnBig(int&a,int*b){
    // int a=1;
    // int b=2;

    // int c =returnBig(a,&b);
    // cout<<"c:"<<c<<endl;

    if(a>*b){
        return a;
    }else{
        return *b;
    }
}
void swapPoint(int* (&p1) ,int* (&p2)  ){
    // int a = 1;
    // int b = 2;
    // int*p1 = &a;
    // int*p2 = &b;
    // swapPoint(p1,p2);
    // a= 11;
    // b=12;
    // cout<<"*p1:"<<*p1<<endl;
    // cout<<"*p2:"<<*p2<<endl;

    int* p3 =p1;
    p1=p2;
    p2=p3;
}
void test6_2_6_27(initializer_list<int> il){
    // test6_2_6_27({1,2,3});
    // test6_2_6_27({1});
    // test6_2_6_27({1,3,4,5,6,7});

    int sum = 0;
    for(int i :il){
        sum+=i;
    }
    cout<<sum<<endl;
}
void recursion(std::vector<int>::iterator start, std::vector<int>::iterator end){
    // vector<int> v ={1,2,3,4,5,6,7};
    // recursion(v.begin(),v.end()-1);


    if(start==end){
        cout<<(*start)<<endl;
        return;
    }else if(start==(end+1)){
        return;
    }else{
        cout<<*start<<"   "<<*end<<endl;
        start++;
        end--;
        recursion(start,end);
    }

}
int main(int argc,char *sa[])//sa实际上是指针 无大小
{
    //透明
    //
    
}
// // for(char *s : sa){//error
//     //     cout<<s<<endl;
//     // }
// string s = "";
//     for(int i=0;i<argc;i++){
//         cout<<sa[i]<<endl;
//         s+=sa[i];
//     }
//     cout<<s<<endl;

