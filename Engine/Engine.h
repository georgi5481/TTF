#ifndef ENGINE_ENGINE_H_
#define ENGINE_ENGINE_H_	//the engine class should hold the classes on a bigger scale

//C system includes

//C++ system includes
#include<cstdint>


//3rd-party includes

//Own includes
#include "Game/Game.h"
#include "sdl_utils/MonitorWindow.h"
#include "sdl_utils/Renderer.h"
#include "sdl_utils/InputEvent.h"
#include "sdl_utils/containers/ImageContainer.h"
#include "sdl_utils/containers/TextContainer.h"

//Forward Declaration
struct EngineConfig;




class Engine {
public:
	int32_t init(const EngineConfig& cfg);
	void deinit();
	void start();

private:
	void mainLoop();
	void drawFrame();
	bool processFrame();
	void handleEvent();


	void limitFPS(int64_t elapsedTimeMicroSeconds);

	MonitorWindow _window;
	InputEvent _event;
	Renderer _renderer;
	ImageContainer _imgContainer;
	TextContainer _textContainer;
	Game _game;
};

#endif /* ENGINE_ENGINE_H_ */
