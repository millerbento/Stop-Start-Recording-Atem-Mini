# Start and stop recording ATEM MINI using Python

# Testing the C++ call
## BUILDING THE C++ file (MacOS)
g++ -I blackmagic_api/mac_os/include/ -framework CoreFoundation blackmagic_api/mac_os/include/BMDSwitcherAPIDispatch.cpp main.cpp RecordingControl.cpp SwitcherConnection.cpp -o Main.o

## RUNNING IT
./Main.o

# Now calling it using Python

The offical Black Magic Library is written in C++ so we need to create a Python wrapper to be able to call it (I'm using CTYPES to do it)

## Compiling it to a shared library

g++ -I blackmagic_api/mac_os/include/ -framework CoreFoundation -shared -fPIC \
    blackmagic_api/mac_os/include/BMDSwitcherAPIDispatch.cpp \
    Main.cpp RecordingControl.cpp SwitcherConnection.cpp -o libatemswitcher.so

<!-- If you intend to create a shared library from your C++ source code, the recommended approach is to compile your code directly into a shared library, rather than trying to convert an existing executable. Here's how you can do it: -->

# Running it using Python

Simply open atemswitcher_wrapper.py and run it