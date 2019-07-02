#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <ext/pb_ds/assoc_container.hpp>

int main(int argc, const char* argv[]) {
    for(int i=0; i< argc; i++) {
        std::cout << *(argv + i) << std::endl;
    }
    std::priority_queue<int> q;
    q.push(3);
    q.push(5);
    q.push(11);
    q.push(1);
    q.push(7);
    int x = q.top();
    q.pop();
    x = q.top();
    std::cout << "x is : " << x << std::endl;

    // policy based data structures
    using namespace __gnu_pbds;
    typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
    indexed_set s;
    s.insert(2);
    s.insert(3);
    s.insert(7);
    s.insert(9);
    auto* x = find_by_order(2);
    std::cout << *x << std::endl;
}