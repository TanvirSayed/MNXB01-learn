#include "Nucleus.h"
#include <iostream>
#include "parse_csv.h"
#include <vector>
#include <string>


int main() {
	const std::string filename{"NucleiList.csv"};
	std::vector<Nucleus> rows{parse_Nucleus(filename)};
	for (auto row : rows) {
		row.print();
		std::cout<<"Mass number is "<< row.massNum() << "\n";
		std::cout<<"Its radius is "<< row.radius() << "\n";
		row.stable();
		std::cout<< "\n";
	};
}

