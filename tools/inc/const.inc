#!/bin/bash

############
### Include file to set up script constants
############

const() {
    # Set up some project constants
    THISSCRIPT="$(basename "$0")"
    SCRIPTNAME="${THISSCRIPT%%.*}"
    VERSION="$(git describe --tags "$(git rev-list --tags --max-count=1)")"
    GITROOT="$(git rev-parse --show-toplevel)"
    GITURL="$(git config --get remote.origin.url)"
    GITPROJ="$(basename "$GITURL")" && GITPROJ="${GITPROJ%.*}"
    PACKAGE="${GITPROJ^^}"
}

# Check if we were used as an include or called directly,
(return 0 2>/dev/null) || echo "Intended to be used as an include file only."
