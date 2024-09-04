Need to set `CGNSLIB` and `CGNSINCLUDE` variables before loading.
Default behavior is to use `$PETSC_DIR` and `$PETSC_ARCH` to determine these locations, but they can be overridden.
May also need to export the appropriate `CC` value (should be `mpicc`).

So:
```
export PETSC_DIR=../ PETSC_ARCH=arch-dev CC=mpicc
make
```
