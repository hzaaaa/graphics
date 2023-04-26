#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <math.h>
#include <tuple>
#include <map>

#include <limits.h>
#include "a.hpp"
#include "Sales_data.cpp"
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

f *returnRef()
{
    // f* f1 = returnRef();
    // (*f1)(1);
    return ifunc;
}

vector<string> vs2vS(vector<string> vs)
{
    // vector<string> vs ={"qwe","sdf"};
    // vs = vs2vS(vs);
    // for(string &s : vs){
    //    cout<<s<<endl;
    // }
    for (string &s : vs)
    {
        for (char &c : s)
        {
            c = toupper(c);
        }
    }
    return vs;
}
void threeMethod()
{
    vector<int> vi1 = {42, 42, 42};
    vector<int> vi2(3, 42);
    for (int i : vi1)
    {
        cout << i << endl;
    }
    for (int i : vi2)
    {
        cout << i << endl;
    }
}
void coutVectorHeadTail()
{
    vector<int> vi = {1, 2, 3, 4, 5, 6, 7, 8};
    auto h = vi.begin();
    auto p1 = h;

    auto t = vi.end();
    auto p2 = t - 1;

    while (p1 != t)
    {
        int sum = *p1 + *p2;
        cout << "1:" << *p1 << endl;
        cout << sum << endl;
        p1++;
        p2--;
    }
}

void testError()
{
    int n1, n2;
    cin >> n1 >> n2;
}
// AC o2 =  AC();
//     cout<<o2.t<<endl;
class AC
{
public:
    int t = 5;
};

int testf1(int a)
{
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
void swapValue(int &a, int &b)
{
    // int a = 1;
    // int b=2;
    // swapValue(a,b);
    // cout<<"a:"<<a<<endl;
    // cout<<"b:"<<b<<endl;
    int c = a;
    a = b;
    b = c;
}
int returnBig(int &a, int *b)
{
    // int a=1;
    // int b=2;

    // int c =returnBig(a,&b);
    // cout<<"c:"<<c<<endl;

    if (a > *b)
    {
        return a;
    }
    else
    {
        return *b;
    }
}
void swapPoint(int *(&p1), int *(&p2))
{
    // int a = 1;
    // int b = 2;
    // int*p1 = &a;
    // int*p2 = &b;
    // swapPoint(p1,p2);
    // a= 11;
    // b=12;
    // cout<<"*p1:"<<*p1<<endl;
    // cout<<"*p2:"<<*p2<<endl;

    int *p3 = p1;
    p1 = p2;
    p2 = p3;
}
void test6_2_6_27(initializer_list<int> il)
{
    // test6_2_6_27({1,2,3});
    // test6_2_6_27({1});
    // test6_2_6_27({1,3,4,5,6,7});

    int sum = 0;
    for (int i : il)
    {
        sum += i;
    }
    cout << sum << endl;
}
void recursion(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
    // vector<int> v ={1,2,3,4,5,6,7};
    // recursion(v.begin(),v.end()-1);

    if (start == end)
    {
        cout << (*start) << endl;
        return;
    }
    else if (start == (end + 1))
    {
        return;
    }
    else
    {
        cout << *start << "   " << *end << endl;
        start++;
        end--;
        recursion(start, end);
    }
}
void testCopy()
{
    vector<int> v1 = {1, 2, 3};
    vector<int> v2 = v1;
    cout << v1[0] << endl;
    v2[0] = 4;
    cout << v1[0] << endl;
}
using SA = string[3];
SA s3 = {"1", "2", "3"};
SA *returnSAName()
{
    // SA* s3l1 = returnSAName();
    // *s3l1[0]="4";

    // SA* s3l2 = returnSAName();
    // cout<<*s3l2[0]<<endl;
    return &s3;
}
string sa[2] = {"123", "123"};
string (*returnSA())[2]
{
    // string (*sal)[2] =returnSA();
    // *sal[0]="321";
    // string  (*sal2)[2] =returnSA();
    // cout<<*sal2[0]<<endl;
    return &sa;
}

class Test
{
    //    vector< int(*)(int,int) > vf = {f_6_7_54};
    //     int c = vf[0](1,3);
    //     cout<<c<<endl;
    //     Test t(1,2,3) ;
    //     t.pb();
private:
    friend int f_6_7_54(int, int);
    void pv()
    {
        cout << "this is private" << endl;
    }

public:
    Test(int a1, int b1, int c1) : a(a1), b(b1), c(c1) {}
    int a, b, c;
    void pb()
    {
        cout << "this is public" << endl;
        cout << a + b + c << endl;
    }
};
int f_6_7_54(int a, int b)
{
    // vector< int(*)(int,int) > vf = {f_6_7_54};
    // int c = vf[0](1,3);
    // cout<<c<<endl;
    // Test t ;
    // t.pv();
    return a + b;
}
#pragma region // Solution
class Solution
{
public:

    int edgeScore(vector<int> &edges)
    {
        int n1 =edges.size();
        int n = n1;
        vector<unsigned>result(n,0);
        unsigned maxResult = 0;
        while(n--){
            result[edges[n]] +=n;
            
           
        }
        int currentMaxi = -1;
        while(n1--){
            if(result[n1]>=maxResult){
                maxResult = result[n1];
                currentMaxi = n1;
            }
        }
        return currentMaxi;

    }
    int countMatches(vector<vector<string>> &items, string ruleKey, string ruleValue)
    {
        int sum = 0;
        map<string, int> kTi;
        kTi["type"] = 0;
        kTi["color"] = 1;
        kTi["name"] = 2;
        int ki = kTi[ruleKey];
        int n = items.size();
        while (n--)
        {
            if (items[n][ki] == ruleValue)
                sum++;
        }
        // for(auto item : items){
        //     if(item[ki]==ruleValue) sum++;
        // }
        return sum;
    }
    // Solution s;
    // // vector<int> v{1,4,1,5,7,3,6,1,9,9,3};
    // // int k=4;
    // vector<int> v{581920, 200100, 526972, 677934, 989025, 294832, 581857, 663919, 961334, 1881, 859626, 251114, 361905, 867006, 86001, 836946, 894279, 859796, 750025, 898166, 674980, 939280, 458563, 117387, 403337, 961067, 589597, 73584, 178968, 955900, 755634, 609754, 97612, 19699, 843950, 907919, 883083, 522938, 670930, 671679, 390248, 704834, 188158, 226340, 80496, 701795, 867627, 280988, 465918, 748627, 321025, 564279, 79716, 786173};
    // int k = 23;
    // // vector<int> v{1,15,7,9,2,5,10};
    // // int k=3;
    // for (int r : v)
    // {
    //     // cout << r << " ";
    // }
    // cout << endl;
    // int result = s.maxSumAfterPartitioning(v, k);
    // cout << result << endl;
    int maxSumAfterPartitioning2(vector<int> &arr, int k)
    {
        int size = arr.size();
        vector<int> resultV(size);

        for (int i = 0; i < size; i++)
        {

            int tempMax = -1;
            resultV[i] = 0;
            for (int j = i; j > i - k && j >= 0; j--)
            {
                tempMax = max(tempMax, arr[j]);
                if (j == 0)
                {
                    resultV[i] = max(resultV[i], tempMax * (i - j + 1));
                }
                else
                {

                    resultV[i] = max(resultV[i], tempMax * (i - j + 1) + resultV[j - 1]);
                }
            }
        }
        return resultV[size - 1];
    }
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        int size = arr.size();
        vector<int> resultV(size + 1);
        resultV[0] = 0;

        for (int i = 1; i <= size; i++)
        {

            int tempMax = -1;
            resultV[i] = 0;
            for (int j = i; j > i - k && j >= 1; j--)
            {
                tempMax = max(tempMax, arr[j - 1]);

                resultV[i] = max(resultV[i], tempMax * (i - j + 1) + resultV[j - 1]);
            }
        }
        return resultV[size];
    }

    int maxSumAfterPartitioningError(vector<int> &arr, int k)
    {
        int l = arr.size();

        vector<int> resultA(l);
        deque<tuple<int, int>> reduceList; // value index

        int maxV = INT_MIN;
        int p = -1;
        for (int i = 0; i < k && i < l; i++)
        {
            int value = arr[i];
            if (value > maxV)
            {
                maxV = value;
                p = i;
            }

            if (reduceList.empty())
            { // null
                tuple<int, int> t{value, i};
                reduceList.push_back(t);
            }
            else
            {
                while ((!reduceList.empty()) && value > get<0>(reduceList.back()))
                {
                    reduceList.pop_back();
                }
                tuple<int, int> t{value, i};
                reduceList.push_back(t);
            }

            resultA[i] = maxV * (i + 1);
        }

        for (int i = k; i < l; i++)
        {
            int value = arr[i];
            if (reduceList.empty())
            { // null
                tuple<int, int> t(value, i);
                reduceList.push_back(t);
            }
            else
            {
                while ((!reduceList.empty()) && value > get<0>(reduceList.back()))
                {
                    reduceList.pop_back();
                }
                tuple<int, int> t{value, i};
                reduceList.push_back(t);
            }
            auto maxTuple = reduceList.front();
            while ((i - get<1>(maxTuple)) >= k)
            {
                reduceList.pop_front();
                maxTuple = reduceList.front();
            }

            // while(reduceList)

            int a = resultA[i - 1] + value; // k=1

            int b = k * get<0>(maxTuple) + resultA[i - k]; // k=k
            resultA[i] = max(a, b);

            for (auto item : reduceList)
            {
                int tempV = (i - get<1>(item) + 1) * get<0>(item) + resultA[get<1>(item) - 1]; // 获取队列 大值
                resultA[i] = max(tempV, resultA[i]);
                //  tempV =  (i-get<1>(item)+1) * get<0>(item) + resultA[get<1>(item)]; //获取队列 大值
                //  resultA[i] = max(tempV, resultA[i]);
            }

            // cout<<"a:"<<a<<"  b:"<<b<<endl;
            // cout<<"i:"<<i<<"  value:"<<value<<endl;
        }
        // cout<<resultA.<<endl;
        for (int r : resultA)
        {
            cout << r << " ";
        }
        cout << endl;
        return resultA[l - 1];
    }
};
#pragma endregion
int main(int argc, char *sah[]) // sa实际上是指针 无大小
{
    Solution s;
    // countMatches()
}

// Sales_data sd1=Sales_data();
// Sales_data sd2=Sales_data();

// Sales_data sd3= add(sd1,sd2);
// sd3.print(cout,sd3);
// sd1.print(cout,sd1);

// // for(char *s : sa){//error
//     //     cout<<s<<endl;
//     // }
// string s = "";
//     for(int i=0;i<argc;i++){
//         cout<<sa[i]<<endl;
//         s+=sa[i];
//     }
//     cout<<s<<endl;
