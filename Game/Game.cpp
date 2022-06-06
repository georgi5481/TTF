//Corresponding header
#include "Game.h"
//C system includes

//C++ system includes
#include<cstdint>
#include<iostream>
//3rd-party includes
#include "sdl_utils/config/MonitorWindowCfg.h"

//Own components includes
#include "sdl_utils/InputEvent.h"
#include "sdl_utils/containers/ImageContainer.h"

int32_t Game::init([[maybe_unused]]const GameCfg& cfg,
			const ImageContainer* imageContainerInterface){

	if(nullptr == imageContainerInterface)
			{
		std::cerr << "Error, nullptr provided for imgContainerInterface" << std::endl;
			return EXIT_FAILURE;
			}

	_imgContainer = imageContainerInterface;


	layer2Img.rsrcId = cfg.layer2RsrcId;
	Rectangle rect = _imgContainer->getImageFrame(layer2Img.rsrcId);
	layer2Img.width = rect.h;
	layer2Img.height = rect.h;
	layer2Img.pos = Point::ZERO;

	pressKeysImg.rsrcId =cfg.pressKeysRsrcId;
	rect = _imgContainer->getImageFrame(pressKeysImg.rsrcId);
	pressKeysImg.width = rect.w;
	pressKeysImg.height = rect.h;
	pressKeysImg.pos = Point::ZERO;
	pressKeysImg.pos.y += 20;

	return EXIT_SUCCESS;
}

void Game::deinit(){

}

void Game::draw(std::vector<DrawParams>& outImages){
	outImages.push_back(pressKeysImg);
	outImages.push_back(layer2Img);
}

void Game::handleEvent([[maybe_unused]]const InputEvent& e){
	/*if(TouchEvent::KEYBOARD_RELEASE == e.type){	//sets to zero if we stoped pressing the key
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
		}*/
}


