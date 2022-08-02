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
struct TextContainer;


class Game {
public:

	int32_t init(const GameCfg& cfg, const ImageContainer* imageContainerInterface, TextContainer* textContainerInterface);
	void deinit();
	void draw(std::vector<DrawParams>& outImages);
	void handleEvent(const InputEvent& e);

private:
	DrawParams pressKeysImg;
	DrawParams layer2Img;
	DrawParams helloText;

	DrawParams pressText;
	DrawParams hideText;


	bool isPressTextHidden = false;

	//TODO: remove me later !!!
	const ImageContainer* _imgContainer = nullptr;
	TextContainer* _textContainer = nullptr;		//we use non constant pointer cuz our functions now make/change some things

};

#endif /* GAME_GAME_H_ */
