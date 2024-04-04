#include "InputHandler.h"

std::unordered_set<std::string> OfferCodeDetails::offerCodeNamesSet = { "OFR001", "OFR002", "OFR003" };

InputHandler::InputHandler()
{
	m_shouldBePackageID = 0;
	std::string inputString;
	std::cin >> m_BaseDeliveryCost;
	std::cin >> m_NumberOfPackages;

	int i = 0;
	while(i < m_NumberOfPackages)
	{
		std::getline(std::cin, inputString);
		if (!inputString.empty())
		{
			m_PackagesDataArray.push_back(inputString);
			i++;
		}
	}
	ParseData();
}

void InputHandler::ParseData()
{
	std::vector<std::vector<std::string>> dataArray;
	for (int i = 0; i < m_NumberOfPackages; i++)
	{
		dataArray.push_back(SeperateData(m_PackagesDataArray[i]));
	}
	
	for (int i = 0; i < m_NumberOfPackages; i++)
	{
		if (dataArray[i].size() != 4) { m_ValidPackages.push_back(OptionalPackage()); continue; }
		int packageWeight   = GetIntegerFromString(dataArray[i][1]); //std::atoi(dataArray[i][1].c_str());
		int packageDistance = GetIntegerFromString(dataArray[i][2]); //std::atoi(dataArray[i][2].c_str());
		Package newPackage(dataArray[i][0], packageWeight, packageDistance, dataArray[i][3]);
		m_ValidPackages.push_back(newPackage.IsValidPackage(i + 1) ? OptionalPackage(newPackage) : OptionalPackage());
	}
}

std::vector<std::string> InputHandler::SeperateData(const std::string& str, char delimiter)
{
	std::vector<std::string> result;
	int						 index	   = 0;
	std::string				 newString = "";
	while (str[index] != '\0')
	{
		if (str[index] == delimiter)
		{
			if (!newString.empty()) { result.push_back(newString); }
			newString = "";
			index++;
			continue;
		}
		newString += str[index];
		index++;
	}
	if (!newString.empty()) { result.push_back(newString); }
	return result;
}

int InputHandler::GetIntegerFromString(const std::string& numberString)
{
	int number = 0;
	int numberStringLength = (int)numberString.length();
	for (int i = 0; i < numberStringLength; i++)
	{
		if (numberString[i] < '0' || numberString[i] > '9') { return -1; }
		number = (number * 10) + (numberString[i] - '0');
	}
	return number;
}

void InputHandler::PrintInput(std::vector<std::string> singleInputArray)
{
	for (std::string str : singleInputArray)
	{
		std::cout << str << std::endl;
	}
	std::cout << "---------------------------" << std::endl;
}
