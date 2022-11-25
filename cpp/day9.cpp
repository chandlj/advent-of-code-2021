#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <iostream>

#include "utils.hh"

using namespace std;

struct coordinate
{
  int x, y;

  bool operator==(const coordinate &other) const {
    return ((x == other.x) && (y == other.y));
  }

  size_t operator()(const coordinate &coord) const {
    return coord.x ^ coord.y;
  }
};

vector<int> split(string line)
{
  vector<int> line_vec;
  for (int i = 0; i < line.size(); ++i){
    int c = line[i] - '0';
    line_vec.push_back(c);
  }
  return line_vec;
}

vector<coordinate> get_neighbors(int x, int y, int bigx, int bigy)
{
  vector<coordinate> neighbors;
  if ((x + 1) < bigx) {
    struct coordinate coord = { (x+1), y };
    neighbors.push_back(coord);
  }

  if ((x - 1) >= 0) {
    struct coordinate coord = { (x-1), y };
    neighbors.push_back(coord);
  }

  if ((y+1) < bigy) {
    struct coordinate coord = { x, (y+1) };
    neighbors.push_back(coord);
  }

  if ((y-1) >= 0) {
    struct coordinate coord = { x, (y-1) };
    neighbors.push_back(coord);
  }

  return neighbors;
}

vector<coordinate> valley_find(vector<vector<int > > &entries, int bigx, int bigy)
{
  vector<coordinate> agenda;
  for (int y = 0; y < entries.size(); ++y) {
    for (int x = 0; x < entries[0].size(); ++x) {
      vector<coordinate> new_coords = get_neighbors(x, y, bigx, bigy);
      bool add = true;
      for (int i = 0; i < new_coords.size(); ++i) {
        struct coordinate new_coord = new_coords[i];
        if (entries[y][x] >= entries[new_coord.y][new_coord.x]) {
          add = false;
          break;
        }
      }
      if (add) {
        struct coordinate coords = { x, y };
        agenda.push_back(coords);
      }
    }
  }
  return agenda;
}

int bfs(vector<vector<int> > &entries, coordinate &coord, int bigx, int bigy)
{
  int size = 0;
  vector<coordinate> level = { coord };
  unordered_set<coordinate, coordinate> seen;
  while (level.size() > 0) {
    vector<coordinate> nxt_level;
    for (int i = 0; i < level.size(); ++i) {
      struct coordinate c = { level[i] };
      if (seen.find(c) == seen.end()) {
        seen.insert(c);
        size += 1;
      }
      vector<coordinate> new_coords = get_neighbors(c.x, c.y, bigx, bigy);
      for (int j = 0; j < new_coords.size(); ++j) {
        struct coordinate new_coord = { new_coords[j] };
        if ((seen.find(new_coord) == seen.end()) && (entries[new_coord.y][new_coord.x] > entries[c.y][c.x]) && (entries[new_coord.y][new_coord.x] != 9)) {
          nxt_level.push_back(new_coord);
        }
      }
    }
    level = nxt_level;
  }
  return size;
}

int main()
{
  vector<string> lines = open_file("09/day9.txt");
  vector<vector<int> > entries;
  transform(lines.begin(), lines.end(), back_inserter(entries), split);
  int bigx = entries[0].size();
  int bigy = entries.size();

  vector<coordinate> agenda = valley_find(entries, bigx, bigy);
  vector<int> results;
  for (int i = 0; i < agenda.size(); ++i) {
    struct coordinate coord = { agenda[i] };
    int res = bfs(entries, coord, bigx, bigy);
    results.push_back(res);
  }

  int ans = 1;
  int maxRes = 0;
  make_heap(results.begin(), results.end());
  for (int i = 0; i < 3; ++i) {
    pop_heap(results.begin(), results.end()); 
    maxRes = results.back();
    results.pop_back();
    ans *= maxRes;
  }

  cout << ans << endl;

  return 0;
}