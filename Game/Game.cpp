//Corresponding header3
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
#include "sdl_utils/containers/TextContainer.h"		//always check if you included your files corectly
#include "utils/drawings/Color.h"
#include "utils/drawings/DrawParams.h"

int32_t Game::init([[maybe_unused]]const GameCfg& cfg,
			const ImageContainer* imageContainerInterface,
			TextContainer* textContainerInterface){

	if(nullptr == imageContainerInterface)
	{
		std::cerr << "Error, nullptr provided for imgContainerInterface" << std::endl;
		return EXIT_FAILURE;
	}

	_imgContainer = imageContainerInterface;

	if(nullptr == textContainerInterface)
	{
		std::cerr << "Error, nullptr provided for textContainerInterface" << std::endl;
		return EXIT_FAILURE;
	}

	_textContainer = textContainerInterface;



	layer2Img.rsrcId = cfg.layer2RsrcId;
	Rectangle rect = _imgContainer->getImageFrame(layer2Img.rsrcId);
	layer2Img.width = rect.h;
	layer2Img.height = rect.h;
	layer2Img.pos = Point::ZERO;
	layer2Img.widgetType = WidgetType::IMAGE;

	pressKeysImg.rsrcId =cfg.pressKeysRsrcId;
	rect = _imgContainer->getImageFrame(pressKeysImg.rsrcId);
	pressKeysImg.width = rect.w;
	pressKeysImg.height = rect.h;
	pressKeysImg.pos = Point::ZERO;
	pressKeysImg.pos.y += 20;
	pressKeysImg.widgetType = WidgetType::IMAGE;

	_textContainer->createText( "Hello,  C++ dudes", Colors::ORANGE, cfg.textFontId, helloText.textId, helloText.width, helloText.height);


	helloText.pos = Point::ZERO;
	helloText.widgetType = WidgetType::TEXT;

	return EXIT_SUCCESS;
}

void Game::deinit(){
	_textContainer->unloadText(helloText.textId);
}

void Game::draw(std::vector<DrawParams>& outImages){
	outImages.push_back(pressKeysImg);
	outImages.push_back(layer2Img);
	outImages.push_back(helloText);

}

void Game::handleEvent([[maybe_unused]]const InputEvent& e){
	if(TouchEvent::KEYBOARD_RELEASE != e.type){	//will basically detect only when you realease a key.
		return;
	}

		switch(e.key){
		//MOVEMENT
		case Keyboard::KEY_UP:
		pressKeysImg.pos.y -= 10;
		break;

		case Keyboard::KEY_DOWN:
		pressKeysImg.pos.y += 10;
		break;

		case Keyboard::KEY_LEFT:
		pressKeysImg.pos.x -= 10;
		break;

		case Keyboard::KEY_RIGHT:
		pressKeysImg.pos.x += 10;
		break;


		//STRETCHING
		case Keyboard::KEY_A:
		pressKeysImg.width -= 10;
		break;
		case Keyboard::KEY_D:
		pressKeysImg.width += 10;
		break;
		case Keyboard::KEY_S:
		pressKeysImg.height -= 10;
		break;
		case Keyboard::KEY_W:
		pressKeysImg.height += 10;
		break;

		//OPACITY
		case Keyboard::KEY_E:
		pressKeysImg.opacity -= 10;
		break;
		case Keyboard::KEY_Q:
		pressKeysImg.opacity += 10;
		break;

		default:
			break;
		}
}


