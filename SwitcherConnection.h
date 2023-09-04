#pragma once

#include "BMDSwitcherAPI.h"

// IP Address
static const CFStringRef ip_address = CFSTR("192.168.1.200");

void simpleConsoleLog(const char* message);

HRESULT ConnectToSwitcher(IBMDSwitcher*& switcher, BMDSwitcherConnectToFailure& connectToFailReason);
