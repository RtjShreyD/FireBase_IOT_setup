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

int n = 0;

void loop() 
{
    
     // set value  
  n=Firebase.getInt("BOX_STATUS");  
  
  // handle error  
  if (n==1) 
  {  
      Serial.println("BOX is OPEN");  
      //digitalWrite(D1,HIGH);  
      Serial.println(Firebase.error());    
      return;  
      delay(100);  
  }  
 else
 {  
      Serial.println("BOX is CLOSE");  
      //digitalWrite(D1,LOW);  
 }  
    
    
    
    
    
    /*// set value
    Firebase.setFloat("number", 42.0);
    
    // handle error
    if (Firebase.failed()) 
    {
        Serial.print("setting /number failed:");
        Serial.println(Firebase.error());  
        return;
    }
    
    delay(1000);
    // update value
    Firebase.setFloat("number", 43.0);
    
    // handle error
    if (Firebase.failed()) 
    {
        Serial.print("setting /number failed:");
        Serial.println(Firebase.error());  
        return;
    }

    delay(1000);

    // get value 
    Serial.print("number: ");
    Serial.println(Firebase.getFloat("number"));
    delay(1000);

    // remove value
    Firebase.remove("number");
    delay(1000);
    // set string value
    Firebase.setString("message", "hello world");

    // handle error
    if (Firebase.failed()) 
    {
        Serial.print("setting /message failed:");
        Serial.println(Firebase.error());  
        return;
    }
    
    delay(1000);
    
    // set bool value
    Firebase.setBool("truth", false);
    
    // handle error
    if (Firebase.failed()) 
    {
        Serial.print("setting /truth failed:");
        Serial.println(Firebase.error());  
        return;
    }
    
    delay(1000);
    
    // append a new value to /logs
    String name = Firebase.pushInt("logs", n++);
    
    // handle error
    if (Firebase.failed()) 
    {
        Serial.print("pushing /logs failed:");
        Serial.println(Firebase.error());  
        return;
    }
    
    Serial.print("pushed: /logs/");
    Serial.println(name);
    
    delay(1000);*/

    
    
}
