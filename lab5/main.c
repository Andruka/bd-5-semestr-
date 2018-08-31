#include <stdio.h>
#include <sql.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

int main(int argc, char **argv) 
{
	char q;	
    SQLHENV henv = NULL;
    SQLHDBC hdbc = NULL;
    SQLHSTMT hstmt;
    if (SQLAllocHandle(SQL_HANDLE_ENV, NULL, &henv) == SQL_ERROR)  {
        fprintf(stderr, "error coonnect 1\n");
    } else {
        SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION, (void*) SQL_OV_ODBC3, SQL_IS_INTEGER);
        if (SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc) == SQL_ERROR)  {
                fprintf(stderr, "error coonnect 3\n");
        } else if (SQLConnect(hdbc, (SQLTCHAR*) "andrei", SQL_NTS, (SQLTCHAR*) "andrei", SQL_NTS, (SQLTCHAR*) "12345", SQL_NTS) == SQL_ERROR) {
                fprintf(stderr, "error coonnect 4\n");
        } else if (SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt) == SQL_ERROR) {
                fprintf(stderr, "error coonnect 5\n");
        } 
    }
		
	while(1)
	{
        system("clear");
		printf("-----------Меню-----------\n");
		printf("(1) Просмотр данных \n");
		printf("(2) Добавление данных\n");
		printf("(3) Удаление данных\n");
		printf("(4) Поиск данных\n");
		printf("(0) Выход\n");
		printf("==>");
		scanf("%c",&q);
        system("clear");
	   switch(q)
	   {
		  case '1':
		  {
		  	read_inf(&hstmt);
            getchar();
            getchar();
			break;
		  }
		  case '2': 
		  { 
		    insert_inf(&hstmt);
            getchar();
            getchar();
			break;
		}

		case '3':
		{ 
			delete_inf(&hstmt);
            getchar();
            getchar();
			break;
		}
		case '4':
		{ 
			search_inf(&hstmt);
            getchar();
            getchar();
			break;
		}
		case '0':
		{
		    SQLDisconnect(hdbc);
            SQLFreeHandle(SQL_HANDLE_DBC, hdbc);
            SQLFreeHandle(SQL_HANDLE_ENV, henv);
            return 0;
		}
        default:
        {
            printf("Error!\n");
        }

	}
	}


	return 0;
}
