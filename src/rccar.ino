/*
 * Project rccar
 * Description: Remote control car with four motors, two on each side, controlled by a Particle Core.
 * Author: nd
 * Date: 2020-02-29
 *
 *  Motor1        Motor3
 *  D0, D1        D2, D3
 *
 *  Motor1        Motor3
 *  D4, D5        D6, D7
 */
#include <blynk.h>

char auth[] = "e80kGWkX8MZv8vrzhI8SRD7EhAKnwYCg";

#define M1A D6
#define M1B D7
#define M2A D5
#define M2B D4
#define M3A D2
#define M3B D3
#define M4A D1
#define M4B D0

void setup() {
  pinMode(M1A, OUTPUT);
  pinMode(M1B, OUTPUT);
  pinMode(M2A, OUTPUT);
  pinMode(M2B, OUTPUT);
  pinMode(M3A, OUTPUT);
  pinMode(M3B, OUTPUT);
  pinMode(M4A, OUTPUT);
  pinMode(M4B, OUTPUT);

  delay(5000); // Allow board to settle

  Blynk.begin(auth);
}

/*
 * Forward and backward.
 */
BLYNK_WRITE(V1) {
  if (param.asInt() == 1) { 
    //Particle.publish("Car", "forward", PRIVATE);
    digitalWrite(M1A, HIGH);
    digitalWrite(M1B, LOW);
    digitalWrite(M2A, HIGH);
    digitalWrite(M2B, LOW);
    digitalWrite(M3A, HIGH);
    digitalWrite(M3B, LOW);
    digitalWrite(M4A, HIGH);
    digitalWrite(M4B, LOW);
  } else if (param.asInt() == -1) { 
    //Particle.publish("Car", "backward", PRIVATE);
    digitalWrite(M1A, LOW);
    digitalWrite(M1B, HIGH);
    digitalWrite(M2A, LOW);
    digitalWrite(M2B, HIGH);
    digitalWrite(M3A, LOW);
    digitalWrite(M3B, HIGH);
    digitalWrite(M4A, LOW);
    digitalWrite(M4B, HIGH);
  } else {
    //Particle.publish("Car", "stopping", PRIVATE);
    digitalWrite(M1A, LOW);
    digitalWrite(M1B, LOW);
    digitalWrite(M2A, LOW);
    digitalWrite(M2B, LOW);
    digitalWrite(M3A, LOW);
    digitalWrite(M3B, LOW);
    digitalWrite(M4A, LOW);
    digitalWrite(M4B, LOW);
  }
}

/*
 * Left and right rotation.
 */
BLYNK_WRITE(V2) {
  if (param.asInt() == 1) { 
    //Particle.publish("Car", "right", PRIVATE);
    digitalWrite(M1A, HIGH);
    digitalWrite(M1B, LOW);
    digitalWrite(M2A, HIGH);
    digitalWrite(M2B, LOW);
    digitalWrite(M3A, LOW);
    digitalWrite(M3B, HIGH);
    digitalWrite(M4A, LOW);
    digitalWrite(M4B, HIGH);
  } else if (param.asInt() == -1) { 
    //Particle.publish("Car", "left", PRIVATE);
    digitalWrite(M1A, LOW);
    digitalWrite(M1B, HIGH);
    digitalWrite(M2A, LOW);
    digitalWrite(M2B, HIGH);
    digitalWrite(M3A, HIGH);
    digitalWrite(M3B, LOW);
    digitalWrite(M4A, HIGH);
    digitalWrite(M4B, LOW);
  } else {
    //Particle.publish("Car", "stopping", PRIVATE);
    digitalWrite(M1A, LOW);
    digitalWrite(M1B, LOW);
    digitalWrite(M2A, LOW);
    digitalWrite(M2B, LOW);
    digitalWrite(M3A, LOW);
    digitalWrite(M3B, LOW);
    digitalWrite(M4A, LOW);
    digitalWrite(M4B, LOW);
  }
}

void loop() {
  Blynk.run();
}
