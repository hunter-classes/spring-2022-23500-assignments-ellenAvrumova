#pragma once
#include <iostream>
#include <time.h>
#include <unistd.h>
#include <cstdlib>
#include <sys/time.h>
#include <math.h>
#include <vector>

void print_vector(std::vector<int> a);
int find_min_index(std::vector<int> a, int start_index, int stop_index);
std::vector<int> ssort(std::vector<int> a);
std::vector<int> merge(std::vector<int> left, std::vector<int> right);
std::vector<int> msort(std::vector<int> v);
std::vector<int> qsort(std::vector<int> list);
std::vector<int> quickSort(std::vector<int> list, int L, int H);
void print_help(char *command_name);