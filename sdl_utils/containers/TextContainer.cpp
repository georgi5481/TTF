//Corresponding header
#include "TextContainer.h"

//C system includes

//C++ system includes

//3rd-party includes
#include <SDL_ttf.h>
//Own includes


int32_t TextContainer::init(const TextContainerCfg& cfg){
	TTF_Font* currFont = nullptr;
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
		_fonts[key] =
	}

	TTF_Font* font = currFont;

	return EXIT_SUCCESS;
}

void TextContainer::deinit(){


}
