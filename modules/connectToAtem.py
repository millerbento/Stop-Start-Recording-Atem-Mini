import PyATEMMax
from configparser import ConfigParser

def connectToAtem():
    configfile = 'config.ini'
    config = ConfigParser()
    config.read(configfile)
    atem = config['paths']['AtemIPAddress'] 

    switcher = PyATEMMax.ATEMMax()
    switcher.connect(atem)
    connected = switcher.waitForConnection(timeout=5)    

    if connected:
        return switcher
    else:
        return False
