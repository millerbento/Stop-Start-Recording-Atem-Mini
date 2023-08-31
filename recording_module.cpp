#include <pybind11/pybind11.h>
#include "BMDSwitcherAPI.h"
#include "RecordingControl.h"  // Include your custom functions

namespace py = pybind11;

//This module will be exposed to Python using pybind11

PYBIND11_MODULE(recording_module, m) {
    m.doc() = "Recording control module";

    // Wrap StartRecording and StopRecording functions
    m.def("start_recording", &StartRecording, "Start recording");
    m.def("stop_recording", &StopRecording, "Stop recording");
}