#include "Spaceball.h"
#include <Windows.h>
#include <iostream>

using namespace std;

int main()
{
	WMRA::Pose p;
	Spaceball s;
	int rate;
	cout << "Sleep time in milliseconds: ";
	cin >> rate;

	while(1)
	{
		p = s.getDeltaPose();
		cout << "X: " << p.x << "\tY: " << p.y << "\tZ: " << p.z << "\tPitch: " << p.pitch << "\tRoll: " << p.roll << "\tYaw: " << p.yaw << "\n" << endl;
		Sleep(rate);
	}
}