#include <iostream>
#include <vector>
#include <numeric>
#include <variant>
using namespace std;

// Union and Variant
struct Node{
    int val;
    Node* next;
    Node(int v): val(v), next(nullptr) {}
};
struct Entry{
    string name;
    variant<Node*, int> v;
};

int main() {
    vector<int> t{2, 3, 4, 5, 6};
    cout << reduce(begin(t), end(t)) << endl;

    //Union and Variant
    Node x(10);
    Node y(11);
    x.next = &y;

    Entry obj;
    obj.name = "test";
    obj.v = &x;

    if(holds_alternative<int>(obj.v)) {
        cout << obj.name << ", " << get<int>(obj.v) << endl;
    }

    if(holds_alternative<Node*>(obj.v)) {
        Node* a = get<Node*>(obj.v);
        cout << "Node* value: " << a->val << endl;
    } 
}