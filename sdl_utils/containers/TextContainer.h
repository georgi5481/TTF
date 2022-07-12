#ifndef SDL_UTILS_CONFIG_TEXTCONTAINER_H_
#define SDL_UTILS_CONFIG_TEXTCONTAINER_H_
//C system includes

//C++ system includes
#include<vector>
#include<unordered_map>

//3rd-party includes

//Own includes

//Forward Declaration
struct SDL_Textures;
typedef struct TTF_Font;


class TextContainer {

public:

	std::vector<SDL_Textures*> _textures; //the textures we will be drawning

	std::unordered_map<int32_t, TTF_Font*> _fonts;
};

#endif /* SDL_UTILS_CONFIG_TEXTCONTAINER_H_ */
