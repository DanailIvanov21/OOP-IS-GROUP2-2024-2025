// This header is for reussing the function in other tasks

#pragma once
#include <iostream>
#include <fstream>

constexpr unsigned MAX_LINE_SIZE = 1024;

bool copyFile(const char* source_filename, const char* destination_filename);