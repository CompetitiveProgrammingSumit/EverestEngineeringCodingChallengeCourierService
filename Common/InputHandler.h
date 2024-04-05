#pragma once

#include <iostream>
#include <vector>
#include "OptionalPackage.h"

class InputHandler
{
	public:
		InputHandler();

		inline const std::vector<OptionalPackage> GetPackages() const { return m_ValidPackages;	   }
		inline const int& GetBaseDeliveryCost()	const				  { return m_BaseDeliveryCost; }
		inline const int& GetNumberOfPackages()	const				  { return m_NumberOfPackages; }

	private:
		int							 m_BaseDeliveryCost;
		int							 m_NumberOfPackages;
		std::vector<std::string>	 m_PackagesDataArray;
		int							 m_shouldBePackageID;
		std::vector<OptionalPackage> m_ValidPackages;

		void ParseData();
		std::vector<std::string> SeperateData(const std::string& str, char delimiter = ' ');
		int GetIntegerFromString(const std::string& numberString);
		void PrintInput(std::vector<std::string> singleInputArray);
};