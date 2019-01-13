#include <iostream>
using namespace std;

#include "MyLinkedList.h"

int main (int argc, char const* argv[])
{
    double points = 2;

    MyLinkedList m;

    // test constructor
    if ( m.isEmpty() == true )
        points += 1.0;
    else
        cout << "T1 failed\n";

    m.insert(3);
    m.print();
    // test is empty
    if ( m.isEmpty() == false )
        points += 1.0;
    else
        cout << "T2 failed\n";


    m.insert(1);
    m.print();
    m.insert(5);
    m.print();
    m.insert(7);
    m.print();

    // test search & insert
    if ( m.search(1) == true )
        points += 1.0;
    else
        cout << "T3 failed\n";

    if ( m.search(7) == true )
        points +=1.0;
    else
        cout << "T4 failed\n";

    // test remove
    m.remove(1);
    m.print();

    if ( m.search(1) == false )
        points += 1.0;
    else
        cout << "T5 failed\n";


    m.insert(1);
    m.print();
    m.remove(5);
    m.print();

    if ( m.search(5) == false )
        points += 1.0;
    else
        cout << "T6 failed\n";

    m.insert(5);
    m.print();

    m.remove(7);
    m.print();
    if ( m.search(7) == false )
        points += 1.0;
        else
        cout << "T7 failed\n";


    m.print();

    m.~MyLinkedList();

    if ( m.isEmpty() == true )
        points++;
    else
        cout << "T8 failed\n";


    m.print();
    cout << "Points=" << points << endl;




    return 0;
}
