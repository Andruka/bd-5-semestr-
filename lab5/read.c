#include "main.h"
#include <stdio.h>
#include <sql.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <string.h>
#include <stdlib.h>

int read_inf(SQLHSTMT *hstmt)
{
	int q;
	printf("---------Введите атрибут для вывода----------- \n");
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
			if (SQLPrepare((*hstmt), (SQLCHAR *) "SELECT id, name, surname FROM persons", SQL_NTS) != SQL_SUCCESS) 
			{
				fprintf(stderr, "Error 5\n");
				return 1;
			}

			SQLINTEGER sql_id;
			SQLVARCHAR sql_name[20];
			SQLVARCHAR sql_surname[30];

			
			SQLBindCol((*hstmt),1, SQL_C_LONG, &sql_id,sizeof(sql_id), NULL);
			SQLBindCol((*hstmt),2, SQL_C_CHAR, &sql_name,sizeof(sql_name), NULL);
			SQLBindCol((*hstmt),3, SQL_C_CHAR, &sql_surname,sizeof(sql_surname), NULL);


			if (SQLExecute((*hstmt)) !=  SQL_SUCCESS) {
				fprintf(stderr, "Error 6\n");
				return 1;
			}

			while(1) {
				if(SQLFetch((*hstmt)) == SQL_NO_DATA) {
					break;
				}
				printf("%d %s %s\n", sql_id, sql_name, sql_surname);
			}
			SQLCloseCursor((*hstmt));
			break;
		}
		case 2:
		{
			if (SQLPrepare((*hstmt), (SQLCHAR *) "SELECT persons.id, location.city, location.street, location.home, location.flat, persons.surname FROM location inner join persons on location.id=persons.id", SQL_NTS) != SQL_SUCCESS) 
			{
				fprintf(stderr, "Error 5\n");
				return 1;
			}

			
			SQLINTEGER sql_id2;
			SQLVARCHAR sql_city[20];
			SQLVARCHAR sql_street[30];
			SQLINTEGER sql_home;
			SQLINTEGER sql_flat;
			SQLVARCHAR sql_id_person[30];

			SQLBindCol((*hstmt),1, SQL_C_LONG, &sql_id2, sizeof(sql_id2), NULL);
			SQLBindCol((*hstmt),2, SQL_C_CHAR, &sql_city,sizeof(sql_city), NULL);
			SQLBindCol((*hstmt),3, SQL_C_CHAR, &sql_street,sizeof(sql_street), NULL);
			SQLBindCol((*hstmt),4, SQL_C_LONG, &sql_home,sizeof(sql_home), NULL);
			SQLBindCol((*hstmt),5, SQL_C_LONG, &sql_flat,sizeof(sql_flat), NULL);
			SQLBindCol((*hstmt),6, SQL_C_CHAR, &sql_id_person,sizeof(sql_id_person), NULL);

			if (SQLExecute((*hstmt)) !=  SQL_SUCCESS) {
				fprintf(stderr, "Error 6\n");
				return 1;
			}

			while(1) {
				if(SQLFetch((*hstmt)) == SQL_NO_DATA) {
					break;
				}
				printf("%d %s %s %d %d %s\n", sql_id2, sql_city, sql_street, sql_home, sql_flat, sql_id_person);
			}
			SQLCloseCursor((*hstmt));
			break;
		}
		case 3:
		{
			if (SQLPrepare((*hstmt), (SQLCHAR *) "SELECT persons.id, number.num, persons.surname FROM number inner join persons on number.id=persons.id", SQL_NTS) != SQL_SUCCESS) 
			{
				fprintf(stderr, "Error 5\n");
				return 1;
			}	
			SQLINTEGER sql_id3;
			SQLVARCHAR sql_number[20];
			SQLVARCHAR sql_id_person2[30];

			SQLBindCol((*hstmt),1, SQL_C_LONG, &sql_id3,sizeof(sql_id3), NULL);
			SQLBindCol((*hstmt),2, SQL_C_CHAR, &sql_number,sizeof(sql_number), NULL);
			SQLBindCol((*hstmt),3, SQL_C_CHAR, &sql_id_person2,sizeof(sql_id_person2), NULL);

			if (SQLExecute((*hstmt)) !=  SQL_SUCCESS) {
				fprintf(stderr, "Error 6\n");
				return 1;
			}

			while(1) {
				if(SQLFetch((*hstmt)) == SQL_NO_DATA) {
					break;
				}
				printf("%d %s %s \n", sql_id3, sql_number, sql_id_person2);
			}
			SQLCloseCursor((*hstmt));
			break;
		}
		case 4:
		{
			if (SQLPrepare((*hstmt), (SQLCHAR *) "SELECT persons.id, email.mail, persons.surname FROM email inner join persons on email.id=persons.id", SQL_NTS) != SQL_SUCCESS) 
			{
				fprintf(stderr, "Error 5\n");
				return 1;
			}	
			SQLINTEGER sql_id4;
			SQLVARCHAR sql_mail[40];
			SQLVARCHAR sql_id_person3[30];

			SQLBindCol((*hstmt),1, SQL_C_LONG, &sql_id4,sizeof(sql_id4), NULL);
			SQLBindCol((*hstmt),2, SQL_C_CHAR, &sql_mail,sizeof(sql_mail), NULL);
			SQLBindCol((*hstmt),3, SQL_C_CHAR, &sql_id_person3,sizeof(sql_id_person3), NULL);

			if (SQLExecute((*hstmt)) !=  SQL_SUCCESS) {
				fprintf(stderr, "Error 6\n");
				return 1;
			}

			while(1) {
				if(SQLFetch((*hstmt)) == SQL_NO_DATA) {
					break;
				}
				printf("%d %s %s \n", sql_id4, sql_mail, sql_id_person3);
			}
			SQLCloseCursor((*hstmt));
			break;
		}
		case 0:
			break;
	}
	return 1;
}
