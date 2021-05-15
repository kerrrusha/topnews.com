#pragma once
#include "MessageType.h"
#include <string>

class Alerts
{
public:
	static void make(MessageType code);
	static void make(MessageType code, std::string name);
};