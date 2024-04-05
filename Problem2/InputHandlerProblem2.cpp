#include "InputHandlerProblem2.h"

InputHandlerProblem2::InputHandlerProblem2() : InputHandler(), m_NumberOfVehicles(-1), m_MaxSpeed(-1), m_MaxWeight(-1)
{
	InputVehiclesDetails();
}

void InputHandlerProblem2::InputVehiclesDetails()
{
	std::cin >> m_NumberOfVehicles >> m_MaxSpeed >> m_MaxWeight;
}
