#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "args.h"

Arg args[52] = {0};
int max_name_len = 0;

void add_arg(char short_name, const char *long_name, const char *description,
             FLAG flags) {
  int len = strlen(long_name);
  if (len > max_name_len) {
    max_name_len = len;
  }
  if (short_name >= 'a' && short_name <= 'z') {
    args[short_name - 'a'] = (Arg){long_name, description, flags};
  } else if (short_name >= 'A' && short_name <= 'Z') {
    args[short_name - 'A' + 26] = (Arg){long_name, description, flags};
  } else {
    fprintf(stderr, "Invalid short name: %c\n", short_name);
    exit(EXIT_FAILURE);
  }
}
