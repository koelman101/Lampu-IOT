#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>

ESP8266WiFiMulti WiFiMulti;

// set variabel pin untuk lampu
int lamp = D0;
int lamp2 = D1;

void setup()
{
    Serial.begin(115200);
    
    // set Wifi SSID dan passwordnya
      WiFiMulti.addAP("PUDJI","Rahardjo");

    // set pin mode ke output
    pinMode(lamp, OUTPUT);
    pinMode(lamp2,OUTPUT);
}

void loop()
{
    // tunggu koneksi Wifi
    if((WiFiMulti.run() == WL_CONNECTED))
    {
        HTTPClient http;

        // contoh
          http.begin("http://192.168.1.14:3000/");
        // mulai koneksi dan ambil HTTP Header
        int httpCode = http.GET();

        // httpCode akan bernilai negatif bila error
        if(httpCode > 0)
        {
            // cetak httpCode ke Serial
            Serial.printf("[HTTP] GET... code: %d\n", httpCode);

            // bila nilai dari server diterima
            if(httpCode == HTTP_CODE_OK)
            {
                // cetak string json dari server
                String json = http.getString();
                Serial.println(json);

                // cek value json
                if(json == "{\"lampu1\":\"1\",\"code\":200}"){
                    // set ke LOW untuk menyalakan
                    digitalWrite(lamp, HIGH);
                }else{
		    digitalWrite(lamp, LOW);
		}

        } else {
            Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }
        // tutup koneksi HTTP
        http.end();
    }

    delay(1000);
  }
}