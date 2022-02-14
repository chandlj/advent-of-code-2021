#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>

#include "../utils/utils.h"

using namespace std;

vector<string> make_entries(string line)
{
  vector<string> entry ( line.size() );
  for (int i = 0; i < line.size(); ++i) {
    entry[i] = line[i];
  }

  return entry;
}

int main()
{
  vector<string> lines = open_file("10/day10.txt");
  vector<vector<string> > entries;
  transform(lines.begin(), lines.end(), back_inserter(entries), &make_entries);

  unordered_set<string> openings ({ "(", "<", "[", "{" });
  unordered_map<string, string> closing_map ({ { "(", ")" } , { "<", ">" } , { "[", "]" } , { "{", "}" } });
  vector<vector<string> > errors;
  for (int i = 0; i < entries.size(); ++i) {
    vector<string> stack;
    bool incomplete = true;
    for (int j = 0; j < entries[i].size(); ++j) {
      string c = entries[i][j];
      if (openings.find(c) != openings.end()) {
        stack.push_back(c);
      } else {
        string opening = stack.back();
        stack.pop_back();
        string closing = closing_map[opening];
        if (closing != c) {
          incomplete = false;
          break;
        }
      }
    }
    if (incomplete) {
      vector<string> closings ( stack.size() );
      for (int k = 0; k < stack.size(); ++k) {
        closings[k] = closing_map[stack[k]];
      }
      reverse(closings.begin(), closings.end());
      errors.push_back(closings);
    }
  }

  vector<size_t> scores ( errors.size() );
  for (int i = 0; i < errors.size(); ++i) {
    size_t score = 0;
    for (int j = 0; j < errors[i].size(); ++j) {
      score *= 5;
      if (errors[i][j] == ")") {
        score += 1;
      } else if (errors[i][j] == "]") {
        score += 2;
      } else if (errors[i][j] == "}") {
        score += 3;
      } else {
        score += 4;
      }
    }
    scores[i] = score;
  }

  sort(scores.begin(), scores.end());

  int idx = floor(scores.size() / 2);
  cout << scores[idx] << endl;
  return 0;
}