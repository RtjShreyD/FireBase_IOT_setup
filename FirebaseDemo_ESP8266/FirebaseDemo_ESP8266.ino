#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>


#define FIREBASE_HOST "restsvr.firebaseio.com" //firebase end point
#define FIREBASE_AUTH "DAyn8zLBXmBecOYEZue81VirzEd3upyRukT23ghG" //secret key for authentication

//#define WIFI_SSID "Tech_D3882400"  
//#define WIFI_PASSWORD "TAQAHYWG"
#define WIFI_SSID "Morphedo -2.4GHz"
#define WIFI_PASSWORD "82$morph"

void setup() 
{
    Serial.begin(9600);
    // connect to wifi.
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    Serial.print("connecting");
    
    while (WiFi.status() != WL_CONNECTED) 
    {
        Serial.print(".");
        delay(500);
    }
    
    Serial.println();
    Serial.print("connected: ");
    Serial.println(WiFi.localIP());
    
    Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

    Firebase.set("BOX_STATUS",0);  
}

String nx = "";

void loop() 
{  
  // GET value  
  nx=Firebase.getString("BOX_STATUS");  
  Serial.println(nx);    
}
