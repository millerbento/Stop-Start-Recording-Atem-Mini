## BUILDING THE C++ file (MacOS)
clang++ -I blackmagic_api/mac_os/include/ -framework CoreFoundation blackmagic_api/mac_os/include/BMDSwitcherAPIDispatch.cpp main.cpp RecordingControl.cpp SwitcherConnection.cpp -o Main.out

## RUNNING IT
./Main.out



# (NOT WORKING YET)
## Python module using Pybind11 
mkdir build
cd build
cmake ..
make

