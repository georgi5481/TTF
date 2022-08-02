//Coresponding header
#include "sdl_utils/Texture.h"

//C system includes

//C++ system includes
#include<iostream>

//3rd-party includes
#include <SDL_surface.h>
#include <SDL_image.h>
#include <SDL_render.h>
#include <SDL_ttf.h> //for SDL_RenderText_Blended function
//Own includes
#include"utils/drawings/Color.h"
//Forward Declaration
//struct SDL_Surface;

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

				std::cerr << "SDL_CreateTextureFromSurface failed. " << std::endl;
				return EXIT_FAILURE;
	}

	freeSurface(InOutSurface);

	return EXIT_SUCCESS;
}

int32_t Texture::createTextureFromText(const std::string& text, const Color& color, TTF_Font* font,
 	 	 SDL_Texture *&outTexture, int32_t &outTextWidth, int32_t &outTextHeight){


	//since static cast won't compile we use reinterpret_cast cuz we need to cast it into const color
	const SDL_Color* sdlColor = reinterpret_cast<const SDL_Color*>(&color.rgba);
	//basically we take a pointer of our own declared structure RGBA, and we cast it into the structure we need so that we encapsulate the SDL

	SDL_Surface* textSurface = TTF_RenderText_Blended(font, text.c_str(), *sdlColor);

	if(textSurface == nullptr){
		std::cerr << "TTF_RenderText_Blended() failed. Reason : " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}
	outTextWidth = textSurface->w;
	outTextHeight = textSurface->h;


	if(EXIT_SUCCESS != Texture::createTextureFromSurface(textSurface, outTexture)){	//will load it into the GPU
		std::cerr << "createTextureFromSurface() failed for text : " << text << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;

}


void Texture::setRenderer(SDL_Renderer* renderer){
	gRenderer = renderer;
}



int32_t Texture::setBlendModeTexture(SDL_Texture *texture, BlendMode blendMode){	//first we gave to the a blending mode and then to change the blending

	//takes two arguments 1 to the texture we are gonna blend, 2nd to the blendmode
if(EXIT_SUCCESS != SDL_SetTextureBlendMode(texture, static_cast<SDL_BlendMode>(blendMode))){
	std::cerr << "SDL_SetTextureAlphaMod() failed. Reason : " << SDL_GetError() << std::endl;
	return EXIT_FAILURE;
}
return EXIT_SUCCESS;
}

int32_t Texture::setAlphaTexture(SDL_Texture *texture, int32_t alpha){//we need to set the blend mode at lease one time, and then we can call this function 100000 times.

if(ZERO_OPACITY > alpha || alpha > FULL_OPACITY){	//can't make changes if the number is negative
	std::cerr << "Error, invalid alpha value: " << alpha << " provided." << std::endl;
	return EXIT_FAILURE;
}

if(EXIT_SUCCESS != SDL_SetTextureAlphaMod(texture, static_cast<uint8_t>(alpha))){


	std::cerr << "SDL_SetTextureAlphaMod() failed. Reason : " << SDL_GetError() << std::endl;
	return EXIT_FAILURE;
}

return EXIT_SUCCESS;
}





