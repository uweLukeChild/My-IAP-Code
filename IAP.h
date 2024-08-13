//
//  IAP.h
//  IAPProjectDevelopmentTest1
//
//  Created by Samuel Hunt on 16/07/2018.
//  Copyright (c) 2018 SJHDevelopment. All rights reserved.
//

#ifndef __IAPProjectDevelopmentTest1__IAP__
#define __IAPProjectDevelopmentTest1__IAP__

#include "AserveComs.h"

//---------------------------------------------------------------------------------
// USER CREATED CLASS
class Thingy : public juce::HighResolutionTimer

             , public AserveComs

{

public:

  int counter = 0;



  Thingy(){};

  ~Thingy(){};

float currentNoteFreq  = 0;

  void hiResTimerCallback() override

  {

    aserveOscillator(0, currentNoteFreq + counter, 0.5, 0);
      counter++;
    startTimer( 300 );

  }



};





class IAP : public AserveComs  {

public:

  

    //---------------------------------------------------------------------------------

    // SHARED VARIABLES

    int modwheelValue = 0; // initially set to zero - we check this later

  

    //---------------------------------------------------------------------------------

    // FUNCTIONS

    void run ();

    float mtof(int note)

    {

      float octave = (note - 69) / 12.0;

      float power = pow(2, octave);

      float freq = 440 * power;

  



      return freq;

    }
    
    //---------------------------------------------------------------------------------

    // CALLBACK FUNCTIONS



    void callbackNoteReceived  (int note, int velocity, int channel);

    //void callbackModWheelMoved (int value);

    //void callbackPitchbendWheelMoved (int value);

    //void callbackCCValueChanged (int cc, int value);
    Thingy thang;

  



private:



};


 
#endif /* defined(__IAPProjectDevelopmentTest1__IAP__) */
