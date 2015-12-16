//============================================================================
// Name        : SendMatrixToBusiness.cpp
// Author      : IFREBAULT
// Version     :
// Copyright   : 
// Description : C++ project
//============================================================================
#include <iostream>
#include <vector>

#include "my_global.h"
#include "mysql.h"
#define SERVER "127.0.0.1"
#define USER "root"
#define PASSWORD ""
#define DATABASE "classrecognition"

using namespace std;

vector<string> getNames(){
    //intitialisation
    vector<string> names;
    //conexion à la base
    MYSQL *connect;
    connect=mysql_init(NULL);
    if(!connect){
        fprintf(stderr,"MySQL Initialization Failed");
    }
    connect=mysql_real_connect(connect,SERVER,USER,PASSWORD,DATABASE,0,NULL,0);
    if(!connect){
    printf("Connection Failed!\n");
    }
    MYSQL_ROW row;
    MYSQL_RES *result = NULL;
    
    //création de la requête
    string selectName = "SELECT fileName FROM pictures ";
    mysql_query(connect, selectName.c_str());
    result = mysql_store_result(connect);
    row = mysql_fetch_row(result);
    for (int i=0; i<row.size(), i=i+1){
    names.push_back("../../OpenCVProject/BDDjpg/" + to_string(row[i]));
    }
	
    return names;
}

vector<int> getIds(){
    //intitialisation
    vector<int> labels;
    //connexion à la base
    MYSQL *connect;
    connect=mysql_init(NULL);
    if(!connect){
        fprintf(stderr,"MySQL Initialization Failed");
    }
    connect=mysql_real_connect(connect,SERVER,USER,PASSWORD,DATABASE,0,NULL,0);
    if(!connect){
        printf("Connection Failed!\n");
    }
    MYSQL_ROW row;
    MYSQL_RES *result = NULL;
    //création de la requête
    string selectName = "SELECT id FROM pictures ";
    mysql_query(connect, selectName.c_str());
    result = mysql_store_result(connect);
    row = mysql_fetch_row(result);
    for (int i=0; i<row.size(), i=i+1){
        names.push_back("../../OpenCVProject/BDDjpg/" + row[i]);
        }
    return labels;
}
