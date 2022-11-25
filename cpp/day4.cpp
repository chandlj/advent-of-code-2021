#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_set>

#include "utils.hh"

using namespace std;

bool checkBoard(vector<vector<string> > &board, unordered_set<int> &chosen) {
  for (int i = 0; i < board.size(); ++i) {
    bool rowResult = true;
    bool colResult = true;
    for (int j = 0; j < board.size(); ++j) {
      if (chosen.find(stoi(board[i][j])) == chosen.end()) rowResult = false;
      if (chosen.find(stoi(board[j][i])) == chosen.end()) colResult = false;
    }
    if (rowResult || colResult) return true;
  }

  return false;
}

int main() {
  vector<string> lines = open_file("04/day4.txt");
  vector<string> numbers = split_string(lines[0], ",");

  vector<vector<vector<string> > > boards;
  for (int i = 2; i < lines.size(); i += 6) {
    vector<string> pre_board = slice_vector(lines, i, i+4);
    vector<vector<string> > board;
    for (int j = 0; j < pre_board.size(); ++j) {
      vector<string> line = split_string(pre_board[j], " ");
      board.push_back(line);
    }
    boards.push_back(board);
  }

  unordered_set<int> chosen;

  int ansNum;
  vector<vector<string> > ansBoard;
  for (int i = 0; i < numbers.size(); ++i) {
    int num = stoi(numbers[i]);
    chosen.insert(num);
    vector<vector<vector<string> > > nxt;
    if (boards.size() == 1) {
      vector<vector<string> > board = boards[0];
      if (checkBoard(board, chosen)) {
        ansBoard = board;
        ansNum = num;
        break;
      } else {
        continue;
      }
    } else {
      for (int j = 0; j < boards.size(); ++j) {
        vector<vector<string> > board = boards[j];
        if (!checkBoard(board, chosen)) {
          nxt.push_back(board);
        }
      }
      boards = nxt;
    }
  }

  int winningSum = 0;
  for (int i = 0; i < ansBoard.size(); ++i) {
    for (int j = 0; j < ansBoard.size(); ++j) {
      if (chosen.find(stoi(ansBoard[i][j])) == chosen.end()) {
        winningSum += stoi(ansBoard[i][j]);
      }
    }
  }

  int answer = {winningSum * ansNum};

  cout << answer << endl;

  return 0;
}