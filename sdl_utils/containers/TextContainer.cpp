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
#include"sdl_utils/Texture.h"


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

	//the third parameter accepts TTF_Font
	auto it = _fonts.find(fontId);		//a save mechanism for searching in the map. Cuz if not found - we will create new element
	if(it == _fonts.end()){
		std::cerr << "Error, fontId: " << fontId << "could not be found. Will not create text: " << text << std::endl;
		return;
	}
	TTF_Font* font = it->second;	//will point to the second element of the map

	SDL_Texture* textTexture = nullptr;

	if(EXIT_SUCCESS != Texture::createTextureFromText(
			text, color, font, textTexture, outTextWidth, outTextHeight)){	//the game will fill the text width of the object

		std::cerr << "Error, createTextureFromText() failed for text: " << text << std::endl;
		return;
	}

	occupyFreeSlotIndex(outTextId, textTexture);
}


void TextContainer::reloadText(const std::string& text, const Color & color, int32_t fontId,
				int32_t &outTextId, int32_t &outTextWidth, int32_t &outTextHeight){

}

void TextContainer::unloadText(int32_t textId){

	if(0 > textId || textId >= static_cast<int32_t>(_textures.size())){
		std::cerr <<  "Error, trying to unload non-existing textId: " << textId << std::endl;
	}
}

SDL_Texture* TextContainer::getTextTexture(int32_t textId) const{

}

void TextContainer::occupyFreeSlotIndex(int32_t & outIdx, SDL_Texture* texture){
	const int32_t size = static_cast<int32_t>(_textures.size());

	bool foundIdx = false;
	for(int32_t i = 0; i<size; ++i){
		if(_textures[i] == nullptr){	//found a free index where we can save
			outIdx = i;
			_textures[i] = texture;
			return;
		}
	}
	if(!foundIdx){
		_textures.push_back(texture);
		outIdx = size;
	}

}

void TextContainer::freeSlotIndex(int32_t index){


}
