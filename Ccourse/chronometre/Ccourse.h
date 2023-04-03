#pragma once
#include "CChrono.h"
class Ccourse
{
private :
	CChrono listParticipant[10];
	bool etatCourse;
public :
	Ccourse();
	~Ccourse();
	bool StartCourse();
	bool StopCourse();
	bool showTime(char* temps, int nuParticipant);
	bool showBestTime(int nuParticipant);
	bool tours(int nuParticipant);
};

