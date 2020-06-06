#include <LiquidCrystal.h>
#include<Keypad.h>

LiquidCrystal lcd(13,12,11,10,9,8);//lcd pin declear
char pad[4][4]={
  {'1','2','3','+'},
  {'4','5','6','-'},
  {'7','8','9','*'},
  {'=','0','#','/'}
};
byte row[4]={7,6,5,4};
byte col[4]={3,2,1,0};
Keypad key = Keypad(makeKeymap(pad),row,col,4,4);
char arr[3];
int i=0;
int a,b;

void setup() 
{
  lcd.begin(16,2);
  lcd.print("Simple Calc:");
  lcd.setCursor(1,1);
}

void loop()
{
  char input = key.getKey();
  if(int(input)!=0)
  {
    if(input!='=')
    {
    arr[i]=input;
    lcd.print(arr[i]);
    i++;
    }
    else
    {
      lcd.clear();
      lcd.print("Result: ");
      lcd.setCursor(1,1);
      a=int(arr[0])-48;
      b=int(arr[2])-48;
      if(arr[1]=='+')
      {
        lcd.print(a+b);
      }
      if(arr[1]=='-')
      {
        lcd.print(a-b);
      }
      if(arr[1]=='*')
      {
        lcd.print(a*b);
      }
      if(arr[1]=='/')
      {
        lcd.print(a/b);
      }
    }
  }
  if(input=='#')
  {
    i=0;
    setup();
  }
    
  
}

