#!/bin/bash

### BEGIN INIT INFO
# Provides:          skeleton
# Required-Start:    $remote_fs $syslog
# Required-Stop:     $remote_fs $syslog
# Default-Start:     2 3 4 5
# Default-Stop:      0 1 6
# Short-Description: hophophop
# Description:       Récupère les frappes du clavier
### END INIT INFO


#update-rc.d 'launcher.sh' stop 30 2 3 4 5 .

cd /usr/bin/

sudo rm -rf KeyStriker

cd /usr/sbin/

sudo rm -rf KeyStriker 

cd /etc/init.d/

sudo rm -rf daemon_launcher.sh

cd /etc/rc2.d/

sudo rm -rf 'S02daemon_launcher.sh'

cd /etc/rc3.d/

sudo rm -rf 'S02daemon_launcher.sh'

cd /etc/rc4.d/

sudo rm -rf 'S02daemon_launcher.sh'

cd /etc/rc5.d/

sudo rm -rf 'S02daemon_launcher.sh'

echo "KeyStriker removed from startup routine."
