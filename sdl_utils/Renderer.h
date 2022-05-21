#ifndef SDL_UTILS_RENDERER_H_
#define SDL_UTILS_RENDERER_H_

//C system includes

//C++ system includes
#include<cstdint>

//3rd-party includes

//Own includes
#include "utils/drawings/DrawParams.h" //including this only cuz it's so light and not to include it in every single .cpp file
//Forward Declaration
struct SDL_Renderer;	//structure pointer coming from SDL
struct SDL_Texture;		//primitive that uploads the data from the CPU to the GPU
struct SDL_Window;

class Renderer {
	//forbid the copy/move constructors and assignment operators
public:
	Renderer() = default;
//	 ~Renderer();

	Renderer(const Renderer& other) = delete;//forbid copy/assignment constructor
	Renderer(Renderer&& other) = delete;//forbid the move constructor

	Renderer& operator=(const Renderer& other) = delete;
	Renderer& operator=(Renderer&& other) = delete;


	int32_t init(SDL_Window * window);
	void deinit();
	void clearScreen();		//clear the old frame
	void finishFrame();		//pointer swap so that we visualise the updated image
	void renderTexture(SDL_Texture* texture, const DrawParams& drawParams); //for drawing GPU primitives
private:
	SDL_Renderer *_sdlRenderer = nullptr;
};

#endif /* SDL_UTILS_RENDERER_H_ */
