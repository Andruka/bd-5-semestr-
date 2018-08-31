#include "main.h"
#include <stdio.h>
#include <sql.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <string.h>
#include <stdlib.h>


int delete_inf(SQLHSTMT *hstmt)
{

	int q;
	printf(" --------Выберите атрибут для удаления--------- \n");
	printf("(1) Человек \n");
	printf("(2) Адрес \n");
	printf("(3) Номер \n");
	printf("(4) Эл.почта \n");
	printf("(0) Выход\n");
	printf("==>");
	scanf("%d",&q);
	switch(q)
	{
		case 1:
		{
			char surname[30];
			printf("Введите фамилию: ");
			scanf("%s",surname);

			SQLSMALLINT     NumParams;
			SQLVARCHAR sql_surname[30];
			
			int s=0;
			SQLBindParameter((*hstmt), 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 30, 0, sql_surname, 30, NULL);

    			if(SQLPrepare((*hstmt), (SQLCHAR*)"delete from persons p where p.surname like ?", SQL_NTS) != SQL_SUCCESS) {
				fprintf(stderr, "Error in insert\n");
				return 1;
					}

    			if (SQLNumParams((*hstmt), &NumParams) != SQL_SUCCESS){
				fprintf(stderr, "Error in parametrs\n");
				return 1;
					}

    			strcpy((char*)sql_surname, surname); 

			if (SQLExecute((*hstmt)) !=  SQL_SUCCESS) {
				s++;
				fprintf(stderr, "Error 6 %d\n", s);
				return 1;
			}

			SQLCloseCursor((*hstmt));
			break;
		}
		case 2:
		{
			
			char city[20];
			char street[20];
			int home, flat;
			printf("Enter city: ");
			scanf("%s",city);
			printf("Enter street: ");
			scanf("%s",street);
			printf("Enter home: ");
			scanf("%d",&home);
			printf("Enter flat: ");
			scanf("%d",&flat);

			SQLSMALLINT     NumParams;

			
			SQLVARCHAR sql_city[20];
			SQLVARCHAR sql_street[30];
			SQLINTEGER sql_home;
			SQLINTEGER sql_flat;
			
			SQLBindParameter((*hstmt), 1, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER, 0, 0, &sql_flat, 0, NULL);
            SQLBindParameter((*hstmt), 2, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER, 0, 0, &sql_home, 0, NULL);
            SQLBindParameter((*hstmt), 3, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 30, 0, sql_street, 30, NULL);
            SQLBindParameter((*hstmt), 4, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 20, 0, sql_city, 20, NULL);
		
			

    			if(SQLPrepare((*hstmt), (SQLCHAR*)"delete from location where flat=? and home=? and street=? and city=?", SQL_NTS) != SQL_SUCCESS) 
			{
				fprintf(stderr, "Error in insert\n");
				return 1;
			}

    			if (SQLNumParams((*hstmt), &NumParams) != SQL_SUCCESS)
			{
				fprintf(stderr, "Error in parametrs\n");
				return 1;
			}
			
			strcpy((char*)sql_city, city);
			strcpy((char*)sql_street, street);
			sql_home=home;
			sql_flat=flat;

			if (SQLExecute((*hstmt)) !=  SQL_SUCCESS) 
			{
				fprintf(stderr, "Error 6\n");
				return 1;
			}

			SQLCloseCursor((*hstmt));
			break;
		}
		case 3:
		{
			char number[12];
			printf("Введите номер: ");
			scanf("%s",number);

			SQLSMALLINT     NumParams;

			SQLVARCHAR sql_number[12];

			
			SQLBindParameter((*hstmt), 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 12, 0, sql_number, 12, NULL);

    			if(SQLPrepare((*hstmt), (SQLCHAR*)"delete from number where num=?", SQL_NTS) != SQL_SUCCESS) 
			{
				fprintf(stderr, "Error in insert\n");
				return 1;
			}

    			if (SQLNumParams((*hstmt), &NumParams) != SQL_SUCCESS)
			{
				fprintf(stderr, "Error in parametrs\n");
				return 1;
			}
			
			strcpy((char*)sql_number, number);

			if (SQLExecute((*hstmt)) !=  SQL_SUCCESS) 
			{
				fprintf(stderr, "Error 6\n");
				return 1;
			}

			SQLCloseCursor((*hstmt));
			break;
		}
		case 4:
		{
			char mail[40];
			printf("Введите эл.почту: ");
			scanf("%s",mail);

			SQLSMALLINT     NumParams;

			SQLVARCHAR sql_mail[40];
			
			SQLBindParameter((*hstmt), 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 40, 0, sql_mail, 40, NULL);

    			if(SQLPrepare((*hstmt), (SQLCHAR*)"delete from email where mail=?", SQL_NTS) != SQL_SUCCESS) 
			{
				fprintf(stderr, "Error in insert\n");
				return 1;
			}

    			if (SQLNumParams((*hstmt), &NumParams) != SQL_SUCCESS)
			{
				fprintf(stderr, "Error in parametrs\n");
				return 1;
			}
			
			strcpy((char*)sql_mail, mail);

			if (SQLExecute((*hstmt)) !=  SQL_SUCCESS) 
			{
				fprintf(stderr, "Error 6\n");
				return 1;
			}

			SQLCloseCursor((*hstmt));
			break;
		}
		case 0:
			break;
	}
	return 1;


}
