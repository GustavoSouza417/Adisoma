//SEÇÃO DE BIBLIOTECAS
  #include <Keypad.h>
  #include "SoftwareSerial.h"



//SEÇÃO DE CONSTANTES
  const byte numRows = 4;
  const byte numCols = 4;



//ATRIBUIÇÕES REFERENTES ÀS BIBLIOTECAS
  byte rowPins[numRows] = {9, 8, 7, 6};
  byte colPins[numCols] = {5, 4, 3, 2};

  char keyMap[numRows][numCols] =
  {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'},
    {'*', '0'}
  };

  Keypad myKeypad = Keypad(makeKeymap(keyMap), rowPins, colPins, numRows, numCols);
  SoftwareSerial comunicacaoSerial(12, 13);



//FUNÇÕES PRINCIPAIS
  void setup()
  {  
    Serial.begin(9600);
    comunicacaoSerial.begin(9600);
  }

  void loop()
  { 
    while(1)
    {
      char myKeypadPressed = myKeypad.getKey();

      if(myKeypadPressed != NO_KEY)
      {
        if(myKeypadPressed == '*')
        {
          comunicacaoSerial.println("101");
          continue;
        }

        comunicacaoSerial.println(myKeypadPressed);
      }
    }
  }