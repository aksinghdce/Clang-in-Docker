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
        tuple<int, int> result;
        while(i < array_size) {
            auto search = dictionary.find(target - array[i]);
            if(search != dictionary.end()) {
                result = make_tuple(i, search->second);
                return result;
            } else {
                dictionary.try_emplace(array[i], i);
            }
            i += 1;
        }
        result = make_tuple(-1, -1);
        return result;
    }

};

int main() {
    vector<int> input_array{1, 3, 4, 6};
    TwoSum twosum(input_array, 9);
    tuple<int, int> result = twosum.get_two_index();
    cout << get<0>(result) << "," << get<1>(result) << endl;
}