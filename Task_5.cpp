#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
using namespace std;

bool TrialDivision (uint64_t n)
{
    if (n < 2)
        return false;
    if (n < 4)
        return true;
    if ((n & 1) == 0)
        return false;
    for (uint64_t i = 3; i <= (uint64_t) sqrt(n); i += 2)
        if (n % i == 0)
            return false;
    return true;
}
template <typename T>T BitCount (T input)
{
    T res = 0;
    static const unsigned shift_size = ((sizeof(T) * 8) - 1);
    if(input < 0)
    {
        res ++;
        input &= ( (1 << shift_size) - 1 );
    }
    while(input)
    {
        res += (input & 1);
        input >>= 1;
    }
    return res;
}
int main ()
{
    uint64_t f;
    for (f = 1; f <= 0xFFFFFFFFFFFFFFFF; f++)
    {
        if (TrialDivision(f) && BitCount(f) == 2)
        {
            cout << dec << f << "\t" << hex << f << endl;
            
        }
       ;
    }
  //  exit(0); 
  return 0;
}
