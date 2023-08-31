#include "RecordingControl.h"
#include <iostream>
#include <chrono>
#include <thread>

HRESULT StartRecording(IBMDSwitcher* switcher) {
    HRESULT result;

    // Check if ISO recording is supported
    IBMDSwitcherRecordAV* recordAV = nullptr;
    result = switcher->QueryInterface(IID_IBMDSwitcherRecordAV, (void**)&recordAV);

    if (result == S_OK && recordAV) {
        Boolean supportsISORecording = false;
        result = recordAV->DoesSupportISORecording(reinterpret_cast<bool*>(&supportsISORecording));

        if (result == S_OK && supportsISORecording) {
            std::cout << "ISO recording is supported!" << std::endl;

            // Start recording
            result = recordAV->StartRecording();
            if (result == S_OK) {
                //std::cout << "Recording started!" << std::endl;
                return S_OK;
            } else {
                std::cerr << "Failed to start recording!" << std::endl;
            }
        } else {
            std::cout << "ISO recording is not supported." << std::endl;
        }

        // Release the recordAV interface
        recordAV->Release();
    } else {
        std::cerr << "Failed to obtain IBMDSwitcherRecordAV interface!" << std::endl;
    }

    return result;
}

HRESULT StopRecording(IBMDSwitcher* switcher) {
    HRESULT result;

    // Check if ISO recording is supported
    IBMDSwitcherRecordAV* recordAV = nullptr;
    result = switcher->QueryInterface(IID_IBMDSwitcherRecordAV, (void**)&recordAV);

    if (result == S_OK && recordAV) {
        // Stop recording
        result = recordAV->StopRecording();
        if (result == S_OK) {
            //std::cout << "Recording stopped!" << std::endl;
            return S_OK;
        } else {
            std::cerr << "Failed to stop recording!" << std::endl;
        }

        // Release the recordAV interface
        recordAV->Release();
    } else {
        std::cerr << "Failed to obtain IBMDSwitcherRecordAV interface!" << std::endl;
    }

    return result;
}
