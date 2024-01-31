#include <iostream>
#include <SFML\Graphics.hpp>
#include <cstdlib>
#include <time.h>

using namespace std;
using namespace sf;

bool redhome = false;
bool greenhome = false;
bool yellowhome = false;
bool bluehome = false;

bool redQ[4];
bool greenQ[4];
bool yellowQ[4];
bool blueQ[4];
//Defining the function for the shappig and clourig and thickness.
void token_assign(CircleShape shape[4])
{
	for (int i = 0; i < 4; i++)
	{
		shape[i].setRadius(16);
		shape[i].setOutlineThickness(-5);
		shape[i].setOutlineColor(Color(0, 0, 0));
	}
}

//////////Token are sended here to sent them on there initial Positions.////////

void token(CircleShape red[4], CircleShape green[4], CircleShape blue[4], CircleShape yellow[4])
{
	token_assign(red);
	token_assign(green);
	token_assign(blue);
	token_assign(yellow);
	for (int i = 0; i < 4; i++)
	{
		red[i].setFillColor(Color(225, 0, 0));
		if (i < 2)
			red[i].setPosition(94 + (i * 40), 430);
		else
			red[i].setPosition(94 + ((i - 2) * 40), 468);
	}
	for (int i = 0; i < 4; i++)
	{
		green[i].setFillColor(Color(0, 225, 0));
		if (i < 2)
			green[i].setPosition(94 + (i * 40), 94);
		else
			green[i].setPosition(94 + ((i - 2) * 40), 134);
	}
	for (int i = 0; i < 4; i++)
	{
		blue[i].setFillColor(Color(0, 0, 225));
		if (i < 2)
			blue[i].setPosition(430 + (i * 40), 430);
		else
			blue[i].setPosition(430 + ((i - 2) * 40), 468);
	}
	for (int i = 0; i < 4; i++)
	{
		yellow[i].setFillColor(Color(239, 255, 0));
		if (i < 2)
			yellow[i].setPosition(430 + (i * 40), 94);
		else
			yellow[i].setPosition(430 + ((i - 2) * 40), 134);
	}
}
void move_token_R(CircleShape token[4], int index, int r)
{
	int x = token[index].getPosition().x;
	int y = token[index].getPosition().y;
	if (x == 248)
	{
		if (y <= 545 && y >= 360)
		{
			for (int i = 0; i <= r; i++)
			{
				if (y <= 545 && y > 360)
				{
					token[index].setPosition(x, y - 37);
					y = token[index].getPosition().y;
				}
				else
				{
					token[index].setPosition(x - 37, 323);
					x = token[index].getPosition().x;
				}
			}
		}
		if (y <= 212 && y >= 27)
		{
			for (int i = 0; i <= r; i++)
			{
				if ((y <= 212 && y > 27) && x == 248)
				{
					token[index].setPosition(x, y - 37);
					y = token[index].getPosition().y;
				}
				else
				{
					if (x >= 248 && x < 322)
					{
						token[index].setPosition(x + 37, y);
						x = token[index].getPosition().x;
					}
					else
					{
						token[index].setPosition(x, y + 37);
						y = token[index].getPosition().y;
					}
				}
			}
		}

	}

	else if (y == 323)
	{
		if (x <= 211 && x >= 26)
		{
			for (int i = 0; i <= r; i++)
			{
				if ((x <= 211 && x > 26) && y == 323)
				{
					token[index].setPosition(x - 37, y);
					x = token[index].getPosition().x;
				}
				else
				{
					if (y <= 323 && y > 249)
					{
						token[index].setPosition(x, y - 37);
						y = token[index].getPosition().y;
					}
					else
					{
						token[index].setPosition(x + 37, y);
						x = token[index].getPosition().x;
					}

				}
			}
		}
		if (x <= 544 && x >= 359)
		{
			for (int i = 0; i <= r; i++)
			{
				if ((x <= 544 && x > 359) && y == 323)
				{
					token[index].setPosition(x - 37, y);
					x = token[index].getPosition().x;
				}
				else
				{
					token[index].setPosition(322, y + 37);
					y = token[index].getPosition().y;
				}
			}
		}
	}

	else if (x == 26)
	{
		for (int i = 0; i <= r; i++)
		{
			if (y <= 286 && y > 249)
			{
				token[index].setPosition(x, y - 37);
				y = token[index].getPosition().y;
			}
			else
			{
				if (x >= 26 && x < 211)
				{
					token[index].setPosition(x + 37, y);
					x = token[index].getPosition().x;
				}
				else
				{
					token[index].setPosition(248, y - 37);
					y = token[index].getPosition().y;
				}
			}
		}
	}

	else if (x == 544)
	{
		for (int i = 0; i <= r; i++)
		{
			if (y < 323 && y >= 249)
			{
				token[index].setPosition(x, y + 37);
				y = token[index].getPosition().y;
			}
			else
			{
				token[index].setPosition(x - 37, y);
				x = token[index].getPosition().x;
			}
		}
	}
	else if (y == 249)
	{
		if (x >= 26 && x <= 211)
		{
			for (int i = 0; i <= r; i++)
			{
				if (x >= 26 && x < 211)
				{
					token[index].setPosition(x + 37, y);
					x = token[index].getPosition().x;
				}
				else
				{
					token[index].setPosition(248, y - 37);
					y = token[index].getPosition().y;
				}
			}
		}
		if (x >= 359 && x <= 544)
		{
			for (int i = 0; i <= r; i++)
			{
				if ((x >= 359 && x < 544) && y == 249)
				{
					token[index].setPosition(x + 37, y);
					x = token[index].getPosition().x;
				}
				else
				{
					if (y >= 249 && y < 323)
					{
						token[index].setPosition(x, y + 37);
						y = token[index].getPosition().y;
					}
					else
					{
						token[index].setPosition(x - 37, y);
						x = token[index].getPosition().x;
					}
				}
			}
		}

	}
	/////////////////////////////////////////////////
	else if (y == 27)
	{
		for (int i = 0; i <= r; i++)
		{
			if (x > 248 && x < 322)
			{
				token[index].setPosition(x + 37, y);
				x = token[index].getPosition().x;
			}
			else
			{
				if (y >= 27 && y < 212)
				{
					token[index].setPosition(x, y + 37);
					y = token[index].getPosition().y;
				}
				else
				{
					token[index].setPosition(x + 37, 249);
					x = token[index].getPosition().x;
				}

			}
		}
	}

	//////////////////////////////////////////////
	else if (x == 322)
	{
		if (y >= 27 && y <= 212)
		{
			for (int i = 0; i <= r; i++)
			{
				if (y >= 27 && y < 212)
				{
					token[index].setPosition(x, y + 37);
					y = token[index].getPosition().y;
				}
				else
				{
					token[index].setPosition(x + 37, 249);
					x = token[index].getPosition().x;
				}
			}
		}
		if (y >= 360 && y <= 545)
		{
			for (int i = 0; i <= r; i++)
			{
				if ((y >= 360 && y < 545) && x == 322)
				{
					token[index].setPosition(x, y + 37);
					y = token[index].getPosition().y;
				}
				else
				{
					if (redhome)
					{
						if (x > 285 && x <= 322)
						{
							token[index].setPosition(x - 37, y);
							x = token[index].getPosition().x;
						}
						else
						{
							token[index].setPosition(x, y - 37);
							y = token[index].getPosition().y;
						}
					}
					else
					{
						if (x > 248 && x <= 322)
						{
							token[index].setPosition(x - 37, y);
							x = token[index].getPosition().x;
						}
						else
						{
							token[index].setPosition(x, y - 37);
							y = token[index].getPosition().y;
						}
					}

				}
			}
		}

	}
	/////////////////////////////////////////////////////////////
	else if (y == 545)
	{
		for (int i = 0; i <= r; i++)
		{
			if (x > 248 && x <= 322)
			{
				token[index].setPosition(x - 37, y);
				x = token[index].getPosition().x;
			}
			else
			{
				token[index].setPosition(x, y - 37);
				y = token[index].getPosition().y;
			}
		}
	}
	else if (redhome && x == 285)
	{
		int D = r * 37;
		if (y - D >= 323)
		{
			token[index].setPosition(x, y - 37);
			y = token[index].getPosition().y;
		}
	}
	if (x == 285 && y == 325)
	{
		redQ[index] = true;
	}
}
////////////////////////////////////////////////////////////////
void move_token_G(CircleShape token[4], int index, int r)
{
	int x = token[index].getPosition().x;
	int y = token[index].getPosition().y;
	if (x == 248)
	{
		if (y <= 545 && y >= 360)
		{
			for (int i = 0; i <= r; i++)
			{
				if (y <= 545 && y > 360)
				{
					token[index].setPosition(x, y - 37);
					y = token[index].getPosition().y;
				}
				else
				{
					token[index].setPosition(x - 37, 323);
					x = token[index].getPosition().x;
				}
			}
		}
		if (y <= 212 && y >= 27)
		{
			for (int i = 0; i <= r; i++)
			{
				if ((y <= 212 && y > 27) && x == 248)
				{
					token[index].setPosition(x, y - 37);
					y = token[index].getPosition().y;
				}
				else
				{
					if (x >= 248 && x < 322)
					{
						token[index].setPosition(x + 37, y);
						x = token[index].getPosition().x;
					}
					else
					{
						token[index].setPosition(x, y + 37);
						y = token[index].getPosition().y;
					}
				}
			}
		}

	}
	////////////////////////////////////////////////////////////////
	else if (y == 323)
	{
		if (x <= 211 && x >= 26)
		{
			for (int i = 0; i <= r; i++)
			{
				if ((x <= 211 && x > 26) && y == 323)
				{
					token[index].setPosition(x - 37, y);
					x = token[index].getPosition().x;
				}
				else
				{
					if (greenhome)
					{
						if (y <= 323 && y > 286)
						{
							token[index].setPosition(x, y - 37);
							y = token[index].getPosition().y;
						}
						else
						{
							token[index].setPosition(x + 37, y);
							x = token[index].getPosition().x;
						}
					}
					else
					{
						if (y <= 323 && y > 249)
						{
							token[index].setPosition(x, y - 37);
							y = token[index].getPosition().y;
						}
						else
						{
							token[index].setPosition(x + 37, y);
							x = token[index].getPosition().x;
						}
					}


				}
			}
		}
		if (x <= 544 && x >= 359)
		{
			for (int i = 0; i <= r; i++)
			{
				if ((x <= 544 && x > 359) && y == 323)
				{
					token[index].setPosition(x - 37, y);
					x = token[index].getPosition().x;
				}
				else
				{
					token[index].setPosition(322, y + 37);
					y = token[index].getPosition().y;
				}
			}
		}
	}
	///////////////////////////////////////////////////
	else if (x == 26)
	{
		for (int i = 0; i <= r; i++)
		{
			if (y <= 286 && y > 249)
			{
				token[index].setPosition(x, y - 37);
				y = token[index].getPosition().y;
			}
			else
			{
				if (x >= 26 && x < 211)
				{
					token[index].setPosition(x + 37, y);
					x = token[index].getPosition().x;
				}
				else
				{
					token[index].setPosition(248, y - 37);
					y = token[index].getPosition().y;
				}
			}
		}
	}
	/////////////////////////////////////////
	else if (x == 544)
	{
		for (int i = 0; i <= r; i++)
		{
			if (y < 323 && y >= 249)
			{
				token[index].setPosition(x, y + 37);
				y = token[index].getPosition().y;
			}
			else
			{
				token[index].setPosition(x - 37, y);
				x = token[index].getPosition().x;
			}
		}
	}
	else if (y == 249)
	{
		if (x >= 26 && x <= 211)
		{
			for (int i = 0; i <= r; i++)
			{
				if (x >= 26 && x < 211)
				{
					token[index].setPosition(x + 37, y);
					x = token[index].getPosition().x;
				}
				else
				{
					token[index].setPosition(248, y - 37);
					y = token[index].getPosition().y;
				}
			}
		}
		if (x >= 359 && x <= 544)
		{
			for (int i = 0; i <= r; i++)
			{
				if ((x >= 359 && x < 544) && y == 249)
				{
					token[index].setPosition(x + 37, y);
					x = token[index].getPosition().x;
				}
				else
				{
					if (y >= 249 && y < 323)
					{
						token[index].setPosition(x, y + 37);
						y = token[index].getPosition().y;
					}
					else
					{
						token[index].setPosition(x - 37, y);
						x = token[index].getPosition().x;
					}
				}
			}
		}

	}
	/////////////////////////////////////////////////
	else if (y == 27)
	{
		for (int i = 0; i <= r; i++)
		{
			if (x > 248 && x < 322)
			{
				token[index].setPosition(x + 37, y);
				x = token[index].getPosition().x;
			}
			else
			{
				if (y >= 27 && y < 212)
				{
					token[index].setPosition(x, y + 37);
					y = token[index].getPosition().y;
				}
				else
				{
					token[index].setPosition(x + 37, 249);
					x = token[index].getPosition().x;
				}

			}
		}
	}

	//////////////////////////////////////////////
	else if (x == 322)
	{
		if (y >= 27 && y <= 212)
		{
			for (int i = 0; i <= r; i++)
			{
				if (y >= 27 && y < 212)
				{
					token[index].setPosition(x, y + 37);
					y = token[index].getPosition().y;
				}
				else
				{
					token[index].setPosition(x + 37, 249);
					x = token[index].getPosition().x;
				}
			}
		}
		if (y >= 360 && y <= 545)
		{
			for (int i = 0; i <= r; i++)
			{
				if ((y >= 360 && y < 545) && x == 322)
				{
					token[index].setPosition(x, y + 37);
					y = token[index].getPosition().y;
				}
				else
				{
					if (x > 248 && x <= 322)
					{
						token[index].setPosition(x - 37, y);
						x = token[index].getPosition().x;
					}
					else
					{
						token[index].setPosition(x, y - 37);
						y = token[index].getPosition().y;
					}
				}

			}
		}
	}
	/////////////////////////////////////////////////////////////
	else if (y == 545)
	{
		for (int i = 0; i <= r; i++)
		{
			if (x > 248 && x <= 322)
			{
				token[index].setPosition(x - 37, y);
				x = token[index].getPosition().x;
			}
			else
			{
				token[index].setPosition(x, y - 37);
				y = token[index].getPosition().y;
			}
		}
	}
	else if (greenhome && y == 286)
	{
		int D = r * 37;
		if (x + D <= 248)
		{
			token[index].setPosition(x + 37, y);
			x = token[index].getPosition().x;
		}
	}
	if (x == 248 && y == 286)
	{
		greenQ[index] = true;
	}
}
///////////////////////////////////////////////////////////////
void move_token_Y(CircleShape token[4], int index, int r)
{
	int x = token[index].getPosition().x;
	int y = token[index].getPosition().y;
	if (x == 248)
	{
		if (y <= 545 && y >= 360)
		{
			for (int i = 0; i <= r; i++)
			{
				if (y <= 545 && y > 360)
				{
					token[index].setPosition(x, y - 37);
					y = token[index].getPosition().y;
				}
				else
				{
					token[index].setPosition(x - 37, 323);
					x = token[index].getPosition().x;
				}
			}
		}
		if (y <= 212 && y >= 27)
		{
			for (int i = 0; i <= r; i++)
			{
				if ((y <= 212 && y > 27) && x == 248)
				{
					token[index].setPosition(x, y - 37);
					y = token[index].getPosition().y;
				}
				else
				{
					if (yellowhome)
					{
						if (x >= 248 && x < 285)
						{
							token[index].setPosition(x + 37, y);
							x = token[index].getPosition().x;
						}
						else
						{
							token[index].setPosition(x, y + 37);
							y = token[index].getPosition().y;
						}
					}
					else
					{
						if (x >= 248 && x < 322)
						{
							token[index].setPosition(x + 37, y);
							x = token[index].getPosition().x;
						}
						else
						{
							token[index].setPosition(x, y + 37);
							y = token[index].getPosition().y;
						}
					}
				}
			}
		}

	}
	////////////////////////////////////////////////////////////////
	else if (y == 323)
	{
		if (x <= 211 && x >= 26)
		{
			for (int i = 0; i <= r; i++)
			{
				if ((x <= 211 && x > 26) && y == 323)
				{
					token[index].setPosition(x - 37, y);
					x = token[index].getPosition().x;
				}
				else
				{
					if (y <= 323 && y > 249)
					{
						token[index].setPosition(x, y - 37);
						y = token[index].getPosition().y;
					}
					else
					{
						token[index].setPosition(x + 37, y);
						x = token[index].getPosition().x;
					}
				}
			}
		}
		if (x <= 544 && x >= 359)
		{
			for (int i = 0; i <= r; i++)
			{
				if ((x <= 544 && x > 359) && y == 323)
				{
					token[index].setPosition(x - 37, y);
					x = token[index].getPosition().x;
				}
				else
				{
					token[index].setPosition(322, y + 37);
					y = token[index].getPosition().y;
				}
			}
		}
	}
	///////////////////////////////////////////////////
	else if (x == 26)
	{
		for (int i = 0; i <= r; i++)
		{
			if (y <= 286 && y > 249)
			{
				token[index].setPosition(x, y - 37);
				y = token[index].getPosition().y;
			}
			else
			{
				if (x >= 26 && x < 211)
				{
					token[index].setPosition(x + 37, y);
					x = token[index].getPosition().x;
				}
				else
				{
					token[index].setPosition(248, y - 37);
					y = token[index].getPosition().y;
				}
			}
		}
	}
	/////////////////////////////////////////
	else if (x == 544)
	{
		for (int i = 0; i <= r; i++)
		{
			if (y < 323 && y >= 249)
			{
				token[index].setPosition(x, y + 37);
				y = token[index].getPosition().y;
			}
			else
			{
				token[index].setPosition(x - 37, y);
				x = token[index].getPosition().x;
			}
		}
	}
	else if (y == 249)
	{
		if (x >= 26 && x <= 211)
		{
			for (int i = 0; i <= r; i++)
			{
				if (x >= 26 && x < 211)
				{
					token[index].setPosition(x + 37, y);
					x = token[index].getPosition().x;
				}
				else
				{
					token[index].setPosition(248, y - 37);
					y = token[index].getPosition().y;
				}
			}
		}
		if (x >= 359 && x <= 544)
		{
			for (int i = 0; i <= r; i++)
			{
				if ((x >= 359 && x < 544) && y == 249)
				{
					token[index].setPosition(x + 37, y);
					x = token[index].getPosition().x;
				}
				else
				{
					if (y >= 249 && y < 323)
					{
						token[index].setPosition(x, y + 37);
						y = token[index].getPosition().y;
					}
					else
					{
						token[index].setPosition(x - 37, y);
						x = token[index].getPosition().x;
					}
				}
			}
		}

	}
	/////////////////////////////////////////////////
	else if (y == 27)
	{
		for (int i = 0; i <= r; i++)
		{
			if (x > 248 && x < 322)
			{
				token[index].setPosition(x + 37, y);
				x = token[index].getPosition().x;
			}
			else
			{
				if (y >= 27 && y < 212)
				{
					token[index].setPosition(x, y + 37);
					y = token[index].getPosition().y;
				}
				else
				{
					token[index].setPosition(x + 37, 249);
					x = token[index].getPosition().x;
				}

			}
		}
	}

	//////////////////////////////////////////////
	else if (x == 322)
	{
		if (y >= 27 && y <= 212)
		{
			for (int i = 0; i <= r; i++)
			{
				if (y >= 27 && y < 212)
				{
					token[index].setPosition(x, y + 37);
					y = token[index].getPosition().y;
				}
				else
				{
					token[index].setPosition(x + 37, 249);
					x = token[index].getPosition().x;
				}
			}
		}
		if (y >= 360 && y <= 545)
		{
			for (int i = 0; i <= r; i++)
			{
				if ((y >= 360 && y < 545) && x == 322)
				{
					token[index].setPosition(x, y + 37);
					y = token[index].getPosition().y;
				}
				else
				{
					if (x > 248 && x <= 322)
					{
						token[index].setPosition(x - 37, y);
						x = token[index].getPosition().x;
					}
					else
					{
						token[index].setPosition(x, y - 37);
						y = token[index].getPosition().y;
					}
				}

			}
		}
	}
	/////////////////////////////////////////////////////////////
	else if (y == 545)
	{
		for (int i = 0; i <= r; i++)
		{
			if (x > 248 && x <= 322)
			{
				token[index].setPosition(x - 37, y);
				x = token[index].getPosition().x;
			}
			else
			{
				token[index].setPosition(x, y - 37);
				y = token[index].getPosition().y;
			}
		}
	}
	else if (yellowhome && x == 286)
	{
		int D = r * 37;
		if (y + D <= 249)
		{
			token[index].setPosition(x, y + 37);
			y = token[index].getPosition().y;
		}
	}
	if (x == 285 && y == 249)
	{
		yellowQ[index] = true;
	}
}
///////////////////////////////////////////////////////////////
void move_token_B(CircleShape token[4], int index, int r)
{
	int x = token[index].getPosition().x;
	int y = token[index].getPosition().y;
	if (x == 248)
	{
		if (y <= 545 && y >= 360)
		{
			for (int i = 0; i <= r; i++)
			{
				if (y <= 545 && y > 360)
				{
					token[index].setPosition(x, y - 37);
					y = token[index].getPosition().y;
				}
				else
				{
					token[index].setPosition(x - 37, 323);
					x = token[index].getPosition().x;
				}
			}
		}
		if (y <= 212 && y >= 27)
		{
			for (int i = 0; i <= r; i++)
			{
				if ((y <= 212 && y > 27) && x == 248)
				{
					token[index].setPosition(x, y - 37);
					y = token[index].getPosition().y;
				}
				else
				{
					if (x >= 248 && x < 322)
					{
						token[index].setPosition(x + 37, y);
						x = token[index].getPosition().x;
					}
					else
					{
						token[index].setPosition(x, y + 37);
						y = token[index].getPosition().y;
					}
				}
			}
		}

	}
	////////////////////////////////////////////////////////////////
	else if (y == 323)
	{
		if (x <= 211 && x >= 26)
		{
			for (int i = 0; i <= r; i++)
			{
				if ((x <= 211 && x > 26) && y == 323)
				{
					token[index].setPosition(x - 37, y);
					x = token[index].getPosition().x;
				}
				else
				{
					if (y <= 323 && y > 249)
					{
						token[index].setPosition(x, y - 37);
						y = token[index].getPosition().y;
					}
					else
					{
						token[index].setPosition(x + 37, y);
						x = token[index].getPosition().x;
					}
				}
			}
		}
		if (x <= 544 && x >= 359)
		{
			for (int i = 0; i <= r; i++)
			{
				if ((x <= 544 && x > 359) && y == 323)
				{
					token[index].setPosition(x - 37, y);
					x = token[index].getPosition().x;
				}
				else
				{
					token[index].setPosition(322, y + 37);
					y = token[index].getPosition().y;
				}
			}
		}
	}
	///////////////////////////////////////////////////
	else if (x == 26)
	{
		for (int i = 0; i <= r; i++)
		{
			if (y <= 286 && y > 249)
			{
				token[index].setPosition(x, y - 37);
				y = token[index].getPosition().y;
			}
			else
			{
				if (x >= 26 && x < 211)
				{
					token[index].setPosition(x + 37, y);
					x = token[index].getPosition().x;
				}
				else
				{
					token[index].setPosition(248, y - 37);
					y = token[index].getPosition().y;
				}
			}
		}
	}

	else if (x == 544)
	{
		for (int i = 0; i <= r; i++)
		{
			if (y < 323 && y >= 249)
			{
				token[index].setPosition(x, y + 37);
				y = token[index].getPosition().y;
			}
			else
			{
				token[index].setPosition(x - 37, y);
				x = token[index].getPosition().x;
			}
		}
	}
	else if (y == 249)
	{
		if (x >= 26 && x <= 211)
		{
			for (int i = 0; i <= r; i++)
			{
				if (x >= 26 && x < 211)
				{
					token[index].setPosition(x + 37, y);
					x = token[index].getPosition().x;
				}
				else
				{
					token[index].setPosition(248, y - 37);
					y = token[index].getPosition().y;
				}
			}
		}
		if (x >= 359 && x <= 544)
		{
			for (int i = 0; i <= r; i++)
			{
				if ((x >= 359 && x < 544) && y == 249)
				{
					token[index].setPosition(x + 37, y);
					x = token[index].getPosition().x;
				}
				else
				{
					if (bluehome)
					{
						if (y >= 249 && y < 286)
						{
							token[index].setPosition(x, y + 37);
							y = token[index].getPosition().y;
						}
						else
						{
							token[index].setPosition(x - 37, y);
							x = token[index].getPosition().x;
						}
					}
					else
					{
						if (y >= 249 && y < 323)
						{
							token[index].setPosition(x, y + 37);
							y = token[index].getPosition().y;
						}
						else
						{
							token[index].setPosition(x - 37, y);
							x = token[index].getPosition().x;
						}
					}
				}
			}
		}

	}
	
	else if (y == 27)
	{
		for (int i = 0; i <= r; i++)
		{
			if (x > 248 && x < 322)
			{
				token[index].setPosition(x + 37, y);
				x = token[index].getPosition().x;
			}
			else
			{
				if (y >= 27 && y < 212)
				{
					token[index].setPosition(x, y + 37);
					y = token[index].getPosition().y;
				}
				else
				{
					token[index].setPosition(x + 37, 249);
					x = token[index].getPosition().x;
				}

			}
		}
	}

	else if (x == 322)
	{
		if (y >= 27 && y <= 212)
		{
			for (int i = 0; i <= r; i++)
			{
				if (y >= 27 && y < 212)
				{
					token[index].setPosition(x, y + 37);
					y = token[index].getPosition().y;
				}
				else
				{
					token[index].setPosition(x + 37, 249);
					x = token[index].getPosition().x;
				}
			}
		}
		if (y >= 360 && y <= 545)
		{
			for (int i = 0; i <= r; i++)
			{
				if ((y >= 360 && y < 545) && x == 322)
				{
					token[index].setPosition(x, y + 37);
					y = token[index].getPosition().y;
				}
				else
				{
					if (x > 248 && x <= 322)
					{
						token[index].setPosition(x - 37, y);
						x = token[index].getPosition().x;
					}
					else
					{
						token[index].setPosition(x, y - 37);
						y = token[index].getPosition().y;
					}
				}

			}
		}
	}

	else if (y == 545)
	{
		for (int i = 0; i <= r; i++)
		{
			if (x > 248 && x <= 322)
			{
				token[index].setPosition(x - 37, y);
				x = token[index].getPosition().x;
			}
			else
			{
				token[index].setPosition(x, y - 37);
				y = token[index].getPosition().y;
			}
		}
	}
	else if (bluehome && y == 286)
	{
		int D = r * 37;
		if (x - D >= 322)
		{
			token[index].setPosition(x, y + 37);
			y = token[index].getPosition().y;
		}
	}
	if (x == 322 && y == 286)
	{
		blueQ[index] = true;
	}
}

void open_lock_R(CircleShape red[4], int index)
{
	red[index].setPosition(248, 508);
}

void open_lock_G(CircleShape green[4], int index)
{
	green[index].setPosition(63, 249);
}

void open_lock_B(CircleShape blue[4], int index)
{
	blue[index].setPosition(507, 323);
}

void open_lock_Y(CircleShape yellow[4], int index)
{
	yellow[index].setPosition(322, 64);
}

bool all_lock_check(bool lock[4])
{
	for (int i = 0; i < 4; i++)
	{
		if (lock[i] == true)
		{
			return false;
			break;
		}
	}
	return true;
}

bool condition(double x, double y)
{
	if (x == 248 && y == 508)
	{
		return true;
	}
	else if (x == 100 && y == 323)
	{
		return true;
	}
	else if (x == 63 && y == 249)
	{
		return true;
	}
	else if (x == 248 && y == 101)
	{
		return true;
	}
	else if (x == 322 && y == 64)
	{
		return true;
	}
	else if (x == 470 && y == 249)
	{
		return true;
	}
	else if (x == 507 && y == 323)
	{
		return true;
	}
	else if (x == 322 && y == 471)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void Lock_Token(CircleShape main[], CircleShape token1[], CircleShape token2[], CircleShape token3[], bool Token1[], bool Token2[], bool Token3[], int i, bool& home)
{
	double x = main[i].getPosition().x;
	double y = main[i].getPosition().y;
	double Tx;
	double Ty;
	if (!condition(x, y))
	{
		for (int k = 0; k < 4; k++)
		{
			Tx = token1[k].getPosition().x;
			Ty = token1[k].getPosition().y;
			if ((x == Tx) && (y == Ty))
			{
				Token1[k] = false;
				home = true;
			}
		}
		for (int k = 0; k < 4; k++)
		{
			Tx = token2[k].getPosition().x;
			Ty = token2[k].getPosition().y;
			if ((x == Tx) && (y == Ty))
			{
				Token2[k] = false;
				home = true;
			}
		}
		for (int k = 0; k < 4; k++)
		{
			Tx = token3[k].getPosition().x;
			Ty = token3[k].getPosition().y;
			if ((x == Tx) && (y == Ty))
			{
				Token3[k] = false;
				home = true;
			}
		}
	}
}

void Lock_Position_RGYB(CircleShape red[], CircleShape green[], CircleShape yellow[], CircleShape blue[], bool lock_R[], bool lock_G[], bool lock_Y[], bool lock_B[])
{
	for (int i = 0; i < 4; i++)
	{
		if (lock_R[i] == false)
		{
			if (i < 2)
				red[i].setPosition(94 + (i * 40), 430);
			else
				red[i].setPosition(94 + ((i - 2) * 40), 468);
		}
		if (lock_G[i] == false)
		{
			if (i < 2)
				green[i].setPosition(94 + (i * 40), 94);
			else
				green[i].setPosition(94 + ((i - 2) * 40), 134);
		}
		if (lock_Y[i] == false)
		{
			if (i < 2)
				yellow[i].setPosition(430 + (i * 40), 94);
			else
				yellow[i].setPosition(430 + ((i - 2) * 40), 134);
		}
		if (lock_B[i] == false)
		{
			if (i < 2)
				blue[i].setPosition(430 + (i * 40), 430);
			else
				blue[i].setPosition(430 + ((i - 2) * 40), 468);
		}
	}
}

void same_Lock(CircleShape main[], bool sameLock[], int i)
{
	double x;
	double y;
	double Tx;
	double Ty;
	for (int k = 0; k < 3; k++)
	{
		x = main[k].getPosition().x;
		y = main[k].getPosition().y;
		for (int j = 0; j < 4; j++)
		{
			Tx = main[j].getPosition().x;
			Ty = main[j].getPosition().y;
			if ((sameLock[k] == true) && (j != k) && (x == Tx && y == Ty))
			{
				sameLock[j] = false;
			}
		}

	}
}

void same_UNLock(CircleShape main[], bool sameLock[], int i)
{
	double x;
	double y;
	double Tx;
	double Ty;
	bool unlock;
	for (int k = 0; k < 4; k++)
	{
		unlock = true;
		x = main[k].getPosition().x;
		y = main[k].getPosition().y;
		if (sameLock[k] == false)
		{
			for (int j = 0; j < 4; j++)
			{
				Tx = main[j].getPosition().x;
				Ty = main[j].getPosition().y;
				if ((j != k) && (x == Tx && y == Ty))
				{
					unlock = false;
					break;
				}
				sameLock[k] = true;
			}
			if (!unlock)
			{
				sameLock[k] = false;
			}
		}


	}
}
///////////////////////////////////////////////////////////////
bool end_game()
{
	bool r, g, y, b;
	for (int i = 0; i < 4; i++)
	{
		if (redQ[i] == false)
		{
			r = false;
			break;
		}
		else
		{
			r = true;
		}

	}
	for (int i = 0; i < 4; i++)
	{
		if (greenQ[i] == false)
		{
			g = false;
			break;
		}
		else
		{
			g = true;
		}

	}
	for (int i = 0; i < 4; i++)
	{
		if (yellowQ[i] == false)
		{
			y = false;
			break;
		}
		else
		{
			y = true;
		}

	}
	for (int i = 0; i < 4; i++)
	{
		if (blueQ[i] == false)
		{
			b = false;
			break;
		}
		else
		{
			b = true;
		}

	}
	if (r && g && y)
	{
		return true;
	}
	else if (g && y && b)
	{
		return true;
	}
	else if (r && y && b)
	{
		return true;
	}
	else if (r && g && b)
	{
		return true;
	}
	else
	{
		return false;
	}
}