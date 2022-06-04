#ifndef GAME_GAME_H_
#define GAME_GAME_H_

//C system includes

//C++ system includes
#include <cstdint>
#include <vector>
#include <string>

//3rd-party includes

//Own includes
#include "Game/config/GameCfg.h"

//Forward Declaration
struct InputEvent;



class Game {
public:

	int32_t init(const GameCfg& cfg);
	void deinit();
	void draw(std::vector<SDL_Texture*>& outImages);
	void handleEvent(const InputEvent& e);

private:

	//game specific logic
	SDL_Texture* _currChosenImage = nullptr;	//the image we are presenting atm
	SDL_Texture* _imageSurfaces[COUNT]{};		//an array of our Surfaces loaded basically in the heap




};

#endif /* GAME_GAME_H_ */
