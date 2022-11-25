#ifndef UTILS_H
#define UTILS_H

#include <unordered_set>
#include <string>
#include <vector>

void test();

void print(std::unordered_set<int> &s);
void print(std::unordered_set<std::string> &s);
void print(std::vector<int> s);
void print(std::vector<std::string> &s);

std::vector<std::string> slice_vector(std::vector<std::string> &vec, int i, int j);

std::vector<std::string> open_file(std::string filename);

std::vector<std::string> split_string(std::string line, std::string delimiter);

#endif