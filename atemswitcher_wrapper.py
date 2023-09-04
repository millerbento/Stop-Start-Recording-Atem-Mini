import ctypes

# Load the shared library
lib = ctypes.CDLL('./libatemswitcher.so')  # Update the path if necessary

# Define the function signatures
lib.SwitcherController_new.restype = ctypes.c_void_p
lib.SwitcherController_Run.argtypes = [ctypes.c_void_p]

class SwitcherControllerWrapper:
    def __init__(self):
        self.obj = lib.SwitcherController_new()

    def run(self):
        lib.SwitcherController_Run(self.obj)

if __name__ == "__main__":
    controller = SwitcherControllerWrapper()
    controller.run()