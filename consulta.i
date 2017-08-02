/* consulta.i */
%module consulta
%inline%{
/* Put header files here or function declarations like below */
#include <sqlite3.h>
#include "consulta.h"
typedef char tiponombre[40];
typedef char tipoconsulta[100];
extern int Insertar(int id, tiponombre nombrecoche, int precio);
%}
