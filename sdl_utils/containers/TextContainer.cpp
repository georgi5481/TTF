//Corresponding header
#include "TextContainer.h"

//C system includes

//C++ system includes
#include<iostream>
#include<unordered_map>
#include<cstdint>
//3rd-party includes
#include<SDL_ttf.h>

//Own includes
#include"utils/drawings/Color.h"


int32_t TextContainer::init(const TextContainerCfg &cfg){
	TTF_Font* currFont = nullptr ;
	for(const auto& pair : cfg.fontConfigs){
		const auto key = pair.first;
		const FontCfg& fontCfg = pair.second;

		//argument 1 - path to the font; argument 2 - size of the font
		currFont = TTF_OpenFont(fontCfg.location.c_str(), fontCfg.fontSize);
		if(currFont == nullptr) {
			std::cerr << "Error TTF_OpenFont failed: for fontLocation: " << fontCfg.location
					<< ". Reason: " << SDL_GetError() << std::endl;
			return EXIT_FAILURE;
		}
		_fonts[key] = currFont;
	}

	return EXIT_SUCCESS;
}

void TextContainer::deinit(){


	for(auto& pair: _fonts){
		TTF_CloseFont(pair.second);	//we have to close the font otherwise we will have memory leak
	}
}

void TextContainer::createText(const std::string& text, const Color & color, int32_t fontId,
				int32_t &outTextId, int32_t &outTextWidth, int32_t &outTextHeight){

}

void TextContainer::reloadText(const std::string& text, const Color & color, int32_t fontId,
				int32_t &outTextId, int32_t &outTextWidth, int32_t &outTextHeight){

}

void TextContainer::unloadText(int32_t textId){

}

SDL_Texture* TextContainer::getTextTexture(int32_t textId) const{

}
