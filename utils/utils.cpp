#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <unordered_set>
#include <fstream>

#include "./utils.h"

using namespace std;

void print(unordered_set<int> &s)
{
  copy(s.begin(), s.end(), ostream_iterator<int>(cout, "\n"));
}

void print(unordered_set<string> &s)
{
  copy(s.begin(), s.end(), ostream_iterator<string>(cout, "\n"));
}

void print(vector<int> s)
{
  cout << "[ ";
  copy(s.begin(), s.end(), ostream_iterator<int>(cout, ", "));
  cout << "]" << endl;
}

void print(vector<string> &s)
{
  cout << "[ ";
  copy(s.begin(), s.end(), ostream_iterator<string>(cout, ", "));
  cout << "]" << endl;
}

vector<string> slice_vector(vector<string> &vec, int i, int j) 
{
  auto start = vec.begin() + i;
  auto end = vec.begin() + j + 1;

  vector<string> result (j - i + 1);

  copy(start, end, result.begin());

  return result;
}

vector<string> open_file(string filename)
{
  string line;
  ifstream file (filename);
  vector<string> lines {};
  if (file.is_open()) {
    while (getline(file, line)) {
      lines.push_back(line);
    }
  }

  return lines;
}

vector<string> split_string(string line, string delimiter)
{
  size_t pos = 0;
  string token;
  vector<string> instr;
  while ((pos = line.find(delimiter)) != string::npos) {
    token = line.substr(0, pos);
    instr.push_back(token);
    line.erase(0, pos + delimiter.length());
  }
  instr.push_back(line);

  return instr;
}