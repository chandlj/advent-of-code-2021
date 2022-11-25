#include <vector>
#include <string>
#include <iostream>

#include "utils.hh"

using namespace std;

vector<vector<int> > transform_line(string line)
{
  string arrow = " -> ";
  int index = line.find(arrow);
  line.replace(index, arrow.size(), " ");
  vector<string> result = split_string(line, " ");
  vector<vector<int> > commands;
  vector<string> comms1 = split_string(result[0], ",");
  vector<string> comms2 = split_string(result[1], ",");
  vector<int> c1;
  vector<int> c2;
  transform(comms1.begin(), comms1.end(), back_inserter(c1), [](const string s) {return stoi(s);});
  transform(comms2.begin(), comms2.end(), back_inserter(c2), [](const string s) {return stoi(s);});
  commands.push_back(c1);
  commands.push_back(c2);
  return commands;
}

int main()
{
  vector<string> lines = open_file("05/day5.txt");
  vector<vector<vector<int> > > entries;
  transform(lines.begin(), lines.end(), back_inserter(entries), transform_line);

  int max_x = 0;
  int max_y = 0;
  int x = 0;
  int y = 0;

  for (int i = 0; i < entries.size(); ++i) {
    for (int j = 0; j < entries[0].size(); ++j) {
      x = entries[i][j][0];
      y = entries[i][j][1];
      if (x > max_x) max_x = x;
      if (y > max_y) max_y = y;
    }
  }

  vector<vector<int> > arr (max_y + 1, vector<int> (max_x + 1, 0));

  for (int i = 0; i < entries.size(); ++i) {
    vector<vector<int> > entry = entries[i];
    vector<int> point1 = entry[0];
    vector<int> point2 = entry[1];
    int x1 = point1[0];
    int y1 = point1[1];
    int x2 = point2[0];
    int y2 = point2[1];
    if (x1 == x2) {
      for (int y = min(y1, y2); y < (max(y1, y2) + 1); ++y) {
        arr[y][x1]++;
      }
    } else if (y1 == y2) {
      for (int x = min(x1, x2); x < (max(x1, x2) + 1); ++x) {
        arr[y1][x]++;
      }
    } else {
      if (x1 < x2) {
        int i = 0;
        for (int x = x1; x < (x2 + 1); ++x) {
          if (y1 < y2) {
            arr[y1 + i][x]++;
          } else {
            arr[y1 - i][x]++;
          }

          ++i;
        }
      } else {
        int i = 0;
        for (int x = x2; x < (x1 + 1); ++x) {
          if (y1 < y2) {
            arr[y2 - i][x]++;
          } else {
            arr[y2 + i][x]++;
          }
          ++i;
        }
      }
    }
  }

  int ans = 0;
  for (int j = 0; j < arr.size(); ++j) {
    for (int i = 0; i < arr[0].size(); ++i) {
      if (arr[j][i] > 1) ans += 1;
    }
  }
  cout << ans << endl;

  return 0;
}