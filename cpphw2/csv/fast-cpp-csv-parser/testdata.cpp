#include "csv.h"
#include <iostream>
#include <vector>
#include <string>

int main(){
	io::CSVReader<4> input{"CleanSöderarm"};
	input.set_header( ,"Datum", "Tid (UTC)", "Lufttemperatur", "Kvalitet" );
	std::string Datum{};
	std::string Tid{};
	double LuftTemp{};
	double Kvalitet{};
	
//	std::vector<std::string> rows{};
	while(input.read_row(Datum, Tid, LuftTemp, Kvalitet)) {
//		rows.push_back(LuftTemp);
		std::cout<<LuftTemp << "\n";
		
	}
}
