#include "main.h"

char Serial_input_char;
char Serial_input_char_arr[10];
uint8_t Station_id;
uint8_t prev_Station_id;
String Serial_input_string;
String Station_name;
String prev_Station_name;
String Station_name_arr[4] = {"A1", "A2", "A3", "A4"};
uint8_t Station_id_arr[4] = {1,2,3,4};


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
        if (Serial_input_string.startsWith(Station_name_arr[i])) {
          prev_Station_name = Station_name;
          Station_name = Station_name_arr[i];
          Station_id = Station_id_arr[i];
          wr_next_station(Station_id);
        }
      }

      
      Serial_input_string = "";
    }
      
    
  }

}

void wr_next_station(uint8_t id) {
  Serial.println("A következő állomás az " + id);
}