#include <vector>
#include <string>
#include <iostream>
#include <regex>

#include "../utils/utils.h"

using namespace std;

bool checkTarget(const int x, const int y, vector<int> &coords) { 
  return ((coords[0] <= x) && (x <= coords[1]) && (coords[2] <= y) && (y <= coords[3]));
};
bool inBounds(const int x, const int y, vector<int> &coords) {
  return ((x <= coords[1]) && (y >= coords[2]));
};

vector<int> get_tokens(string data)
{
  regex word_regex("(-?\\d+)");
  auto words_begin = sregex_iterator(data.begin(), data.end(), word_regex);
  auto words_end = sregex_iterator();

  vector<int> matches;
  for (sregex_iterator i = words_begin; i != words_end; ++i) {
      smatch match = *i;
      int match_str = stoi(match.str());
      matches.push_back(match_str);
  }

  return matches;
}

int simulate(int vx, int vy, vector<int> &coords)
{
  int x = 0;
  int y = 0;
  int max_y = 0;
  bool hit_target = false;
  while (!hit_target && inBounds(x, y, coords)) {
    x += vx;
    y += vy;
    max_y = max(max_y, y);
    vx = max(vx-1, 0);
    vy -= 1;

    hit_target = checkTarget(x, y, coords);
  }

  return hit_target;
}

int main()
{
  vector<string> lines = open_file("17/day17.txt");
  string data = lines[0];

  vector<int> coords = get_tokens(data);

  int maximum = 0;
  for (int vx = 0; vx < 1000; ++vx) {
    for (int vy = -1000; vy < 1000; ++vy) {
      maximum += simulate(vx, vy, coords);
    }
  }
  cout << maximum << endl;
}