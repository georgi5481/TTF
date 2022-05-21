//Corresponding header
#include "ImageContainer.h"

//C system includes

//C++ system includes
#include<iostream>

//3rd-party includes

//Own includes


SDL_Texture* ImageContainer::getImageTexture(int32_t rsrcId) const{
	//we need to find if there is an element in the map with this key first, otherwise it will make a new element with this key if not found.
	auto it = _textures.find(rsrcId);
		if(it == _textures.end()){
			std::cerr <<"Error, invalid rsrcId: " << rsrcId << " requested." << std::endl;
			return nullptr;
		}

		return it->second;	//and basically returning the value of the found element via the key rsrcId
}


Rectangle ImageContainer::getImageFrame(int32_t rsrcId) const{
	//we need to find if there is an element in the map with this key first, otherwise it will make a new element with this key if not found.
	auto it = _textureFrames.find(rsrcId);
		if(it == _textureFrames.end()){
			std::cerr <<"Error, invalid rsrcId: " << rsrcId << " requested. Returning ZERO rectangle" << std::endl;
			return Rectangle::ZERO;
		}

	return it->second;	//and basically returning the value of the found element via the key rsrcId
}

