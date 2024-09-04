#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#include "pcgnslib.h"
#include "mpi.h"

#define cgp_doError {printf("Error at %s:%d\n",__FILE__, __LINE__); return 1;}

int main(int argc, char* argv[]) {
  int err, comm_rank, comm_size, fn;

  err = MPI_Init(&argc,&argv);
  if(err!=MPI_SUCCESS) cgp_doError;
  err = MPI_Comm_rank(MPI_COMM_WORLD, &comm_rank);
  if(err!=MPI_SUCCESS) cgp_doError;
  err = MPI_Comm_size(MPI_COMM_WORLD, &comm_size);
  if(err!=MPI_SUCCESS) cgp_doError;

  int sleep_length;
  if (true) sleep_length = comm_rank;
  else sleep_length = -comm_rank + comm_size - 1; // reverse sleep time

  sleep(sleep_length);
  printf("rank: %d, sleep_length: %d\n", comm_rank, sleep_length);
  cgp_mpi_comm(MPI_COMM_WORLD);
  if (cgp_open("test_unstruc_quad.cgns", CG_MODE_WRITE, &fn)) cgp_error_exit();

  if (cgp_close(fn)) cgp_error_exit();

  err = MPI_Finalize();
  if(err!=MPI_SUCCESS) cgp_doError;
 return 0;
}
