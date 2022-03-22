#pragma once
#include <iostream> 
#include "game.cpp"

void explosion(Ships* characteristic, int ship_pos[12][24], int plus, int& end) //уничтожение кораблкиков и определение победителя в игре
{
	int A = 0; 
	int B = 13; 
	int C = 0; 
	bool alive = false; 
	for (size_t n = 13; n > 3; n--) 
	{
		for (size_t i = 1; i < 11; i++) 
		{
			for (size_t r = 2; r < 22; r++)
			{
				if (ship_pos[i][r] == n) 
				{
					alive = true;
					i = 11; 
					break;
				}
			}
		}
		if (alive == false) 
		{
			characteristic[B - n + plus].alive = false; 
		}
		else 
		{
			alive = false; 
		}
	}
	for (size_t i = plus; i < 10 + plus; i++)
	{
		if (i == 0 || i == 10) 
		{
			A = 0; 
		}
		else if (i == 1 || i == 2 || i == 11 || i == 12)
		{
			A = 1; 
		}
		else if (i > 2 && i < 6 || i > 12 && i < 16)  
		{
			A = 2; 
		}
		else  
		{
			A = 3; 
		}
		if (characteristic[i].alive == false) 
		{
			if (characteristic[i].horizontal == true) 
			{
				for (size_t q = 0; q < 3; q++) 
				{
					for (size_t w = 0; w < characteristic[i].deck * 3 + A; w++)
					{
						ship_pos[characteristic[i].y - 2 + q][characteristic[i].x - 4 + w] = 2; 
					}
				}
				for (size_t g = 0; g < 2 * characteristic[i].deck; g++) 
				{
					ship_pos[characteristic[i].y - 1][characteristic[i].x - 2 + g] = 3;
				}
			}
			else if (characteristic[i].horizontal == false)  
			{
				for (size_t q = 0; q < characteristic[i].deck + 2; q++) 
				{
					for (int w = -4; w < 2; w++)  
					{
						ship_pos[characteristic[i].y - 2 + q][characteristic[i].x + w] = 2; 
					}
				}
				for (int g = 0; g < characteristic[i].deck; g++) 
				{
					for (int n = -2; n < 0; n++) 
					{
						ship_pos[characteristic[i].y - 1 + g][characteristic[i].x + n] = 3; 
					}
				}
			}
			C++; 
		}
	}
	if (C == 10 && plus == 0)
	{
		end = 1; 
	}
	else if (C == 10 && plus == 10) 
	{
		end = 2; 
	}
	else
	{
		C = 0; 
	}
}
void LoadCharactShips(Ships* characteristic) 
{
	for (size_t i = 0; i < 20; i++)
	{
		if (i == 0 || i == 10) 
		{
			characteristic[i].deck = 4; 
		}
		else if (i > 0 && i <= 2 || i > 10 && i <= 12) 
		{
			characteristic[i].deck = 3; 
		}
		else if (i > 2 && i <= 5 || i > 12 && i <= 15) 
		{
			characteristic[i].deck = 2; 
		}
		else if (i > 5 && i <= 9 || i > 15 && i <= 19) 
		{
			characteristic[i].deck = 1; 
		}
	}
}
