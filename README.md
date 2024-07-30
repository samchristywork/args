![Banner](https://s-christy.com/sbs/status-banner.svg?icon=action/terminal&hue=0&title=Args&description=A%20library%20for%20processing%20command%20line%20arguments)

## Features

- Handling of boolean, integer, string, and string list arguments.
- Supports up to 52 arguments, one for each uppercase and lowercase letter.
- Supports long and short descriptions for each argument.
- Sample program to illustrate usage.
- No dependencies.
- Can be built with `gcc -c src/args.c`.
- Automatic creation of a usage/help message.
- Automatic creation of a version message.

## Example Usage

```C
#include <stdio.h>
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
  add_arg('n', "name", "The name to use", ARG_REQUIRED);

  bool helpFlag = get_arg_bool(argc, argv, 'h', false);
  bool versionFlag = get_arg_bool(argc, argv, 'v', false);
  char *nameFlag = get_arg_string(argc, argv, 'n', NULL);

  if (helpFlag) {
    usage(argv[0]);
    exit(EXIT_SUCCESS);
  }

  if (versionFlag) {
    version(VERSION_STRING, LICENSE_STRING);
    exit(EXIT_SUCCESS);
  }

  if (nameFlag) {
    printf("Hello, %s!\n", nameFlag);
  } else {
    printf("Hello, World!\n");
  }
}
```

## License

This work is licensed under the GNU General Public License version 3 (GPLv3).

[<img src="https://s-christy.com/status-banner-service/GPLv3_Logo.svg" width="150" />](https://www.gnu.org/licenses/gpl-3.0.en.html)
