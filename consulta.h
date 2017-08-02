/*=========================================================
Ejemplo de Wrapper para Python de Libreria que realiza un INSERT 
a una tabla (Cars) base de datos (test.db) SQLite 

Autor: Bartolome Vich Lozano
Email: amadews23@hotmail.com

===========================================================*/

#pragma once

typedef char tiponombre[40];

int Insertar(int id, tiponombre nombrecoche, int precio);
