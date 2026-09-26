#pragma once
#include <iostream>
#include <string>
using namespace std;
class clsInterfaceCommunication
{
public:
	virtual void SandEmail(string Tital, string Body) = 0;
	virtual void SandFox(string Tital, string Body) = 0;
	virtual void SandSMS(string Tital, string  Body);
};




