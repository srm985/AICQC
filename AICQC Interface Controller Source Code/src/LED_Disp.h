#ifndef LED_Disp_h_
#define LED_Disp_h_

#define Digit_Locations			0x03

#define zero			0xC0
#define one				0xF9
#define two				0xA4
#define three			0xB0
#define four			0x99
#define five			0x92
#define six				0x82
#define seven			0xF8
#define eight			0x80
#define nine			0x98
#define dash			0xBF
#define digit_one		0x01
#define digit_two		0x02
#define digit_three		0x03

void LED_init(void);
void LED_Write(uint8_t letter, uint8_t digit);
void LED_Clear(void);

#endif