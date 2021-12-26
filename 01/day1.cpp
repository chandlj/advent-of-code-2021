#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

#include "../utils/utils.h"

using namespace std;

int main() {
  vector<string> lines = open_file("01/day1.txt");
  vector<int> entries;
  transform(lines.begin(), lines.end(), back_inserter(entries), [](const string s) {return stoi(s);});

  int answer = 0;
  for (int i = 1; i < entries.size(); ++i) {
    if (entries[i] > entries[i-1]) answer += 1;
  }

  cout << answer << endl;

  answer = 0;
  int sum1 = 0;
  int sum2 = 0;
  for (int i = 4; i < entries.size(); ++i) {
    sum1 = 0;
    sum2 = 0;
    for (int j = (i-3); j < i; ++j) {
      sum1 += entries[j];
      sum2 += entries[j-1];
    }

    if (sum1 > sum2) answer += 1;
  }

  cout << answer << endl;

  return answer;
}