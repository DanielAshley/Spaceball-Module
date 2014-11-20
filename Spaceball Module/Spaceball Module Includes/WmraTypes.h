#ifndef WMRATYPES_H
#define WMRATYPES_H

/**
This file contains declarations of data types used by the WMRA program

Written by Indika Pathirage
Distributed under GPL2 or higher

**/
#include <string>
#include <vector>
#include <sstream> 
#include "matrix.h"

using namespace math;
#define PI 3.14159265

#ifndef _NO_TEMPLATE
typedef matrix<double> Matrix;
#else
typedef matrix Matrix;
#endif

namespace WMRA{

   enum CordFrame { ARM_FRAME_ABS=0, ARM_FRAME_REL=1, GRIPPER_FRAME_REL=2, ARM_FRAME_PILOT_MODE=3}; 

   struct KinematicData{
      Matrix T01;
      Matrix T12;
      Matrix T23;
      Matrix T34;
      Matrix T45;
      Matrix T56;
      Matrix T67;
      Matrix Tfinal;
   };

   class Pose{
   public:
      int x;
      int y;
      int z;
      double yaw;
      double pitch;
      double roll;    
      Pose(int _x =0, int _y =0, int _z=0, double _yaw=0, double _pitch=0, double _roll=0){
         x = _x; y = _y; z = _z; pitch = _pitch; yaw = _yaw ; roll = _roll;
      }
      bool clear(){
         x = 0; y =0; z=0; yaw=0; pitch=0; roll=0;
         return true;
      }
   };

   struct WheelChairPose{
      int x,y;
      double angle;
      matrix<double> transformation;
   };

   class JointValueSet{
   public:
      vector<double> Joint;
      JointValueSet(){
         Joint.resize(7);
      }
      int size(){
         return (int)Joint.size();
      }
      double& operator[](int i){
         if(i < Joint.size())  return Joint[i];
      }
      std::string toString(){
         std::stringstream ss;
         //add the firat n-1 elements with a comma
         for(int i = 0 ; i < 6 ; ++i){
            ss << Joint[i] << "," ;
         }
         ss << Joint[6]; // add the last element witjout a comma
         return ss.str();
      }
   };

   

}
#endif;
