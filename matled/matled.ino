#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_LEDBackpack.h>

Adafruit_8x8matrix matrix = Adafruit_8x8matrix();

void setup() {
  // シリアルポートを57600 bps[ビット/秒]で初期化
  // 超大事、LightBluBean専用これを入れないと動かない
  Serial.begin(57600);

  Serial.println("8x8 LED Matrix Test");

  matrix.begin(0x70);  // pass in the address

  matrix.clear();
  matrix.setRotation(90);
}

static const uint8_t PROGMEM
windmillBmp0[] =
{ B11000001,
  B01100011,
  B00110110,
  B00011100,
  B00111000,
  B01101100,
  B11000110,
  B10000011
},
windmillBmp1[] =
{ B01100000,
  B00110001,
  B00011011,
  B00111110,
  B01111100,
  B11011000,
  B10001100,
  B00000110
},
windmillBmp2[] =
{ B00110000,
  B00011000,
  B00011001,
  B01111111,
  B11111110,
  B10011000,
  B00011000,
  B00001100
},
windmillBmp3[] =
{ B00000110,
  B10001100,
  B11101100,
  B01111000,
  B00011110,
  B00110111,
  B00110001,
  B01100000
},
windmillBmp4[] =
{ B10000011,
  B11000110,
  B01101100,
  B00111000,
  B00011100,
  B00110110,
  B01100011,
  B11000001
};

static const uint8_t PROGMEM
fireworkBmp0[] =
{ B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00010000
},
fireworkBmp1[] =
{ B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00010000,
  B00010000
},
fireworkBmp2[] =
{ B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00010000,
  B00010000,
  B00010000
},
fireworkBmp3[] =
{ B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00010000,
  B00010000,
  B00010000,
  B00000000
},
fireworkBmp4[] =
{ B00000000,
  B00000000,
  B00000000,
  B00010000,
  B00010000,
  B00010000,
  B00000000,
  B00000000
},
fireworkBmp5[] =
{ B00000000,
  B00000000,
  B00000000,
  B00010000,
  B00010000,
  B00000000,
  B00000000,
  B00000000
},
fireworkBmp6[] =
{ B00000000,
  B00000000,
  B00000000,
  B00010000,
  B00000000,
  B00000000,
  B00000000,
  B00000000
},
fireworkBmp7[] =
{ B00000000,
  B00000000,
  B00000000,
  B00011000,
  B00011000,
  B00000000,
  B00000000,
  B00000000
},
fireworkBmp8[] =
{ B00000000,
  B00000000,
  B00100100,
  B00011000,
  B00011000,
  B00100100,
  B00000000,
  B00000000
},
fireworkBmp9[] =
{ B00000000,
  B00000000,
  B00101100,
  B00111000,
  B00011100,
  B00110100,
  B00000000,
  B00000000
},
fireworkBmp10[] =
{ B00000000,
  B00011000,
  B00100100,
  B01011010,
  B01011010,
  B00100100,
  B00011000,
  B00000000
},
fireworkBmp11[] =
{ B00000000,
  B01011010,
  B00100100,
  B01011010,
  B01011010,
  B00100100,
  B01011010,
  B00000000
},
fireworkBmp12[] =
{ B00000100,
  B01011010,
  B10100100,
  B01011010,
  B01011010,
  B00100101,
  B01011010,
  B00100000
},
fireworkBmp13[] =
{ B00100100,
  B01011010,
  B10100101,
  B01011010,
  B01011010,
  B10100101,
  B01011010,
  B00100100
},
fireworkBmp14[] =
{ B00111100,
  B01011010,
  B10100101,
  B11011011,
  B11011011,
  B10100101,
  B01011010,
  B00111100
},
fireworkBmp15[] =
{ B00100100,
  B01011010,
  B10100101,
  B01011010,
  B01011010,
  B10100101,
  B01011010,
  B00100100
},
fireworkBmp16[] =
{ B00000000,
  B01011010,
  B10100101,
  B01011010,
  B01011010,
  B10100101,
  B01011010,
  B00000000
},
fireworkBmp17[] =
{ B00000000,
  B00011000,
  B00100100,
  B01011010,
  B01011010,
  B00100100,
  B00011000,
  B00000000
},
fireworkBmp18[] =
{ B00000000,
  B00001000,
  B00100100,
  B01011000,
  B00011010,
  B00100100,
  B00010000,
  B00000000
},
fireworkBmp19[] =
{ B00000000,
  B00000000,
  B00100100,
  B00011000,
  B00011000,
  B00100100,
  B00000000,
  B00000000
},
fireworkBmp20[] =
{ B00000000,
  B00000000,
  B00000000,
  B00011000,
  B00011000,
  B00000000,
  B00000000,
  B00000000
},
fireworkBmp21[] =
{ B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000
};

static const uint8_t PROGMEM
dogJumpBmp0[] =
{ B00000000,
  B00000000,
  B00001000,
  B10001110,
  B01111110,
  B01111000,
  B01001000,
  B00000000
},
dogJumpBmp1[] =
{ B00000000,
  B00000100,
  B01000111,
  B00111111,
  B00111100,
  B01000010,
  B00000000,
  B00000000
},
dogJumpBmp2[] =
{ B00000000,
  B00000000,
  B00000100,
  B00000111,
  B01111111,
  B00111100,
  B00100100,
  B00000000
},
dogJumpBmp3[] =
{ B00000000,
  B00000000,
  B00000010,
  B00100011,
  B00011111,
  B00011110,
  B00100001,
  B00000000
},
dogJumpBmp4[] =
{ B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00001111,
  B00000111,
  B00000010,
  B00000000
},
dogJumpBmp5[] =
{ B00000000,
  B00000000,
  B00000000,
  B00000010,
  B00000001,
  B00000001,
  B00000010,
  B00000000
},
dogJumpBmp6[] =
{ B00000000,
  B00000000,
  B00000000,
  B11000000,
  B11000000,
  B00000000,
  B10000000,
  B00000000
},
dogJumpBmp7[] =
{ B00000000,
  B00000000,
  B01000000,
  B01110000,
  B11110000,
  B11000000,
  B00100000,
  B00000000
},
dogJumpBmp8[] =
{ B00000000,
  B00000000,
  B00010000,
  B00011100,
  B11111100,
  B11110000,
  B00100000,
  B00000000
},
dogJumpBmp9[] =
{
  B00000000,
  B00000000,
  B00001000,
  B10001110,
  B01111110,
  B01111000,
  B01001000,
  B00000000
};

static const uint8_t PROGMEM
dogEatBmp0[] =
{ B00000000,
  B00000000,
  B00001000,
  B10001110,
  B01111110,
  B01110000,
  B01010111,
  B00000000
},
dogEatBmp1[] =
{ B00000000,
  B00000000,
  B00001000,
  B00001100,
  B11111110,
  B01110100,
  B01010111,
  B00000000
};

static const uint8_t PROGMEM
dogSitdownBmp0[] =
{ B00000000,
  B00000000,
  B00001000,
  B10001110,
  B01111110,
  B01111000,
  B01001000,
  B00000000
},
dogSitdownBmp1[] =
{ B00000000,
  B00000000,
  B00001000,
  B00001110,
  B10011110,
  B01111000,
  B01101000,
  B00000000
},
dogSitdownBmp2[] =
{ B00000000,
  B00000000,
  B00001000,
  B00001110,
  B00011110,
  B01111000,
  B11101000,
  B00000000
};

static const uint8_t PROGMEM
dogShakeTailBmp0[] =
{ B00000000,
  B00000000,
  B00001000,
  B10001110,
  B01111110,
  B01111000,
  B01001000,
  B00000000
},
dogShakeTailBmp1[] =
{ B00000000,
  B00000000,
  B00001000,
  B00001110,
  B01111110,
  B11111000,
  B01001000,
  B00000000
};


static const uint8_t PROGMEM
dogBarkBmp0[] =
{ B00000000,
  B00000000,
  B00001000,
  B10001110,
  B01111110,
  B01111000,
  B01001000,
  B00000000
},
dogBarkBmp1[] =
{ B00000000,
  B00000000,
  B00000100,
  B10011110,
  B01111100,
  B01111000,
  B01001000,
  B00000000
};

static const uint8_t PROGMEM
confort0_bmp[] =
{ B00000000,
  B00011000,
  B00111100,
  B00111100,
  B00011000,
  B00111100,
  B01111110,
  B10111101
},
confort1_bmp[] =
{ B00000000,
  B00011000,
  B00111100,
  B10111101,
  B01011010,
  B00111100,
  B00111100,
  B00111100
},
normal0_bmp[] =
{ B00000000,
  B00011000,
  B00111100,
  B00111100,
  B00011000,
  B00111100,
  B01111110,
  B01111110
},
normal1_bmp[] =
{ B00000000,
  B00011000,
  B00111100,
  B00111100,
  B00011000,
  B00111100,
  B01111110,
  B10111101
},
sweat0_bmp[] =
{ B00000000,
  B00011000,
  B00111100,
  B00111100,
  B00011000,
  B00111100,
  B01111110,
  B01111110
},
sweat1_bmp[] =
{ B00000000,
  B00001100,
  B00011110,
  B00011110,
  B00011100,
  B00111100,
  B01111110,
  B01111110
},
sweat2_bmp[] =
{ B00000000,
  B00110000,
  B01111000,
  B01111000,
  B00111000,
  B00111100,
  B01111110,
  B10111110
},
sweat3_bmp[] =
{ B00000000,
  B00000100,
  B00110001,
  B01111000,
  B01111010,
  B00111100,
  B01111110,
  B10111101
},
house_bmp[] =
{ B00000000,
  B00000000,
  B00011000,
  B00111100,
  B01111110,
  B00100100,
  B00111100,
  B00000000
};

static const uint8_t PROGMEM
smile_bmp[] =
{ B00111100,
  B01000010,
  B10100101,
  B10000001,
  B10100101,
  B10011001,
  B01000010,
  B00111100
},
neutral_bmp[] =
{ B00111100,
  B01000010,
  B10100101,
  B10000001,
  B10111101,
  B10000001,
  B01000010,
  B00111100
},
frown_bmp[] =
{ B00111100,
  B01000010,
  B10100101,
  B10000001,
  B10011001,
  B10100101,
  B01000010,
  B00111100
};

void loop() {
  while (Serial.available()) {
    startRead();
  }
}

void wave() {

}

void logo() {
  for (int8_t x = 7; x >= -60; x--) {
    matrix.clear();
    matrix.setCursor(x, 0);
    matrix.print("Matled");
    matrix.writeDisplay();
    delay(100);
  }

  matrix.clear();
}

void temperature() {
  int temperature = Bean.getTemperature();
  // Set LED color based on temperature of the Bean


  if (temperature > 31) {
    matrix.clear();
    matrix.drawBitmap(0, 0, house_bmp, 8, 8, LED_ON);
    matrix.writeDisplay();

    delay(150);
  } else if (temperature > 28) {
    matrix.clear();
    matrix.drawBitmap(0, 0, sweat0_bmp, 8, 8, LED_ON);
    matrix.writeDisplay();
    delay(150);
    matrix.clear();
    matrix.drawBitmap(0, 0, sweat1_bmp, 8, 8, LED_ON);
    matrix.writeDisplay();
    delay(150);
    matrix.clear();
    matrix.drawBitmap(0, 0, sweat2_bmp, 8, 8, LED_ON);
    matrix.writeDisplay();
    delay(150);
    matrix.clear();
    matrix.drawBitmap(0, 0, sweat3_bmp, 8, 8, LED_ON);
    matrix.writeDisplay();
    delay(150);
  } else if (temperature > 25) {
    matrix.clear();
    matrix.drawBitmap(0, 0, normal0_bmp, 8, 8, LED_ON);
    matrix.writeDisplay();
    delay(150);
    matrix.clear();
    matrix.drawBitmap(0, 0, normal1_bmp, 8, 8, LED_ON);
    matrix.writeDisplay();
    delay(150);
  } else if (temperature > 18) {
    matrix.clear();
    matrix.drawBitmap(0, 0, confort0_bmp, 8, 8, LED_ON);
    matrix.writeDisplay();
    delay(150);
    matrix.clear();
    matrix.drawBitmap(0, 0, confort1_bmp, 8, 8, LED_ON);
    matrix.writeDisplay();
    delay(150);
  } else if (temperature > 15) {
    matrix.clear();
    matrix.drawBitmap(0, 0, normal0_bmp, 8, 8, LED_ON);
    matrix.writeDisplay();

    delay(150);
    matrix.clear();
    matrix.drawBitmap(0, 0, normal1_bmp, 8, 8, LED_ON);
    matrix.writeDisplay();

    delay(150);
  } else if (temperature > 11) {
    matrix.clear();
    matrix.drawBitmap(0, 0, sweat0_bmp, 8, 8, LED_ON);
    matrix.writeDisplay();
    delay(150);
    matrix.clear();
    matrix.drawBitmap(0, 0, sweat1_bmp, 8, 8, LED_ON);
    matrix.writeDisplay();

    delay(150);
    matrix.clear();
    matrix.drawBitmap(0, 0, sweat2_bmp, 8, 8, LED_ON);
    matrix.writeDisplay();
    delay(150);
    matrix.clear();
    matrix.drawBitmap(0, 0, sweat3_bmp, 8, 8, LED_ON);
    matrix.writeDisplay();

    delay(150);
  } else {
    matrix.clear();
    matrix.drawBitmap(0, 0, house_bmp, 8, 8, LED_ON);
    matrix.writeDisplay();
    delay(150);
  }
  Bean.sleep(50);
}

int split(String *result, size_t resultsize, String data, char delimiter){
    int index = 0;
    int datalength = data.length();
    for (int i = 0; i < datalength; i++) {
        char tmp = data.charAt(i);
        if ( tmp == delimiter ) {
            index++;
            if ( index > (resultsize - 1)) return -1;
        }
        else result[index] += tmp;
    }
    return (index + 1);
}

uint8_t getMatrixRow(String rowString) {
  int rowInt = rowString.toInt();
  unsigned char result = (unsigned char)rowInt;

  return result;
}

void displayBitmap(String replacedString) {
  // replacedString = "60.66.165.129.165.153.66.60";
  String matrixRows[8] = {};
  char delimiter = '.'; 
  split(matrixRows, 8, replacedString, delimiter);

  unsigned char matrixRow1 = getMatrixRow(matrixRows[0]);
  unsigned char matrixRow2 = getMatrixRow(matrixRows[1]);
  unsigned char matrixRow3 = getMatrixRow(matrixRows[2]);
  unsigned char matrixRow4 = getMatrixRow(matrixRows[3]);
  unsigned char matrixRow5 = getMatrixRow(matrixRows[4]);
  unsigned char matrixRow6 = getMatrixRow(matrixRows[5]);
  unsigned char matrixRow7 = getMatrixRow(matrixRows[6]);
  unsigned char matrixRow8 = getMatrixRow(matrixRows[7]);


  /*
    unsigned char matrixRow1 = 60;
    unsigned char matrixRow2 = 66;
    unsigned char matrixRow3 = 165;
    unsigned char matrixRow4 = 129;
    unsigned char matrixRow5 = 165;
    unsigned char matrixRow6 = 153;
    unsigned char matrixRow7 = 66;
    unsigned char matrixRow8 = 60;
  */

  uint8_t PROGMEM receive_bmp[] =
  { matrixRow1,
    matrixRow2,
    matrixRow3,
    matrixRow4,
    matrixRow5,
    matrixRow6,
    matrixRow7,
    matrixRow8
  };

  matrix.clear();
  matrix.drawBitmap(0, 0, receive_bmp, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(500);
  matrix.clear();
}

void dogSitdown() {

  matrix.clear();
  matrix.drawBitmap(0, 0, dogSitdownBmp0, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(400);

  matrix.clear();
  matrix.drawBitmap(0, 0, dogSitdownBmp1, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(400);

  matrix.clear();
  matrix.drawBitmap(0, 0, dogSitdownBmp2, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(1000);

  matrix.clear();
  matrix.drawBitmap(0, 0, dogSitdownBmp1, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(400);

  matrix.clear();
  matrix.drawBitmap(0, 0, dogSitdownBmp0, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(400);
}

void dogBark() {
  matrix.clear();
  matrix.drawBitmap(0, 0, dogBarkBmp0, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(400);

  matrix.clear();
  matrix.drawBitmap(0, 0, dogBarkBmp1, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(400);
}

void dogShakeTail() {
  matrix.clear();
  matrix.drawBitmap(0, 0, dogShakeTailBmp0, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(400);

  matrix.clear();
  matrix.drawBitmap(0, 0, dogShakeTailBmp1, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(400);

}

void dogEat() {
  matrix.clear();
  matrix.drawBitmap(0, 0, dogEatBmp0, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(400);

  matrix.clear();
  matrix.drawBitmap(0, 0, dogEatBmp1, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(400);
}

void dogJump() {
  matrix.clear();
  matrix.drawBitmap(0, 0, dogJumpBmp0, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(400);

  matrix.clear();
  matrix.drawBitmap(0, 0, dogJumpBmp1, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(400);

  matrix.clear();
  matrix.drawBitmap(0, 0, dogJumpBmp2, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(400);

  matrix.clear();
  matrix.drawBitmap(0, 0, dogJumpBmp3, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(400);

  matrix.clear();
  matrix.drawBitmap(0, 0, dogJumpBmp4, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(400);

  matrix.clear();
  matrix.drawBitmap(0, 0, dogJumpBmp5, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(400);

  matrix.clear();
  matrix.drawBitmap(0, 0, dogJumpBmp6, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(400);

  matrix.clear();
  matrix.drawBitmap(0, 0, dogJumpBmp7, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(400);

  matrix.clear();
  matrix.drawBitmap(0, 0, dogJumpBmp8, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(400);

  matrix.clear();
  matrix.drawBitmap(0, 0, dogJumpBmp9, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(400);
}

void windmill() {
  matrix.clear();
  matrix.drawBitmap(0, 0, windmillBmp0, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(200);

  matrix.clear();
  matrix.drawBitmap(0, 0, windmillBmp1, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(200);

  matrix.clear();
  matrix.drawBitmap(0, 0, windmillBmp2, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(200);

  matrix.clear();
  matrix.drawBitmap(0, 0, windmillBmp3, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(200);

  matrix.clear();
  matrix.drawBitmap(0, 0, windmillBmp4, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(200);

}

void firework() {
  matrix.clear();
  matrix.drawBitmap(0, 0, fireworkBmp0, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(80);

  matrix.clear();
  matrix.drawBitmap(0, 0, fireworkBmp1, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(80);

  matrix.clear();
  matrix.drawBitmap(0, 0, fireworkBmp2, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(80);

  matrix.clear();
  matrix.drawBitmap(0, 0, fireworkBmp3, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(80);

  matrix.clear();
  matrix.drawBitmap(0, 0, fireworkBmp4, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(80);

  matrix.clear();
  matrix.drawBitmap(0, 0, fireworkBmp5, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(80);

  matrix.clear();
  matrix.drawBitmap(0, 0, fireworkBmp6, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(80);

  matrix.clear();
  matrix.drawBitmap(0, 0, fireworkBmp7, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(80);

  matrix.clear();
  matrix.drawBitmap(0, 0, fireworkBmp8, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(80);

  matrix.clear();
  matrix.drawBitmap(0, 0, fireworkBmp9, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(80);

  matrix.clear();
  matrix.drawBitmap(0, 0, fireworkBmp10, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(120);

  matrix.clear();
  matrix.drawBitmap(0, 0, fireworkBmp11, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(150);

  matrix.clear();
  matrix.drawBitmap(0, 0, fireworkBmp12, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(180);

  matrix.clear();
  matrix.drawBitmap(0, 0, fireworkBmp13, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(210);

  matrix.clear();
  matrix.drawBitmap(0, 0, fireworkBmp14, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(250);

  matrix.clear();
  matrix.drawBitmap(0, 0, fireworkBmp15, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(250);

  matrix.clear();
  matrix.drawBitmap(0, 0, fireworkBmp16, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(250);

  matrix.clear();
  matrix.drawBitmap(0, 0, fireworkBmp17, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(250);

  matrix.clear();
  matrix.drawBitmap(0, 0, fireworkBmp18, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(250);

  matrix.clear();
  matrix.drawBitmap(0, 0, fireworkBmp19, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(250);

  matrix.clear();
  matrix.drawBitmap(0, 0, fireworkBmp20, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(200);

  matrix.clear();
  matrix.drawBitmap(0, 0, fireworkBmp21, 8, 8, LED_ON);
  matrix.writeDisplay();
  delay(180);
}

void startRead() {
  Bean.setLed(0, 0, 0);
  Bean.setLedGreen(255);
  String inputString = Serial.readStringUntil(';');

  Serial.println("inputString:" + inputString);

  if (inputString.startsWith("pict")) {
    inputString.replace("pict", "");
    displayBitmap(inputString);
  } else if (inputString == "logo") {
    logo();
  } else if (inputString == "temperature") {
    temperature();
  } else if (inputString == "dogsitdown") {
    dogSitdown();
  } else if (inputString == "dogbark") {
    dogBark();
  } else if (inputString == "dogeat") {
    dogEat();
  } else if (inputString == "dogjump") {
    dogJump();
  } else if (inputString == "dogshaketail") {
    dogShakeTail();
  } else if (inputString == "firework") {
    firework();
  } else if (inputString == "windmill") {
    windmill();
  }
}
