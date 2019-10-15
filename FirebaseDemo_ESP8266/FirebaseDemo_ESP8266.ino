#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <string.h>
#include <stdlib.h>

#define FIREBASE_HOST "restsvr.firebaseio.com" //firebase end point
#define FIREBASE_AUTH "DAyn8zLBXmBecOYEZue81VirzEd3upyRukT23ghG" //secret key for authentication

#define WIFI_SSID "Tech_D3882400"  
#define WIFI_PASSWORD "TAQAHYWG"

//#define WIFI_SSID "Morphedo -2.4GHz"
//#define WIFI_PASSWORD "82$morph"

//Global Variables block//
char sub_str[15], box_id[5], odr_id[5], charBuf[10];
String nx = "";

//******** Global Variables block end ********//

//Custom functions block//
void str_slice(char string[], int pos, int len)  //to slice a string from in betwn//pos starts from 1 and len is no of chars from pos including pos itself
{
  int c = 0;
  while (c < len) 
  {
      sub_str[c] = string[pos+c-1];
      c++;
    }
   sub_str[c] = '\0';
}
//*******Custom functions block end********//


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

    Firebase.set("BOX_STATUS","!101:3980:1@");  //saved 
} 

//str_slice(res_data, 12,3);  //from 12th char 3 chars

void loop() 
{  

  // GET value  
  nx=Firebase.getString("BOX_STATUS"); 
  nx.toCharArray(charBuf, 50);
  str_slice(charBuf, 2,4);
  strcpy(box_id, sub_str);
  Serial.println(box_id);  
  delay(1000);
  memset(sub_str,0,strlen(sub_str));
  memset(box_id,0,strlen(box_id));
  delay(1000);

}          
