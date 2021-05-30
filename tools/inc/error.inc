#!/bin/bash

############
### Functions to catch/display errors during execution
############

warn() {
    local fmt="$1"
    command shift 2>/dev/null
    echo -e "$fmt" > /dev/tty
    echo -e "${@}" > /dev/tty
    echo -e "\n*** ERROR ERROR ERROR ERROR ERROR ***" > /dev/tty
    echo -e "-------------------------------------" > /dev/tty
    echo -e "See above lines for error message." > /dev/tty
    echo -e "Setup NOT completed.\n" > /dev/tty
}

die () {
    local st="$?"
    warn "$@"
    exit "$st"
}

# Check if we were used as an include or called directly,
(return 0 2>/dev/null) || echo "Intended to be used as an include file only."
