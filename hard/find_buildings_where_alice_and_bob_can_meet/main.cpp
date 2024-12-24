#include <cstddef>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

string get_key(int val1, int val2) {
  string s = to_string(val1) + "-" + to_string(val2);
  return s;
}

int get_cache_value(unordered_map<string, int> &cache, int val1, int val2) {
  auto it = cache.find(get_key(val1, val2));

  if (it != cache.end())
    return it->second;

  return NULL;
}

vector<int> left_most_building_queries(vector<int> &buildings,
                                       vector<vector<int>> &queries) {

  unordered_map<string, int> cache;

  vector<int> result(queries.size(), -1);

  for (int i = 0; i < queries.size(); i++) {
    int alice = queries[i][0];
    int bob = queries[i][1];

    if (get_cache_value(cache, alice, bob) != NULL) {
      result[i] = get_cache_value(cache, alice, bob);
      continue;
    }

    // if both are already in the same building
    if (alice == bob) {
      result[i] = alice;
      cache.insert(make_pair(get_key(alice, bob), result[i]));
      continue;
    }

    int height1 = buildings[alice];
    int height2 = buildings[bob];

    // when one of them is ahead and is in the taller building
    // they can meet in the that person's building
    if (alice < bob && height1 < height2) {
      result[i] = bob;
      cache.insert(make_pair(get_key(alice, bob), result[i]));
      continue;
    } else if (bob < alice && height2 < height1) {
      result[i] = alice;
      cache.insert(make_pair(get_key(alice, bob), result[i]));
      continue;
    }

    int max_index = max(alice, bob);        // index of who is ahead
    int max_height = max(height1, height2); // maximum of the both buildings

    int found = -1;
    int index = ++max_index;
    while (index < buildings.size() && found == -1) {

      if (buildings[index] > max_height)
        found = index;

      index++;
    }

    result[i] = found;

    // store in the cache
    cache.insert(make_pair(get_key(alice, bob), found));
  }

  return result;
}

int main() {

  int testcases;
  cin >> testcases;

  while (testcases > 0) {
    testcases--;

    int len, queries_len;
    cin >> len;

    vector<int> buildings;
    for (int i = 0; i < len; i++) {
      int num;
      cin >> num;

      buildings.push_back(num);
    }

    cin >> queries_len;

    vector<vector<int>> queries;
    for (int i = 0; i < queries_len; i++) {
      int first, second;
      cin >> first >> second;

      vector<int> query;
      query.push_back(first);
      query.push_back(second);

      queries.push_back(query);
    }

    vector<int> result = left_most_building_queries(buildings, queries);

    for (int val : result)
      cout << val << " ";

    cout << '\n';
  }

  return 0;
}
