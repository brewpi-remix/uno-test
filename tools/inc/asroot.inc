#!/bin/bash

############
### Include file to check privilges and permissions
### Will relaunch with sudo if not root/sudo
############

asroot() {
    local retval
    # Check if we have root privs
    if [[ $EUID -ne 0 ]]; then
        sudo -n true 2> /dev/null
        retval="$?"
        if [[ "$retval" == "0" ]]; then
            # If we are not root/sudo, relaunch as such
            echo -e "\nNot running as root, relaunching." > /dev/tty
            sleep 2
            eval "sudo bash $SCRIPTPATH/$THISSCRIPT $@"
            exit $?
        else
            # sudo not available, give instructions
            echo -e "\nThis script must be run as root: sudo $SCRIPTPATH/$THISSCRIPT $@" 1>&2 > /dev/tty
            exit 1
        fi
    fi
    # Get the real user's home directory
    if [ -n "$SUDO_USER" ]; then REALUSER="$SUDO_USER"; else REALUSER=$(whoami); fi
    shadow="$( (getent passwd "$REALUSER") 2>&1)"
    retval="$?"
    if [ "$retval" -eq 0 ]; then
        HOMEPATH="$(echo "$shadow" | cut -d':' -f6)"
    else
        echo -e "\nUnable to retrieve $REALUSER's home directory. Manual install may be necessary." > /dev/tty
        exit 1
    fi
}

# Check if we were used as an include or called directly,
(return 0 2>/dev/null) || echo "Intended to be used as an include file only."
