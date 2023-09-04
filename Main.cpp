#include "BMDSwitcherAPI.h"
#include "RecordingControl.h" // Include your custom functions
#include "SwitcherConnection.h" // Include the switcher connection functions
#include <cstdio>
#include <ctime>

class SwitcherController {
public:
    SwitcherController() {}

    int Run() {
        HRESULT result;

        // Use the discovery instance to connect to the switcher
        simpleConsoleLog("Connecting to switcher...");
        IBMDSwitcher* switcher;
        BMDSwitcherConnectToFailure connectToFailReason;

        // Call the ConnectToSwitcher function to establish the connection
        result = ConnectToSwitcher(switcher, connectToFailReason);

        if (result != S_OK) {
            simpleConsoleLog("Failed to connect to switcher! :/");
            return 1;
        } else {
            simpleConsoleLog("Connected to switcher! :)");

            // Start recording
            result = StartRecording(switcher);
            if (result == S_OK) {
                simpleConsoleLog("Recording started!");

                // Wait for 10 seconds (using C standard library)
                time_t startTime = time(nullptr);
                while (difftime(time(nullptr), startTime) < 10.0) {
                    // Waiting...
                }

                // Stop recording
                result = StopRecording(switcher);
                if (result == S_OK) {
                    simpleConsoleLog("Recording stopped!");
                } else {
                    simpleConsoleLog("Failed to stop recording!");
                }
            } else {
                simpleConsoleLog("Failed to start recording!");
            }

            // Don't forget to release the switcher interface and perform necessary cleanup.
            switcher->Release();

            return 0;
        }
    }
};

int main() {
    SwitcherController controller;
    return controller.Run();
}

// Since ctypes can only talk to C functions, we need to provide those declaring them as extern "C"
extern "C" {
    SwitcherController* SwitcherController_new() { return new SwitcherController(); }
    void SwitcherController_Run(SwitcherController* SwitcherController) { SwitcherController->Run(); }
}
