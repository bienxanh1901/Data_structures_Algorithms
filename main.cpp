#include <iostream>
#include "include/SinglyLinkList.h"

using namespace std;


int main()
{
    cout << "Hello world!" << endl;
    SinglyLinkList<int> intlist;
    int i = 1;
    bool listStatus = intlist.is_empty();
    intlist.push_back(i);
    i++;
    intlist.push_front(i);
    i++;
    intlist.insert(2, i);
    listStatus = intlist.is_empty();
//    cout << intlist.size() << endl;
//    cout << intlist.front() << endl;
//    cout << intlist.back() << endl;
    SinglyLinkList<int> intlist2(intlist);
    SinglyLinkList<int> intlist3;
    intlist3 = intlist2;
    intlist3.sort();
    cout << intlist3.front() << endl;
    cout << intlist3.back() << endl;
    intlist2.erase(2);
    intlist.clear();
    return 0;
}
