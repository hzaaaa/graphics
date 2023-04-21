#include <string>
#include <iostream>
using namespace std;
class Sales_data
{
private:
    /* data */
public:
    string bookNo;
    unsigned units_sold;
    double revenue;
    Sales_data(/* args */);
    ~Sales_data();
     double avg_price() const
    {
        return revenue / units_sold;
    }
    string isbn()
    {
        return bookNo;
    }
    Sales_data &combine(Sales_data &sd)
    {
        Sales_data& sd3 = *this;
        sd3.revenue = sd.revenue + revenue;
        sd3.units_sold = sd.units_sold + units_sold;
        return sd3;
    }

    istream &read(istream &is, Sales_data &sd)
    {
        
        cout << "new item" << endl;
        double price = 0;
        cout << "bookNo:";
        is >> sd.bookNo;
        cout << "units_sold:";
        is >> sd.units_sold;
        cout << "price:";
        is >> price;
        sd.revenue = sd.units_sold * price;
        return is;
    }
    ostream &print(ostream &os,const Sales_data &sd)
    {
        os << sd.bookNo << "     " << sd.units_sold << "    " << sd.revenue << endl;
        os << sd.avg_price() << endl;
        return os;
    }
};

Sales_data::Sales_data(/* args */)
{
    read(cin, *this);
}

Sales_data::~Sales_data()
{
}
Sales_data add(const Sales_data &lsd, Sales_data &rsd)//局部不可返回引用 ，可返回非引用（赋值）
{
    Sales_data sum = lsd;
    sum.combine(rsd);
    return sum;
}
