#include <iostream>
#include <tuple>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Solution {
    public:
        string convert(string s, int numRows) {
            if(1 >= numRows) {
                return s;
            }
            map<tuple<int, int>, char> matrix;
            bool goingDown = true;
            int row{0};
            int col{0};
            string result = "";
            vector<tuple<int, int>> keys;
            for(char ss: s) {
                // put value into matrix
                matrix.emplace(make_tuple(row, col), ss);
                if(goingDown) {
                    row += 1;
                } else {
                    row -= 1;
                    col += 1;
                }
                if(numRows - 1 == row or 0 == row ) { goingDown = ! goingDown;}
            }
            for(auto const& [key, val]: matrix) {
                keys.push_back(key);
            }
            sort(keys.begin(), keys.end());
            for(auto const& key: keys) {
                result += matrix[key];
            }
            return result;
        }
};

int main() {
    Solution sol;
    string result = sol.convert("Amit Kumar Singh", 5);
    cout << result << endl;
}