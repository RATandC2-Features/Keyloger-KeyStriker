# Keyloger-KeyStriker
A linux keyloger.

Compile the source with code blocks IDE or from src folder and linux command line : gcc main.c keylogger.c utils.c -o KeyStriker

Then for launch the keyloger use the command : sudo ./KeyStriker

The log keys are in /var/log/KeyStriker.log

For see at any time if the keyloger is running use the command : ps -aux | grep KeyStriker, if you see a line like this : 

root      6727  0.0  0.0   4380    76 ?        Ss   03:26   0:00 ./KeyStriker

The keylogger is running.

For stop the keyloger use the command : sudo killall KeyStriker

Thanks.
