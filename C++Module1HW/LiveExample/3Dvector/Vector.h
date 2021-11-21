#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <cmath>

//1. class keyboard
//2. name 
//3. recipe {}
//4. ;


// Recipe:
//1. access specifier
//2. member variables
//3. constructors

class Vector {
	public:

	//Constructor
	//member function that does not have a return value and same name as type defined
	//class declaration
	Vector();
	
	explicit Vector(double value) ;

	Vector(double x, double y, double z) ;

	void print_vector() const ;

	double magnitude() const ;

	void set_from_spherical(double r, double theta, double phi) ;

	private:
		double _x;
		double _y;
		double _z;
};

#endif // VECTOR_H
