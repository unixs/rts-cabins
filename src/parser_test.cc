#include <cstdio>

#include "/Users/alex/Dev/java/rts-parser/src/main/antlr4/samples/cab.cc"

using namespace model;


int main(int argc, char** argv) {
  printf("Parser test.\n");

  auto kon = cab1::sw::KONT1_3;
  auto st = cab1::st::KONT1::DEFAULT;

  cab->Switch(cab2::sw::RED_107, cab2::st::RED::DEFAULT);


  return 0;
}
