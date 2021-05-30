#!/bin/bash

############
### Include file for --help and --version functionality
############

# Outputs to stdout the --help usage message.
usage() {
    echo -e "\n$SCRIPTNAME usage: sudo $SCRIPTPATH/$THISSCRIPT"
}

# Outputs to stdout the --version message.
version() {
cat << EOF

"$SCRIPTNAME" Copyright (C) 2021 Lee C. Bussy (@LBussy)

This program comes with ABSOLUTELY NO WARRANTY.

This is free software, and you are welcome to redistribute it
under certain conditions.

There is NO WARRANTY, to the extent permitted by law.
EOF
}

# Processes help/version arguments
help() {
    declare arg
    arg="$1"
    if [ -n "$arg" ]; then
        arg="${arg//-}" # Strip out all dashes
        if [[ "$arg" == "r"* ]]; then REINSTALL=1; fi
        if [[ "$arg" == "h"* ]]; then usage; exit 0; fi
        if [[ "$arg" == "v"* ]]; then version; exit 0; fi
    fi
}

# Check if we were used as an include or called directly,
(return 0 2>/dev/null) || echo "Intended to be used as an include file only."
