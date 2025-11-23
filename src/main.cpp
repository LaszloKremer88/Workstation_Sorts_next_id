#include "main.h"

char Serial_input_char;
char Serial_input_char_arr[10];
String Serial_input_string;
String Station_ID;
String prev_Station_ID;
String Station_ID_arr[4] = {"A1", "A2", "A3", "A4"};


void setup() {
  Serial.begin(115200);
  Serial.print("Az id sorter bekapcsova");
  Serial.println();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    Serial_input_char = Serial.read();
    if (Serial_input_char != '\n' && Serial_input_char != '\r') {
      Serial_input_string += Serial_input_char;
    }


    if (Serial_input_char == '\n') {
      
      Serial.println("Beérkezett teljes sor:");
      Serial.println(Serial_input_string);

      for (uint8_t i = 0; i < 4; i++)
      {
        if (Serial_input_string.startsWith(Station_ID_arr[i])) {
          prev_Station_ID = Station_ID;
          Station_ID = Station_ID_arr[i];
          wr_next_station(Station_ID);
        }
      }

      
      Serial_input_string = "";
    }
      
    
  }

}

void wr_next_station(String id) {
  Serial.println("A következő állomás az " + id);
}