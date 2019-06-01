#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Superset {
private:
    vector<vector<int>> S;
    vector<int> init;
    void generate_set(vector<int> &v, int index) {
        if(index == init.size()){
            S.push_back(v);
            return;
        }
        else {
            v.push_back(init[index]);
            generate_set(v, index+1);
            v.pop_back();
            generate_set(v, index+1);
        }
    }
public:
    explicit Superset(const vector<int>& in) {
        if(! in.empty()) {
            init = in;
        }
    }
    vector<vector<int>> get_supersets() {
        vector<int> v;
        generate_set(v, 0);
        return S;
    }
    friend ostream& operator<<(ostream &o, Superset& sup) {
        for(auto & i: sup.S) {
           for(auto & ii:i) {
               o << ii;
           }
           o << endl;
        }
        return o;
    }
};

int main() {
    vector<int> v = {1, 2, 3};
    Superset s = Superset(v);
    vector<vector<int>> supersets = s.get_supersets();
    cout << "Superset:" << s;
    short size_s = supersets.size();
    short v_size = v.size();
    assert((1<<v_size) == size_s);
    return 0;
}