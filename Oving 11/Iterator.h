#pragma once
#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

void testIterator();
void replace(vector<string>& vec, string old, string replacement);
void replace(set<string>& set1, string old, string replacement);
void print_reverse(const vector<string> vec);
void print_reverse(const set<string> set1);
void print(const vector<string> vec);
void print(const set<string> set1);