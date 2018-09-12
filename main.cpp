#include "mbed.h"
// #include "sample.h"
#include "Adafruit_ST7735.h"
#include "MyUSBSerial.h"

#define DEBUG 1

// Generic DEBUG_PRINTF must not used at any interrupt
#if DEBUG
#define DEBUG_PRINTF(...) serial.printf(__VA_ARGS__)
#else
#define DEBUG_PRINTF(...)
#endif
Serial serial(UART_TX, UART_RX);

#define DIN P0_9
#define CLK P0_10
#define CD P0_11
#define DC P0_12
#define RST P0_13

Adafruit_ST7735 tft(DIN, NC, CLK, CD, DC, RST);
MyUSBSerial usbserial(0xf055, 0xf001);

void command_f() {
	char res[64];
	uint8_t buf[2];

	// usbcdc.write(new Uint8Array(Array.from("\\f\x07\xff").map(i=>i.charCodeAt(0))));
	usbserial.read(2, buf);
	uint16_t c = ((uint16_t)buf[0] << 8) | (uint16_t)buf[1];
	tft.fillScreen(c);
	usbserial.writeBlock(&res[0], sprintf(res, "OK:f %x\r\n", c));
}

void command_b() {
	char res[64];
	uint8_t buf[2];

	uint16_t offsetx = 0;
	uint16_t offsety = 0;
	uint16_t width = 160;
	uint16_t height = 128;
	tft.setAddrWindow(offsetx, offsety, offsetx + width - 1, offsety + height - 1);
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			usbserial.read(2, buf);
			uint16_t c = (buf[0] << 8) | buf[1];
			tft.pushColor(c);
		}
	}
	usbserial.writeBlock(&res[0], sprintf(res, "OK:b\r\n"));
}

int main() {
	tft.initS();
	tft.setRotation(3);

	tft.fillScreen(ST7735_BLACK);
	tft.setTextCursor(5, 5);
	tft.setTextColor(ST7735_GREEN);
	tft.writeChar('i');
	tft.writeChar('n');
	tft.writeChar('i');
	tft.writeChar('t');

	DEBUG_PRINTF("init\r\n");
	char res[64];

	while (1) {
		while (usbserial.read() != '\\'); // skip
		uint8_t command = usbserial.read();
		DEBUG_PRINTF("command %x\r\n", command);
		switch (command) {
		case 'f':
			command_f();
			break;
		case 'b':
			command_b();
			break;
		default:
			usbserial.writeBlock(&res[0], sprintf(res, "ERR:invalid command:%c\r\n", command));
		}
	}

//	uint16_t c = tft.Color565(0, 0, 255);
//	while (1) {
//		tft.fillScreen(ST7735_BLACK);
//
//		const uint16_t offsetx = (160 - sample_w) / 2;
//		const uint16_t offsety = (128 - sample_h) / 2;
//		tft.setAddrWindow(offsetx, offsety, offsetx + sample_w - 1, offsety + sample_h - 1);
//		for (int y = 0; y < sample_h; y++) {
//			for (int x = 0; x < sample_w; x++) {
//				uint16_t h = sample[(x + y * sample_w) * 2 + 0];
//				uint16_t l = sample[(x + y * sample_w) * 2 + 1];
//				uint16_t c = (h << 8) | l;
//				// tft.drawPixel(x + offsetx, y + offsety, c);
//				tft.pushColor(c);
//			}
//		}
//
//		wait_ms(1000);
//
//		uint16_t i = 0;
//		while (i++ < 200) {
//			x = rand() % 160;
//			y = rand() % 128;
//
//			tft.fillRect(x, y, 5, 5, c++);
//
//			wait_ms(24);
//		}
//	}
}

