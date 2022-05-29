//Corresponding header
#include "Engine/Engine.h"

//C system includes

//C++ system includes
#include<cstdint>
#include<iostream>

//3rd-party includes
//#include<thread>

//Own includes
#include "Engine/config/EngineConfig.h"
#include "utils/thread/ThreadUtils.h"
#include "utils/Time/Time.h"


int32_t Engine::init(const EngineConfig& cfg){

	if (EXIT_SUCCESS != _window.init(cfg.windowCfg)){		//load the size of the window
			std::cerr << "loadResources() failed. Reason: " << std::endl;
			return EXIT_FAILURE;
	}

	if (EXIT_SUCCESS != _renderer.init(_window.getWindow())){		//get the render algorithm
			std::cerr << "render init() failed. Reason: " << std::endl;
			return EXIT_FAILURE;
	}

	if (EXIT_SUCCESS != _imgContainer.init(cfg.imageContainerCfg)){		//initialising the image container logic (a simple map  with int as ID and string as the path)
			std::cerr << "imgContainer init() failed. Reason: " << std::endl;
			return EXIT_FAILURE;
	}

	if (EXIT_SUCCESS != _event.init()){			//scan what event occurred
			std::cerr << "InputEvent failed. Reason: " << std::endl;
			return EXIT_FAILURE;
	}

	const GameCfg gameCfg= {.dummy = 1337};

	if (EXIT_SUCCESS != _game.init(gameCfg)){	//load the resources in the window
			std::cerr << "_game.init() failed." << std::endl;
			return EXIT_FAILURE;
	}


return EXIT_SUCCESS;
}




void Engine::deinit(){	//always deinitialise backwards according to initialisings
	_game.deinit();
	_event.deinit();
	_imgContainer.deinit();
	_renderer.deinit();
	_window.deinit();
}

void Engine::start(){
	mainLoop();

}

void Engine::mainLoop(){
	Time time;

while(true){
	time.getElapsed().toMicroseconds();

	const bool shouldExit = processFrame();

		if(shouldExit){
			break;
		}

		limitFPS(time.getElapsed().toMicroseconds());
	}
}

void Engine::drawFrame(){

	_renderer.clearScreen();	//always start with clearing the screen

	std::vector<SDL_Texture*> images;

	_game.draw(images);

/*
	for(auto& image : images){
	_renderer.renderTexture(image);
	}
*/

		_renderer.finishFrame();	//update the image
}



bool Engine::processFrame(){
	while(_event.pollEvent()){
		if(_event.checkForExitRequiest()){
			return true;
		}

		handleEvent();
	}

	drawFrame();

	return false;
}


void Engine::limitFPS(int64_t elapsedTimeMicroSeconds){
	constexpr auto maxFrames = 30;
	constexpr auto microSecondsInASecond = 1000000;
	constexpr auto microSecondsPerFrame = microSecondsInASecond / maxFrames;
	const int64_t sleepDurationMicroSeconds = microSecondsPerFrame - elapsedTimeMicroSeconds;

	if(sleepDurationMicroSeconds > 0){
	ThreadUtils::sleepFor(sleepDurationMicroSeconds);
	}
}



void Engine::handleEvent(){
_game.handleEvent(_event);
}

/*
	while(true) {
		if(event.pollEvent()){
			if(event.type == TouchEvent::KEYBOARD_PRESS){
				std::cout << "pressed key: " << (char)event.key << std::endl;
			}
			else if(event.type == TouchEvent::KEYBOARD_RELEASE){
				std::cout << "released key: " << (char)event.key << std::endl;
			}
			else if(event.type == TouchEvent::TOUCH_PRESS){
				std::cout << "mouse button idx pressed: " << event.mouseButton << std::endl;
			}
			else if(event.type == TouchEvent::TOUCH_RELEASE){
				std::cout << "mouse button idx released: " << event.mouseButton << std::endl;
			}
			else {
				std::cout << "event position X(" << event.pos.x << ") Y (" << event.pos.y << ")" << std::endl;
			}
		}
	}*/





