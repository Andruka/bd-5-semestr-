#include "main.h"
#include <stdio.h>
#include <sql.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <string.h>
#include <stdlib.h>

int search_inf(SQLHSTMT *hstmt)
{
	int q;
	printf("----------Введите атрибут для поиска---------- \n");
	printf("(1) Фамилия \n");
	printf("(2) Имя \n");
	printf("(3) Номер \n");
	printf("(4) Город \n");
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
			SQLVARCHAR sql_surname1[30];
			SQLVARCHAR sql_surname[30];
			SQLVARCHAR sql_name[20];
			SQLVARCHAR sql_number[20];
	
			SQLBindParameter((*hstmt), 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 30, 0, sql_surname1, 30, NULL);

    			if (SQLPrepare((*hstmt), (SQLCHAR *) "SELECT number.num, persons.surname, persons.name FROM number right join persons on number.id=persons.id where persons.surname like ?", SQL_NTS) != SQL_SUCCESS) {
				fprintf(stderr, "Error 5\n");
				return 1;
					}

    			if (SQLNumParams((*hstmt), &NumParams) != SQL_SUCCESS){
				fprintf(stderr, "Error in parametrs\n");
				return 1;
					}
			*sql_surname1="%"+*surname+"%";
			SQLBindCol((*hstmt),1, SQL_C_CHAR, &sql_number,sizeof(sql_number), NULL);
			SQLBindCol((*hstmt),2, SQL_C_CHAR, &sql_surname,sizeof(sql_surname), NULL);
			SQLBindCol((*hstmt),3, SQL_C_CHAR, &sql_name,sizeof(sql_name), NULL);

			if (SQLExecute((*hstmt)) !=  SQL_SUCCESS) {
				fprintf(stderr, "Error 6\n");
				return 1;
			}

			while(1) {
				if(SQLFetch((*hstmt)) == SQL_NO_DATA) {
					break;
				}
				printf("%s %s %s \n", sql_number, sql_surname, sql_name);
			}

			SQLCloseCursor((*hstmt));
			break;
		}
		case 2:
		{
			char name[20];
			printf("Введите имя: ");
			scanf("%s",name);

			SQLSMALLINT     NumParams;
			SQLVARCHAR sql_name1[30];
			SQLVARCHAR sql_surname[30];
			SQLVARCHAR sql_name[20];
			SQLVARCHAR sql_number[20];

			SQLBindParameter((*hstmt), 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 20, 0, sql_name1, 20, NULL);

    			if (SQLPrepare((*hstmt), (SQLCHAR *) "SELECT number.num, persons.surname, persons.name FROM number inner join persons on number.id=persons.id where persons.name=?", SQL_NTS) != SQL_SUCCESS) {
				fprintf(stderr, "Error 5\n");
				return 1;
					}

    			if (SQLNumParams((*hstmt), &NumParams) != SQL_SUCCESS){
				fprintf(stderr, "Error in parametrs\n");
				return 1;
					}
			strcpy((char*)sql_name1, name);

			SQLBindCol((*hstmt),1, SQL_C_CHAR, &sql_number,sizeof(sql_number), NULL);
			SQLBindCol((*hstmt),2, SQL_C_CHAR, &sql_surname,sizeof(sql_surname), NULL);
			SQLBindCol((*hstmt),3, SQL_C_CHAR, &sql_name,sizeof(sql_name), NULL);

			if (SQLExecute((*hstmt)) !=  SQL_SUCCESS) {
				fprintf(stderr, "Error 6\n");
				return 1;
			}

			while(1) {
				if(SQLFetch((*hstmt)) == SQL_NO_DATA) {
					break;
				}
				printf("%s %s %s \n", sql_number, sql_surname, sql_name);
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
			SQLVARCHAR sql_number1[30];
			SQLVARCHAR sql_surname[30];
			SQLVARCHAR sql_name[20];
			SQLVARCHAR sql_number[20];

			SQLBindParameter((*hstmt), 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 12, 0, sql_number1, 12, NULL);

    			if (SQLPrepare((*hstmt), (SQLCHAR *) "SELECT number.num, persons.surname, persons.name FROM number inner join persons on number.id=persons.id where number.num=?", SQL_NTS) != SQL_SUCCESS) {
				fprintf(stderr, "Error 5\n");
				return 1;
					}

    			if (SQLNumParams((*hstmt), &NumParams) != SQL_SUCCESS){
				fprintf(stderr, "Error in parametrs\n");
				return 1;
					}
			strcpy((char*)sql_number1, number);

			SQLBindCol((*hstmt),1, SQL_C_CHAR, &sql_number,sizeof(sql_number), NULL);
			SQLBindCol((*hstmt),2, SQL_C_CHAR, &sql_surname,sizeof(sql_surname), NULL);
			SQLBindCol((*hstmt),3, SQL_C_CHAR, &sql_name,sizeof(sql_name), NULL);

			if (SQLExecute((*hstmt)) !=  SQL_SUCCESS) {
				fprintf(stderr, "Error 6\n");
				return 1;
			}

			while(1) {
				if(SQLFetch((*hstmt)) == SQL_NO_DATA) {
					break;
				}
				printf("%s %s %s \n", sql_number, sql_surname, sql_name);
			}

			SQLCloseCursor((*hstmt));
			break;
		}
		case 4:
		{
			char city[20];
			printf("Введите город: ");
			scanf("%s",city);

			SQLSMALLINT     NumParams;
			SQLVARCHAR sql_city1[20];
			SQLVARCHAR sql_surname[30];
			SQLVARCHAR sql_name[20];
			SQLVARCHAR sql_number[20];
			SQLVARCHAR sql_city[20];
			SQLVARCHAR sql_street[30];
			SQLINTEGER sql_home;
			SQLINTEGER sql_flat;

			SQLBindParameter((*hstmt), 1, SQL_PARAM_INPUT, SQL_C_CHAR, SQL_CHAR, 12, 0, sql_city1, 12, NULL);

    			if (SQLPrepare((*hstmt), (SQLCHAR *) "SELECT location.city, location.street, location.home, location.flat, number.num, persons.surname, persons.name FROM location inner join number on location.id=number.id inner join persons on location.id=persons.id where location.city=?", SQL_NTS) != SQL_SUCCESS) {
				fprintf(stderr, "Error 5\n");
				return 1;
					}

    			if (SQLNumParams((*hstmt), &NumParams) != SQL_SUCCESS){
				fprintf(stderr, "Error in parametrs\n");
				return 1;
					}
			strcpy((char*)sql_city1, city);

			SQLBindCol((*hstmt),1, SQL_C_CHAR, &sql_city,sizeof(sql_city), NULL);
			SQLBindCol((*hstmt),2, SQL_C_CHAR, &sql_street,sizeof(sql_street), NULL);
			SQLBindCol((*hstmt),3, SQL_C_LONG, &sql_home,sizeof(sql_home), NULL);
			SQLBindCol((*hstmt),4, SQL_C_LONG, &sql_flat,sizeof(sql_flat), NULL);
			SQLBindCol((*hstmt),5, SQL_C_CHAR, &sql_number,sizeof(sql_number), NULL);
			SQLBindCol((*hstmt),6, SQL_C_CHAR, &sql_surname,sizeof(sql_surname), NULL);
			SQLBindCol((*hstmt),7, SQL_C_CHAR, &sql_name,sizeof(sql_name), NULL);


			if (SQLExecute((*hstmt)) !=  SQL_SUCCESS) {
				fprintf(stderr, "Error 6\n");
				return 1;
			}

			while(1) {
				if(SQLFetch((*hstmt)) == SQL_NO_DATA) {
					break;
				}
				printf("%s %s %d %d %s %s %s\n", sql_city, sql_street, sql_home, sql_flat, sql_number, sql_surname, sql_name);
			}

			SQLCloseCursor((*hstmt));
			break;
		}
		case 0:
			break;
	}
	return 1;
}
