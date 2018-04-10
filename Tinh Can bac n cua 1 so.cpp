#include <iostream>
#include <limits>
 
using namespace std;
 
double _exp(double x)
{
    double s = 0, temp = 1;
    unsigned k = 0;
    while (s != s + temp)
    {
        s += temp;
        k++;
        temp *= x/k;
    }
    return s;
}
 
double _log(double x)
{
    x = x - 1;
    if (-1 < x && x <= 1)
    {
        double s = 0, temp = x;
        unsigned k = 0;
        while (s != s + temp)
            {
                s += temp;
                k++;
                temp *= -x*k/(k+1);
            }
        return s;
    }
    else return _log(1 + 1/x) - _log(1/x);
}
 
double sqrtn(double x, unsigned n)
{
    if (x == 0) return 0;
    else
        if (n%2)
            if (x > 0) return _exp(_log(x)/n);
            else return -_exp(_log(-x)/n);
        else
            if (x > 0) return _exp(_log(x)/n);
            else return numeric_limits<float>::quiet_NaN();
}
 
int main()
{
    double x; unsigned n;
    x = 8; n = 3;
    cout << "Can bac "<< n << " cua " << x << " bang " << sqrtn(x,n) << endl;
    x = -8; n = 3;
    cout << "Can bac "<< n << " cua " << x << " bang " << sqrtn(x,n) << endl;
    x = 16; n = 2;
    cout << "Can bac "<< n << " cua " << x << " bang " << sqrtn(x,n) << endl;
    x = -5; n = 2;
    cout << "Can bac "<< n << " cua " << x << " bang " << sqrtn(x,n) << endl;
}
