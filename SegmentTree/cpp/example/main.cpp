#include "SegmentTree.h"
#include <vector>
#include <iostream>
using namespace std;


int main()
{
    vector<int> input = {1, 2, 3, 4, 5, 6, 7, 8};
    SegmentTree tree(input);

    cout << tree.RangeQuery(1, 3) << endl;
    tree.Update(1, 100);
    cout << tree.RangeQuery(1, 3) << endl;
    tree.RangeUpdate(1, 5, 4);
    cout << tree.RangeQuery(1, 3) << endl;
}