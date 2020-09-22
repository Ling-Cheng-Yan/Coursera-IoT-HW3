#include <EEPROM.h>

int address = 0;
int value;

void setup(void)
{
    Serial.begin(9600);
}

void loop(void)
{
    String s;
    s = Serial.readString();
    
    if(s.startsWith("read")){
        address = s.substring(5).toInt();
        Serial.print("Data Address: ");
        Serial.println(address);
        Serial.println(EEPROM.read(address));
    }
    else if(s.startsWith("write")){
        s.remove(0, 6);
        int writeArg1 = s.indexOf(' ');
        int address = s.substring(0, writeArg1).toInt();
        String s1 = s.substring(writeArg1, s.length());
        int value = s1.toInt();
        Serial.print("Address: ");
        Serial.println(address);
        Serial.print("Data Write: ");
        Serial.println(value);
        EEPROM.write(address, value);
        }
}
