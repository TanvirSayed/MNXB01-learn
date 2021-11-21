#include "Vector.h"
#include <iostream>


int main() {
	const Vector v{};
	v.print_vector();

	const Vector v2{3.17};
	v2.print_vector();

	Vector v3{27,5,9};
	v3.print_vector();

	Vector v4{0, 0, 0};
	std::cout << "Magnitude of v4 is" << v4.magnitude() << "\n";
	v4.set_from_spherical(11, 22, 33);
	v4.print_vector();
}
