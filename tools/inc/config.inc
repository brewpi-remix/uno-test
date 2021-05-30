#!/bin/bash

############
### Include file to get config file values
### Usage: value="$(getVal $configItem $scriptPath)"
### Arguments: Strings representing:
###               $configItem) Configuration item requested
###               $scriptPath) Script root (will find config in ./settings/\*)
### Return: String value of configuration item
############

# Get location of config file based on brewpi path
getConfigFile() {
    local configPath
    configPath="${1}/settings"
    if [ -f "$configPath/config.cfg" ]; then
        echo "$configPath/config.cfg"
    else
        echo "$configPath/defaults.cfg"
    fi
}

# Get location of default file based on brewpi path
getDefaultFile() {
    local configPath
    configPath="${1}/settings"
    if [ -f "$configPath/defaults.cfg" ]; then
        echo "$configPath/defaults.cfg"
    fi
}

# Raw read of config file
readConfig() {
    local val
    val=$( (grep -E "^${2} = " -m 1 "${1}" 2>/dev/null || echo "VAR = __UNDEFINED__") | head -n 1 | cut -d '=' -f 2-;)
    echo "$val"
}

# Strip leading/trailing spaces and trailing slash
strip() {
    local val
    val=$(echo "${1}" | sed -e 's/^[[:space:]]*//' -e 's/[[:space:]]*$//')
    echo "${val%/}"
}

# Get requested value
getVal() {
    local configFile defConfigFile val configItem configPath
    configItem="${1}"
    configPath="${2}"
    configFile="$(getConfigFile "${configPath}")"
    defConfigFile="$(getDefaultFile "${configPath}")"
    val="$(readConfig "${configFile}" "${configItem}")"
    if [[ "${val}" == *"__UNDEFINED__"* ]]; then
        val="$(readConfig "${defConfigFile}" "${configItem}")"
    fi
    val=$(printf -- "%s" "${val}";)
    # shellcheck disable=SC2005
    echo "$(strip "${val}")"
}

# Check if we were used as an include or called directly,
(return 0 2>/dev/null) || echo "Intended to be used as an include file only."
