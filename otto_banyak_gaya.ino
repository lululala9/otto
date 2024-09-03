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
char bufferPaket[20];
String perintah;
WiFiUDP espUdp;

String j[]={"F","B","L","R","bL","bR","sL","sR"};
String jg[]={"moonL","moonR","crusL","crusR","flapL","flapR"};
String gest[]={"senang1","senang2","sedih","tidur","bingung","resah","cinta","marah","magic","wave","menang","gagal","kentut"};

void bacaPaketUdp(){
  int ukuranPaket = espUdp.parsePacket();
  if(ukuranPaket){
    int panjang=espUdp.read(bufferPaket,20);
    if(panjang>0){
      bufferPaket[panjang]=0;
    }
     perintah = String(bufferPaket);
  }
}
void jalan(){
  if (perintah==j[0]) {
    Otto.walk(1,1000,1); // FORWARD
  } else if (perintah==j[1]) {
    Otto.walk(1,1000,-1); // BACKWARD
  } else if (perintah==j[2]) {
    Otto.turn(1,1000,1); // LEFT
  } else if (perintah==j[3]) {
    Otto.turn(1,1000,-1); // RIGHT
  } else if (perintah==j[4]) {
    Otto.bend(1,1000,1);
  } else if (perintah==j[5]) {
    Otto.bend(1,1000,-1);
  } else if (perintah==j[6]) {
    Otto.shakeLeg(1,1000,-1);
  } else if (perintah==j[7]) {
    Otto.shakeLeg(1,1000,1);
  }

}

void joged(){
  if (perintah==jg[0]) {
    Otto.moonwalker(1, 1000, 25, 1);
  } else if (perintah==jg[1]) {
    Otto.moonwalker(1, 1000, 25, -1);
  } else if (perintah==jg[2]) {
    Otto.crusaito(1, 1000, 25, 1);
  } else if (perintah==jg[3]) {
    Otto.crusaito(1, 1000, 25, -1);
  } else if (perintah==jg[4]) {
    Otto.flapping(1, 1000, 25, 1);
  } else if (perintah==jg[5]) {
    Otto.flapping(1, 1000, 25, -1);
  }
}

void gestur(){
  if (perintah==gest[0]) {
    Otto.playGesture(OttoSuperHappy);
  } else if (perintah==gest[1]) {
    Otto.playGesture(OttoHappy);
  } else if (perintah==gest[2]) {
    Otto.playGesture(OttoSad);
  } else if (perintah==gest[3]) {
    Otto.playGesture(OttoSleeping);
  } else if (perintah==gest[4]) {
    Otto.playGesture(OttoConfused);
  } else if (perintah==gest[5]) {
    Otto.playGesture(OttoFretful);
  } else if (perintah==gest[6]) {
    Otto.playGesture(OttoLove);
  } else if (perintah==gest[7]) {
    Otto.playGesture(OttoAngry);
  } else if (perintah==gest[8]) {
    Otto.playGesture(OttoMagic);
  } else if (perintah==gest[9]) {
    Otto.playGesture(OttoWave);
  } else if (perintah==gest[10]) {
    Otto.playGesture(OttoVictory);
  } else if (perintah==gest[11]) {
    Otto.playGesture(OttoFail);
  } else if (perintah==gest[12]) {
    Otto.playGesture(OttoFart);
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
  jalan();
  joged();
  gestur();
}