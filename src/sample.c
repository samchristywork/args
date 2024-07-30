#include <stdlib.h>

#include "args.h"

#define VERSION_STRING "args-1.0.0"

#define LICENSE_STRING                                                         \
  "Copyright (C) 2024 Sam Christy.\n"                                          \
  "License GPLv3+: GNU GPL version 3 or later "                                \
  "<http://gnu.org/licenses/gpl.html>\n"                                       \
  "\n"                                                                         \
  "This is free software; you are free to change and redistribute it.\n"       \
  "There is NO WARRANTY, to the extent permitted by law."

int main(int argc, char *argv[]) {
  add_arg('h', "help", "Print this help message", ARG_NONE);
  add_arg('v', "version", "Print the version number", ARG_NONE);

  bool helpFlag = get_arg_bool(argc, argv, 'h', false);
  bool versionFlag = get_arg_bool(argc, argv, 'v', false);

  if (helpFlag) {
    usage(argv[0]);
    exit(EXIT_SUCCESS);
  }

  if (versionFlag) {
    version(VERSION_STRING, LICENSE_STRING);
    exit(EXIT_SUCCESS);
  }
}
