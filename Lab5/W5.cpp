// Workshop 5 - Lambda Expression
// 345_w5.cpp
// Chris Szalwinski & Dr. Elliott Coleshill
// 2018-08-22

#include <iostream>
#include <fstream>
#include "Grades.h"
#include "Letter.h"
using namespace sict;

int main(int argc, char *argv[])
{

	std::ofstream ofs("Lab5Output.txt");

	std::cout << "Command Line : ";
	for (int i = 0; i < argc; i++)
	{
		std::cout << argv[i] << ' ';
	}
	std::cout << std::endl;

	if (argc == 1)
	{
		std::cerr << "\n*** Insufficient number of arguments ***\n";
		std::cerr << "Usage: " << argv[0] << " fileName \n";
		return 1;
	}
	else if (argc != 2)
	{
		std::cerr << "\n*** Too many arguments ***\n";
		std::cerr << "Usage: " << argv[0] << " fileName \n";
		return 2;
	}

	//Update the main functions as per the specifications here
	// using Letter.h
	Grades grades(argv[1]);
	auto letter = [](double grade) {
	// 	if (x >= 90)
	// 		return "A+";
	// 	else if (x >= 80)
	// 		return "A";
	// 	else if (x >= 75)
	// 		return "B+";
	// 	else if (x >= 70)
	// 		return "B";
	// 	else if (x >= 65)
	// 		return "C+";
	// 	else if (x >= 60)
	// 		return "C";
	// 	else if (x >= 55)
	// 		return "D+";
	// 	else if (x >= 50)
	// 		return "D";
	// 	else
	// 		return "F";
	// };
		return grade >= 90 ? convertString(Letter::A_p) :
		grade >= 80 ? convertString(Letter::A) :
		grade >= 75 ? convertString(Letter::B_p) :
		grade >= 70 ? convertString(Letter::B) :
		grade >= 65 ? convertString(Letter::C_p) :
		grade >= 60 ? convertString(Letter::C) :
		grade >= 55 ? convertString(Letter::D_p) :
		grade >= 50 ? convertString(Letter::D) :
		  convertString(Letter::F);
	};
	grades.displayGrades(ofs, letter);

	ofs.close();
}