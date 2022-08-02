#ifndef SDL_UTILS_TEXTURE_H_
#define SDL_UTILS_TEXTURE_H_

//C system includes

//C++ system includes
#include<cstdint>
#include<string>

//3rd-party includes

//Own includes
#include "utils/drawings/DrawParams.h"

//Forward Declaration
struct SDL_Surface;
struct SDL_Texture;
struct SDL_Renderer;
struct Color;
typedef struct _TTF_Font TTF_Font;

class Texture {	//a class with static functions is equal to a namespace
public:
	Texture() = delete;
	 ~Texture();

	 static int32_t createSurfaceFromFile(const std::string& filePath, SDL_Surface*& outSurface);	//returning int32_t as an error message.
	 static int32_t createTextureFromFile(const std::string& filePath, SDL_Texture*& outTexture);

	 static int32_t createTextureFromSurface(SDL_Surface*& InOutSurface, SDL_Texture*& outTexture);

	 static int32_t createTextureFromText(const std::string &text, const Color &color, TTF_Font* font,
			 	 	 	 SDL_Texture *&outTexture, int32_t &outTextWidth, int32_t &outTextHeight);


	 static void freeSurface(SDL_Surface*& outSurface);
	 static void freeTexture(SDL_Texture*& outTexture);

	 static void setRenderer(SDL_Renderer* renderer);

	 static int32_t setBlendModeTexture(SDL_Texture *texture, BlendMode blendMode);

	 static int32_t setAlphaTexture(SDL_Texture *texture, int32_t alpha);
};

#endif /* SDL_UTILS_TEXTURE_H_ */
