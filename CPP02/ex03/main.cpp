#include "Point.hpp"

int main( void )
{
	std::cout << "IN : Middle" << std::endl;
	Point const A1(1, 1);
	Point const B1(3,3);
	Point const C1(5,1);
	Point const P1(3,2);

	if (bsp(A1,B1,C1,P1) > 0)
		std::cout << "\t[IN]" << std::endl;
	else
		std::cout << "\t[OUT]" << std::endl;
	
	std::cout << "OUT : Far" << std::endl;

	Point const A2(1,1);
	Point const B2(3,3);
	Point const C2(5,1);
	Point const P2(9,2);

	if (bsp(A2,B2,C2,P2) > 0)
		std::cout << "\t[IN]" << std::endl;
	else
		std::cout << "\t[OUT]" << std::endl;

	std::cout << "IN : On a side" << std::endl;
	Point const A3(1,1);
	Point const B3(3,3);
	Point const C3(5,1);
	Point const P3(4,2);

	if (bsp(A3,B3,C3,P3) > 0)
		std::cout << "\t[IN]" << std::endl;
	else
		std::cout << "\t[OUT]" << std::endl;

	std::cout << "OUT : near a side" << std::endl;
	Point const A4(1,1);
	Point const B4(3,3);
	Point const C4(5,1);
	Point const P4(4.1,2);

	if (bsp(A4,B4,C4,P4) > 0)
		std::cout << "\t[IN]" << std::endl;
	else
		std::cout << "\t[OUT]" << std::endl;

	return (0);
}