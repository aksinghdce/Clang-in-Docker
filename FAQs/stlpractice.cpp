#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    vector<int> t{2, 3, 4, 5, 6};
    cout << reduce(begin(t), end(t)) << endl;
}