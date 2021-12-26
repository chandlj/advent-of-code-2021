#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "../utils/utils.h"

using namespace std;

int main()
{
  vector<string> lines = open_file("07/day7.txt");
  vector<string> line = split_string(lines[0], ",");
  vector<int> entries;
  transform(line.begin(), line.end(), back_inserter(entries), [](const string s) {return stoi(s);});

  float global_min = INFINITY;
  int max_elem = *max_element(entries.begin(), entries.end());
  int top = floor(max_elem / 2);
  for (int target = 1; target < top; ++target) {
    int fuel = 0;
    for (int i = 0; i < entries.size(); ++i) {
      int entry = entries[i];
      int n = abs(entry - target);
      int sum = {(n*(n+1)) / 2};
      fuel += (n + sum);
    }
    if (fuel < global_min) {
      global_min = fuel;
    }
  }
  int answer = global_min;
  cout << answer << endl;
  return 0;
}