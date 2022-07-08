#ifndef UTILS_DRAWINGS_COLOR_H_
#define UTILS_DRAWINGS_COLOR_H_

//C system includes

//C++ system includes
#include<cstdint>

//3rd-party includes

//Own includes


//Forward Declaration

struct RGBA{
	uint8_t r {0};
	uint8_t g {0};
	uint8_t b {0};
	uint8_t a {255};
};


class Color {
public:
	Color(const uint8_t r, const uint8_t g, const uint8_t b, const uint8_t a = 255)

private:
	Color() = delete; //forbid the default constructor

	RGBA rgba;

};

#endif /* UTILS_DRAWINGS_COLOR_H_ */
