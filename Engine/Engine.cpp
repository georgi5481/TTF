//Corresponding header
#include "Engine/Engine.h"

//C system includes

//C++ system includes
#include<cstdint>
#include<iostream>

//3rd-party includes
//#include<thread>
#include<SDL_ttf.h>

//Own includes
#include "Engine/config/EngineConfig.h"
#include "utils/thread/ThreadUtils.h"
#include "utils/Time/Time.h"
#include "sdl_utils/Texture.h"


int32_t gTextHeight = 0;
int32_t gTextWidth = 0;
SDL_Texture* gTextTexture = nullptr;

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


	if (EXIT_SUCCESS != _game.init(cfg.gameCfg, &_imgContainer)){	//load the resources in the window
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

	std::vector<DrawParams> images;

	_game.draw(images);

SDL_Texture* texture = nullptr;

	for(const DrawParams& image : images){	//the function bellow accepts only const DrawParams !!! This is why we declare here a const object pointer
		texture = _imgContainer.getImageTexture(image.rsrcId);
		_renderer.renderTexture(texture,image);
	}
	DrawParams textDrawParams;
	textDrawParams.pos.x = 100;
	textDrawParams.pos.y = 200;
	textDrawParams.height = gTextWidth;
	textDrawParams.height = gTextHeight;
	_renderer.renderTexture(gTextTexture,textDrawParams);	//GPU render the texture

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

void Engine::handleEvent(){
_game.handleEvent(_event);
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





void Engine::loadText(){
	//argument 1 - path to the font; argument 2 - size of the font
	TTF_Font* font = TTF_OpenFont("../resources/fonts/AngelineVintage.ttf", 40);

	if(font == nullptr){
		std::cerr <<  "Error. TTF_OpenFont failed: " << SDL_GetError() << std::endl;
		return;
	}
	//we decide what color we would like to display the font
	SDL_Color colorText = {.r = 127, .g =127, .b = 127, .a = 255};
	//we create the font first as a surface
	SDL_Surface * textSurface = TTF_RenderText_Solid(font, "Proba, probra. 1,2,3", colorText);
	//trought the pointer of the surface we take the hight and with of the font
	gTextWidth = textSurface->w;
	gTextHeight = textSurface->h;
	//we turn it into a texture
	Texture::createTextureFromSurface(textSurface, gTextTexture);

	TTF_CloseFont(font);	//usually you should close the font at the end of the program so that you can use the font runtime
}




