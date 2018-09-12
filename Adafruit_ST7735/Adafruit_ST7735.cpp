/***************************************************
  This is a library for the Adafruit 1.8" SPI display.
  This library works with the Adafruit 1.8" TFT Breakout w/SD card
  ----> http://www.adafruit.com/products/358
  as well as Adafruit raw 1.8" TFT display
  ----> http://www.adafruit.com/products/618

  Check out the links above for our tutorials and wiring diagrams
  These displays use SPI to communicate, 4 or 5 pins are required to
  interface (RST is optional)
  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.
  MIT license, all text above must be included in any redistribution
 ****************************************************/

#include "mbed.h"
#include "Adafruit_ST7735.h"

// Constructor 
Adafruit_ST7735::Adafruit_ST7735(PinName mosi, PinName miso, PinName sck, PinName cs, PinName rs, PinName rst) 
        : lcdPort(mosi, miso, sck), _cs(cs), _rs(rs), _rst(rst), Adafruit_GFX(ST7735_TFTWIDTH, ST7735_TFTHEIGHT) 
{ }


void Adafruit_ST7735::writecommand(uint8_t c)
{
    _rs = 0;
    _cs = 0;
    lcdPort.write( c );
    _cs = 1;
}


void Adafruit_ST7735::writedata(uint8_t c)
{
    _rs = 1;
    _cs = 0;
    lcdPort.write( c );

    _cs = 1;
}


// Rather than a bazillion writecommand() and writedata() calls, screen
// initialization commands and arguments are organized in these tables
// stored in PROGMEM.  The table may look bulky, but that's mostly the
// formatting -- storage-wise this is hundreds of bytes more compact
// than the equivalent code.  Companion function follows.
#define DELAY 0x80

static unsigned char Scmd[] = {
    21,
    ST7735_SWRESET,   DELAY,  //  1: Software reset, 0 args, w/delay
    150,                    //     150 ms delay
    ST7735_SLPOUT ,   DELAY,  //  2: Out of sleep mode, 0 args, w/delay
    255,                    //     500 ms delay
    ST7735_FRMCTR1, 3      ,  //  3: Frame rate ctrl - normal mode, 3 args:
    0x01, 0x2C, 0x2D,       //     Rate = fosc/(1x2+40) * (LINE+2C+2D)
    ST7735_FRMCTR2, 3      ,  //  4: Frame rate control - idle mode, 3 args:
    0x01, 0x2C, 0x2D,       //     Rate = fosc/(1x2+40) * (LINE+2C+2D)
    ST7735_FRMCTR3, 6      ,  //  5: Frame rate ctrl - partial mode, 6 args:
    0x01, 0x2C, 0x2D,       //     Dot inversion mode
    0x01, 0x2C, 0x2D,       //     Line inversion mode
    ST7735_INVCTR , 1      ,  //  6: Display inversion ctrl, 1 arg, no delay:
    0x07,                   //     No inversion
    ST7735_PWCTR1 , 3      ,  //  7: Power control, 3 args, no delay:
    0xA2,
    0x02,                   //     -4.6V
    0x84,                   //     AUTO mode
    ST7735_PWCTR2 , 1      ,  //  8: Power control, 1 arg, no delay:
    0xC5,                   //     VGH25 = 2.4C VGSEL = -10 VGH = 3 * AVDD
    ST7735_PWCTR3 , 2      ,  //  9: Power control, 2 args, no delay:
    0x0A,                   //     Opamp current small
    0x00,                   //     Boost frequency
    ST7735_PWCTR4 , 2      ,  // 10: Power control, 2 args, no delay:
    0x8A,                   //     BCLK/2, Opamp current small & Medium low
    0x2A,
    ST7735_PWCTR5 , 2      ,  // 11: Power control, 2 args, no delay:
    0x8A, 0xEE,
    ST7735_VMCTR1 , 1      ,  // 12: Power control, 1 arg, no delay:
    0x0E,
    ST7735_INVOFF , 0      ,  // 13: Don't invert display, no args, no delay
    ST7735_MADCTL , 1      ,  // 14: Memory access control (directions), 1 arg:
    0b11000110,                   //     row addr/col addr, bottom to top refresh
    ST7735_COLMOD , 1      ,  // 15: set color mode, 1 arg, no delay:
    0x05,
    ST7735_CASET  , 4      ,  //  1: Column addr set, 4 args, no delay:
    0x00, 0x02,             //     XSTART = 0
    0x00, 0x7F+0x02,        //     XEND = 127
    ST7735_RASET  , 4      ,  //  2: Row addr set, 4 args, no delay:
    0x00, 0x01,             //     XSTART = 0
    0x00, 0x9F+0x01,
    ST7735_GMCTRP1, 16      , //  1: Magical unicorn dust, 16 args, no delay:
    0x02, 0x1c, 0x07, 0x12,
    0x37, 0x32, 0x29, 0x2d,
    0x29, 0x25, 0x2B, 0x39,
    0x00, 0x01, 0x03, 0x10,
    ST7735_GMCTRN1, 16      , //  2: Sparkles and rainbows, 16 args, no delay:
    0x03, 0x1d, 0x07, 0x06,
    0x2E, 0x2C, 0x29, 0x2D,
    0x2E, 0x2E, 0x37, 0x3F,
    0x00, 0x00, 0x02, 0x10,
    ST7735_NORON  ,    DELAY, //  3: Normal display on, no args, w/delay
    10,                     //     10 ms delay
    ST7735_DISPON ,    DELAY, //  4: Main screen turn on, no args w/delay
    100
};

// Companion code to the above tables.  Reads and issues
// a series of LCD commands stored in byte array.
void Adafruit_ST7735::commandList(uint8_t *addr)
{

    uint8_t  numCommands, numArgs;
    uint16_t ms;

    numCommands = *addr++;   // Number of commands to follow
    while(numCommands--) {                 // For each command...
        writecommand(*addr++); //   Read, issue command
        numArgs  = *addr++;    //   Number of args to follow
        ms       = numArgs & DELAY;          //   If hibit set, delay follows args
        numArgs &= ~DELAY;                   //   Mask out delay bit
        while(numArgs--) {                   //   For each argument...
            writedata(*addr++);  //     Read, issue argument
        }

        if(ms) {
            ms = *addr++; // Read post-command delay time (ms)
            if(ms == 255) ms = 500;     // If 255, delay for 500 ms
            wait_ms(ms);
        }
    }
}


// Initialization code common to both 'B' and 'R' type displays
void Adafruit_ST7735::commonInit(uint8_t *cmdList)
{

    colstart  = rowstart = 0; // May be overridden in init func

    _rs = 1;
    _cs = 1;

    // use default SPI format
    lcdPort.format(8,0);
    lcdPort.frequency(4000000);     // Lets try 4MHz

    // toggle RST low to reset; CS low so it'll listen to us
    _cs = 0;
    _rst = 1;
    wait_ms(500);
    _rst = 0;
    wait_ms(500);
    _rst = 1;
    wait_ms(500);

    if(cmdList) commandList(cmdList);
}


// Initialization for ST7735B screens
void Adafruit_ST7735::initS(void)
{
    commonInit(Scmd);
}

void Adafruit_ST7735::setAddrWindow(uint8_t x0, uint8_t y0, uint8_t x1,
                                    uint8_t y1)
{

    writecommand(ST7735_CASET); // Column addr set
    writedata(0x00);
    writedata(x0+colstart);     // XSTART
    writedata(0x00);
    writedata(x1+colstart);     // XEND

    writecommand(ST7735_RASET); // Row addr set
    writedata(0x00);
    writedata(y0+rowstart);     // YSTART
    writedata(0x00);
    writedata(y1+rowstart);     // YEND

    writecommand(ST7735_RAMWR); // write to RAM
}


void Adafruit_ST7735::fillScreen(uint16_t color)
{

    uint8_t x, y, hi = color >> 8, lo = color;

    setAddrWindow(0, 0, _width-1, _height-1);

    _rs = 1;
    _cs = 0;

    for(y=_height; y>0; y--) {
        for(x=_width; x>0; x--) {
            lcdPort.write( hi );
            lcdPort.write( lo );
        }
    }

    _cs = 1;
}


void Adafruit_ST7735::pushColor(uint16_t color)
{
    _rs = 1;
    _cs = 0;

    lcdPort.write( color >> 8 );
    lcdPort.write( color );
    _cs = 1;
}


void Adafruit_ST7735::drawPixel(int16_t x, int16_t y, uint16_t color)
{

    if((x < 0) ||(x >= _width) || (y < 0) || (y >= _height)) return;

    setAddrWindow(x,y,x+1,y+1);

    _rs = 1;
    _cs = 0;

    lcdPort.write( color >> 8 );
    lcdPort.write( color );

    _cs = 1;
}


void Adafruit_ST7735::drawFastVLine(int16_t x, int16_t y, int16_t h,
                                    uint16_t color)
{

    // Rudimentary clipping
    if((x >= _width) || (y >= _height)) return;
    if((y+h-1) >= _height) h = _height-y;
    setAddrWindow(x, y, x, y+h-1);

    uint8_t hi = color >> 8, lo = color;
    _rs = 1;
    _cs = 0;
    while (h--) {
        lcdPort.write( hi );
        lcdPort.write( lo );
    }
    _cs = 1;
}


void Adafruit_ST7735::drawFastHLine(int16_t x, int16_t y, int16_t w,
                                    uint16_t color)
{

    // Rudimentary clipping
    if((x >= _width) || (y >= _height)) return;
    if((x+w-1) >= _width)  w = _width-x;
    setAddrWindow(x, y, x+w-1, y);

    uint8_t hi = color >> 8, lo = color;
    _rs = 1;
    _cs = 0;
    while (w--) {
        lcdPort.write( hi );
        lcdPort.write( lo );
    }
    _cs = 1;
}


// fill a rectangle
void Adafruit_ST7735::fillRect(int16_t x, int16_t y, int16_t w, int16_t h,
                               uint16_t color)
{

    // rudimentary clipping (drawChar w/big text requires this)
    if((x >= _width) || (y >= _height)) return;
    if((x + w - 1) >= _width)  w = _width  - x;
    if((y + h - 1) >= _height) h = _height - y;

    setAddrWindow(x, y, x+w-1, y+h-1);

    uint8_t hi = color >> 8, lo = color;
    _rs = 1;
    _cs = 0;
    for(y=h; y>0; y--) {
        for(x=w; x>0; x--) {
            lcdPort.write( hi );
            lcdPort.write( lo );
        }
    }

    _cs = 1;
}


// Pass 8-bit (each) R,G,B, get back 16-bit packed color
uint16_t Adafruit_ST7735::Color565(uint8_t r, uint8_t g, uint8_t b)
{
    return ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3);
}


#define MADCTL_MY  0x80
#define MADCTL_MX  0x40
#define MADCTL_MV  0x20
#define MADCTL_ML  0x10
#define MADCTL_RGB 0x00
#define MADCTL_MH  0x04

void Adafruit_ST7735::setRotation(uint8_t m)
{

    writecommand(ST7735_MADCTL);
    rotation = m % 4; // can't be higher than 3
    switch (rotation) {
        case 0:
            writedata(MADCTL_MX | MADCTL_MY | MADCTL_RGB);
            _width  = ST7735_TFTWIDTH;
            _height = ST7735_TFTHEIGHT;
            break;
        case 1:
            writedata(MADCTL_MY | MADCTL_MV | MADCTL_RGB);
            _width  = ST7735_TFTHEIGHT;
            _height = ST7735_TFTWIDTH;
            break;
        case 2:
            writedata(MADCTL_RGB);
            _width  = ST7735_TFTWIDTH;
            _height = ST7735_TFTHEIGHT;
            break;
        case 3:
            writedata(MADCTL_MX | MADCTL_MV | MADCTL_RGB);
            _width  = ST7735_TFTHEIGHT;
            _height = ST7735_TFTWIDTH;
            break;
    }
}


void Adafruit_ST7735::invertDisplay(boolean i)
{
    writecommand(i ? ST7735_INVON : ST7735_INVOFF);
}


