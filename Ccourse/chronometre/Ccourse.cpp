#include "Ccourse.h"

Ccourse::Ccourse()
{
	bool etatCourse = false
}
Ccourse::~Ccourse()
{

}
bool Ccourse::StartCourse()
{
	int i;
	bool etatChrono = true;
	while (i >= 10 && etatChrono == true)
	{
		etatChrono = listParticipant[i].Start();
		i++;
	}
	if (etatChrono == true)
		return true;
	else
		return false;
}
bool Ccourse::StopCourse()
{
	return true;
}
bool Ccourse::showTime(char* temps,int nuParticipant)
{
	return true;
}
bool Ccourse::showBestTime(int nuParticipant)
{
	return true;
}
bool Ccourse::tours(int nuParticipant)
{
	return true;
}
