#include "server_Server.h"
int main(int argc, char *argv[]) {
  if (argc < 4)
    return 1;
  RealSIU realSiu(argv[2], argv[3]);
  MonitorSiu siu(realSiu);
  Server server(argv[1], siu);
  server.start();
  while (getc(stdin) != 'q') {}
  server.stop();
  server.join();
}
