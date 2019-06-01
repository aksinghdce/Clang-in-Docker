#include <iostream>
#include <vector>
#include <map>
#include <tuple>

using namespace std;

class TwoSum {
    vector<int> array;
    int target;
  public:
    TwoSum(vector<int> seq, int sum) {
        array = seq;
        target = sum;
    }
    tuple<int, int> get_two_index() {
        int i=0;
        int array_size = array.size();
        map<const int, int> dictionary;
        while(i < array_size) {
            auto search = dictionary.find(target - array[i]);
            if(search != dictionary.end()) {
                return tuple(i, dictionary.extract(*search));
            } else {
                dictionary.emplace(array[i], i);
            }
            i += 1;
        }
        return tuple(-1, -1);
    }

};

int main() {
    TwoSum twosum([1, 3, 4, 6], 9);
    tuple<int, int> result = twosum.get_two_index();
    cout << result << endl;
}