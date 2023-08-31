#pragma once

//Header file for function prototypes 

#include "BMDSwitcherAPI.h"
#include "SwitcherConnection.h"

HRESULT StartRecording(IBMDSwitcher* switcher);
HRESULT StopRecording(IBMDSwitcher* switcher);