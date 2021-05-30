#!/bin/bash

############
### Include file to check network connection
###########

nettest() {
    echo -e "\nChecking for connection to GitHub." > /dev/tty
    declare retval
    wget -q --spider "$GITURL"
    retval="$?"
    if [ "$retval" -ne 0 ]; then
        echo -e "\nError: Could not connect to GitHub.  Please check your network" > /dev/tty
        echo -e "and try again. A connection to GitHub is required to proceed." > /dev/tty
        die
    else
        echo -e "\nConnection to GitHub ok." > /dev/tty
    fi
}

# Check if we were used as an include or called directly,
(return 0 2>/dev/null) || echo "Intended to be used as an include file only."
