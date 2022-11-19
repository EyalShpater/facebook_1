#include <iostream>
#include <list>

#include "time.h"
#include "date.h"

using namespace std;

int main()
{
    cout << "hello" << endl;
    Time t(22, 00, 32);
    Date d(19, 11, 2021);

    t.show();
    d.show();
    
    return 0;
}
