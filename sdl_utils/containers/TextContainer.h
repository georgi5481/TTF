#ifndef SDL_UTILS_CONFIG_TEXTCONTAINER_H_
#define SDL_UTILS_CONFIG_TEXTCONTAINER_H_
//C system includes

//C++ system includes
#include<cstdint>
#include<vector>
#include<unordered_map>

//3rd-party includes

//Own includes
#include"sdl_utils/config/TextContainerCfg.h"


//Forward Declaration
struct SDL_Texture;
struct Color;
typedef struct _TTF_Font TTF_Font;

class TextContainer {

public:
	int32_t init(const TextContainerCfg& cfg);

	void deinit();

	void createText(const std::string& text, const Color & color, int32_t fontId,
					int32_t &outTextId, int32_t &outTextWidth, int32_t &outTextHeight);

	void reloadText(const std::string& text, const Color & color, int32_t fontId,
					int32_t &outTextId, int32_t &outTextWidth, int32_t &outTextHeight);

	void unloadText(int32_t textId);

	SDL_Texture* getTextTexture(int32_t textId) const;
private:
	void occupyFreeSlotIndex(int32_t & ooutIdx, SDL_Texture* texture);
	void freeSlotIndex(int32_t index);

	std::vector<SDL_Texture*> _textures; //the textures we will be drawning

	std::unordered_map<int32_t, TTF_Font*> _fonts;
};

#endif /* SDL_UTILS_CONFIG_TEXTCONTAINER_H_ */
