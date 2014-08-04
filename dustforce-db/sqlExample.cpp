#include "stdafx.h"

using namespace std;

//tut at
//http://dev.mysql.com/doc/connector-cpp/en/connector-cpp-getting-started-examples.html

class SqlExample {


	sql::mysql::MySQL_Driver * driver;
	sql::Connection * con;



public: SqlExample() {
	driver = sql::mysql::get_mysql_driver_instance();
	con = driver->connect("tcp://192.168.0.30:3306", "root", "13243546");

}








					//The MySQL Connector/Net allows you to create a graphical Windows application that is data-based. When your application runs, it must connect to a MySQL database. To support this connection, you can use the MySqlConnection class that is defined in the MySql::Data::MySqlClient namespace. Before using this class, you can first include that namespace in your file.
					//
					//To connect to a database, you can declare a pointer to MySqlConnection using one of its two constructors. The default constructor allows you to declare the variable without specifying how the connection would be carried. The second constructor takes as argument a string value. Its syntax is:

					//public: MySqlConnection(string *connectionstring);
					//If you want, you can first create the string that would be used to handle the connection, then pass that string to the second construction. This would be done as follows:

	//private: void createConnection()
	//{
	//	 string *strConnection = new string("");
	//	 MySqlConnection *conSQL = new MySqlConnection(strConnection);
	//}
	//				//You can also directly create the necessary (but appropriate) string in the second constructor when declaring the variable:

	//private: void createConnection()
	//{			
	//	 MySqlConnection *conSQL = new MySqlConnection(new string(""));
	//}
	//				//If you prefer to use the default constructor, you can first define a string value. To pass it to the default constructor, the MySqlConnection class is equipped with a property called Connectionstring that is of type string. You would use it as follows:

	//private: void createConnection()
	//{
	//	string *strConnection = new string("");
	//	MySqlConnection *conServer = new MySqlConnection();

	//	 conServer->Connectionstring = strConnection;				
	//				//To use a MySqlConnection object, you must provide various pieces of information, packaged as one and made available to the variable. These pieces are joined into a string but are separated from each other with a semi-colon ";". Each piece appears as a Key=Value format. In our lesson, we will refer to each of these pieces (Key=Value) as an attribute of the connection string. When joined, these attributes appear as follows:

	//				//Key1=Value1;Key2=Value2;Key_n=Value_n
	//				//Anything that part of this string is not case-sensitive. Remember that this whole ensemble is either passed as a string to the second constructor:

	//	//MySqlConnection conServer = new MySqlConnection(S"Key1=Value1;Key2=Value2;Key_n=Value_n");
	//						//or assigned as a string to the MySqlConnection.Connectionstring property:

	//	//MySqlConnection *conServer = new MySqlConnection();
	//	//string *strConnection = new string("Key1=Value1;Key2=Value2;Key_n=Value_n";

	//	//conServer->Connectionstring = strConnection;
	//						//How you create these attributes depends on the type of computer you are connecting to, whether you are connecting to a database, what level the security you would use (or need), etc. There are various of these attributes, some of them are always required, some of them are usually optional, and some others depend on the circumstances.

	//}

 //
	//				//The Source of Data
	//				//To establish a connection, you must specify the computer you are connecting to, that has MySQL installed. To indicate the computer you are connecting to, use the Data Source, the DataSource, the Host, the Server, the Addr, the Address, or the Network Address attribute of the connection string. If you are connecting to a local database (installed in the same computer where the application is running), you can omit specifying the name of the computer. Otherwise, you can assign localhost or the 127.0.0.1 IP address to this attribute. Here is an example:

	//private: void createConnection()
	//{
	//	 MySqlConnection *cnnVideos = new MySqlConnection(new string("Data Source=127.0.0.1;")); 
	//			//The Database
	//			//If you have already created a database you want to connect to, you can specify it in your connection string. If you are not trying to connect to a particular database, you don't need to specify one. 
	//			//
	//			//To specify the database you want to connect to, the connection string includes an attribute named Database or Initial Catalog. This attribute allows you to specify the name of the database you are connecting to, if any. If you are connecting to an existing database, assign its name to this attribute. If you are not connecting to a database, you can omit this attribute. Alternatively, you can assign nothing to this attribute. Here is an example:

	//	//MySqlConnection *conDatabase = new MySqlConnection(S"Address=127.0.0.1;Database=; ");
	//			//Another alternative is to assign an empty, single-quoted, string to this attribute. Here is an example:

	//	MySqlConnection *conDatabase = new MySqlConnection(new string("Network Address=127.0.0.1;Initial Catalog=''; "));
	//			//As mentioned above, the Database or Initial Catalog attribute is optional, especially if you are only connecting to the computer and not to a specific database.

	//}

 //
	//				//Security
	//				//An important aspect of establishing a connection to a computer is security. Even if you are developing an application that would be used on a standalone computer, you must take care of this issue. The security referred to in this attribute has to do with the connection, not how to protect your database.
	//				//
	//				//To support security, the connection string of the MySqlConnection class includes an attribute called Persist Security Info that can have a value of true, false, yes, no.
	//				//
	//				//If you are establishing a trusted or simple connection that doesn't need to be verified, you can assign a value of true.  Here is an example:

	//private: void createConnection()
	//{
	//	MySqlConnection *cnnVideos = new MySqlConnection(
	//		new string("Network Address='127.0.0.1';Persist Security Info=true;"));
	//				//If the connection exists already, to find it out, remember that you can can get the value of the MySqlConnection::Connectionstring property. If you had set the Persist Security Info attribute to true, the person getting this information may see the username and the password that were used to establish the connection. If you don't want this information available, you should set this attribute to false or no. If you do this, when somebody inquires about the connection string, he or she would not get the username and the password.

 //
	//				//The Username
	//				//If you are connecting to a MySQL server and you want to apply authentication, you can specific a username and a password. To specify the user name, use the User Id, the Uid, the User name, or the Username attribute and assign it a valid MySQL login username. Here is an example:

	//	MySqlConnection *conDatabase = new MySqlConnection(new string("Server=localhost;Persist Security Info=no;User ID=MammaMia"));
 //
	//				//The Password
	//				//When using authentication during connection, after specifying (if you had specified) the username, you must also provide a password to complete the authentication. To specify the password, you can user either the PASSWORD or the PWD (remember that the attributes are not case-sensitive) attribute and assign it the exact password associated with the User Id, the Uid, the User name, or the Username attribute of the same connection string. Here is an example:
	//}

	//private: void createConnection()
	//{
	//	 MySqlConnection *cnnVideos = new MySqlConnection(new string("Network Address=localhost;"),
	//																														 new string("Persist Security Info=no;"),
	//																														 new string("User Name='root';"),
	//																														 new string("Password='R0gerMiLl@'"));
	//}


	////Additional Attributes
	//				//There are various other attributes used in the connection string. They include Encrypt, Connection Timeout (or Connect Timeout), CharSet (or Character Set), Port, Protocol, Logging, Allow Batch, Shared Memory Name, Allow Zero Datetime, Old Syntax (or OldSyntax), Connection Lifetime, Max Pool Size, Min Pool Size, Pooling, and Pipe Name (or Pipe).
	//				//
	//				//After creating the connection string, when the application executes, the compiler would "scan" the string to validate each key=value section. If it finds an unknown Key, an unknown value, or an invalid combination of key=value, it would throw an ArgumentException exception and the connection cannot be established.
	//				//
	//				// 
	//				//Operations on a MySQL Server Database Connection
	//				// 
	//				//Opening a Connection
	//				//After creating a connection string, to apply it and actually establish the connection, you must call the MySqlConnection::Open(). Its syntax is:
	//				//
	//				//public: void Open();
	//				//As you can see, this method doesn't take any argument. The MySqlConnection object that calls it is responsible to get the connection string ready. If the connection fails, the compiler would throw a MySqlException exception. If the connection string doesn't contain a data source or server, the compiler would throw an InvalidOperationException exception.
	//				//
	//				// 
	//				//Closing a Connection
	//				//After using a connection and getting the necessary information from it, you should terminate it. To close a connection, you can call the MySqlConnection::Close() method. Its syntax is:
	//				//
	//				//public: void Close();
	//				//This method is simply called to close the current connection. While you should avoid calling the Open() method more than once if a connection is already opened, you can call the Close() method more than once.
};