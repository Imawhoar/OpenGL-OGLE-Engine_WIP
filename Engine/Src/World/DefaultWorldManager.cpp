#include "DefaultWorldManager.h"

#include <iostream>

void OGLE::DefaultWorldManager::Begin()
{
	std::cout << "Starting default worldmanager \n";
}

void OGLE::DefaultWorldManager::End()
{
	std::cout << "Ending default worldmanager\n";
}

void OGLE::DefaultWorldManager::Tick(float deltaTime)
{
}
