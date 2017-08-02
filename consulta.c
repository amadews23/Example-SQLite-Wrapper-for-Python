#include <sqlite3.h>
#include <stdio.h>
#include <string.h>
#include "consulta.h"
#include <stdlib.h>

/*=========================================================
Ejemplo de Wrapper para Python de Libreria que realiza un INSERT 
a una tabla (Cars) base de datos (test.db) SQLite 

Autor: Bartolome Vich Lozano
Email: amadews23@hotmail.com

===========================================================*/


int Insertar(int id, tiponombre nombrecoche, int precio) {

    int tamanyonombre ;
    //medimos el tamanyo de nombrecoche
    tamanyonombre = strlen(nombrecoche);
    printf("tamanyo nombrecoche %d\n",tamanyonombre);
    char *sql;
    //reservamos para el puntero sql 43+tamanyocoche 
    sql = (char *) malloc((43+tamanyonombre)* sizeof(char));
    sqlite3 *db;
    char *err_msg = 0;  

    if (NULL == sql) {
    /* gestión del error en la asignación… */

	return 2;

    }

    int rc = sqlite3_open("test.db", &db);
    
    if (rc != SQLITE_OK) {
        
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        
        return 1;
    }

    //Insertamos en en un string (ConsultA) los valores recibidos en la funcion
    sprintf(sql, "INSERT INTO Cars values ('%d', '%s', '%d');", id, nombrecoche, precio);
    //ejecutamos la consultA que viene de un string sql sql
    rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    
    if (rc != SQLITE_OK ) {
        
        fprintf(stderr, "SQL error: %s\n", err_msg);
        
        sqlite3_free(err_msg);        
        sqlite3_close(db);
        
        return 1;
    } 
    
    sqlite3_close(db);
    free(sql);
    sql = NULL;
    return 0;

}


