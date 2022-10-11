#include "common.h"
#include "chunk.h"
#include "debug.h"

/*
 * search for that part and keep going through the book.
 * There’s more going on here. As with OP_RETURN, we print out the name of the opcode. Then we pull out the constant index from the subsequent byte in the chunk. We print that index, but that isn’t super useful to us human readers. So we also look up the actual constant value—since constants are known at compile time after all—and display the value itself too.

This requires some way to print a clox Value. That function will live in the “value” module, so we include that.
 */
int main(int argc, const char* argv[]) {
  Chunk chunk;
  initChunk(&chunk);

  int constant = addConstants(&chunk, 1.2);
  writeChunk(&chunk, OP_CONSTANT, 123);
  writeChunk(&chunk, constant, 123);


  writeChunk(&chunk, OP_RETURN, 123);
  disassembleChunk(&chunk, "test chunk");
  freeChunk(&chunk);
  return 0;
}
