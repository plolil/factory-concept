#pragma once
#include <stdio.h>

class open {
public:
  FILE* fd;
  open(char *filename, char *mode) {
    fd = fopen(filename, mode);
  }
  ~open() {
    fclose(fd);
  }
};
