#ifndef PARSE_CSV_H
#define PARSE_CSV_H
#include "Nucleus.h"
#include <csv/csv.h>
#include <iostream>
#include <vector>
#include <string>
std::vector<Nucleus> parse_Nucleus(const std::string& filename);

#endif // PARSE_CSV_H
