#include "InputHandlerProblem2.h"

int main()
{
	InputHandlerProblem2		 inputHandler;
	std::vector<OptionalPackage> packages = inputHandler.GetPackages();
	return 0;
}



/*
100 5
PKG1 50 30 OFR001
PKG2 75 125 OFFR0008
PKG3 175 100 OFR003
PKG4 110 60 OFR002
PKG5 155 95 NA
2 70 200
*/