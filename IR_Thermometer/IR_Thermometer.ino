#include <Wire.h>
#include <SPI.h>
#include <Adafruit_MLX90614.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


Adafruit_MLX90614 mlx = Adafruit_MLX90614();
Adafruit_SSD1306 display(-1);

float temperatureC;
float temperatureF;

void setup()
{
  mlx.begin();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();


}

void loop()
{
  temperatureC = mlx.readObjectTempC();
  temperatureF = mlx.readObjectTempF();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("    IR Thermometer");

  display.setCursor(0, 28);
  display.print("Temp: ");
  display.setTextSize(2);
  display.print(temperatureC);
  display.setTextSize(1);
  display.println( "*C");
  display.println("");

  display.print("      ");
  display.setTextSize(2);
  display.print(temperatureF);
  display.setTextSize(1);
  display.println( "*F");



  display.display();
  delay(200);
  display.clearDisplay();


}
