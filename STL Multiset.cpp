
#include <bits/stdc++.h>
using namespace std;
int main()
{

    multiset<int> s;

    // Function to insert elements
    // in the set container
    s.insert(1);
    s.insert(4);
    s.insert(1);
    s.insert(5);
    s.insert(1);
    multiset<int>::iterator it;

    cout << "The elements in multiset are: ";
    for ( it = s.begin(); it != s.end(); it++)
        cout << *it << " ";

    return 0;
}
