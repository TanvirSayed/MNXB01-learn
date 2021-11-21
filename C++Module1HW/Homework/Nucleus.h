#ifndef Nucleus_H
#define Nucleus_H
#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#include <cmath>
#include <string>

class Nucleus {
	public:
		Nucleus() : _p{1}, _n{0} {}
		
		explicit Nucleus(int protonNo) : _p{protonNo}, _n{protonNo} {}

		Nucleus(int proton, int neutron) : _p{proton}, _n{neutron} {}	

		int protonNum() const;

		int massNum() const;

		void print() const;	

		std::string rep() const;

		double radius() const;

		bool stable() const;

		void alpha_decay() ;


	private:
		int _p;
		int _n;


};

#endif //Nucleus_H
