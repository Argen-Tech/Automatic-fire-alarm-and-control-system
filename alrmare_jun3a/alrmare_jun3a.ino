#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int temp1=A0;
int temp2=A1; 
int temp3=A2;
int mainpump=13;
int emergency=10;
int zone1_p=9;
int zone2_p=8;
int zone3_p=7; 
int buzzer=6;
int normal=1;
int mainpower=0;
int battery=A5;

void setup() {
 pinMode(zone1_p, OUTPUT);
 pinMode(zone2_p, OUTPUT);
 pinMode(zone3_p, OUTPUT);
 pinMode(mainpump, OUTPUT);
 pinMode(emergency, OUTPUT);
 pinMode(buzzer, OUTPUT);
 pinMode(normal, OUTPUT);
 pinMode(mainpower, OUTPUT);
 pinMode(battery, OUTPUT);
 lcd.begin(16,2);
 lcd.setCursor(0,0);
 lcd.print("THIS IS FIRE ALARM ");
}

void loop() {
   float firea =analogRead(temp1);
   float fireb=analogRead(temp2);
   float firec=analogRead(temp3);
   firea=(firea*5)/1023;
   firea=firea*100;
   fireb=(fireb*5)/1023;
   fireb=fireb*100;
   firec=(firec*5)/1023;
   firec=firec*100;
   lcd.setCursor(0,2);
   lcd.print(firea);
   lcd.setCursor(6,2);
   lcd.print(fireb);
   lcd.setCursor(12,2);
   lcd.print(firec);
   if((firea>50)&&(fireb<50)&&(firec<50))
   {
      lcd.setCursor(0,0);
       lcd.clear();
      lcd.print("FIRE IN 1                  ");
      digitalWrite(13,HIGH);
      digitalWrite(emergency,HIGH);
      digitalWrite(zone1_p,HIGH);
      digitalWrite(zone2_p,LOW);
      digitalWrite(zone3_p,LOW);
      digitalWrite(buzzer,HIGH);
      digitalWrite(normal,LOW);
      digitalWrite(mainpower,LOW);
     digitalWrite(battery,HIGH);
   }
       else if((fireb>50)&&(firea<50)&&(firec<50))
     {
       lcd.setCursor(0,0);
       lcd.print("FIRE IN 2 ");
       digitalWrite(mainpump,HIGH);
       digitalWrite(emergency,HIGH);
       digitalWrite(zone2_p,HIGH);
       digitalWrite(zone1_p,LOW);
       digitalWrite(zone3_p,LOW);
       digitalWrite(buzzer,HIGH);
       digitalWrite(normal,LOW);
       digitalWrite(mainpower,LOW);
       digitalWrite(battery,HIGH);
      }
         else if((firec>50)&&(firea<50)&&(fireb<50))
        {
         lcd.setCursor(0,0);
         lcd.print("FIRE IN 3 ");
         digitalWrite(mainpump,HIGH);
         digitalWrite(emergency,HIGH);
         digitalWrite(zone3_p,HIGH);
         digitalWrite(zone1_p,LOW);
         digitalWrite(zone2_p,LOW);
         digitalWrite(buzzer,HIGH);
         digitalWrite(normal,LOW);
         digitalWrite(mainpower,LOW);
         digitalWrite(battery,HIGH);
        }
          else if((firea>50)&&(fireb>50)&&(firec<50))
          {
           lcd.setCursor(0,0);
           lcd.print("FIRE IS SET IN ZONE1 &2 ");
           digitalWrite(mainpump,HIGH);
           digitalWrite(emergency,HIGH);
           digitalWrite(zone2_p,HIGH);
           digitalWrite(zone1_p,HIGH);
           digitalWrite(zone3_p,LOW);
           digitalWrite(buzzer,HIGH);
           digitalWrite(normal,LOW);
           digitalWrite(mainpower,LOW);
           digitalWrite(battery,HIGH);
          }
            else if((firea>50)&&(firec>50)&&(fireb<50))
            {
             lcd.setCursor(0,0);
             lcd.print("FIRE IS SET IN ZONE1 &3 ");
             digitalWrite(mainpump,HIGH);
             digitalWrite(emergency,HIGH);
             digitalWrite(zone3_p,HIGH);
             digitalWrite(zone1_p,HIGH);
             digitalWrite(zone2_p,LOW);
             digitalWrite(buzzer,HIGH);
             digitalWrite(normal,LOW);
             digitalWrite(mainpower,LOW);
             digitalWrite(battery,HIGH);
            }
               else if((fireb>50)&&(firec>50)&&(firea<50))
              {
               lcd.setCursor(0,0);
               lcd.print("FIRE IS SET IN ZONE2 &3 ");
               digitalWrite(mainpump,HIGH);
               digitalWrite(emergency,HIGH);
               digitalWrite(zone2_p,HIGH);
               digitalWrite(zone3_p,HIGH);
               digitalWrite(zone1_p,LOW);
               digitalWrite(buzzer,HIGH);
               digitalWrite(normal,LOW);
               digitalWrite(mainpower,LOW);
               digitalWrite(battery,HIGH);
              }
                else if((firea>50)&&(fireb>50)&&(firec>50))
                {
                 lcd.setCursor(0,0);
                 lcd.print("FIRE IS SET IN ZONE1 &2 ");
                 digitalWrite(mainpump,HIGH);
                 digitalWrite(emergency,HIGH);
                 digitalWrite(zone2_p,HIGH);
                 digitalWrite(zone1_p,HIGH);
                 digitalWrite(zone3_p,HIGH);
                 digitalWrite(buzzer,HIGH);
                 digitalWrite(normal,LOW);
                 digitalWrite(mainpower,LOW);
                 digitalWrite(battery,HIGH);
                }
                   else if((firea<50)&&(fireb<50)&&(firec<50))
                  {
                   digitalWrite(mainpump,LOW);
                   digitalWrite(emergency,LOW);
                   digitalWrite(zone1_p,LOW);
                   digitalWrite(zone2_p,LOW);
                   digitalWrite(zone3_p,LOW);
                   digitalWrite(buzzer,LOW);
                   digitalWrite(normal,HIGH);
                   digitalWrite(mainpower,HIGH);
                   digitalWrite(battery,LOW);
                   lcd.setCursor(0,0);
                   lcd.print("THIS IS FIRE ALARM ");
                  }

  }
