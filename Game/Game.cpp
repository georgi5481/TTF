//Corresponding header
#include "Game.h"
//C system includes

//C++ system includes
#include<cstdint>
#include<iostream>
//3rd-party includes
#include "sdl_utils/config/MonitorWindowCfg.h"

//Own components includes
#include "sdl_utils/Texture.h"
#include "sdl_utils/InputEvent.h"


int32_t Game::init(const GameCfg& cfg){
	if (EXIT_SUCCESS != loadResources(cfg.imgPaths)){	//load the resources in the window
			std::cerr << "loadResources() failed. Reason: " << std::endl;
			return EXIT_FAILURE;
	}

	_currChosenImage = _imageSurfaces[PRESS_KEYS];


	return EXIT_SUCCESS;
}

void Game::deinit(){
	for(int32_t i = 0; i < COUNT; ++i){
		Texture::freeTexture(_imageSurfaces[i]);	//have to free the surface otherwise we have a memory leak
	}
}

void Game::draw(std::vector<SDL_Texture*>& outImages){
	for(int i = 0; i <20; i++){			//remove this later on
		outImages.push_back(_currChosenImage);

	}
}

void Game::handleEvent(const InputEvent& e){
	if(TouchEvent::KEYBOARD_RELEASE == e.type){	//sets to zero if we stoped pressing the key
		_currChosenImage = _imageSurfaces[PRESS_KEYS];
	}

	if(TouchEvent::KEYBOARD_PRESS != e.type){	//check if our event is a keyboard event in the first place
		return;
	}

		switch(e.key){
		case Keyboard::KEY_UP:
		_currChosenImage = _imageSurfaces[UP];
		break;

		case Keyboard::KEY_DOWN:
		_currChosenImage = _imageSurfaces[DOWN];
		break;

		case Keyboard::KEY_LEFT:
		_currChosenImage = _imageSurfaces[LEFT];
		break;

		case Keyboard::KEY_RIGHT:
		_currChosenImage = _imageSurfaces[RIGHT];
		break;

		default:
			break;
		}
}


int32_t Game::loadResources(const std::unordered_map<Images, std::string>& res){

for(const auto& pair : res){

	const auto resId = pair.first;
	const auto& resLocation = pair.second;

	if(EXIT_SUCCESS != Texture::createTextureFromFile(resLocation, _imageSurfaces[resId])){
			std::cerr << "createSurfaceFromFile failed for file : " << resLocation << std::endl;
		return EXIT_FAILURE;
		}
}
	return EXIT_SUCCESS;
}
