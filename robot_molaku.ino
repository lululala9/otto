#include <Otto.h>
Otto Otto;
#include <PlayRtttl.hpp>


int Gesto = 0;

#define LeftLeg 14 // left leg pin, servo[0] - D5
#define RightLeg 12 // right leg pin, servo[1] -D6
#define LeftFoot 13 // left foot pin, servo[2] - D7
#define RightFoot 15 // right foot pin, servo[3] - D8
#define Buzzer A0 //buzzer pin

double random_int(int a,int b) {
  if (a > b) {
    int c = a;
    a = b;
    b = c;
  }
  return (double) random(a,b+1);
}

void setup() {
  Otto.init(LeftLeg, RightLeg, LeftFoot, RightFoot, true, Buzzer);
Otto.home();

    playRtttlBlockingPGM(13,(char*)TakeOnMe);

}

void loop() {
    Gesto = random_int(1, 15);
    delay(2*1000);
    if (Gesto == 1) {
      Otto.moonwalker(1, 1000, 25, 1);
      Otto.moonwalker(1, 1000, 25, -1);
    }
    if (Gesto == 2) {
      Otto.crusaito(1, 1000, 25, 1);
      Otto.crusaito(1, 1000, 25, -1);
    }
    if (Gesto == 3) {
      Otto.flapping(1, 1000, 25, 1);
      Otto.flapping(1, 1000, 25, -1);
    }
    if (Gesto == 4) {
      Otto.swing(1, 1000, 25);
    }
    if (Gesto == 5) {
      Otto.updown(1, 1000, 25);
    }
    if (Gesto == 6) {
      Otto.tiptoeSwing(1, 1000, 25);
    }
    if (Gesto == 7) {
      Otto.ascendingTurn(1, 1000, 25);
    }
    if (Gesto == 8) {
      Otto.bend(1,1000,1);
    }
    if (Gesto == 9) {
      Otto.bend(1,1000,-1);
    }
    if (Gesto == 10) {
      Otto.jitter(1, 1000, 25);
    }
    if (Gesto == 11) {
      Otto.jump(1,1000);
    }
    if (Gesto == 12) {
      Otto.shakeLeg(1,1000,-1);
    }
    if (Gesto == 13) {
      Otto.shakeLeg(1,1000,1);
    }
    if (Gesto == 14) {
      Otto.walk(1,1000,1); // FORWARD
    }
    if (Gesto == 15) {
      Otto.walk(1,1000,-1); // BACKWARD
    }

}
