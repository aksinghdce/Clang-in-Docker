#include <iostream>
#include <vector>

using namespace std;

class MedianTwoSortedArray{
    private:
        int get_kth_smallest(vector<int> A1, vector<int> A2, int k) {
            int l1 = A1.size() / 2;
            int l2 = A2.size() / 2;
            if(A1.size() == 0) {
                return A2[k];
            }
            if(A2.size() == 0) {
                return A1[k];
            }
            int m1 = A1[l1];
            int m2 = A2[l2];
            if(l1+l2 < k) {
                //median must be in the later half of A1 or A2
                if(m1<m2) {
                    //median must be in later half of A1
                    vector<int> vec(A1.cbegin() + l1 + 1 , A1.cend());
                    return get_kth_smallest(vec, A2, k-l1 - 1);
                }else {
                    vector<int> vec(A2.cbegin() + l2 + 1, A2.cend());
                    return get_kth_smallest(A1, vec, k-l2 - 1);
                }
            } else {
                //median must be in earlier half of A1 or A2
                if(m1<m2) {
                    // median must be in earlier half of A2
                    vector<int> vec(A2.cbegin(), A2.cbegin() + l2);
                    return get_kth_smallest(A1, vec, k);
                } else{
                    vector<int> vec(A1.cbegin(), A1.cbegin() + l1);
                    return get_kth_smallest(vec, A2, k);
                }
            }
        }
    public:
        int get_median(vector<int> &arr1, vector<int> &arr2) {
            int result = 0;
            int l1 = arr1.size();
            int l2 = arr2.size();
            int l = l1+l2;
            if(l%2) /*l1+l2 is odd*/ {
                result = get_kth_smallest(arr1, arr2, l/2 + 1);
            } else {
                result = (get_kth_smallest(arr1, arr2, l/2) + get_kth_smallest(arr1, arr2, l/2 + 1)) / 2;
            }
            return result;
        }
};

int main() {
    MedianTwoSortedArray msa;
    vector<int> A{0, 2};
    vector<int> B{1, 3};
    int result = msa.get_median(A, B);
    cout << result << endl;
}