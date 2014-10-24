#include <application.h>
#include "math.h"

#include "color.h"

// Convert a color from RGB representation to HSV representation.
void Color::Rgb::toHsv(Color::Hsv& hsv)
{
    uint8_t r = this->r;
    uint8_t g = this->g;
    uint8_t b = this->b;
    
	uint8_t min = min(r, min(g, b));
    uint8_t max = max(r, max(g, b));
	uint8_t delta = max - min;

    hsv.v = max;

    if (max == 0)
    {
        hsv.h = 0;
        hsv.s = 0;
        return;
    }

    if (max == r)
        hsv.h = (g - b) * (Color::Hsv::H_MAX / 6) / delta;
    else if (max == g)
        hsv.h = (b - r) * (Color::Hsv::H_MAX / 6) / delta + (2 * Color::Hsv::H_MAX / 6);
    else
        hsv.h = (r - g) * (Color::Hsv::H_MAX / 6) / delta + (Color::Hsv::H_MAX / 6);
	
	hsv.s = delta * Color::Hsv::S_MAX / max;
}

Color::Hsv Color::Rgb::toHsv()
{
	Color::Hsv hsv;
	this->toHsv(hsv);
	return hsv;
}

// Convert a color from HSV representation to RGB representation.
void Color::Hsv::toRgb(Color::Rgb& rgb)
{
	float h = this->h / (Color::Hsv::H_MAX / 6.0);
	float s = this->s / Color::Hsv::S_MAX;
	float v = this->v;

	uint16_t i = int(h);
	float f = h - i;
	uint8_t p = (uint8_t)(v * (1 - s));
	uint8_t q = (uint8_t)(v * (1 - s * f));
	uint8_t t = (uint8_t)(v * (1 - s * (1 - f)));
	
	switch (i % 6)
	{
	case 0: rgb.r = v; rgb.g = t; rgb.b = p; break;
	case 1: rgb.r = q; rgb.g = v; rgb.b = p; break;
	case 2: rgb.r = p; rgb.g = v; rgb.b = t; break;
	case 3: rgb.r = p; rgb.g = q; rgb.b = v; break;
	case 4: rgb.r = t; rgb.g = p; rgb.b = v; break;
	case 5: rgb.r = v; rgb.g = p; rgb.b = q; break;
	}
}

Color::Rgb Color::Hsv::toRgb()
{
	Color::Rgb rgb;
	this->toRgb(rgb);
	return rgb;
}
