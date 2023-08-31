#include "SwitcherConnection.h"

void simpleConsoleLog(const char* message) {
    // Using C standard library for console output
    printf("%s\n", message);
}

HRESULT ConnectToSwitcher(IBMDSwitcher*& switcher, BMDSwitcherConnectToFailure& connectToFailReason) {
    HRESULT result;

    // Create discovery instance
    IBMDSwitcherDiscovery* discovery = CreateBMDSwitcherDiscoveryInstance();
    if (!discovery) {
        simpleConsoleLog("Failed to create IBMDSwitcherDiscovery!");
        return E_FAIL;
    }

    // Use the discovery instance to connect to the switcher
    //simpleConsoleLog("Connecting to switcher...");
    result = discovery->ConnectTo(ip_address, &switcher, &connectToFailReason);
    discovery->Release();
    if (result != S_OK) {
        //simpleConsoleLog("Failed to connect to switcher! :/");
        return result;
    } else {
        //simpleConsoleLog("Connected to switcher! :)");
        return S_OK;
    }
}