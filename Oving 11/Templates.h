#pragma once

#include <random>
#include <time.h>
#include <iostream>
#include <string>

using namespace::std;


template <typename T>
T maximum(T a, T b);

int randBetween(int a, int b);

template <typename T>
void shuffle(T& vec);

template <typename T>
void print(const T vec);

void testTemplate();
