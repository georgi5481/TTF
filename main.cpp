//Corresponding header

//C system includes

//C++ system includes
#include <iostream>
#include <cstdint>
#include <cstdlib>
#include <string>
//3rd-party includes

//own include
#include "sdl_utils/SDLLoader.h"
#include "sdl_utils/MonitorWindow.h"
#include "Engine/Engine.h"
#include "Engine/EngineConfigLoader.h"

static int32_t runAplication(){
Engine engine;

	if(EXIT_SUCCESS != engine.init(EngineConfigLoader::loadConfig())){
			std::cerr << "Engine init() failed" << std::endl;
			return EXIT_FAILURE;
		}

		engine.start();

		engine.deinit();

		return EXIT_SUCCESS;
}



int32_t main ([[maybe_unused]]int32_t argc, [[maybe_unused]]char* argv[])
{

	if(EXIT_SUCCESS != SDLLoader::init())
	{
		std::cerr << "init() failed. " << std::endl;
		return EXIT_FAILURE;
	}

	if(EXIT_SUCCESS != runAplication())
	{
		std::cerr << "runAplication failed. " << std::endl;
		return EXIT_FAILURE;
	}


	SDLLoader::deinit();

	return EXIT_SUCCESS;
}
