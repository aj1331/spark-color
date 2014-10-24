#ifndef _COLOR
#define _COLOR

namespace Color
{
	struct Hsv;

	struct Rgb
	{
	    // Red [0, 255]
		uint8_t r;
		
		// Green [0, 255]
		uint8_t g;
		
		// Blue [0, 255]
		uint8_t b;

		void toHsv(Hsv& hsv);
		Hsv toHsv();

		static const uint8_t R_MIN = 0;
		static const uint8_t R_MAX = 255;
		static const uint8_t G_MIN = 0;
		static const uint8_t G_MAX = 255;
		static const uint8_t B_MIN = 0;
		static const uint8_t B_MAX = 255;
	};

	struct Hsv
	{
	    // Hue [0, 360]
		uint16_t h;
		
		// Saturation [0, 255]
		uint8_t s;
		
		// Value [0, 255]
		uint8_t v;

		void toRgb(Rgb& rgb);
		Rgb toRgb();

		static const uint16_t H_MIN = 0;
		static const uint16_t H_MAX = 360;
		static const uint8_t S_MIN = 0;
		static const uint8_t S_MAX = 255;
		static const uint8_t V_MIN = 0;
		static const uint8_t V_MAX = 255;
	};
}


#endif