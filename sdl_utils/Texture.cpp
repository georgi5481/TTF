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


