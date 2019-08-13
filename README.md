# Example-SQLite-Wrapper-for-Python
We create a wrapper  from c code (with Swig) to test an INSERT from Python


THESE ARE THE STEPS TO COMPILE AND CREATE WRAPPER:

```swig -python consulta.i ```

```gcc -c consulta.c consulta_wrap.c -lsqlite3 -I /usr/include/python2.7 -fPIC```

```ld -shared consulta.o consulta_wrap.o -lsqlite3 -o _consulta.so```

EXAMPLE TO USE (in the python console):

```import consulta

consulta.Insertar(2, "Cadillac", 10000)```
