#include "stdafx.h"

//// sql.cpp -- sample program to read a database 
//// Special project requirements: 
////   Project->Settings->All Configurations: use MFC in a static library 
////   Add a Libs folder to the project and include in it Odbc32.lib from the vc98 folder 
////   Configure the database for ODBC access using Start->Settings->Control Panel->ODBC32
//#include <iostream> 
//using std::cin; 
//using std::cout; 
//using std::endl;
//
//#include <afxwin.h> 
//#include <sql.h> 
//#include <sqlext.h>
//
//int main() 
//{ 
//  // declarations needed for SQL 
//  RETCODE rc;        // ODBC return code 
//  HENV henv;         // Environment 
//  HDBC hdbc;         // Connection handle 
//  HSTMT hstmt;       // Statement handle 
//  SDWORD cbData;     // Output length of data
//
//  // attempt to connect to the ODBC database 
//  char db[] = "myDatabase"; // ODBC database name 
//  cout << "Attempting to open database " << db << "..." << endl; 
//  SQLAllocEnv(&henv); 
//  SQLAllocConnect(henv, &hdbc); 
//  rc = SQLConnect(hdbc, (unsigned char*)db, SQL_NTS, 0, 0, 0, 0);
//
//  // if not successful, quit 
//  if ((rc != SQL_SUCCESS) && (rc != SQL_SUCCESS_WITH_INFO)) 
//  { 
//    cout << "Cannot open database -- make sure ODBC is configured properly." << endl; 
//    SQLFreeConnect(hdbc); 
//    SQLFreeEnv(henv); 
//    cout << "Press ENTER to continue." << endl; 
//    cin.get(); 
//    return 1; 
//  }
//
//  // create a SQL statement 
//  rc = SQLAllocStmt(hdbc, &hstmt); 
//  char* sql = "INSERT INTO courses (desig, term, units, grade) VALUES ('COMSC-265', 'FA2001', 4, 'A')"; 
//  cout << "Executing " << sql << endl; 
//  rc = SQLExecDirect(hstmt, (unsigned char*)sql, SQL_NTS); 
//  if ((rc != SQL_SUCCESS) && (rc != SQL_SUCCESS_WITH_INFO)) 
//  { 
//    // error executing SQL statement 
//    SQLCHAR sqlState[8], msgText[1024]; 
//    SQLINTEGER NativeErrorPtr; 
//    SQLSMALLINT TextLengthPtr; 
//    SQLGetDiagRec(SQL_HANDLE_STMT, hstmt, 1, sqlState, 
//      &NativeErrorPtr, msgText, sizeof(msgText), &TextLengthPtr); 
//    SQLFreeStmt(hstmt, SQL_DROP); 
//    SQLDisconnect(hdbc); 
//    SQLFreeConnect(hdbc); 
//    SQLFreeEnv(henv); 
//    cout << "Error  " << endl << msgText << endl; 
//    cout << "Press ENTER to continue." << endl; 
//    cin.get(); 
//    return 2; 
//  } 
//  SQLFreeStmt(hstmt, SQL_DROP);
//
//  // create another SQL statement 
//  rc = SQLAllocStmt(hdbc, &hstmt); 
//  sql = "SELECT desig,term,units,grade FROM courses";
//
//  // execute the SQL statement 
//  cout << "Executing " << sql << endl; 
//  rc = SQLExecDirect(hstmt, (unsigned char*)sql, SQL_NTS); 
//  if ((rc != SQL_SUCCESS) && (rc != SQL_SUCCESS_WITH_INFO)) 
//  { 
//    // error executing SQL statement 
//    SQLCHAR sqlState[8], msgText[1024]; 
//    SQLINTEGER NativeErrorPtr; 
//    SQLSMALLINT TextLengthPtr; 
//    SQLGetDiagRec(SQL_HANDLE_STMT, hstmt, 1, sqlState, 
//      &NativeErrorPtr, msgText, sizeof(msgText), &TextLengthPtr); 
//    SQLFreeStmt(hstmt, SQL_DROP); 
//    SQLDisconnect(hdbc); 
//    SQLFreeConnect(hdbc); 
//    SQLFreeEnv(henv); 
//    cout << "Error  " << endl << msgText << endl; 
//    cout << "Press ENTER to continue." << endl; 
//    cin.get(); 
//    return 3; 
//  }
//
//  // if SQL statement is a SELECT statement, show records (skip for INSERT, DELETE, or UPDATE) 
//  cout << "Reading records returned by SQL statement..." << endl; 
//  for (rc = SQLFetch(hstmt); rc == SQL_SUCCESS; rc = SQLFetch(hstmt)) 
//  { 
//    // refs: 
//    // http://msdn.microsoft.com/library/default.asp?url=/library/en-us/odbc/htm/odbcc_data_types.asp 
//    // http://www.pdc.kth.se/doc/SP/manuals/db2-7.1/html/db2l0/frame3.htm#db2l0162 
//    char desig[32], term[8], grade[2]; 
//    int units; 
//    SQLGetData(hstmt, 1, SQL_C_CHAR, desig, sizeof(desig), &cbData); // read 1st column as text 
//    SQLGetData(hstmt, 2, SQL_C_CHAR, term, sizeof(term), &cbData); // read 2nd column as text 
//    SQLGetData(hstmt, 3, SQL_INTEGER, &units, sizeof(int), &cbData); // read 3rd column as int 
//    SQLGetData(hstmt, 4, SQL_C_CHAR, grade, sizeof(grade), &cbData); // read 4th column as text 
//    cout << desig << ' ' << term << ' ' << units << ' ' << grade << endl; 
//  }
//
//  // close database 
//  SQLFreeStmt(hstmt, SQL_DROP); 
//  SQLDisconnect(hdbc); 
//  SQLFreeConnect(hdbc);
//
//  cout << "Finished. Press ENTER to continue." << endl; 
//  cin.get(); 
//  return 0; 
//}