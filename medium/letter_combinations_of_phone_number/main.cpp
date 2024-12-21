#include <iostream>
#include <string>
#include <vector>
using namespace std;

static vector<char> mappings[] = {{}, // empty for number "0"
                                  {}, // empty for number "1"
                                  {'a', 'b', 'c'},
                                  {'d', 'e', 'f'},
                                  {'g', 'h', 'i'},
                                  {'j', 'k', 'l'},
                                  {'m', 'n', 'o'},
                                  {'p', 'q', 'r', 's'},
                                  {'t', 'u', 'v'},
                                  {'w', 'x', 'y', 'z'}};

template <typename T> void print_vector(vector<T> vec) {
  for (auto val : vec)
    cout << val << " ";

  cout << '\n';
}

// Pop the first element from the string
void pop_string(string &str) {
  string s = "";

  int i = 1;
  while (i < str.length()) {
    s.push_back(str[i]);
    i++;
  }

  str = s;
}

vector<string> letter_combinations_of_phone_number(string digits) {
  string temp_digits = digits;
  vector<string> result;

  while (temp_digits.length() > 0) {
    int digit = temp_digits[0] - '0';

    vector<char> mapping = mappings[digit];
    vector<string> temp;

    for (int i = 0; i < mapping.size(); i++) {

      string curr_char;
      curr_char.push_back(mapping[i]);

      if (result.size() == 0) {
        temp.push_back(curr_char);

      } else {
        for (int j = 0; j < result.size(); j++) {
          temp.push_back(result[j] + curr_char);
        }
      }
    }

    result = temp;
    pop_string(temp_digits);
  }

  return result;
}

int main() {

  int testcases;
  cin >> testcases;

  while (testcases > 0) {
    testcases--;

    string digits = "";
    cin >> digits;

    cout << "Input => " << digits << '\n';

    vector<string> result = letter_combinations_of_phone_number(digits);

    print_vector(result);
  }

  return 0;
}
