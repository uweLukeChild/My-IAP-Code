//
//  IAP.cpp
//  IAPProjectDevelopmentTest1
//
//  Created by Samuel Hunt on 16/07/2018.
//  Copyright (c) 2018 SJHDevelopment. All rights reserved.
//

#include "IAP.h"
#include <iostream>


void IAP::run()

{

  thang.startTimer(200);

  


  while(true)

  {


    aserveSleep(100);

  }

}

void IAP::callbackNoteReceived  (int note, int velocity, int channel){
    if(velocity>0)
    {
        thang.currentNoteFreq = mtof(note + 2);
        aserveOscillator(0, mtof(note), 1.0, 0);
    }
}

