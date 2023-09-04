#include "BMDSwitcherAPI.h"
#include "RecordingControl.h" // Include your custom functions
#include "SwitcherConnection.h" // Include the switcher connection functions
#include <cstdio>
#include <ctime>
#include <cstring> // Include for strcmp

class SwitcherController {
private:
    IBMDSwitcher* switcher;

    HRESULT ConnectToSwitcher() {
        BMDSwitcherConnectToFailure connectToFailReason;
        return ::ConnectToSwitcher(switcher, connectToFailReason);
    }

public:
    SwitcherController() : switcher(nullptr) {}

    ~SwitcherController() {
        if (switcher) {
            switcher->Release();
            switcher = nullptr;
        }
    }

    int Run() {
        HRESULT result;

        // Use the discovery instance to connect to the switcher
        simpleConsoleLog("Connecting to switcher...");

        // Call the ConnectToSwitcher function to establish the connection
        result = ConnectToSwitcher();

        if (result != S_OK) {
            simpleConsoleLog("Failed to connect to switcher! :/");
            return 1;
        } else {
            simpleConsoleLog("Connected to switcher! :)");

            // Start recording
            result = StartRecording();
            if (result == S_OK) {
                simpleConsoleLog("Recording started!");

                // Wait for 10 seconds (using C standard library)
                time_t startTime = time(nullptr);
                while (difftime(time(nullptr), startTime) < 10.0) {
                    // Waiting...
                }

                // Stop recording
                result = StopRecording();
                if (result == S_OK) {
                    simpleConsoleLog("Recording stopped!");
                } else {
                    simpleConsoleLog("Failed to stop recording!");
                }
            } else {
                simpleConsoleLog("Failed to start recording!");
            }

            return 0;
        }
    }

    HRESULT StartRecording() {
        // Connect to the switcher if not already connected
        if (!switcher) {
            HRESULT connectResult = ConnectToSwitcher();
            if (connectResult != S_OK) {
                return connectResult;
            }
        }

        return ::StartRecording(switcher);
    }

    HRESULT StopRecording() {
        // Connect to the switcher if not already connected
        if (!switcher) {
            HRESULT connectResult = ConnectToSwitcher();
            if (connectResult != S_OK) {
                return connectResult;
            }
        }

        return ::StopRecording(switcher);
    }
};

int main() {
    SwitcherController controller;
    return controller.Run();
}

// Declare the StartRecording and StopRecording functions as extern "C" to expose them to C
extern "C" {
    SwitcherController* SwitcherController_new() { return new SwitcherController(); }
    void SwitcherController_Run(SwitcherController* SwitcherController) { SwitcherController->Run(); }
    HRESULT SwitcherController_StartRecording(SwitcherController* controller) {
        return controller->StartRecording();
    }
    HRESULT SwitcherController_StopRecording(SwitcherController* controller) {
        return controller->StopRecording();
    }
}