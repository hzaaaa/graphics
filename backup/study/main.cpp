#include <iostream>
#include <string>
#include <vector>
using namespace std;

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
int main()
{
    
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