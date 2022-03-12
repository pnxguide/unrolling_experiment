#include <iostream>
#include <chrono>

#define N 1000000

int main() {

  size_t A[N];
  for (size_t i = 0; i < N; i++) {
    A[i] = i;
  }

  size_t start_time = std::chrono::duration_cast<std::chrono::nanoseconds>
    (std::chrono::system_clock::now().time_since_epoch())
    .count();

  size_t sum = 0;

#ifndef UNROLL
  for (size_t i = 0; i < N; i++) {
    sum += A[i];
  }
#else
  for (size_t i = 0; i < N; i += 2) {
    sum += A[i];
    sum += A[i+1];
  }
#endif

  size_t end_time = std::chrono::duration_cast<std::chrono::nanoseconds>
    (std::chrono::system_clock::now().time_since_epoch())
    .count();

  double exec_time_ms = (double)((end_time - start_time) / 1000000.0);
  printf("Sum:  %lu\n", sum);
  printf("Time: %.4f ms\n", exec_time_ms);

  FILE *time_log = fopen("./time.log", "a+");
  if (time_log == NULL) {
    return 0;
  }

#ifdef UNROLL
  fprintf(time_log, "U %.4f\n", exec_time_ms);
#else
  fprintf(time_log, "N %.4f\n", exec_time_ms);
#endif

  fclose(time_log);

  return 0;
}
