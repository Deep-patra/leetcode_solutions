/*
Final Prices with a special discount in a shop

Problem:

You are given an integer array prices where prices[i] is the price of the ith
item in a shop.

There is a special discount for items in the shop. If you buy the ith item, then
you will receive a discount equivalent to prices[j] where j is the minimum index
such that j > i and prices[j] <= prices[i]. Otherwise, you will not receive any
discount at all.

Return an integer array answer where answer[i] is the final price you will pay
for the ith item of the shop, considering the special discount.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> final_price_with_a_special_discount_in_shop(vector<int> &prices) {
  vector<int> answer;
  answer.resize(prices.size());

  if (prices.size() == 1) {
    answer.push_back(prices[0]);
    return answer;
  }

  for (int i = 0; i < prices.size(); i++) {
    int price = prices[i];

    int j = i + 1;
    while (j < prices.size()) {
      if (prices[j] <= prices[i]) {
        price = prices[i] - prices[j];
        break;
      }

      j++;
    }

    answer[i] = price;
  }

  return answer;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int test_cases = 0;
  cin >> test_cases; // Get number of testcases

  for (int i = 0; i < test_cases; i++) {

    int elements = -1;
    cin >> elements;

    vector<int> nums;

    while (elements > 0) {
      elements--;

      int num = 0;
      cin >> num;

      nums.push_back(num);
    }

    vector<int> answer = final_price_with_a_special_discount_in_shop(nums);

    for (auto value : answer) {
      cout << value << " ";
    }
    cout << "\n";
  }

  return 0;
}
