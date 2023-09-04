import ctypes

# Load the shared library
lib = ctypes.CDLL('./libatemswitcher.so')  # Update the path if necessary

# Define the function signatures
lib.SwitcherController_new.restype = ctypes.c_void_p
lib.SwitcherController_Run.argtypes = [ctypes.c_void_p]
lib.SwitcherController_StartRecording.argtypes = [ctypes.c_void_p]
lib.SwitcherController_StopRecording.argtypes = [ctypes.c_void_p]

class SwitcherControllerWrapper:
    def __init__(self):
        self.obj = lib.SwitcherController_new()

    def run(self):
        lib.SwitcherController_Run(self.obj)

    def start_recording(self):
        lib.SwitcherController_StartRecording(self.obj)

    def stop_recording(self):
        lib.SwitcherController_StopRecording(self.obj)

if __name__ == "__main__":
    controller = SwitcherControllerWrapper()
    controller.start_recording()  # Start recording
    controller.stop_recording()  # Stop recording
    #controller.run()  # Run the main function (records for 10 seconds and then stops)
