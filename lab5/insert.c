#include "main.h"
#include <stdio.h>
#include <sql.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <string.h>
#include <stdlib.h>

int insert_inf(SQLHSTMT *hstmt)
{

	int q;
	printf("----------Выберите атрибут для вставки------------ \n");
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
			char name[20];
			printf("Введите фамилию: ");
			scanf("%s",name);
			printf("Введите имя: ");
			scanf("%s",surname);

			SQLSMALLINT     NumParams;

			SQLVARCHAR sql_name[20];
			SQLVARCHAR sql_surname[30];

			
			SQLBindParameter((*hstmt), 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 20, 0, sql_name, 20, NULL);
    			SQLBindParameter((*hstmt), 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 30, 0, sql_surname, 30, NULL);

    			if(SQLPrepare((*hstmt), (SQLCHAR*)"insert into persons values((select max(id) from persons)+1,?,?);", SQL_NTS) != SQL_SUCCESS) {
				fprintf(stderr, "Error in insert\n");
				return 1;
					}

    			if (SQLNumParams((*hstmt), &NumParams) != SQL_SUCCESS){
				fprintf(stderr, "Error in parametrs\n");
				return 1;
					}
			
			strcpy((char*)sql_name, name);
			strcpy((char*)sql_surname, surname);

			if (SQLExecute((*hstmt)) !=  SQL_SUCCESS) 
			{
				fprintf(stderr, "Error 6\n");
				return 1;
			}

			SQLCloseCursor((*hstmt));
			break;
		}
		case 2:
		{
			
			char surname3[30];
			char city[20];
			char street[20];
			int home, flat;
			printf("Введите город: ");
			scanf("%s",city);
			printf("Введите улицу: ");
			scanf("%s",street);
			printf("Введите дом: ");
			scanf("%d",&home);
			printf("Введите квартиру: ");
			scanf("%d",&flat);
			printf("Введите фамилию: ");
			scanf("%s",surname3);

			SQLSMALLINT     NumParams;

			
			SQLVARCHAR sql_city[20];
			SQLVARCHAR sql_street[30];
			SQLINTEGER sql_home;
			SQLINTEGER sql_flat;
			SQLVARCHAR sql_surname3[30];

			
            SQLBindParameter((*hstmt), 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 30, 0, sql_surname3, 30, NULL);
            SQLBindParameter((*hstmt), 2, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER, 0, 0, &sql_flat, 0, NULL);
            SQLBindParameter((*hstmt), 3, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER, 0, 0, &sql_home, 0, NULL);
            SQLBindParameter((*hstmt), 4, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 30, 0, sql_street, 30, NULL);
            SQLBindParameter((*hstmt), 5, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 20, 0, sql_city, 20, NULL);
		
			

    			if(SQLPrepare((*hstmt), (SQLCHAR*)"insert into location values((select id from persons where surname like ?), ?, ?, ?, ? )", SQL_NTS) != SQL_SUCCESS) 
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
			strcpy((char*)sql_surname3, surname3);
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
			char surname1[30];
			char number[12];
			printf("Введите номер: ");
			scanf("%s",number);
			printf("Введите фамилию: ");
			scanf("%s",surname1);

			SQLSMALLINT     NumParams;

			SQLVARCHAR sql_number[12];
			SQLVARCHAR sql_surname1[30];

			
    		SQLBindParameter((*hstmt), 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 30, 0, sql_surname1, 30, NULL);
            	SQLBindParameter((*hstmt), 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 12, 0, sql_number, 12, NULL);

    			if(SQLPrepare((*hstmt), (SQLCHAR*)"insert into number values((select id from persons where surname like ?), ? )", SQL_NTS) != SQL_SUCCESS) 
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
			strcpy((char*)sql_surname1, surname1);

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
			char surname2[30];
			char mail[40];
			printf("Введите эл.почту: ");
			scanf("%s",mail);
			printf("Введите фамилию: ");
			scanf("%s",surname2);

			SQLSMALLINT     NumParams;

			SQLVARCHAR sql_mail[12];
			SQLVARCHAR sql_surname2[30];

			
            		SQLBindParameter((*hstmt), 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 30, 0, sql_surname2, 30, NULL);
			SQLBindParameter((*hstmt), 2, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_VARCHAR, 40, 0, sql_mail, 40, NULL);

    			if(SQLPrepare((*hstmt), (SQLCHAR*)"insert into email values((select id from persons where surname like ?), ?)", SQL_NTS) != SQL_SUCCESS) 
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
			strcpy((char*)sql_surname2, surname2);

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
