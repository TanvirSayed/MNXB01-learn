#include "Vector.h"

//Constructor
//member function that does not have a return value and same name as type defined

//need to tell its a member function- class::memberfunction(): ...
Vector::Vector() : _x{0.}, _y{0.}, _z{0.} {
	//add additional functionality to the constructors here
		std::cout << "Vector{}\n";
		print_vector();
	}

//making a single taking value constructor, special/unique so make it explicit so doesnt mix up double value taking class?
Vector::Vector(double value) : _x{value}, _y{value}, _z{value} {
	std::cout << "explicit Vector(length)\n" ;
	print_vector();
}

Vector::Vector(double x, double y, double z) : _x{x}, _y{y}, _z{z} {
	std::cout << "Vector(x,y,z)\n" ;
	print_vector();
}

void Vector::print_vector() const {
	std::cout << "(x, y, z): (" << _x << ", " <<  _y << ", " <<  _z << ") \n";
}

double Vector::magnitude() const {
		return std::sqrt(_x*_x+_y*_y+_z*_z);
}

void Vector::set_from_spherical(double r, double theta, double phi) {
	auto cos_theta = std::cos(theta);
	auto sin_theta = std::sin(theta);
	auto sin_phi = std::sin(phi);
	_x = r * cos_theta * sin_phi;
	_y = r * sin_theta * sin_phi;
	_z = r * cos_theta;
}
