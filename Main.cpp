#include "BMDSwitcherAPI.h"
#include "RecordingControl.h" // Include your custom functions
#include "SwitcherConnection.h" // Include the switcher connection functions
#include <cstdio>
#include <ctime>

int main() {
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









//ONE FILE EXAMPLE
// #include "BMDSwitcherAPI.h"
// #include <iostream>
// #include <chrono>
// #include <thread>

// // IP Address
// static const CFStringRef ip_address = CFSTR("192.168.1.81");

// int main() {
//     HRESULT result;

//     // Create discovery instance
//     IBMDSwitcherDiscovery* discovery = CreateBMDSwitcherDiscoveryInstance();
//     if (!discovery) {
//         std::cerr << "Failed to create IBMDSwitcherDiscovery!" << std::endl;
//         return 1;
//     }

//     // Use the discovery instance to connect to the switcher
//     std::cout << "Connecting to switcher..." << std::endl;
//     IBMDSwitcher* switcher;
//     BMDSwitcherConnectToFailure connectToFailReason;
//     result = discovery->ConnectTo(ip_address, &switcher, &connectToFailReason);
//     discovery->Release();
//     if (result != S_OK) {
//         std::cerr << "Failed to connect to switcher! :/" << std::endl;
//         return 1;
//     } else {
//         std::cout << "Connected to switcher! :)" << std::endl;

//         // The IBMDSwitcherRecordAV object interface provides functionality to start and 
//         // stop recording of video and audio to externally connected disks.        

//         // Check if ISO recording is supported
//         IBMDSwitcherRecordAV* recordAV = nullptr;
//         result = switcher->QueryInterface(IID_IBMDSwitcherRecordAV, (void**)&recordAV);

//         if (result == S_OK && recordAV) {
//             Boolean supportsISORecording = false;
//             result = recordAV->DoesSupportISORecording(reinterpret_cast<bool*>(&supportsISORecording));

//             if (result == S_OK && supportsISORecording) {
//                 std::cout << "ISO recording is supported!" << std::endl;

//                 // Start recording
//                 result = recordAV->StartRecording();
//                 if (result == S_OK) {
//                     std::cout << "Recording started!" << std::endl;

//                     // Wait for 10 seconds
//                     std::this_thread::sleep_for(std::chrono::seconds(10));

//                     // Stop recording
//                     result = recordAV->StopRecording();
//                     if (result == S_OK) {
//                         std::cout << "Recording stopped!" << std::endl;
//                     } else {
//                         std::cerr << "Failed to stop recording!" << std::endl;
//                     }
//                 } else {
//                     std::cerr << "Failed to start recording!" << std::endl;
//                 }
//             } else {
//                 std::cout << "ISO recording is not supported." << std::endl;
//             }

//             // Release the recordAV interface
//             recordAV->Release();
//         } else {
//             std::cerr << "Failed to obtain IBMDSwitcherRecordAV interface!" << std::endl;
//         }

//         // Don't forget to release the switcher interface and perform necessary cleanup.
//         switcher->Release();

//         return 0;
//     }
// }


// // // BUILDING THE C++ file
// // // clang++ -I blackmagic_api/mac_os/include/ -framework CoreFoundation blackmagic_api/mac_os/include/BMDSwitcherAPIDispatch.cpp main.cpp -o Main.out

// // // RUNNING IT
// // // ./Main.out