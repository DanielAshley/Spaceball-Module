#include "Spaceball.h"
#include "Arm.h"
#include <Windows.h>
#include <iostream>

using namespace std;

int main()
{
	Arm a;
	a.initialize();

	WMRA::Pose WMRA_pose, Spaceball_pose, Destination_pose;
	Spaceball s;

	float gain = 0.05;
	int rate, comments, count = 50;

	cout << "Comments On? 1=yes 0=no" << endl;
	cin >> comments;

	cout << "Sleep time in milliseconds: ";
	cin >> rate;

	while(count != 0)
	{
		Spaceball_pose = s.getDeltaPose();
		if(comments) cout << "Spaceball Delta:\n\tX: " << Spaceball_pose.x << "\tY: " << Spaceball_pose.y << "\tZ: " << Spaceball_pose.z << "\tPitch: " << Spaceball_pose.pitch << "\tRoll: " << Spaceball_pose.roll << "\tYaw: " << Spaceball_pose.yaw << "\n" << endl;
		
		if(Spaceball_pose.x != 0 || Spaceball_pose.y != 0 || Spaceball_pose.z != 0)
		{
			if(a.isInitialized())
			{
				WMRA_pose = a.getPose();
				if(comments) cout << "WMRA Position:\n\tX: " << WMRA_pose.x << "\tY: " << WMRA_pose.y << "\tZ: " << WMRA_pose.z << "\tPitch: " << WMRA_pose.pitch << "\tRoll: " << WMRA_pose.roll << "\tYaw: " << WMRA_pose.yaw << "\n" << endl;
		
				Destination_pose.x = WMRA_pose.x + (Spaceball_pose.x*gain);
				Destination_pose.y = WMRA_pose.y + (Spaceball_pose.y*gain);
				Destination_pose.z = WMRA_pose.z + (Spaceball_pose.z*gain);
				Destination_pose.pitch = WMRA_pose.pitch + (Spaceball_pose.pitch*gain);
				Destination_pose.roll = WMRA_pose.roll + (Spaceball_pose.roll*gain);
				Destination_pose.yaw = WMRA_pose.yaw + (Spaceball_pose.yaw*gain);
				if(comments) cout << "Destination Position:\n\tX: " << Destination_pose.x << "\tY: " << Destination_pose.y << "\tZ: " << Destination_pose.z << "\tPitch: " << Destination_pose.pitch << "\tRoll: " << Destination_pose.roll << "\tYaw: " << Destination_pose.yaw << "\n" << endl;
		
				//a.teleoperation(Destination_pose, WMRA::ARM_FRAME_PILOT_MODE);
			}
			count --;
		}

		Sleep(rate);
		
	}
	
}