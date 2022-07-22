//Corresponding header
#include "Renderer.h"

//C system includes

//C++ system includes
#include<iostream>

//3rd-party includes
#include <SDL_render.h>
#include<SDL_hints.h>

//Own includes
#include"sdl_utils/Texture.h"



int32_t Renderer::init(SDL_Window * window){
	//first we have to hint what we want to fix and then we have to render the image we want.
	if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")){	//1 means it will use linear algorithm
		std::cerr << "Warning: Linear texture filtering not enabled ! "
				"SDL_SetHint() failed. SDL Error:" << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}


	/*giving the SDL_CreateRenderer function:
	 * 1 the window(pointer) where rendering is displayed,
	 * 2 setting -1 for using default driver(DiretX in this case)
	 * 3 A flag for using the hardware acceleration instead of CPU.*/

	constexpr auto unspecifiedDriverId = -1;
	_sdlRenderer = SDL_CreateRenderer(window, unspecifiedDriverId, SDL_RENDERER_ACCELERATED);
	if(_sdlRenderer == nullptr)
	{
		std::cerr << "SDL_CreateRenderer failed. Reason:" << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	//SDL_SetRenderDrawColor will place a color on every pixel on the buffer we are clearing
	if(EXIT_SUCCESS != SDL_SetRenderDrawColor(_sdlRenderer, 200, 255, 0, SDL_ALPHA_OPAQUE)){
		std::cerr << "SDL_SetRenderDrawColor failed. Reason:" << SDL_GetError() << std::endl;
		return EXIT_FAILURE;

	}


	Texture::setRenderer(_sdlRenderer);//will basically set another pointer for the renderer outside the class

	return EXIT_SUCCESS;
}

void Renderer::deinit(){
	if(_sdlRenderer){
	SDL_DestroyRenderer(_sdlRenderer);
	_sdlRenderer = nullptr;
	}
}


void Renderer::clearScreen(){
	if(EXIT_SUCCESS != SDL_RenderClear(_sdlRenderer)){
		std::cerr << "SDL_RenderClear() failed. Reason:" << SDL_GetError() << std::endl;
	}

}

void Renderer::finishFrame(){
	SDL_RenderPresent(_sdlRenderer);	//will swap the pointers
}

void Renderer::renderTexture(SDL_Texture* texture, const DrawParams& drawParams){//SDL_Texture is a primitive we are drawing
	if(WidgetType::IMAGE == drawParams.widgetType){
		DrawImage(drawParams, texture);
	}
	else if(WidgetType::TEXT == drawParams.widgetType){
		DrawText(drawParams,texture);
	}
	else{
		std::cerr << "Error unknown widgetType : " << static_cast<int>(drawParams.widgetType) << " for rsrcId : " << drawParams.rsrcId << std::endl;
	}
}

void Renderer::DrawText(const DrawParams& drawParams, SDL_Texture* texture){
	const SDL_Rect destRect = {.x = drawParams.pos.x, .y = drawParams.pos.y,		//destination rectangle basically sets to place the texture on the left corner with full lenght
								.w = drawParams.width, .h = drawParams.height };

	const int32_t err = SDL_RenderCopy(_sdlRenderer, texture,nullptr, & destRect);
	//TODO: handle properly - do not set alpha every time
	if(EXIT_SUCCESS != err) {
		std::cerr << "RenderCopy() failed for rsrcId():" << drawParams.rsrcId << " Reason : " << SDL_GetError() << std::endl;
	}
}

void Renderer::DrawImage(const DrawParams& drawParams, SDL_Texture* texture){

	const SDL_Rect destRect = {.x = drawParams.pos.x, .y = drawParams.pos.y,		//destination rectangle basically sets to place the texture on the left corner with full lenght
								.w = drawParams.width, .h = drawParams.height };

	int32_t err = EXIT_SUCCESS;
	if(ZERO_OPACITY >= drawParams.opacity && FULL_OPACITY <= drawParams.opacity) {
		/*first argument - The renderer which should copy parts of a texture
		 * second - The source texture
		 * third - NULL for the entire texture to be displayed
		 * fourth - NULL for the entire rendering target*/
		err = SDL_RenderCopy(_sdlRenderer, texture,nullptr, &destRect);
	}
	else{
		if(EXIT_SUCCESS != Texture::setAlphaTexture(texture, drawParams.opacity)){
			std::cerr << "Texture::setAlphaTexture failed for rsrcId : " << drawParams.rsrcId << std::endl;
		}
		err = SDL_RenderCopy(_sdlRenderer, texture,nullptr, & destRect);


	}
	if(EXIT_SUCCESS != err) {
		std::cerr << "RenderCopy() failed for rsrcId():" << drawParams.rsrcId << " Reason : " << SDL_GetError() << std::endl;
	}
}

