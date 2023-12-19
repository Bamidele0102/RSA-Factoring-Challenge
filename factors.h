#ifndef FACTORS_H
#define FACTORS_H

#include <vector>
#include <utility>
#include <string>

std::vector<std::pair<long long, long long>> factorize(long long number);
void factorize_file(const std::string& file_path);

#endif
