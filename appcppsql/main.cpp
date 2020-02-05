#include <iostream>
#include <windows.h>
#include <mysql/mysql.h>
#include <sstream>
#include <time.h>

using namespace std;

int main()
{
    MYSQL *con;     // Указатель на соединение
    MYSQL_ROW row;  // переменная для чтения результата
    MYSQL_RES* res; // указатель на результат

    stringstream stringQuery;
    string field = "test_record";

    int qstate = 0;
    con = mysql_init(0);    // Инициализация нового подключения

    cout << "== MYSQL & C++ ==" << endl;
    Sleep(2000);
    cout << "Try connect to db...." << endl;
    Sleep(2000);

    // mysql_real_connect(con, "localhost", "__username", "__password", "__dbName", 3306, NULL, 0);
    con = mysql_real_connect(con, "__host", "__username", "__password", "__dbName", 3306, NULL, 0);

    // check connection
    if(con) {
        cout << "Done" << endl;
    } else {
        cout << "Faild!" << endl;
        cout << mysql_error(con) << endl;
    }

    //ss << "INSERT INTO new_table(field) VALUES('" << field << "')";
    //string query = ss.str();
    //const char* q = query.c_str();
    //qstate = mysql_query(con, q);


    //if(qstate == 0) {
      //  cout << "Record added!" << endl;

    //} else {
       // cout << "Error" << endl;
    //}

    if (con) {
        stringQuery << "SELECT * FROM new_table";
        qstate = mysql_query(con, stringQuery.str().c_str());
        if (!qstate) {
            res = mysql_store_result(con);

            // Извлекает следующую строку из результирующего набора.
            while(row = mysql_fetch_row(res)) {
                if (row[0] == NULL) {
                    cout << " | " << "NULL" << " | " << row[1] << " | " << endl;
                    cout << "-------------------------" << endl;
                } else {
                    cout << " | "<< row[0] << " | " << row[1] << " | " << endl;
                    cout << "-------------------------" << endl;

                }

            }
        }
    }

    return 0;
}
