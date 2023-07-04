from modules.connectToAtem import connectToAtem

switcherConnected = connectToAtem()

if switcherConnected:
    isRecording = switcherConnected.macro.recordingStatus.isRecording
    if isRecording:
        switcherConnected.execMacroStopRecording()
    else:
        switcherConnected.execMacroRecord()
else:
    print('The system cannot connect to the Atem')