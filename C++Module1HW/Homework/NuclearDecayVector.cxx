#include "Nucleus.h"
#include <iostream>
#include <vector>
#include <string>

int main() {

	// try with specified number of max alpha decays

	Nucleus X{88,138}; //radium-226, our test nucleus 1
	X.print();

	const int n = 10; // set number of alpha decays one would one to see (if possible)
					// set high enough value to see where the decay chain ends
	
	std::vector<std::string> DecayChain{X.rep()}; 	

	for (int i=0; i < n; i++) {
		std::cout << "Current nucleus is " << X.rep() << "\n" ; 
		X.alpha_decay();
		if ( *(DecayChain.begin()+i) == X.rep() ) {
			std::cout << "alpha decays stop here \n";
			break;
		} else 
			{DecayChain.push_back(X.rep());
		}


	}
std::cout << "\n" ;
std::cout << "Final Decay chain consists of nuclei : \n";
for (auto ptr = DecayChain.begin(); ptr != DecayChain.end(); ++ptr) {
		std::cout << *ptr << "," ;
}


}
