from modules.connectToAtem import connectToAtem

def startAndStopRecording(action):
    message = ''
    switcherConnected = connectToAtem()

    if switcherConnected:
        if action == 'startRecording':
            switcherConnected.setMacroAction('macro1','runMacro') #macro1 starts recording
            message = 'recording started'
        elif action == 'stopRecording':    
            switcherConnected.setMacroAction('macro2','runMacro') #macro2 stops recording
            message = 'recording stopped'
        else:
            message = 'invalid option. Use startRecording or stopRecording'
    else:
        message = 'The system cannot connect to the Atem'

    return message