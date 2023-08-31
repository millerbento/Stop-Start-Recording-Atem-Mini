#include <pybind11/pybind11.h>
#include "SwitcherConnection.h"

namespace py = pybind11;

void simpleConsoleLog(const char* message) {
    // Using C standard library for console output
    printf("%s\n", message);
}

PYBIND11_MODULE(switcher, m) {
    m.def("simpleConsoleLog", &simpleConsoleLog, "Simple console log function");
    m.def("ConnectToSwitcher", &ConnectToSwitcher, "Connect to the switcher function");
}
