//Corresponding header
#include "ImageContainer.h"

//C system includes

//C++ system includes
#include<iostream>
#include<cstdint>
//3rd-party includes

//Own includes
#include "sdl_utils/Texture.h"

int32_t ImageContainer::init(const ImageContainerCfg& cfg){
	for(const auto& pair : cfg.imageConfigs)
	{
		const auto& elem = pair.second;
		const auto rsrcId = pair.first;
		if(EXIT_SUCCESS !=loadSingleResource(elem, rsrcId)){
				std::cerr << "loadSingleResource failed for file : " << elem.location << std::endl;
			return EXIT_FAILURE;
			}
	}


	return EXIT_SUCCESS;
}


int32_t ImageContainer::deinit(){
	for(auto& pair : _textures)	//we dont need const reference since we are going to modificate the texture.
	{
		Texture::freeTexture(pair.second);
	}

	return EXIT_SUCCESS;
}

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
	//we need to find if there is an element in the map with this key first. Otherwise it will make a new element with this key if not found.
	auto it = _textureFrames.find(rsrcId);
		if(it == _textureFrames.end()){
			std::cerr <<"Error, invalid rsrcId: " << rsrcId << " requested. Returning ZERO rectangle" << std::endl;
			return Rectangle::ZERO;
		}

	return it->second;	//and basically returning the value of the found element via the key rsrcId
}


int32_t ImageContainer::loadSingleResource(const ImageCfg& resCfg, int32_t rsrcId){

	SDL_Texture* texture = nullptr;
	if(EXIT_SUCCESS != Texture::createTextureFromFile(resCfg.location, texture)){
			std::cerr << "createSurfaceFromFile failed for file : " << resCfg.location << std::endl;
		return EXIT_FAILURE;
		}
	_textures[rsrcId] = texture;

	//a good practice is to take out the reference, and then implement the values. Don't always search in the map with the key.
	Rectangle& rect = _textureFrames[rsrcId];	//using this way the reference is so much better
	rect.x = 0;
	rect.y = 0;
	rect.w = resCfg.width;
	rect.h = resCfg.height;

	return EXIT_SUCCESS;
}

