#include "utils.h"
#include "checker.h"

#include <fstream>
#include <iostream>

int main(int argc, const char **argv) {
  if (argc != 3) {
    std::cerr << "Usage: " << argv[0] << " input_file solution_file\n";
    exit(1);
  }

  // Read input
  InputData data = ReadInput(argv[1]);
  SolutionType solution = ReadSolution(argv[2]);

  // Evaluate
  std::cout << Evaluate(data, solution) << "\n";
  return 0;
}
