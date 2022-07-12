//Corresponding header
#include "TextContainer.h"

//C system includes

//C++ system includes

//3rd-party includes
#include<SDL_ttf.h>
//Own includes


int32_t TextContainer::init(const TextContainerCfg& cfg){
	for(const auto& pair : cfg.fontConfigs){
		const auto key = pair.first;
		const FontCfg& fontCfg = pair.second;
	}

	//argument 1 - path to the font; argument 2 - size of the font
	TTF_Font* font = TTF_OpenFont("../resources/fonts/AngelineVintage.ttf", 300);

	if(font == nullptr){
		std::cerr <<  "Error. TTF_OpenFont failed: " << SDL_GetError() << std::endl;
		return;
	}
	''
}

void TextContainer::deinit(){


}
