#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

void generate_possibilities(string tiles, set<string> &p, int index = 0) {
  if (index >= tiles.length())
    return;

  // insert the current tile
  p.insert(string(1, tiles[index]));

  string remaining_tiles = tiles.substr(0, index) + tiles.substr(index + 1);

  for (int i = 0; i < tiles.length() - 1; i++) {
    for (int j = 0; j < tile.length() - i - 1; j++) {

      // add the current tile at the start
      p.insert(tiles[index] + remaining_tiles.substr(0, j));
      // add the current tile at the end
      p.insert(remaining_tiles.substr(0, j) + tiles[index]);

      for (int k = 1; k < j; k++)
        p.insert(remaining_tiles.substr(0, k) + tiles[index] +
                 remaining_tiles.substr(k + 1, j));
    }
  }

  return generate_possibilities(tiles, p, index + 1);
}

int letter_tile_possibilities(string tiles) {
  set<string> possibilities;

  generate_possibilities(tiles, possibilities);

  for (string s : possibilities)
    cout << s << endl;

  return possibilities.size();
}

int main() {
  int t;
  cin >> t;

  while (t > 0) {
    t--;

    string s;
    cin >> s;

    int result = letter_tile_possibilities(s);
    cout << result << '\n';
  }

  return 0;
}
