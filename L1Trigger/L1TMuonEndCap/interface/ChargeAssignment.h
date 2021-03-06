//// Takes in delta phi between all stations 
//// and returns a charge based on this
////
//// Author: M. Carver (UF)
//
// From Andrew Brinkerhoff:
// Mode is a bitword defined by which stations have LCTs in the track.  
// It is defined as 8 x (station 1) + 4 x (station 2) + 2 x (station 3) + 1 x (station 4)
// Modes 11, 13, & 14 all have an LCT in station 1, plus an LCT in two other stations
// Mode 15 has LCTs in all four stations.  
// These are our "SingleMu" quality modes (Quality >= 12) 

#ifndef ADD_ChargeAssignment
#define ADD_ChargeAssignment


int getCharge(int phi1, int phi2, int phi3, int phi4, int mode){
  
  // -1 = postive physical charge to match pdgId code (i.e. -13 is positive, anti-muon). +1 = negative physical charge.
  // Also matches DN-2015/017 format for track finder --> uGMT interface format, where 0 indicates positive, 1 negative.
  int emuCharge = 0;
  int phidiffs[6] = {phi2 - phi1, phi3 - phi1, phi4 - phi1, phi3 - phi2, phi4 - phi2, phi4 - phi3};
  
  if(mode == 15 ){
    if(phidiffs[0] > 0)
      emuCharge = 1;
    else if(phidiffs[0] == 0 && phidiffs[1] < 0)
      emuCharge = 1;
    else if(phidiffs[1] == 0 && phidiffs[2] < 0)
      emuCharge = 1;
    else
      emuCharge = -1;
  }
  
  if(mode == 14){
    if(phidiffs[0] < 0)
      emuCharge = -1;
    else if(phidiffs[0] == 0 && phidiffs[1] < 0)
      emuCharge = -1;
    else
      emuCharge = 1;
  }
  
  if(mode == 13){
    if(phidiffs[0] > 0)
      emuCharge = 1;
    else if(phidiffs[0] == 0 && phidiffs[2] < 0)
      emuCharge = 1;
    else
      emuCharge = -1;
  }
  
  if(mode == 12){
    if(phidiffs[0] > 0)
      emuCharge = 1;
    else
      emuCharge = -1;
  }
  
  if(mode == 11){
    if(phidiffs[1] > 0)
      emuCharge = 1;
    else if(phidiffs[1] == 0 && phidiffs[2] < 0)
      emuCharge = 1;
    else
      emuCharge = -1;
  }
  
  if(mode == 10){
    if(phidiffs[1] > 0)
      emuCharge = 1;
    else
      emuCharge = -1;
  }
  
  if(mode == 9){
    if(phidiffs[2] > 0)
      emuCharge = 1;
    else
      emuCharge = -1;
  }
  
  if(mode == 7){
    if(phidiffs[3] > 0)
      emuCharge = 1;
    else if(phidiffs[3] == 0 && phidiffs[4] < 0)
      emuCharge = 1;
    else
      emuCharge = -1;
  }
  
  if(mode == 6){
    if(phidiffs[3] > 0)
      emuCharge = 1;
    else
      emuCharge = -1;
  }
  
  if(mode == 5){
    if(phidiffs[4] > 0)
      emuCharge = 1;
    else
      emuCharge = -1;
  }
  
  if(mode == 3){
    if(phidiffs[5] > 0)
      emuCharge = 1;
    else
      emuCharge = -1;
  }
  
  int charge = 0;
  if(emuCharge == 1)
    charge = 1;
  
  return charge;
  
}

#endif
