/* ENGGEN131 (2020) - Lab 9 (5th - 9th October, 2020)
   EXERCISE SIX - Da Vinci Code

   Draw something spectacular!
*/

#include "LibBMP.h"

int main(void)
{
	int width, height, i;
	int border = 5;

	LoadBMPFile("blank.bmp", &width, &height);

	// Draw the border
	for (i = border; i < width - border; i++) {
		DrawPixel(border, i, 0, 0, 0);
		DrawPixel(height - border, i, 0, 0, 0);
	}
	for (i = border; i < height - border; i++) {
		DrawPixel(i, border, 0, 0, 0);
		DrawPixel(i, width - border, 0, 0, 0);
	}

	// Some basic art...
	DrawLine(280, 280, 320, 320, 0, 0, 0);
	DrawLine(280, 320, 320, 280, 0, 0, 0);
	FillCircle(300, 260, 20, 0, 0, 255);
	DrawSquare(260, 300, 20, 255, 0, 0);
	FillSquare(340, 300, 20, 0, 255, 0);
	DrawCircle(300, 340, 20, 255, 0, 0);

	SaveBMPFile("output.bmp", width, height);

	return 0;
}
