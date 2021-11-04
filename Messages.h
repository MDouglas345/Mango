#ifndef MESSAGES_H
#define MESSAGES_H

#include <string>

struct MInterface{
  unsigned char type : 4;
};

struct MAuthenticate{
  char User[50];
  char Password[100];
};

#endif
