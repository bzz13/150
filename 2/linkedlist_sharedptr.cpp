#include "linkedlist_sharedptr.h"
#include <iostream>
#include <algorithm>

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

    {
        cout << endl;
        linkedlist<int> le;
        cout << le.is_polindrom() << " " << true << endl;
        linkedlist<int> l0({1});
        cout << l0.is_polindrom() << " " << true << endl;

        linkedlist<int> l1({1,2,3,2,1});
        cout << l1.is_polindrom() << " " << true << endl;
        linkedlist<int> l2({1,2,2,1});
        cout << l2.is_polindrom() << " " << true << endl;

        linkedlist<int> l3({1,2,3,4,1});
        cout << l3.is_polindrom() << " " << false << endl;
        linkedlist<int> l4({1,2,3,3,4,1});
        cout << l4.is_polindrom() << " " << false << endl;
    }
    {
        cout << endl;
        linkedlist<int> list = {1, 3, 6, 4, 2, 10};
        cout << list << endl;
        cout << "find 4" << endl;
        for(auto f = find(list.begin(), list.end(), 4); f != list.end(); ++f)
        {
            cout << *f << " -> ";
        }
        cout << endl;
    }

    return 0;
}
