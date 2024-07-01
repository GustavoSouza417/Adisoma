//SEÇÃO DE BIBLIOTECAS
  #include <LiquidCrystal.h>



//SEÇÃO DE #DEFINES
  #define rs 12
  #define e 11
  #define d7 7
  #define d6 6
  #define d5 5
  #define d4 4



//ATRIBUIÇÕES REFERENTES À BIBLIOTECA
  LiquidCrystal lcd(rs, e, d4, d5, d6, d7);



//SEÇÃO DE PROTOTIPAÇÃO
  void randomNumberGenerator(int *, int *, int *);
  void displayOnLCD(int *, int *);
  bool resultValidation(int *, int *);
  void resultsPresentation(bool *, int *);



//FUNÇÕES PRINCIPAIS
  void setup()
  {
    Serial.begin(9600);
    lcd.begin(16, 2);
    randomSeed(analogRead(0));
  }

  void loop()
  {
    int number1, number2, result, userResult;
  	String accumulator = "";
  	bool rightAnswer;

  	randomNumberGenerator(&number1, &number2, &result);
  	displayOnLCD(&number1, &number2);
  
  	while(1)
    {
      if(Serial.available())
      {
        int received = Serial.parseInt();

        if(received == 101)
        {
          userResult = accumulator.toInt();
          break;
        }
        else
          accumulator += received;
      }
    }

    lcd.print(userResult);
    delay(1500);

    rightAnswer = resultValidation(&userResult, &result);
    resultsPresentation(&rightAnswer, &result);
    delay(1500);  
  }



//SEÇÃO DE FUNÇÕES
  void randomNumberGenerator(int *number1, int *number2, int *result)
  {
    *number1 = random(1, 100);
  	*number2 = random(1, 100);
  	*result  = *number1 + *number2;
  }

  void displayOnLCD(int *number1, int *number2)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(*number1);
    lcd.print(" + ");
  	lcd.print(*number2);
  	lcd.print(" = ");
  }

  bool resultValidation(int *userResult, int *result)
  {
  	if(*userResult == *result)
      return true;
    
    return false;
  };

  void resultsPresentation(bool *rightAnswer, int *result)
  {
  	lcd.clear();

  	if(*rightAnswer)
      lcd.print("Resposta correta");
    else
    {
      lcd.print("Resposta");
      lcd.setCursor(0, 1);
      lcd.print("Incorreta");
      lcd.setCursor(11, 1);
      lcd.print("R:");
      lcd.print(*result);
    }
  }