#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "utils.hh"

using namespace std;

vector<string> split_commands(string line)
{
  return split_string(line, " ");
}

int main() {
  vector<string> lines = open_file("02/day2.txt");
  vector<vector<string> > entries;
  transform(lines.begin(), lines.end(), back_inserter(entries), split_commands);
  
  int horiz = 0;
  int depth = 0;
  int aim = 0;
  for (int i = 0; i < entries.size(); ++i) {
    string action = entries[i][0];
    int value = stoi(entries[i][1]);

    if (action == "forward") {
      horiz += value;
      depth += (aim * value);
    } else if (action == "backward") {
      horiz -= value;
      horiz -= (aim * value);
    } else if (action == "up") {
      aim -= value;
    } else {
      aim += value;
    }
  }

  int answer = { horiz * depth };
  cout << answer << endl;
  return answer;
}