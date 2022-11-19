#include <iostream>
#include <ctime>

#include "time.h"
#include "date.h"

using namespace std;

int main()
{
    cout << "hello" << endl;
    Time t(22, 00, 32);
    Date d(19, 11, 2021);

    time_t t1;

    t.show();
    d.show();
    t1 = time(nullptr);

    cout << asctime(localtime(&t1));
    return 0;
}
