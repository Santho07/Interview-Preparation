//https://www.geeksforgeeks.org/product-nodes-k-th-level-tree-represented-string/

// C++ implementation to find sum of
// digits of elements at k-th level
#include <bits/stdc++.h>
using namespace std;

// Function to find sum of digits
// of elements at k-th level
int sumAtKthLevel(string tree, int k)
{
    int level = -1;
    int sum = 0; // Initialize result
    int n = tree.length();

    for (int i = 0; i < n; i++) {
        // increasing level number
        if (tree[i] == '(')
            level++;

        // decreasing level number
        else if (tree[i] == ')')
            level--;

        else {
            // check if current level is
            // the desired level or not
            if (level == k)
                sum += (tree[i] - '0');
        }
    }

    // required product
    return sum;
}

// Driver program
int main()
{
    string tree = "(0(5(6()())(4()(9()())))(7(1()())(3()())))";
    int k = 2;
    cout <<sumAtKthLevel(tree, k);
    return 0;
}
