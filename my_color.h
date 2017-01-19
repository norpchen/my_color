#pragma once


// ---------------------------------------------------------------------------------------------------------------------------
// Simple class to encapsulate an RGB 8 bit color
class  my_color
{
public:
	byte r;
	byte g;
	byte b;
	my_color (byte r1,byte g1,byte b1)
	{
		this->r = r1;
		this->g = g1;
		this->b = b1;
	};
	inline blend( my_color other, unsigned int amount)
	{
		this->r = ((other.r*amount) + (this->r * (255-amount)))>>8;
		this->g = ((other.g*amount) + (this->g * (255-amount)))>>8;
		this->b = ((other.b*amount) + (this->b * (255-amount)))>>8;
	}
	// we can let the compiler generate the default copy operator (which will memcpy)

	
};

// these are const, so they don't eat RAM
const my_color np_white  (255,255,255);
const my_color np_black  (0  ,0,0);
const my_color np_red    (255,0,0);
const my_color np_orange (255,128,0);
const my_color np_yellow (255,255,0);
const my_color np_green  (0  ,255,0);
const my_color np_cyan   (0  ,255,128);
const my_color np_blue   (0  ,0,255);
const my_color np_purple (128,0,255);

// blend two colors and return a new color object with the result
inline my_color blend( my_color a, my_color b, unsigned int amount)
{
	return my_color( ((b.r*amount) + (a.r * (255-amount)))>>8, ((b.g*amount) + (a.g * (255-amount)))>>8,((b.b*amount) + (a.b * (255-amount)))>>8) ;
}


