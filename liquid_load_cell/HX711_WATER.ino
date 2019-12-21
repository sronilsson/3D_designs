#include "HX711.h"

HX711 scale(2, 3);

float calibration_factor = -1000; // this calibration factor is adjusted according to my load cell
float units;

void setup() {
  Serial.begin(9600);
  scale.set_scale();
  scale.tare();  //Reset the scale to 0

  long zero_factor = scale.read_average(); //Get a baseline reading
}

void loop() {

  scale.set_scale(calibration_factor); //Adjust to this calibration factor
  units = scale.get_units(), 10;
  if (units < 0)
  {
    units = 0.00;
  }
  String print_string = String(units) + ',';
  Serial.println(print_string);
}
