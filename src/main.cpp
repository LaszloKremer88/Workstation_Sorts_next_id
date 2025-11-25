#include "main.h"

uint16_t seq;
char Serial_input_char;
char Serial_input_char_arr[10];
String Serial_input_string;
String Station_name_arr[5] = {"A0", "A1", "A2", "A3", "A4"};
uint8_t Station_ID_arr[5] = {0,1,2,3,4};
uint8_t Station_arr_length = 5;
uint8_t Station_ID;
uint8_t prev_Station_ID;
bool ready_for_r_pickup = false;
uint8_t Station_ID_to_robot;
uint8_t error_ID;


void setup() {
  Serial.begin(115200);
  Serial.print("Az id sorter bekapcsova");
  Serial.println();

  seq = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  if (seq == 0) {
      if (Serial.available() > 0) {
        Serial_input_char = Serial.read();
        if (Serial_input_char != '\n' && Serial_input_char != '\r') {
          Serial_input_string += Serial_input_char;
        }


        if (Serial_input_char == '\n') {
          
          Serial.println("Beérkezett teljes sor:");
          Serial.println(Serial_input_string);

          for (uint8_t i = 0; i < Station_arr_length; i++)
          {
            if (Serial_input_string.startsWith(Station_name_arr[i])) {
              prev_Station_ID = Station_ID;
              Station_ID = Station_ID_arr[i];
              wr_next_station(Station_ID);
              seq = 100;
            }
          }

          
          Serial_input_string = "";
        }
      
      } 
  }
  
  if (seq == 100) {

      if (Station_ID == 0) {
          Serial.println("Unknown station id");
          seq += 2000;
      }
      else if (Station_ID >= 0 && Station_ID < Station_arr_length) {
          Serial.print("Product waiting for: ");
          Serial.print(" A");
          Serial.print(Station_ID);
          Serial.println();
          seq = 200;
      }
      
  }

  if (seq == 200) {
      Serial.println("Set ready for robot pickup output");
      seq = 300;
  }

  if (seq == 300) {
      // to be continue
  }

  if (seq > 2000) {
      Serial.print("Hiba történt a ");
      Serial.print(error_ID);
      Serial.print(" hibaazonosítóval");
      Serial.println();

      seq = 0;
      
  }

}

void wr_next_station(uint8_t id) {
  Serial.print("A következő állomás az");
  Serial.print(" A");
  Serial.print(id);
  Serial.println();
}