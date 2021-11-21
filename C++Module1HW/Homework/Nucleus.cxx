#include "Nucleus.h"

bool Nucleus::stable() const {
		bool stability = false;
		if (_p * _p / (_p + _n) <= 35) 
			{stability = true;
			std::cout << "the nucleus is stable with respect to spontaneous fission" << "\n" ;
		} else {
			std::cout << "the nucleus is unstable \n" ;
		}
		return stability;
}

double Nucleus::radius() const {
		double A = _p + _n ;
		return 1.2 / pow(10,15) * std::cbrt(A);
}

void Nucleus::print() const {
		std::cout << "This nucleus has " << _p << " protons and " << _n << " neutrons." << "\n";
}

std::string Nucleus::rep() const {
		std::string represent = "(";
		represent += std::to_string(_p) ;
		represent += ", " ;
		represent += std::to_string(_n);
		represent += ")";
		return represent;
}

int Nucleus::protonNum() const {
	int P = _p;		
	return P ;
}

int Nucleus::massNum() const {
	int A = _p + _n ;
	return A ;
}

// should actually have made a separate file for the alpha_decay member function
void Nucleus::alpha_decay() {
		const double m1H = 938.783 ; // mass hydrogen, masses in MeV/c^2
		const double mn = 939.565 ; // mass neutron
		const double ma = 3727.379 ; // mass alpha

		const double cv = 15.9;
        const double cs = 18.4;
        const double cc = 0.71;
        const double ca = 23.2;
        const double cp = 11.5;
        
		double Zpar = _p;
        double Npar = _n;
		double Apar = _p + _n;

		double Zdat = _p - 2.;
        double Ndat = _n - 2.;
		double Adat = _p + _n - 4;

		double pairP = 0. ; 
		double pairD = 0. ;
		

		// actually i dont really need this as they will cancel out in Q
		if ( (_p + _n) % 2 == 0 ) {
			if (_p % 2 == 0) {
				pairP = cp / std::sqrt(Apar) ;
			} else {
				pairP = -cp / std::sqrt(Apar) ;
			}
		} 

		if ( (_p + _n - 4) % 2 == 0 ) {
			if ( (_p -2) % 2 == 0) {
				pairD = cp / std::sqrt(Adat) ;
			} else {
				pairD = -cp / std::sqrt(Adat) ;
			}
		} 


		double BEpar = cv * Apar - cs * std::cbrt(Apar*Apar) - cc * (Zpar * Zpar) / std::cbrt(Apar) - ca * (Npar-Zpar) * (Npar-Zpar) / Apar + pairP ;  

		double BEdat = cv * Adat - cs * std::cbrt(Adat*Adat) - cc * (Zdat * Zdat) / std::cbrt(Adat) - ca * (Ndat-Zdat) * (Ndat-Zdat) / Adat + pairD ;

		double massPar = Zpar * m1H + Npar * mn - BEpar ;
		double massdat = Zdat * m1H + Ndat * mn - BEdat ;

		double Qalpha = massPar - massdat - ma;

		std::cout << "Q_alpha for decay of " << rep() << " is " << Qalpha << "\n";

		if (Qalpha >= 0) {
		_p = _p - 2;
		_n = _n - 2;
		std::cout << "The parent nucleus has undergone Alpha decay and changed to " << rep() << "\n";
		} else 
			{std::cout << "Alpha decay not energetically possible for the nucleus " << rep() << "\n";
		}
		
}









