/* Tiny TFT Graphics Library v8 - see http://www.technoblogy.com/show?5N9Y

   David Johnson-Davies - www.technoblogy.com - 29th March 2026
   
   Licensed under the MIT license: https://opensource.org/licenses/MIT
*/

#if defined(MEGATINYCORE)
// ATtiny 0, 1, or 2-series PORTA positions. Change these for your circuit
const int dc = 7;
const int mosi = 1;
const int sck = 3;
const int cs = 6;

// ATtiny 0-, 1-, and 2-series port manipulations - assumes all pins in same port
#define PORT_TOGGLE(x)  PORTA.OUTTGL = (x)
#define PORT_LOW(x)     PORTA.OUTCLR = (x)
#define PORT_HIGH(x)    PORTA.OUTSET = (x)
#define PORT_OUTPUT(x)  PORTA.DIRSET = (x)

#else
// ATtiny45/85 PORTB positions. Change these for your circuit
const int dc = 4;
const int mosi = 1;
const int sck = 2;
const int cs = 3;

// Classic ATtiny port manipulations - assumes all pins in same port
#define PORT_TOGGLE(x)  PINB = (x)
#define PORT_LOW(x)     PORTB = PORTB & ~((x));
#define PORT_HIGH(x)    PORTB = PORTB | ((x))
#define PORT_OUTPUT(x)  DDRB = DDRB | (x)

#endif

// Display parameters - uncomment the line for the one you want to use

// Adafruit 1.44" 128x128 display
// const int xsize = 128, ysize = 128, xoff = 2, yoff = 1, invert = 0, rotate = 3, bgr = 1;

// AliExpress 1.44" 128x128 display
// const int xsize = 128, ysize = 128, xoff = 2, yoff = 1, invert = 0, rotate = 3, bgr = 1;

// Adafruit 0.96" 160x80 display
// const int xsize = 160, ysize = 80, xoff = 0, yoff = 24, invert = 0, rotate = 6, bgr = 0;

// AliExpress 0.96" 160x80 display
// const int xsize = 160, ysize = 80, xoff = 1, yoff = 26, invert = 1, rotate = 0, bgr = 1;

// Adafruit 1.8" 160x128 display
// const int xsize = 160, ysize = 128, xoff = 0, yoff = 0, invert = 0, rotate = 0, bgr = 1;

// AliExpress 1.8" 160x128 display (red PCB)
// const int xsize = 160, ysize = 128, xoff = 0, yoff = 0, invert = 0, rotate = 0, bgr = 1;

// AliExpress 1.8" 160x128 display (blue PCB)
// const int xsize = 160, ysize = 128, xoff = 0, yoff = 0, invert = 0, rotate = 6, bgr = 0;

// Adafruit 1.14" 240x135 display
// const int xsize = 240, ysize = 135, xoff = 40, yoff = 53, invert = 1, rotate = 6, bgr = 0;

// AliExpress 1.14" 240x135 display
// const int xsize = 240, ysize = 135, xoff = 40, yoff = 52, invert = 1, rotate = 0, bgr = 0;

// Adafruit 1.28" round 240x240 display
// #define GC9A01A
// const int xsize = 240, ysize = 240, xoff = 0, yoff = 0, invert = 1, rotate = 7, bgr = 1;

// AliExpress 1.28" round 240x240 display (octagonal PCB)
// #define GC9A01A
// const int xsize = 240, ysize = 240, xoff = 0, yoff = 0, invert = 1, rotate = 7, bgr = 1;

// AliExpress 1.28" round 240x240 display (round PCB)
// #define GC9A01A
// const int xsize = 240, ysize = 240, xoff = 0, yoff = 0, invert = 1, rotate = 7, bgr = 1;

// Adafruit 1.3" 240x240 display
const int xsize = 240, ysize = 240, xoff = 0, yoff = 80, invert = 1, rotate = 5, bgr = 0;

// Adafruit 1.54" 240x240 display
// const int xsize = 240, ysize = 240, xoff = 0, yoff = 80, invert = 1, rotate = 5, bgr = 0;

// AliExpress 1.54" 240x240 display
// const int xsize = 240, ysize = 240, xoff = 0, yoff = 80, invert = 1, rotate = 5, bgr = 0;

// Adafruit 1.9" 320x170 display
// const int xsize = 320, ysize = 170, xoff = 0, yoff = 35, invert = 1, rotate = 0, bgr = 0;

// AliExpress 1.9" 320x170 display
// const int xsize = 320, ysize = 170, xoff = 0, yoff = 35, invert = 1, rotate = 0, bgr = 0;

// Adafruit 1.47" 320x172 rounded rectangle display
// const int xsize = 320, ysize = 172, xoff = 0, yoff = 34, invert = 1, rotate = 0, bgr = 0;

// AliExpress 1.47" 320x172 rounded rectangle display
// const int xsize = 320, ysize = 172, xoff = 0, yoff = 34, invert = 1, rotate = 0, bgr = 0;

// Adafruit 2.0" 320x240 display
// const int xsize = 320, ysize = 240, xoff = 0, yoff = 0, invert = 1, rotate = 6, bgr = 0;

// AliExpress 2.0" 320x240 display
// const int xsize = 320, ysize = 240, xoff = 0, yoff = 0, invert = 1, rotate = 0, bgr = 0;

// Adafruit 2.2" 320x240 display
// const int xsize = 320, ysize = 240, xoff = 0, yoff = 0, invert = 0, rotate = 4, bgr = 1;

// AliExpress 2.4" 320x240 display
// const int xsize = 320, ysize = 240, xoff = 0, yoff = 0, invert = 0, rotate = 2, bgr = 1;

#define swap(a, b) do { int tmp = (a); (a) = (b); (b) = tmp; } while (0)

// Character set for text - stored in program memory
const uint8_t CharMap[96][6] PROGMEM = {
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, 
{ 0x00, 0x00, 0x5F, 0x00, 0x00, 0x00 }, 
{ 0x00, 0x07, 0x00, 0x07, 0x00, 0x00 }, 
{ 0x14, 0x7F, 0x14, 0x7F, 0x14, 0x00 }, 
{ 0x24, 0x2A, 0x7F, 0x2A, 0x12, 0x00 }, 
{ 0x23, 0x13, 0x08, 0x64, 0x62, 0x00 }, 
{ 0x36, 0x49, 0x56, 0x20, 0x50, 0x00 }, 
{ 0x00, 0x08, 0x07, 0x03, 0x00, 0x00 }, 
{ 0x00, 0x1C, 0x22, 0x41, 0x00, 0x00 }, 
{ 0x00, 0x41, 0x22, 0x1C, 0x00, 0x00 }, 
{ 0x2A, 0x1C, 0x7F, 0x1C, 0x2A, 0x00 }, 
{ 0x08, 0x08, 0x3E, 0x08, 0x08, 0x00 }, 
{ 0x00, 0x80, 0x70, 0x30, 0x00, 0x00 }, 
{ 0x08, 0x08, 0x08, 0x08, 0x08, 0x00 }, 
{ 0x00, 0x00, 0x60, 0x60, 0x00, 0x00 }, 
{ 0x20, 0x10, 0x08, 0x04, 0x02, 0x00 }, 
{ 0x3E, 0x51, 0x49, 0x45, 0x3E, 0x00 }, 
{ 0x00, 0x42, 0x7F, 0x40, 0x00, 0x00 }, 
{ 0x72, 0x49, 0x49, 0x49, 0x46, 0x00 }, 
{ 0x21, 0x41, 0x49, 0x4D, 0x33, 0x00 }, 
{ 0x18, 0x14, 0x12, 0x7F, 0x10, 0x00 }, 
{ 0x27, 0x45, 0x45, 0x45, 0x39, 0x00 }, 
{ 0x3C, 0x4A, 0x49, 0x49, 0x31, 0x00 }, 
{ 0x41, 0x21, 0x11, 0x09, 0x07, 0x00 }, 
{ 0x36, 0x49, 0x49, 0x49, 0x36, 0x00 }, 
{ 0x46, 0x49, 0x49, 0x29, 0x1E, 0x00 }, 
{ 0x00, 0x00, 0x14, 0x00, 0x00, 0x00 }, 
{ 0x00, 0x40, 0x34, 0x00, 0x00, 0x00 }, 
{ 0x00, 0x08, 0x14, 0x22, 0x41, 0x00 }, 
{ 0x14, 0x14, 0x14, 0x14, 0x14, 0x00 }, 
{ 0x00, 0x41, 0x22, 0x14, 0x08, 0x00 }, 
{ 0x02, 0x01, 0x59, 0x09, 0x06, 0x00 }, 
{ 0x3E, 0x41, 0x5D, 0x59, 0x4E, 0x00 }, 
{ 0x7C, 0x12, 0x11, 0x12, 0x7C, 0x00 }, 
{ 0x7F, 0x49, 0x49, 0x49, 0x36, 0x00 }, 
{ 0x3E, 0x41, 0x41, 0x41, 0x22, 0x00 }, 
{ 0x7F, 0x41, 0x41, 0x41, 0x3E, 0x00 }, 
{ 0x7F, 0x49, 0x49, 0x49, 0x41, 0x00 }, 
{ 0x7F, 0x09, 0x09, 0x09, 0x01, 0x00 }, 
{ 0x3E, 0x41, 0x41, 0x51, 0x73, 0x00 }, 
{ 0x7F, 0x08, 0x08, 0x08, 0x7F, 0x00 }, 
{ 0x00, 0x41, 0x7F, 0x41, 0x00, 0x00 }, 
{ 0x20, 0x40, 0x41, 0x3F, 0x01, 0x00 }, 
{ 0x7F, 0x08, 0x14, 0x22, 0x41, 0x00 }, 
{ 0x7F, 0x40, 0x40, 0x40, 0x40, 0x00 }, 
{ 0x7F, 0x02, 0x1C, 0x02, 0x7F, 0x00 }, 
{ 0x7F, 0x04, 0x08, 0x10, 0x7F, 0x00 }, 
{ 0x3E, 0x41, 0x41, 0x41, 0x3E, 0x00 }, 
{ 0x7F, 0x09, 0x09, 0x09, 0x06, 0x00 }, 
{ 0x3E, 0x41, 0x51, 0x21, 0x5E, 0x00 }, 
{ 0x7F, 0x09, 0x19, 0x29, 0x46, 0x00 }, 
{ 0x26, 0x49, 0x49, 0x49, 0x32, 0x00 }, 
{ 0x03, 0x01, 0x7F, 0x01, 0x03, 0x00 }, 
{ 0x3F, 0x40, 0x40, 0x40, 0x3F, 0x00 }, 
{ 0x1F, 0x20, 0x40, 0x20, 0x1F, 0x00 }, 
{ 0x3F, 0x40, 0x38, 0x40, 0x3F, 0x00 }, 
{ 0x63, 0x14, 0x08, 0x14, 0x63, 0x00 }, 
{ 0x03, 0x04, 0x78, 0x04, 0x03, 0x00 }, 
{ 0x61, 0x59, 0x49, 0x4D, 0x43, 0x00 }, 
{ 0x00, 0x7F, 0x41, 0x41, 0x41, 0x00 }, 
{ 0x02, 0x04, 0x08, 0x10, 0x20, 0x00 }, 
{ 0x00, 0x41, 0x41, 0x41, 0x7F, 0x00 }, 
{ 0x04, 0x02, 0x01, 0x02, 0x04, 0x00 }, 
{ 0x40, 0x40, 0x40, 0x40, 0x40, 0x00 }, 
{ 0x00, 0x03, 0x07, 0x08, 0x00, 0x00 }, 
{ 0x20, 0x54, 0x54, 0x78, 0x40, 0x00 }, 
{ 0x7F, 0x28, 0x44, 0x44, 0x38, 0x00 }, 
{ 0x38, 0x44, 0x44, 0x44, 0x28, 0x00 }, 
{ 0x38, 0x44, 0x44, 0x28, 0x7F, 0x00 }, 
{ 0x38, 0x54, 0x54, 0x54, 0x18, 0x00 }, 
{ 0x00, 0x08, 0x7E, 0x09, 0x02, 0x00 }, 
{ 0x18, 0xA4, 0xA4, 0x9C, 0x78, 0x00 }, 
{ 0x7F, 0x08, 0x04, 0x04, 0x78, 0x00 }, 
{ 0x00, 0x44, 0x7D, 0x40, 0x00, 0x00 }, 
{ 0x20, 0x40, 0x40, 0x3D, 0x00, 0x00 }, 
{ 0x7F, 0x10, 0x28, 0x44, 0x00, 0x00 }, 
{ 0x00, 0x41, 0x7F, 0x40, 0x00, 0x00 }, 
{ 0x7C, 0x04, 0x78, 0x04, 0x78, 0x00 }, 
{ 0x7C, 0x08, 0x04, 0x04, 0x78, 0x00 }, 
{ 0x38, 0x44, 0x44, 0x44, 0x38, 0x00 }, 
{ 0xFC, 0x18, 0x24, 0x24, 0x18, 0x00 }, 
{ 0x18, 0x24, 0x24, 0x18, 0xFC, 0x00 }, 
{ 0x7C, 0x08, 0x04, 0x04, 0x08, 0x00 }, 
{ 0x48, 0x54, 0x54, 0x54, 0x24, 0x00 }, 
{ 0x04, 0x04, 0x3F, 0x44, 0x24, 0x00 }, 
{ 0x3C, 0x40, 0x40, 0x20, 0x7C, 0x00 }, 
{ 0x1C, 0x20, 0x40, 0x20, 0x1C, 0x00 }, 
{ 0x3C, 0x40, 0x30, 0x40, 0x3C, 0x00 }, 
{ 0x44, 0x28, 0x10, 0x28, 0x44, 0x00 }, 
{ 0x4C, 0x90, 0x90, 0x90, 0x7C, 0x00 }, 
{ 0x44, 0x64, 0x54, 0x4C, 0x44, 0x00 }, 
{ 0x00, 0x08, 0x36, 0x41, 0x00, 0x00 }, 
{ 0x00, 0x00, 0x77, 0x00, 0x00, 0x00 }, 
{ 0x00, 0x41, 0x36, 0x08, 0x00, 0x00 }, 
{ 0x00, 0x06, 0x09, 0x06, 0x00, 0x00 },  // degree symbol = '~'
{ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00 }
};

// TFT colour display **********************************************

const int CASET = 0x2A; // Define column address
const int RASET = 0x2B; // Define row address
const int RAMWR = 0x2C; // Write to display RAM

const int White = 0xFFFF;
const int Black = 0;

// Current plot position and colours
int xpos = 0, ypos = 0;
int fore = White;
int back = Black;
int scale = 1;     // Text scale

// Send a byte to the display
void Data (uint8_t d) {
  for (uint8_t bit = 0x80; bit; bit >>= 1) {
    PORT_TOGGLE(1<<sck);
    if (d & bit) PORT_HIGH(1<<mosi); else PORT_LOW(1<<mosi);
    PORT_TOGGLE(1<<sck);
  }
}

// Send a command to the display
void Command (uint8_t c) {
  PORT_TOGGLE(1<<dc);
  Data(c);
  PORT_TOGGLE(1<<dc);
}

// Send a command followed by two data words
void Command2 (uint8_t c, uint16_t d1, uint16_t d2) {
  PORT_TOGGLE(1<<dc);
  Data(c);
  PORT_TOGGLE(1<<dc);
  Data(d1>>8); Data(d1); Data(d2>>8); Data(d2);
}

// Send a command followed by 0xff terminated data bytes
void CommandN (uint8_t c, uint8_t *data) {
  Command(c);
  do {
    Data(*(data++));
  } while (*data != 0xff);
}

uint8_t ColMap1[] = { 0x3C, 0x00, 0xCD, 0x67, 0x45, 0x45, 0x10, 0x00, 0x00, 0x00, 0xff };
uint8_t ColMap2[] = { 0x00, 0x3C, 0x00, 0x00, 0x00, 0x01, 0x54, 0x10, 0x32, 0x98, 0xff };

void InitDisplay () {
  PORT_OUTPUT(1<<dc | 1<<cs | 1<<mosi | 1<<sck); // All outputs
  PORT_HIGH(1<<dc | 1<<cs | 1<<sck);       // Outputs high
  PORT_TOGGLE(1<<cs);
  Command(0x01);                           // Software reset
  PORT_TOGGLE(1<<cs);
  delay(250);                              // delay 250 ms
  PORT_TOGGLE(1<<cs);
  #if defined(GC9A01A)
  Command(0xFE);                           // INREGEN1
  Command(0xEF);                           // INREGEN2
  Command(0xC3); Data(0x13);               // Power control 2
  Command(0xC4); Data(0x13);               // Power control 3
  Command(0xC9); Data(0x22);               // Power control 4
  CommandN(0x66, ColMap1);
  CommandN(0x67, ColMap2);
  #endif
  Command(0x36); Data(rotate<<5 | bgr<<3); // Set orientation and rgb/bgr
  Command(0x3A); Data(0x55);               // Set color mode - 16-bit color
  Command(0x20+invert);                    // Invert
  Command(0x11);                           // Out of sleep mode
  delay(150);
  PORT_TOGGLE(1<<cs);
}

void DisplayOn () {
  PORT_TOGGLE(1<<cs);
  Command(0x29);                           // Display on
  delay(150);
  PORT_TOGGLE(1<<cs);
}

void ClearDisplay () {
  PORT_TOGGLE(1<<cs);
  Command2(CASET, yoff, yoff + ysize - 1);
  Command2(RASET, xoff, xoff + xsize - 1);
  Command(0x3A); Data(0x03);               // 12-bit colour
  Command(RAMWR);                          // Leaves mosi low
  for (int i=0; i<xsize*4; i++) {
    for (int j=0; j<ysize*3; j++) {
    PORT_TOGGLE(1<<sck);
    PORT_TOGGLE(1<<sck);
    }
  }
  Command(0x3A); Data(0x05);               // Back to 16-bit colour
  PORT_TOGGLE(1<<cs);
}

unsigned int Colour (int r, int g, int b) {
  return (r & 0xf8)<<8 | (g & 0xfc)<<3 | b>>3;
}

// Move current plot position to x,y
void MoveTo (int x, int y) {
  xpos = x; ypos = y;
}

void MoveBy (int x, int y) { MoveTo(xpos+x, ypos+y); }

// Plot point at x,y
void PlotPoint (int x, int y) {
  PORT_TOGGLE(1<<cs);
  Command2(CASET, yoff+y, yoff+y);
  Command2(RASET, xoff+x, xoff+x);
  Command(RAMWR); Data(fore>>8); Data(fore & 0xff);
  PORT_TOGGLE(1<<cs);
}

// Draw a line to x,y
void DrawTo (int x, int y) {
  int sx, sy, e2, err;
  int dx = abs(x - xpos);
  int dy = abs(y - ypos);
  if (xpos < x) sx = 1; else sx = -1;
  if (ypos < y) sy = 1; else sy = -1;
  err = dx - dy;
  for (;;) {
    PlotPoint(xpos, ypos);
    if (xpos==x && ypos==y) return;
    e2 = err<<1;
    if (e2 > -dy) { err = err - dy; xpos = xpos + sx; }
    if (e2 < dx) { err = err + dx; ypos = ypos + sy; }
  }
}

void DrawBy (int x, int y) { DrawTo(xpos+x, ypos+y); }

void DrawRect (int w, int h) {
  int x0 = xpos, y0 = ypos;
  FillRect(w-1, 1); MoveTo(x0, y0+1);
  FillRect(1, h-1); MoveTo(x0+1, y0+h-1);
  FillRect(w-1, 1); MoveTo(x0+w-1, y0);
  FillRect(1, h-1);
  xpos = x0; ypos = y0;
}

void FillRect (int w, int h) {
  PORT_TOGGLE(1<<cs);
  Command2(CASET, ypos+yoff, ypos+yoff+h-1);
  Command2(RASET, xpos+xoff, xpos+xoff+w-1);
  Command(RAMWR);
  uint8_t hi = fore>>8, lo = fore & 0xff;
  for (int i=0; i<w; i++) {
    for (int j=0; j<h; j++) {
      Data(hi); Data(lo);
    }
  }
  PORT_TOGGLE(1<<cs);
}

void DrawCircle(int radius) {
  int x0 = xpos, y0 = ypos;
  int x = radius, y = 0;
  int err = 1 - x;
  while (x >= y) {
    PlotPoint(x0-x, y0+y); PlotPoint(x0+x, y0+y);
    PlotPoint(x0-y, y0+x); PlotPoint(x0+y, y0+x);
    PlotPoint(x0-y, y0-x); PlotPoint(x0+y, y0-x);
    PlotPoint(x0-x, y0-y); PlotPoint(x0+x, y0-y);
    y++;
    if (err < 0) {
      err = err + 2*y + 1;
    } else {
      x--;
      err = err + 2*(y - x) + 1;
    }
  }
}

void FillCircle (int radius) {
  int x0 = xpos, y0 = ypos;
  int x = radius, y = 0;
  int err = 1 - x;
  while (x >= y) {
    MoveTo(x0-x, y0+y); FillRect(x<<1, 1);
    MoveTo(x0-y, y0+x); FillRect(y<<1, 1);
    MoveTo(x0-y, y0-x); FillRect(y<<1, 1);
    MoveTo(x0-x, y0-y); FillRect(x<<1, 1);
    y++;
    if (err < 0) {
      err = err + 2*y + 1;
    } else {
      x--;
      err = err + 2*(y - x) + 1;
    }
  }
  xpos = x0; ypos = y0;
}

void DrawTriangle (uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2) {
  int x0 = xpos, y0 = ypos;
  DrawTo(x1, y1); DrawTo(x2, y2); DrawTo(x0, y0);
}

void DrawTriangleBy (int x1, int y1, int x2, int y2) {
  DrawTriangle(xpos+x1, ypos+y1, xpos+x1+x2, ypos+y1+y2);
}

void FillTriangle (int16_t x1, int16_t y1, int16_t x2, int16_t y2) {
  int x0 = xpos, y0 = ypos, xpos0 = xpos, ypos0 = ypos;
  // Sort coordinates by y order (y2 >= y1 >= y0)
  if (y0 > y1) { swap(y0, y1); swap(x0, x1); }
  if (y1 > y2) { swap(y1, y2); swap(x1, x2); }
  if (y0 > y1) { swap(y0, y1); swap(x0, x1); }
  TriangleQuad(x0, y0, x1, y1, x2, y2, x2, y2);
  xpos = xpos0; ypos = ypos0;
}

void FillTriangleBy (int x1, int y1, int x2, int y2) {
  FillTriangle(xpos+x1, ypos+y1, xpos+x1+x2, ypos+y1+y2);
}

void DrawQuad (uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t x3, uint16_t y3) {
  int x0 = xpos, y0 = ypos;
  DrawTo(x1, y1); DrawTo(x2, y2); DrawTo(x3, y3); DrawTo(x0, y0);
}

void DrawQuadBy (int x1, int y1, int x2, int y2, int x3, int y3) {
  DrawQuad (xpos+x1, ypos+y1, xpos+x1+x2, ypos+y1+y2, xpos+x1+x2+x3, ypos+y1+y2+y3);
}

void FillQuad (int16_t x1, int16_t y1, int16_t x2, int16_t y2, int16_t x3, int16_t y3) {
  int x0 = xpos, y0 = ypos, xpos0 = xpos, ypos0 = ypos;
  // Sort coordinates by y order (y3 >= y2 >= y1 >= y0)
  if (y0 > y1) { swap(y0, y1); swap(x0, x1); }
  if (y2 > y3) { swap(y2, y3); swap(x2, x3); }
  if (y1 > y3) { swap(y1, y3); swap(x1, x3); }
  if (y0 > y2) { swap(y0, y2); swap(x0, x2); }
  if (y1 > y2) { swap(y1, y2); swap(x1, x2); }
  TriangleQuad(x0, y0, x1, y1, x2, y2, x3, y3);
  xpos = xpos0; ypos = ypos0;
}

void FillQuadBy (int x1, int y1, int x2, int y2, int x3, int y3) {
  FillQuad (xpos+x1, ypos+y1, xpos+x1+x2, ypos+y1+y2, xpos+x1+x2+x3, ypos+y1+y2+y3);
}

void TriangleQuad (int16_t x0, int16_t y0, int16_t x1, int16_t y1,
                  int16_t x2, int16_t y2, int16_t x3, int16_t y3) {
  // Coordinates already in y order (y3 >= y2 >= y1 >= y0)
  int16_t a, b, y;

  // Special case?
  int16_t x4 = x0 + (x3 - x0) * (y1 - y0) / (y3 - y0);
  int16_t x5 = x0 + (x3 - x0) * (y2 - y0) / (y3 - y0);

  if ((x5 > x2) == (x4 > x1)) {
    swap(x2, x5);
  } else { // Kite
    x4 = x0 + (x2 - x0) * (y1 - y0) / (y2 - y0);
    x5 = x1 + (x3 - x1) * (y2 - y1) / (y3 - y1);
  }
  
  // Fill bottom section
  for (y = y0; y <= y1; y++) {
    a = x0 + (x4 - x0) * (y - y0) / (y1 - y0);
    b = x0 + (x1 - x0) * (y - y0) / (y1 - y0);
    if (a > b) swap(a, b);
    // MoveTo(a, y); DrawTo(b, y);
    MoveTo(a, y); FillRect(b - a + 1, 1);
  }

  // Fill middle section
  for (; y <= y2; y++) {
    a = x4 + (x2 - x4) * (y - y1) / (y2 - y1);
    b = x1 + (x5 - x1) * (y - y1) / (y2 - y1);
    if (a > b) swap(a, b);
    // MoveTo(a, y); DrawTo(b, y);
    MoveTo(a, y); FillRect(b - a + 1, 1);
  }

  // Fill top section
  for (; y <= y3; y++) {
    a = x2 + (x3 - x2) * (y - y2) / (y3 - y2);
    b = x5 + (x3 - x5) * (y - y2) / (y3 - y2);
    if (a > b) swap(a, b);
    // MoveTo(a, y); DrawTo(b, y);
    MoveTo(a, y); FillRect(b - a + 1, 1);
  }
}

// Plot an ASCII character with bottom left corner at x,y
void PlotChar (char c) {
  int colour;
  PORT_TOGGLE(1<<cs);
  Command2(CASET, yoff+ypos, yoff+ypos+8*scale-1);
  Command2(RASET, xoff+xpos, xoff+xpos+6*scale-1);
  Command(RAMWR);
  for (int xx=0; xx<6; xx++) {
    int bits = pgm_read_byte(&CharMap[c-32][xx]);
    for (int xr=0; xr<scale; xr++) {
      for (int yy=0; yy<8; yy++) {
        if (bits>>(7-yy) & 1) colour = fore; else colour = back;
        for (int yr=0; yr<scale; yr++) {
          Data(colour>>8); Data(colour & 0xFF);
        }
      }
    }
  }
  PORT_TOGGLE(1<<cs);
  xpos = xpos + 6*scale;
}

// Plot text from a char array starting at the current plot position
void PlotChars (char *s) {
 while (*s) PlotChar(*s++);
}

// Plot text starting at the current plot position
void PlotText (PGM_P p) {
  while (1) {
    char c = pgm_read_byte(p++);
    if (c == 0) return;
    PlotChar(c);
  }
}

void PlotInt (int n) {
  bool lead = false;
  if (n < 0) { PlotChar('-'); n = - n; }
  for (int d=10000; d>0; d = d/10) {
    char j = (n/d) % 10;
    if (j!=0 || lead || d==1) { PlotChar(j + '0'); lead = true; }
  }
}

void TestChart () {
  #if defined(GC9A01A)
  MoveTo(xsize/2, ysize/2); DrawCircle(xsize/2-1);
  #else
  DrawRect(xsize, ysize);
  #endif
  scale = 8;
  fore = Colour(255, 0, 0);
  MoveTo((xsize-40)/2, (ysize-64)/2); PlotChar('F');
  scale = 1;
}

// Demos **********************************************

// Barchart **********************************************

void BarChart () {
  int x0 = 0, y0 = 0, w = xsize, h = ysize, x1 = 15, y1 = 11;
  MoveTo(x0+(w-x1-90)/2+x1, y0+h-8); PlotText(PSTR("Sensor Readings"));
  // Horizontal axis
  int xinc = (w-x1)/20;
  MoveTo(x0+x1, y0+y1); DrawTo(x0+w-1, y0+y1);
  for (int i=0; i<=20; i=i+4) {
    int mark = x1+i*xinc;
    MoveTo(x0+mark, y0+y1); DrawTo(x0+mark, y0+y1-2);
    // Draw histogram
    if (i != 20) {
      int bar = xinc*4/3;
      for (int b=2; b>=0; b--) {
        fore = Colour(255, 127*b, 0); // Red, Orange, Yellow 
        MoveTo(x0+mark+bar*b-b+1, y0+y1+1); FillRect(bar, 5+random(h-y1-20));
      }
      fore = White;
    }
    if (i > 9) MoveTo(x0+mark-7, y0+y1-11); else MoveTo(x0+mark-3, y0+y1-11);
    PlotInt(i);
  }
  // Vertical axis
  int yinc = (h-y1)/20;
  MoveTo(x0+x1, y0+y1); DrawTo(x0+x1, y0+h-1);
  for (int i=0; i<=20; i=i+5) {
    int mark = y1+i*yinc;
    MoveTo(x0+x1, y0+mark); DrawTo(x0+x1-2, y0+mark);
    if (i > 9) MoveTo(x0+x1-15, y0+mark-4); else MoveTo(x0+x1-9, y0+mark-4);
    PlotInt(i);
  }
}

// Waterfall plot **********************************************

void Waterfall () {
  int x0 = 0, y0 = 0, w = xsize, h = ysize, x1 = 15, y1 = 11;
  int factor = 5440/h*10;
  MoveTo(x0+(w-x1-60)/2+x1, y0+h-8); PlotText(PSTR("Luminance"));
  // Horizontal axis
  int xinc = (w-x1-15)/30;
  MoveTo(x0+x1, y0+y1); DrawTo(x0+x1+xinc*20, y0+y1);
  for (int i=0; i<=20; i=i+5) {
    int mark = x1+i*xinc;
    MoveTo(x0+mark, y0+y1); DrawTo(x0+mark, y0+y1-2);
    if (i > 9) MoveTo(x0+mark-7, y0+y1-11); else MoveTo(x0+mark-3, y0+y1-11);
    PlotInt(i);
  }
  // Vertical axis
  int yinc = (h-y1)/20;
  MoveTo(x0+x1, y0+y1); DrawTo(x0+x1, y0+h-1);
  for (int i=0; i<=20; i=i+5) {
    int mark = y1+i*yinc;
    MoveTo(x0+x1, y0+mark); DrawTo(x0+x1-2, y0+mark);
    if (i > 9) MoveTo(x0+x1-15, y0+mark-4); else MoveTo(x0+x1-9, y0+mark-4);
    PlotInt(i);
  }
  // Diagonal axis
  yinc = xinc/2;
  // MoveTo(x0+x1, y0+y1); DrawTo(x0+x1+10*xinc, y0+y1+10*xinc);
  MoveTo(x0+x1+20*xinc, y0+y1); DrawTo(x0+x1+30*xinc, y0+y1+10*xinc);
  for (int i=0; i<=20; i=i+5) {
    MoveTo(x0+x1+20*xinc+i*xinc/2, y0+y1+i*xinc/2);
    DrawTo(x0+x1+20*xinc+i*xinc/2+3, y0+y1+i*xinc/2);
    MoveTo(x0+x1+20*xinc+i*xinc/2+6, y0+y1+i*xinc/2-4); PlotInt(i);
  }
  // Plot data
  for (int y=20; y>=0; y--) {
    for (int i=0; i<=20; i++) {
      int fn0 = 180-(i-10)*(i-10)-(y-10)*(y-10);
      int fn1 = 180-(i+1-10)*(i+1-10)-(y-10)*(y-10);
      fore = Colour(255, 255, 0);
      MoveTo(x0+x1+y*yinc+i*xinc, y0+y1+y*yinc+fn0*fn0/factor);
      DrawTo(x0+x1+y*yinc+(i+1)*xinc, y0+y1+y*yinc+fn1*fn1/factor);
      fore = White;
    }
  }
}

// Sampler for 240x240 display **********************************************

void PlotTextCentred (PGM_P text) {
  int len = strlen_P(text);
  xpos = xpos-len*6/2;
  PlotText(text);
}

void Sampler () {
  int c = 120;
  fore = Colour(255, 255, 0);
  MoveTo(c-108, c-54); DrawRect(216, 108);
  MoveTo(c-54, c-108); DrawRect(108, 216);
  MoveTo(c-108, c); DrawBy(215, 0);
  MoveTo(c, c-108); DrawBy(0, 215);
  fore = White;
  MoveTo(c-27, c+97); PlotTextCentred(PSTR("Points"));
  MoveTo(c+27, c+97); PlotTextCentred(PSTR("Line"));
  PGM_P p[4] = { PSTR("Circle"), PSTR("Rect"), PSTR("Triangle"), PSTR("Quad") };
  for (int i=0; i<4; i++) {
    MoveTo(c-81+i*54, c+43); PlotTextCentred(p[i]);
    MoveTo(c-81+i*54, c-11); PlotTextCentred(p[i]);
  }
  MoveTo(c-27, c-65); PlotTextCentred(PSTR("Char"));
  MoveTo(c+27, c-65); PlotTextCentred(PSTR("Integer"));
  int j=0; for (int i=c-40; i<c-14; i++) { PlotPoint(i, c+77+j); j=j+random(5)-2; }
  MoveTo(c+7, c+61); DrawBy(33, 33); 
  MoveTo(c-81, c+23); DrawCircle(15);
  MoveTo(c-40, c+10); DrawRect(27, 27);
  MoveTo(c+10, c+10); DrawTriangleBy(17, 30, 17, -17);
  MoveTo(c+64, c+22);
  DrawQuadBy(16, 16, 16, -16, -16, -16);
  fore = Colour(255, 64, 64); MoveTo(c-81, c-31); FillCircle(15);
  fore = Colour(255, 0, 255); MoveTo(c-40, c-44); FillRect(27, 27);
  fore = Colour(0, 128, 255);
  MoveTo(c+10, c-44); FillTriangleBy(17, 30, 17, -17);
  fore = Colour(255, 128, 0); MoveTo(c+64, c-32);
  FillQuadBy(16, 16, 16, -16, -16, -16);
  fore = Colour(255, 0, 0); MoveTo(c-34, c-100); scale=3; PlotChar('Q'); scale = 1;
  fore = Colour(0, 255, 0); MoveTo(c+8, c-94); scale=2; PlotInt(765); scale=1;
}

// Setup **********************************************

void setup() {
  InitDisplay();
  ClearDisplay();
  DisplayOn();
}

void loop () {
  BarChart();
  for (;;);
}
