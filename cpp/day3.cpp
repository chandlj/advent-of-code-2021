#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>

#include "utils.hh"

using namespace std;

vector<string> get_most_common(vector<vector<string> > &list) {
  int ones = 0;
  int zeros = 0;
  for (int i = 0; i < list.size(); ++i) {
    vector<string> entry = list[i];
    string digit = entry[entry.size() - 1];
    if (digit == "1") {
      ones += 1;
    } else {
      zeros += 1;
    }
  }

  vector<string> return_vec;
  if (ones >= zeros) {
    return_vec.push_back("1");
    return_vec.push_back("0");
    return return_vec;
  }
  return_vec.push_back("0");
  return_vec.push_back("1");
  return return_vec;
}

vector<string> reverse_digits(string line)
{
  vector<string> digits;
  for (int i = 0; i < line.size(); ++i) {
    string digit(1, line[i]);
    digits.push_back(digit);
  }

  return digits;
}


int main() {
  vector<string> lines = open_file("03/day3.txt");
  vector<vector<string> > filtered;
  transform(lines.begin(), lines.end(), back_inserter(filtered), reverse_digits);
  int N = filtered.size();

  vector<vector<string> > entries = filtered;
  string oxygen = "";
  for (int i = 0; i < N; ++i) {
    string most = "";
    vector<string> result = get_most_common(entries);
    most = result[0];
    oxygen.append(most);
    vector<vector<string> > new_entries;
    for (int i = 0; i < entries.size(); ++i) {
      if (entries[i][entries[i].size() - 1] == most) {
        vector<string> new_entry;
        for (int j = 0; j < entries[i].size() - 1; ++j) {
          string c = entries[i][j];
          new_entry.push_back(c);
        }
        new_entries.push_back(new_entry);
      }
    }
    if (new_entries.size() == 1) {
      vector<string> entry = new_entries[0];
      reverse(entry.begin(), entry.end());
      for (int i = 0; i < entry.size(); ++i) {
        string c = entry[i];
        oxygen.append(c);
      }
      break;
    } else {
      entries = new_entries;
    }
  }
  cout << oxygen << endl;

  entries = filtered;
  string co2 = "";
  for (int i = 0; i < N; ++i) {
    string least = "";
    vector<string> result = get_most_common(entries);
    least = result[1];
    co2.append(least);
    vector<vector<string> > new_entries;
    for (int i = 0; i < entries.size(); ++i) {
      if (entries[i][entries[i].size() - 1] == least) {
        vector<string> new_entry;
        for (int j = 0; j < entries[i].size() - 1; ++j) {
          string c = entries[i][j];
          new_entry.push_back(c);
        }
        new_entries.push_back(new_entry);
      }
    }
    if (new_entries.size() == 1) {
      vector<string> entry = new_entries[0];
      reverse(entry.begin(), entry.end());
      for (int i = 0; i < entry.size(); ++i) {
        string c = entry[i];
        co2.append(c);
      }
      break;
    } else {
      entries = new_entries;
    }
  }
  cout << co2 << endl;

  reverse(oxygen.begin(), oxygen.end());
  reverse(co2.begin(), co2.end());
  int num1 = 0;
  int num2 = 0;
  for (int i = 1; i < oxygen.size(); ++i) {
    int x = oxygen[i] - '0'; // converts char to integer
    int y = co2[i] - '0';
    num1 += pow(2, (i - 1)) * x;
    num2 += pow(2, (i - 1)) * y;
  }

  int answer = {num1 * num2};
  cout << answer << endl;
  return 0;
}