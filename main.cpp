#include "mbed.h"
#include "sample.h"
#include "Adafruit_ST7735.h"

#define DIN P0_9
#define CLK P0_10
#define CD P0_11
#define DC P0_12
#define RST P0_13

Adafruit_ST7735 tft(DIN, NC, CLK, CD, DC, RST);

int main() {
	tft.initS();
	tft.setRotation(3);

	tft.fillScreen(ST7735_WHITE);
	uint8_t x = 0;
	uint8_t y = 0;

	tft.fillRect(50, 50, 5, 5, tft.Color565(255, 0, 0));
	tft.fillRect(50, 55, 5, 5,  tft.Color565(0, 255, 0));
	tft.fillRect(50, 60, 5, 5,  tft.Color565(0, 0, 255));
	tft.fillRect(50, 65, 5, 5,  tft.Color565(255, 255, 0));
	tft.fillRect(55, 50, 5, 5,  ST7735_RED);
	tft.fillRect(55, 55, 5, 5,  ST7735_GREEN);
	tft.fillRect(55, 60, 5, 5,  ST7735_BLUE);
	tft.fillRect(55, 65, 5, 5,  ST7735_YELLOW);

	/*
	tft.setTextCursor(100, 100);
	tft.setTextColor(ST7735_BLACK);
	tft.writeChar('c');
	tft.writeChar('h');
	tft.writeChar('o');
	tft.writeChar('4');
	tft.writeChar('5');
	*/

	uint16_t c = tft.Color565(0, 0, 255);
	while (1) {
		tft.fillScreen(ST7735_BLACK);

		const uint16_t offsetx = (160 - sample_w) / 2;
		const uint16_t offsety = (128 - sample_h) / 2;
		tft.setAddrWindow(offsetx, offsety, offsetx + sample_w - 1, offsety + sample_h - 1);
		for (int y = 0; y < sample_h; y++) {
			for (int x = 0; x < sample_w; x++) {
				uint16_t h = sample[(x + y * sample_w) * 2 + 0];
				uint16_t l = sample[(x + y * sample_w) * 2 + 1];
				uint16_t c = (h << 8) | l;
				// tft.drawPixel(x + offsetx, y + offsety, c);
				tft.pushColor(c);
			}
		}

		wait_ms(1000);

		uint16_t i = 0;
		while (i++ < 200) {
			x = rand() % 160;
			y = rand() % 128;

			tft.fillRect(x, y, 5, 5, c++);

			wait_ms(24);
		}
	}
}

