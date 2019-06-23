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

    double* s = new double[3];
    s[0] = 3.14;
    s[1] = 2.15;
    s[2] = 4.2;
    s[4] = 1.3; // Why did't it result into compile time error?
    cout << "*s=" << s[4] << endl;
    delete[] s;
    cout << "*s=" << s[4] << endl; // Why is this still accessible?
    
}