#include <string.h>

// original based on http://playground.arduino.cc/LEDMatrix/Max7219

// pins
int dataIn = 2;
int load = 3;
int clock = 4;

int letter_display_time = 500;

class Character
{
  String _char_name;
  unsigned char _col_1;
  unsigned char _col_2;
  unsigned char _col_3;
  unsigned char _col_4;
  unsigned char _col_5;
  unsigned char _col_6;
  unsigned char _col_7;
  unsigned char _col_8;
public:
  Character(String char_name, unsigned char col_1, unsigned char col_2, unsigned char col_3, unsigned char col_4, unsigned char col_5, unsigned char col_6, unsigned char col_7, unsigned char col_8)
  {
    _char_name = char_name;
    _col_1 = col_1;
    _col_2 = col_2;
    _col_3 = col_3;
    _col_4 = col_4;
    _col_5 = col_5;
    _col_6 = col_6;
    _col_7 = col_7;
    _col_8 = col_8;
  }
  String get_name()
  {
    return _char_name;
  }
  unsigned char get_col(unsigned char col)
  {
    switch(col)
    {
      case 1:
        return _col_1;
      case 2:
        return _col_2;
      case 3:
        return _col_3;
      case 4:
        return _col_4;
      case 5:
        return _col_5;
      case 6:
        return _col_6;
      case 7:
        return _col_7;
      case 8:
        return _col_8;
    }
  }
};

Character characters[87] = {
  Character("poop", 192, 176, 204, 170, 164, 152, 176, 192),
  Character("heart", 6, 25, 33, 194, 194, 33, 25, 6),
  Character("beer", 254, 132, 138, 132, 138, 254, 72, 48),
  Character("wine", 0, 12, 148, 228, 148, 12, 0, 0),
  Character("cocktail", 0, 12, 148, 228, 150, 13, 0, 0),
  Character("coffee", 124, 134, 133, 134, 133, 124, 72, 48),
  Character("tea", 188, 196, 198, 197, 196, 188, 36, 28),
  Character("eye_open", 24, 36, 66, 90, 90, 66, 36, 24),
  Character("eye_half_open", 24, 44, 78, 94, 94, 78, 44, 24),
  Character("eye_closed", 24, 60, 126, 126, 126, 126, 60, 24),

  Character(" ", 0, 0, 0, 0, 0, 0, 0, 0),

  Character("A", 0, 224, 28, 27, 27, 28, 224, 0),
  Character("B", 0, 255, 153, 153, 153, 158, 96, 0),
  Character("C", 0, 60, 66, 129, 129, 129, 66, 0),
  Character("D", 0, 255, 129, 129, 129, 66, 60, 0),
  Character("E", 0, 255, 153, 153, 153, 129, 129, 0),
  Character("F", 0, 255, 25, 25, 25, 1, 1, 0),
  Character("G", 0, 60, 66, 129, 145, 145, 114, 0),
  Character("H", 0, 255, 24, 24, 24, 24, 255, 0),
  Character("I", 0, 129, 129, 255, 129, 129, 0, 0),
  Character("J", 0, 96, 129, 129, 127, 1, 1, 0),
  Character("K", 0, 255, 24, 36, 66, 128, 0, 0),
  Character("L", 0, 0, 255, 128, 128, 128, 128, 0),
  Character("M", 255, 2, 4, 24, 24, 4, 2, 255),
  Character("N", 0, 255, 4, 8, 16, 32, 255, 0),
  Character("O", 0, 126, 129, 129, 129, 129, 126, 0),
  Character("P", 0, 255, 17, 17, 17, 14, 0, 0),
  Character("Q", 0, 126, 129, 129, 161, 193, 254, 128),
  Character("R", 0, 255, 17, 17, 17, 110, 128, 0),
  Character("S", 0, 134, 137, 137, 137, 113, 0, 0),
  Character("T", 0, 1, 1, 255, 255, 1, 1, 0),
  Character("U", 0, 127, 128, 128, 128, 128, 127, 0),
  Character("V", 3, 12, 48, 192, 192, 48, 12, 3),
  Character("W", 7,56, 192, 48, 48, 192, 56, 7),
  Character("X", 129, 66, 36, 24, 24, 36, 66, 129),
  Character("Y", 1, 2, 4, 248, 4, 2, 1, 0),
  Character("Z", 129, 193, 161, 145, 137, 133, 131, 129),

  Character("a", 0, 24, 36, 36, 20, 60, 0, 0),
  Character("b", 0, 63, 36, 36, 36, 24, 0, 0),
  Character("c", 0, 24, 36, 36, 36, 36, 0, 0),
  Character("d", 0, 24, 36, 36, 36, 63, 0, 0),
  Character("e", 0, 24, 52, 52, 44, 40, 0, 0),
  Character("f", 0, 16, 255, 17, 1, 2, 0, 0),
  Character("g", 0, 24, 164, 164, 164, 124, 0, 0),
  Character("h", 0, 63, 4, 4, 4, 56, 0, 0),
  Character("i", 0, 0, 36, 61, 32, 0, 0, 0),
  Character("j", 0, 0, 128, 132, 125, 0, 0, 0),
  Character("k", 0, 63, 16, 24, 36, 36, 0, 0),
  Character("l", 0, 0, 1, 63, 32, 32, 0, 0),
  Character("m", 0, 60, 4, 60, 4, 56, 0, 0),
  Character("n", 0, 60, 4, 4, 4, 56, 0, 0),
  Character("o", 0, 24, 36, 36, 36, 24, 0, 0),
  Character("p", 0, 252, 36, 36, 36, 24, 0, 0),
  Character("q", 0, 24, 36, 36, 36, 252, 0, 0),
  Character("r", 0, 60, 8, 4, 4, 4, 0, 0),
  Character("s", 0, 40, 44, 44, 44, 20, 0, 0),
  Character("t", 0, 4, 31, 36, 36, 16, 0, 0),
  Character("u", 0, 28, 32, 32, 32, 60, 0, 0),
  Character("v", 0, 12, 16, 32, 16, 12, 0, 0),
  Character("w", 0, 60, 32, 24, 32, 60, 0, 0),
  Character("x", 0, 36, 20, 24, 40, 36, 0, 0),
  Character("y", 0, 28, 160, 160, 160, 124, 0, 0),
  Character("z", 0, 36, 52, 44, 44, 36, 0, 0),

  Character("0", 0, 60, 66, 90, 66, 60, 0, 0),
  Character("1", 0, 0, 68, 126, 64, 0, 0, 0),
  Character("2", 0, 100, 82, 82, 82, 76, 0, 0),
  Character("3", 0, 34, 66, 74, 74, 54, 0, 0),
  Character("4", 0, 16, 24, 20, 126, 16, 0, 0),
  Character("5", 0, 38, 74, 74, 74, 50, 0, 0),
  Character("6", 0, 48, 76, 74, 74, 48, 0, 0),
  Character("7", 0, 6, 2, 114, 10, 6, 0, 0),
  Character("8", 0, 52, 74, 74, 74, 52, 0, 0),
  Character("9", 0, 12, 82, 82, 82, 60, 0, 0),

  Character("\xc2", 0, 72, 62, 73, 66, 32, 0, 0),  // £
  Character("$", 0, 4, 42, 127, 42, 16, 0, 0),
  Character("%", 0, 38, 22, 8, 52, 50, 0, 0),
  Character("&", 0, 26, 37, 45, 18, 24, 0, 0),
  Character("*", 0, 36, 24, 14, 24, 36, 0, 0),
  Character("-", 0, 8, 8, 8, 8, 8, 0 , 0),
  Character("+", 0, 8, 8, 62, 8, 8, 0, 0),
  Character("=", 0, 20, 20, 20, 20, 20, 0, 0),
  Character("/", 0, 32, 16, 8, 4, 2, 0, 0),
  Character("?", 0, 4, 2, 90, 10, 4, 0, 0),
  Character("!", 0, 0, 0, 94, 0, 0, 0, 0),
  Character(".", 0, 0, 0, 64, 0, 0, 0, 0),
  Character(",", 0, 0, 0, 192, 0, 0, 0, 0),
  Character("#", 0, 20, 62, 20, 62, 20, 0, 0),

};

void display_symbol(String symbol)
{
  for(int i=0; i<sizeof(characters); i++)
  {
    if(characters[i].get_name() == symbol)
    {
      unsigned char bitmap[] = {
        characters[i].get_col(1),
        characters[i].get_col(2),
        characters[i].get_col(3),
        characters[i].get_col(4),
        characters[i].get_col(5),
        characters[i].get_col(6),
        characters[i].get_col(7),
        characters[i].get_col(8)
      };
      
      display_bitmap(bitmap);
      
      break;
    }
  }
}

void display_string(String message)
{
  for(int i=0; i<message.length(); i++)
  {
    String character = String(message.charAt(i));
    display_symbol(character);
    delay(letter_display_time);

    // special case to allow better "spacing" between words without forcing the string to be double-spaced
    if(character == " ")
    {
      delay(letter_display_time);
    }
  }
  // this adds extra "space" at the end of the message
  display_symbol(" ");
  delay(letter_display_time);
}
 
int maxInUse = 1;    //change this variable to set how many MAX7219's you'll use
 
// define max7219 registers
byte max7219_reg_noop        = 0x00;
byte max7219_reg_digit0      = 0x01;
byte max7219_reg_digit1      = 0x02;
byte max7219_reg_digit2      = 0x03;
byte max7219_reg_digit3      = 0x04;
byte max7219_reg_digit4      = 0x05;
byte max7219_reg_digit5      = 0x06;
byte max7219_reg_digit6      = 0x07;
byte max7219_reg_digit7      = 0x08;
byte max7219_reg_decodeMode  = 0x09;
byte max7219_reg_intensity   = 0x0a;
byte max7219_reg_scanLimit   = 0x0b;
byte max7219_reg_shutdown    = 0x0c;
byte max7219_reg_displayTest = 0x0f;

void putByte(byte data)
{
  byte i = 8;
  byte mask;
  
  while(i > 0) 
  {
    mask = 0x01 << (i - 1);      // get bitmask
    digitalWrite( clock, LOW);   // tick
    
    if (data & mask)
    {            // choose bit
      digitalWrite(dataIn, HIGH);// send 1
    }
    else
    {
      digitalWrite(dataIn, LOW); // send 0
    }
    
    digitalWrite(clock, HIGH);   // tock
    --i;                         // move to lesser bit
  }
}
     
void maxSingle( byte reg, byte col)
{    
  //maxSingle is the "easy"  function to use for a single max7219
 
  digitalWrite(load, LOW);       // begin
  putByte(reg);                  // specify register
  putByte(col);//((data & 0x01) * 256) + data >> 1); // put data  
  digitalWrite(load, LOW);       // and load da stuff
  digitalWrite(load,HIGH);
}

// initialize  all  MAX7219's in the system
void maxAll (byte reg, byte col) 
{    
  int c = 0;
  digitalWrite(load, LOW);  // begin   
   
  for ( c =1; c<= maxInUse; c++)
  {
    putByte(reg); // specify register
    putByte(col); //((data & 0x01) * 256) + data >> 1); // put data
  }
  
  digitalWrite(load, LOW);
  digitalWrite(load,HIGH);
}

void display_space()
{
  for (int col=1; col<=8; col++) 
  {
    maxSingle(col,0);
  }
}

void display_bitmap(unsigned char* bitmap)
{
  for(char col=1; col<=8; col++)
  {
    maxSingle(col, bitmap[col-1]);
  }
}
  
void setup () 
{
  pinMode(dataIn, OUTPUT);
  pinMode(clock,  OUTPUT);
  pinMode(load,   OUTPUT);

  //initiation of the max 7219
  maxAll(max7219_reg_scanLimit, 0x07);      
  maxAll(max7219_reg_decodeMode, 0x00);  // using an led matrix (not digits)
  maxAll(max7219_reg_shutdown, 0x01);    // not in shutdown mode
  maxAll(max7219_reg_displayTest, 0x00); // no display test

  // empty registers, turn all LEDs off
  for (int col=1; col<=8; col++) 
  {
    maxAll(col,0);
  }
  
  maxAll(max7219_reg_intensity, 0x0f & 0x01);    // the first 0x0f is the value you can set
                                                 // range: 0x00 to 0x0f
}  
     
void loop () 
{
  /*display_symbol("poop");
  delay(letter_display_time);*/
  display_string("\xc2");
}

