#include <assert.h>
#include <iostream>
#include <vector>
using namespace std;

class ProductOfNumbers {
private:
  vector<int> nums;

public:
  ProductOfNumbers() {}

  void add(int num) { this->nums.push_back(num); }

  int getProduct(int k) {
    int product = 1;

    int i = nums.size() - 1, end = nums.size() - k;
    while (product != 0 && end <= i) {
      product *= this->nums[i];
      i--;
    }

    return product;
  }
};

int main() {

  ProductOfNumbers p1;

  p1.add(1);

  assert(p1.getProduct(1) == 1);
  assert(p1.getProduct(1) == 1);
  assert(p1.getProduct(1) == 1);

  ProductOfNumbers p;

  p.add(3);
  p.add(0);
  p.add(2);
  p.add(5);
  p.add(4);

  assert(p.getProduct(2) == 20);
  assert(p.getProduct(3) == 40);

  p.add(8);
  assert(p.getProduct(2) == 32);
  return 0;
}
