#pragma once

#include </usr/local/mpich-3.3.2/include/mpi.h>

#include <chrono>
#include <iostream>
#include <queue>

#include "graph.h"

#define MAX_INT 1073741824
#define MAX_DIST MAX_INT
#define MAX_SOURCES 1024

using Time = chrono::high_resolution_clock;
using us = std::chrono::microseconds;
using ms = std::chrono::milliseconds;