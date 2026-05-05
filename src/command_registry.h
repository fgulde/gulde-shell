#ifndef COMMAND_REGISTRY_H
#define COMMAND_REGISTRY_H

#include "command.h"

/**
 * Finds a command by its name.
 *
 * @param command_name The name of the command to find.
 * @return A pointer to the Command struct if found, or NULL if not found.
 */
const Command* find_command(const char* command_name);

#endif