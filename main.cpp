#include <iostream>
using namespace std;
void testPointAndReference();
void testExtern()
{
    extern int num;
    cout << num << endl;
    extern void func();
    func();
}
void testTypedef()
{
    typedef double d2;
    d2 b = 1.23;
    cout<<b<<endl;
    using d3 = double;
    d3 c =2.34;
    cout<<c<<endl;
}
int main()
{
    cout << "test" << endl;
testTypedef();
    return 0;
}

void testPointAndReference()
{
    int i = 1;
    cout << "i  " << i << endl;
    int *p = &i;
    (*p)++; // ++结合性 强于 *
    cout << "i  " << i << endl;
    int *&p1 = p;
    (*p1)++;
    cout << "i  " << i << endl;

    int &i1 = i;
    i1++;
    cout << "i  " << i << endl;
}