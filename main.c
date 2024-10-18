/*
 * File:   main.c
 * Author: Wels
 *
 * Created on 16 de diciembre de 2023, 11:52 PM
 */
#include "main.h"
#include "I2C.h"
#include "SSD1306.h"
#include "Text_Font.h"

void test_1( ssd1306_t * SSD1306 );

void test_2( ssd1306_t * SSD1306 );

void test_3( ssd1306_t * SSD1306 );

void test_4( ssd1306_t * SSD1306 );

int main(void) 
{
    //I2C_Init();
    /* SSD1306 */
    ssd1306_t SSD1306;
    SSD1306.address = SSD1306_ADDR;
    SSD1306.width= SSD1306_WIDTH ;
    SSD1306.height = SSD1306_HEIGHT;
    SSD1306.color = SSD1306_WHITE;
    SSD1306.contrast = 0xCF;
    SSD1306.left = SSD1306_LEFT;
    SSD1306.right = SSD1306_RIGHT;
    SSD1306.center = SSD1306_CENTER;
    SSD1306_I2C_Init (&SSD1306);
    __delay_ms(100);
    SSD1306_I2C_ClearDisplay(&SSD1306);
    SSD1306_I2C_Update(&SSD1306);
    __delay_ms(1000);
    SSD1306_I2C_DrawPixel(&SSD1306, 20, 50);
    SSD1306_I2C_Update(&SSD1306);
    __delay_ms(300);
    SSD1306_I2C_ClearDisplay(&SSD1306);
    /* TEST 1 */
    test_1(&SSD1306);
    SSD1306_I2C_Update(&SSD1306);
    __delay_ms(1000);
    SSD1306_I2C_ClearDisplay(&SSD1306);
    __delay_ms(100);
    /* TEST 2 */
    test_2(&SSD1306);
    SSD1306_I2C_Update(&SSD1306);
    __delay_ms(1000);
    SSD1306_I2C_ClearDisplay(&SSD1306);
    /* TEST 3 */
    test_3(&SSD1306);
    SSD1306_I2C_Update(&SSD1306);
    __delay_ms(1000);
    SSD1306_I2C_ClearDisplay(&SSD1306);
    /* TEST 4 */
    test_4(&SSD1306);
    SSD1306_I2C_Update(&SSD1306);
    __delay_ms(1000);
    SSD1306_I2C_ClearDisplay(&SSD1306);
    /* FONT */
    SSD1306_I2C_SetFont( &SSD1306, SMALL_FONTS );
    SSD1306_I2C_Cadena( &SSD1306,0,0,"asdasdasd");
    SSD1306_I2C_Cadena( &SSD1306,0,8,"VWXYZ0123456789~!@#$%");
    SSD1306_I2C_Update(&SSD1306);
    __delay_ms(2000);
    SSD1306_I2C_Cadena( &SSD1306,0,16,"abcdefghijklmnopqrstu");
    SSD1306_I2C_Cadena( &SSD1306,0,24,"vwxyz");
    SSD1306_I2C_Update( &SSD1306);
    SSD1306_I2C_ClearDisplay(&SSD1306);
    __delay_ms(3000);

    SSD1306_I2C_SetFont( &SSD1306, BIG_FONTS);
    SSD1306_I2C_Cadena( &SSD1306,0,0,"ABCDEFGH");
    SSD1306_I2C_Cadena( &SSD1306, 0,16,"abcdefgh");
    SSD1306_I2C_Cadena( &SSD1306,0,32,"0123456789");
    SSD1306_I2C_Update( &SSD1306);
    __delay_ms(2000);
    while(1)
    {
        LED_Curiosity = ~LED_Curiosity;
        __delay_ms(100);
    }
    return 0;
}

void test_1( ssd1306_t * SSD1306 )
{
  uint8_t i = 0;
  for ( i=0; i<SSD1306->width; i+=4)
  {
    SSD1306_I2C_Linea(SSD1306, 0, 0, i, SSD1306->height-1);
    SSD1306_I2C_Update(SSD1306);
  }
  for ( i=0; i<SSD1306->height; i+=4 )
  {
    SSD1306_I2C_Linea(SSD1306, 0, 0, SSD1306->width-1, i);
    SSD1306_I2C_Update(SSD1306);
  }
}

void test_2( ssd1306_t * SSD1306 )
{
  uint8_t i;
  // Horizontal lines test
  for( i=0; i< SSD1306->height; i+=4 )
  {
   SSD1306_I2C_LineaHorizontal(SSD1306, 0, SSD1306->width-1, i);
   SSD1306_I2C_Update(SSD1306);
  }
  __delay_ms(1000);
  SSD1306_I2C_ClearDisplay(SSD1306);
  SSD1306_I2C_Update(SSD1306);
  // Vertical lines test
  for( i=0; i< SSD1306->width; i+=4 )
  {
    SSD1306_I2C_LineaVertical(SSD1306, 0, SSD1306->height-1, i);
    SSD1306_I2C_Update(SSD1306);
  }
}

void test_3( ssd1306_t * SSD1306 )
{
  uint8_t i;
  for ( i=0; i<SSD1306->height/2; i+=2)
  {
    SSD1306_I2C_Rectangulo(SSD1306, i, i, SSD1306->width-1-i, SSD1306->height-1-i);
    SSD1306_I2C_Update(SSD1306);
    __delay_ms(250);
  }
  __delay_ms(1000);
  SSD1306_I2C_ClearDisplay(SSD1306);
  SSD1306_I2C_Update(SSD1306);
  for( i=SSD1306->height/2; i>0; i-- )
  {
    SSD1306_I2C_Rectangulo(SSD1306, i,i, SSD1306->width-i, SSD1306->height-i);
  }
}

void test_4( ssd1306_t * SSD1306 )
{
  uint8_t i;
  for( i=0; i<SSD1306->width/2; i+=5 )
  {
    SSD1306_I2C_Circulo(SSD1306,SSD1306->width/2, SSD1306->height/2, i );
    SSD1306_I2C_Update(SSD1306);
  }
}