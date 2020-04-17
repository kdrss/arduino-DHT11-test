#include <DHT_U.h>
#include <DHT.h>

#define DHTPIN 4 // DHT11's output pin
#define DHTTYPE DHT11 // DHT type set to DHT11

#define CELSIUS false
#define FAHRENHEIT true

DHT sensor(DHTPIN,DHTTYPE); // Create a handle for DHT

void setup()
{
    Serial.begin(9600);
    sensor.begin();
}

void loop()
{
	delay(2000);

    double humidity = sensor.readHumidity();
    float temperature = sensor.readTemperature(CELSIUS);

    if (isnan(humidity) || isnan(temperature) || (humidity > 100)) // communication okay?
    {
    Serial.println(F("Failed to read from DHT sensor"));
    return;
    }

    Serial.println(sensor.computeHeatIndex(temperature,humidity));


}
