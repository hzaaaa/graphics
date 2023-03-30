#include <iostream>
using namespace std;
void testPointAndReference();
int main()
{
    cout << "test" << endl;
    testPointAndReference();
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