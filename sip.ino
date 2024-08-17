#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <Otto.h>

Otto Otto;

#define LeftLeg 14 // left leg pin, servo[0]
#define RightLeg 12 // right leg pin, servo[1]
#define LeftFoot 13 // left foot pin, servo[2]
#define RightFoot 15 // right foot pin, servo[3]
#define Buzzer 3 //buzzer pin

const char* SSID ="daffa4g";
const char* password="";
unsigned int localUdpPort=2222;
char bufferPaket[4];

WiFiUDP espUdp;


void bacaPaketUdp(){
  int ukuranPaket = espUdp.parsePacket();
  if(ukuranPaket){
    int panjang=espUdp.read(bufferPaket,8);
    if(panjang>0){
      bufferPaket[panjang]=0;
    }
    if(String(bufferPaket)=="F"){
      Otto.walk(1,600,-1);
    }
    if(String(bufferPaket)=="B"){
      Otto.walk(1,600,1);
    }
    if(String(bufferPaket)=="R"){
      Otto.turn(2, 600, -1); //1 kiri -1 kanan
      //Otto.moonwalker(1,600,30,1);
    }
    if(String(bufferPaket)=="L"){
      Otto.turn(2, 600, 1); //1 kiri -1 kanan
      //Otto.moonwalker(1,600,30,-1);
    }
  }
}


void setup() {
 Otto.init(LeftLeg, RightLeg, LeftFoot, RightFoot, true, Buzzer);
 Otto.home();
 Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  delay(10);
  WiFi.begin(SSID,password);
  while(WiFi.status()!=WL_CONNECTED){delay(500);}

  espUdp.begin(localUdpPort);


}

void loop(){
 bacaPaketUdp();
}
