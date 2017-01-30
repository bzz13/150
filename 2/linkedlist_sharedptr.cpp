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
    {
        cout << endl;
        linkedlist<int> list({7,6,5,4,3,2,1,0});
        cout << list.find_k_from_end(0) << " " << 0 << endl;
        cout << list.find_k_from_end(1) << " " << 1 << endl;
        cout << list.find_k_from_end(2) << " " << 2 << endl;
        cout << list.find_k_from_end(3) << " " << 3 << endl;
        cout << list.find_k_from_end(4) << " " << 4 << endl;
        cout << list.find_k_from_end(5) << " " << 5 << endl;
        cout << list.find_k_from_end(6) << " " << 6 << endl;
        cout << list.find_k_from_end(7) << " " << 7 << endl;
    }

    return 0;
}
