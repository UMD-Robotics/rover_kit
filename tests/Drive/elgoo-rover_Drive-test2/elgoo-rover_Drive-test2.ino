#include <ElegooRover.h>

void motion();

//Create drive object
Drive drive(9, 8, 7, 6, 10, 5);

unsigned long time(millis());
int cond(0);
int motioninstance(0);
int newinstance(0);

void setup() {
  
}

void loop() {
  //Loop condition
  if ((millis() - time) >= 10){
    cond = 10;
    time = millis();
  }

  switch (cond){
    case 10:
    ++motioninstance;
    motion();
    cond = 0;
    break;
  }
}

void motion(){
  if (motioninstance <= 50){
  drive.move((double)motioninstance / 50, (double)motioninstance / 50);
  }
  else if(motioninstance <= 200){
    drive.move(1, 1);
  }
  else if(motioninstance <= 250){
    drive.move((250 - (double)motioninstance) / 50, (250 - (double)motioninstance) / 50);
  }
  else if (motioninstance <= 350){
    drive.move(0, 0);
  }

  if (motioninstance >350){
    newinstance = motioninstance - 350;
    
    if (newinstance <= 50){
    drive.move((double)newinstance / -50, (double)newinstance / -50);
    }
    else if(newinstance <= 200){
      drive.move(-1, -1);
    }
    else if(newinstance <= 250){
      drive.move(((double)newinstance - 250) / 50, ((double)newinstance - 250) / 50);
    }
    else if (newinstance <= 350){
      drive.move(0, 0);
    }
    else{
    motioninstance = 0;
    }
  }
 
}

