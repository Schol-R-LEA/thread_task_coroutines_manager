#ifndef glcd_spi_h
#define glcd_spi_h
// pins configurations
#define CS_PIN						10
#define MOSI_PIN					11
#define CLK_PIN						13
// glcd main defs
#define CMD_MSK						0xF8
#define DATA_MSK					0xFA
// glcd basic instruction set
#define DISPLAY_CLEAR				0x01
#define RETURN_HOME					0x02
#define ENTERY_MODE					0x06	// CURSOR_MOVE_RIGHT=1, DIS_SHIFT_R/L=0
#define DISPLAY_CONTROL				0x0C	// DIS=ON, CURSOR=OFF, BLINK=OFF
#define DIS_CURSOR_CTL				0x14	// cur mov right, no dis shift
#define FUNCTION_SET_BASIC			0x30	// 8-bit, basic instruction set
#define CHAR_GEN_ADDRESS			0x40	// ORed w A5-A0 6bit add 0x00 - 0x3f
//#define DATA_RAM					0x80	// ORed w A5-A0, A6=0, 6bit add
// glcd extended instruction set
#define FUNCTION_SET_EXTENDED		0x34	// 8-bit, extended instruction set
#define GRAPHICS_ON1				0x32	// graphics on
#define GRAPHICS_ON2				0x36	// graphics on
#define GRAPHICS_OFF1				0x34	// graphics off
#define GRAPHICS_OFF2				0x30	// graphics off
#define STANDBY_MODE				0x01	// put glcd in standby mode
#define DISABLE_V_SCROLL			0x02	// disable vertical scroll => CGRAM
#define ENABLE_V_SCROLL				0x03	// enable vertical scroll

//LCD_INIT,LCD_MODES,LCD_CMDT
//////////////////////////////////////////////////////////////////////////////////
typedef enum  {START, CS_HI,	INIT_CMD}LCD_INIT;
typedef enum  {CONTROL, PIXEL_WRITE, CHARS_WRITE, IMG_DRW,
CLEAR_DISPLAY, CIRCLE_DRW, LINE_DRW, RECTANGLE_DRW}LCD_MODES;
typedef enum  {IDLE, CMD, DATA}LCD_CMDT;

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////


// basic/control functions
void glcd_init(void);
void glcd_cmd(uint8_t cmd);
void glcd_data(uint8_t data);
void glcd_manager(void);
void glcd_delay_routine(void);
void glcd_graphics_mode(bool mode);
void glcd_move_cursor(uint8_t row, uint8_t col);
void glcd_clr(void);
// draw functions
void glcd_img(const uint8_t *img);
void glcd_pixel_set(uint8_t x_axis, uint8_t y_axis);
void glcd_pixel_clear(uint8_t x_axis, uint8_t y_axis);
void glcd_line(uint8_t y0, uint8_t y1, uint8_t x0, uint8_t x1);
void glcd_circle(uint8_t y, uint8_t x, uint8_t r);
// online functions
void circle(int xc, int yc, int radius);
void midPointCircleDraw(int y, int x, int r);
void circleBres(int xc, int yc, int r);
void drawCircle(int xc, int yc, int x, int y);
// development
void circle_sketch(uint8_t x0, uint8_t y0, uint8_t radius);

#endif

