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
        cout << endl;
        linkedlist<int> list({1,2,3,4,5,1,2,3,6,7,3});
        cout << list << endl;
        list.remove_duplicates_values();
        cout << list << endl;
        list.add(8);
        cout << list << endl;
    }
    {
        cout << endl;
        linkedlist<int> list({1,2,3,4,5,1,2,3,6,7,3});
        cout << list << endl;
        list.remove_duplicates_values2();
        cout << list << endl;
        list.add(8);
        cout << list << endl;
    }

    return 0;
}
