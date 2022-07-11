#ifndef GAME_GAME_H_
#define GAME_GAME_H_		//the game class should be the one that holds the game specific logic

//C system includes

//C++ system includes
#include <cstdint>
#include <vector>
#include <string>

//3rd-party includes

//Own includes
#include "Game/config/GameCfg.h"
#include "utils/drawings/DrawParams.h"

//Forward Declaration
struct InputEvent;
struct ImageContainer;


class Game {
public:

	int32_t init(const GameCfg& cfg, const ImageContainer* imageContainerInterface);
	void deinit();
	void draw(std::vector<DrawParams>& outImages);
	void handleEvent(const InputEvent& e);

private:
	DrawParams pressKeysImg;
	DrawParams layer2Img;

	//TODO: remove me later !!!
	const ImageContainer* _imgContainer = nullptr;

};

#endif /* GAME_GAME_H_ */
