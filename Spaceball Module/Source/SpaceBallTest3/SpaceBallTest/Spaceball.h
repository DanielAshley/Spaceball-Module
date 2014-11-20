
#ifndef SPACEBALL_H
#define SPACEBALL_H

#include "WmraTypes.h"

class Spaceball{
public:
	Spaceball();
	WMRA::Pose getDeltaPose();
private:
	//LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM) ;
	int initialize();
};
#endif;