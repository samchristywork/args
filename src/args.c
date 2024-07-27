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

void usage(const char *program_name) {
  fprintf(stderr, "Usage: %s [options]\n", program_name);
  fprintf(stderr, "\n");
  fprintf(stderr, "Options:\n");
  for (int i = 0; i < 52; i++) {
    if (args[i].long_name != NULL) {
      fprintf(stderr, "  ");
      fprintf(stderr, "-%c", i < 26 ? 'a' + i : 'A' + i - 26);
      fprintf(stderr, ", ");
      fprintf(stderr, "--%s:", args[i].long_name);
      for (size_t j = 0; j < max_name_len - strlen(args[i].long_name); j++) {
        fprintf(stderr, " ");
      }
      fprintf(stderr, "  %s\n", args[i].description);
    }
  }
  exit(EXIT_FAILURE);
}

void version(const char *versionString, const char *licenseString) {
  printf("%s\n\n%s\n", versionString, licenseString);
}
