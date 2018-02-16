# Keyloger-KeyStriker
A linux keyloger.

Hello everyones,

Here is my keylogger called KeyStriker, no installation needed, only few things to know for make it work.

Decompress the archive where you want to, then open a terminal and enter : sudo ./KeyStriker
The log file is in /var/log folder, the file is called KeyStriker.log

If you want at any time see if the keylogger is really running you can enter in a terminal this command : ps -aux | grep KeyStriker, if you see a line like this :

root 3317 0.0 0.0 4364 76 ? Ss 07:29 0:00 KeyStriker

The keylogger is running.

For stop the keylogger use the command : sudo killall KeyStriker

Thanks.
