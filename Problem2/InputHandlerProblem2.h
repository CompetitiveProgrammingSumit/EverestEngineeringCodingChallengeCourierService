#pragma once
#include "InputHandler.h"

class InputHandlerProblem2 : public InputHandler
{
	public:
		InputHandlerProblem2();

	private:
		int m_NumberOfVehicles;
		int m_MaxSpeed;
		int m_MaxWeight;

		void InputVehiclesDetails();
};