import ctypes

# Load the shared library
recording_control = ctypes.CDLL('./RecordingControl.dylib')  # Update the path to the shared library

# Define the function prototypes
recording_control.StartRecording.argtypes = None
recording_control.StartRecording.restype = ctypes.c_int

recording_control.StopRecording.argtypes = []
recording_control.StopRecording.restype = ctypes.c_int  # HRESULT is an int in C/C++

# Define wrapper functions
def start_recording():
    result = recording_control.StartRecording()
    return result == 0  # Assuming S_OK is 0

def stop_recording():
    result = recording_control.StopRecording()
    return result == 0  # Assuming S_OK is 0

if __name__ == '__main__':
    # Example usage
    if start_recording():
        print("Recording started!")
        # Wait or perform other operations
        if stop_recording():
            print("Recording stopped!")
        else:
            print("Failed to stop recording!")
    else:
        print("Failed to start recording!")
