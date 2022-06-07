//Coresponding header
#include "Texture.h"

//C system includes

//C++ system includes
#include<iostream>

//3rd-party includes
#include <SDL_surface.h>
#include <SDL_image.h>
#include <SDL_render.h>
//Own includes

//Forward Declaration
struct SDL_Surface;
static SDL_Renderer* gRenderer = nullptr;

int32_t Texture::createSurfaceFromFile(const std::string& filePath, SDL_Surface*& outSurface){

	outSurface = IMG_Load(filePath.c_str()); //load the file with the path

	if(outSurface == nullptr){	//check if loading the file went well
		std::cerr << "SDL_LoadBMP failed. Reason: " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}


	return EXIT_SUCCESS;
}

int32_t Texture::createTextureFromFile(const std::string& filePath,SDL_Texture*& outTexture){

	SDL_Surface* surface = nullptr;
	if(EXIT_SUCCESS != createSurfaceFromFile(filePath, surface)){
			std::cerr << "createSurfaceFromFile() failed for filePath" << filePath << std::endl;
		}

	if(EXIT_SUCCESS != createTextureFromSurface(surface, outTexture)){
		std::cerr << "createTextureFromSurface() failed for filepath : " << filePath << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}


void Texture::freeSurface(SDL_Surface*& outSurface){
	if(outSurface != nullptr){
		SDL_FreeSurface(outSurface);
		outSurface = nullptr;
	}
}

void Texture::freeTexture(SDL_Texture*& outTexture){
	if(outTexture != nullptr){
		SDL_DestroyTexture(outTexture);
		outTexture = nullptr;
	}
}


int32_t Texture::createTextureFromSurface(SDL_Surface*& InOutSurface, SDL_Texture*& outTexture){

	outTexture = SDL_CreateTextureFromSurface(gRenderer, InOutSurface);
	if(outTexture == nullptr){
				outTexture = nullptr;
	}

	freeSurface(InOutSurface);

	return EXIT_SUCCESS;
}



void Texture::setRenderer(SDL_Renderer* renderer){
	gRenderer = renderer;
}



int32_t setBlendModeTexture(SDL_Texture *texture, BlendMode blendMode){

	//takes two arguments 1 to the texture we are gonna blend, 2nd to the blendmode
if(EXIT_SUCCESS != SDL_SetTextureBlendMode(texture, static_cast<SDL_BlendMode>(blendMode))){
	std::cerr << "SDL_SetTextureAlphaMod() failer. Reason : " << SDL_GetError() << std::endl;
	return EXIT_FAILURE;
}
return EXIT_SUCCESS;
}

int32_t setAlphaTexture(SDL_Texture *texture, int32_t alpha){


if(EXIT_SUCCESS != SDL_SetTextureAlphaMod(texture, static_cast<uint8_t>(alpha))){
	if(ZERO_OPACITY > alpha || alpha > FULL_OPACITY){	//can't make changes if the number is negative
		std::cerr << "Error, invalid alpha value: " << alpha << " provided." << std::endl;
	}

	std::cerr << "SDL_SetTextureAlphaMod() failer. Reason : " << SDL_GetError() << std::endl;
	return EXIT_FAILURE;
}

return EXIT_SUCCESS;
}





