#include "Nucleus.h"
#include <iostream>

//testing to see if the defined class and its member functions work.

int main() {
	Nucleus H{};
	H.print();

	Nucleus Ca{20,20};
	Ca.print();
	Ca.protonNum();
	std::cout << "The nucleus is represented as (protons, neutrons) = " << Ca.rep() << "\n";
	Ca.massNum();
	std::cout << "Ca has radius " << Ca.radius() << "m" << "\n" ;
	Ca.stable();
	Ca.alpha_decay() ; 
	
	Nucleus Ra{88,138};
	Ra.print();
	Ra.rep();
}
