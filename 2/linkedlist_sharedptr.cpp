#include "linkedlist_sharedptr.h"
#include <iostream>

using namespace std;

int main()
{
    {
        linkedlist<int> list;
        list.add(1);
        list.add(2);
        list.add(3);
        cout << list << endl;
        list.remove_first_of(0);
        cout << list << endl;
        list.remove_first_of(1);
        cout << list << endl;
        list.remove_first_of(3);
        cout << list << endl;

        list.add(4);
        cout << list << endl;

        list.clear();
        cout << list << endl;
    }
    {
        linkedlist<int> list({1,2,3,4,5});
        cout << list << endl;
    }

    return 0;
}
