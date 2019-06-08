#include <iostream>
#include <vector>
#include <cassert>
#include <tuple>

using namespace std;

class LinearRegression  {
    private:
      vector<double> X;
      vector<double> Y;
      void show_data() {
        cout << "X:" << endl;
        for(auto& x: X) {
            cout << x << " ";
        }
        cout << endl;
        cout << "Y:" << endl;
        for(auto& y: Y) {
            cout << y << " ";
        }
        cout << endl;
      }
      tuple<double, double> get_grad(double a_, double b_) {
          assert(X.size() == Y.size());
          double N = X.size();
          cout << "N:" << N << endl;
          double del_a_E = 0;
          double del_b_E = 0;
          for(int i = 0; i < N; i++) {
              del_a_E += X[i] * (Y[i] - (a_*X[i] + b_));
              del_b_E += Y[i] - (a_ * X[i] + b_);
          }
          return make_tuple((-2)*del_a_E*(1/N), (-2)*del_b_E*(1/N));
          //return make_tuple((double)((-2)*del_a_E*(1/(double)N)), (double)((-2)*del_b_E*(1/(double)N)));
      }
    public:
      LinearRegression() {}
      LinearRegression(vector<double>& x_, vector<double>& y_): X(x_), Y(y_) {}
      ~LinearRegression() {}

      tuple<double, double> train(double numIterations, double init_a, double init_b) {
          show_data();
          double alpha_ = 0.02;
          double a_ = init_a;
          double b_ = init_b;
          for(int i=0; i < numIterations; i++) {
              tuple<double, double> grads = get_grad(a_, b_);
              cout << "grad_a:" << get<0>(grads) << " grad_b:" << get<1>(grads) << endl;
              a_ = a_ - ((alpha_ * get<0>(grads)));
              b_ = b_ - ((alpha_ * get<1>(grads)));
          }
          cout << "a_:" << a_ << ", b_:" << b_ << endl;
          return make_tuple(a_, b_);
      }
};

int main(const int argc, const char* argv[]) {
    vector<double> y{4.3, 3.2, 3.1, 2.8, 5.1};
    vector<double> x{1, 2, 3, 4, 5};

    for(int i=0; i<argc; i++) {
        cout << argv[i] << endl;
    }

    LinearRegression lr(x, y);
    tuple<double, double> coefs = lr.train(1000, 3.2, 4.1);
    cout << get<0>(coefs) << " " << get<1>(coefs) << endl;
    return 0;
}