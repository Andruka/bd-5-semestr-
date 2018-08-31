/* Processed by ecpg (4.11.0) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "ecpg.ec"
#include <string.h>
#include "ecpg.h"

void do_commit() {
	{ ECPGtrans(__LINE__, NULL, "commit");}
#line 5 "ecpg.ec"

}

#define SQLCHECK if(sqlca.sqlcode) { \
	printf("SQLERROR(%d): '%s' '%.5s' %ld\n", __LINE__, sqlca.sqlerrm.sqlerrmc, sqlca.sqlstate, sqlca.sqlcode);\
	do_commit(); \
	return 1;\
	}

int db_connect() {

	{ ECPGconnect(__LINE__, 0, "variant11" , "andrei" , NULL , NULL, 0); }
#line 16 "ecpg.ec"

	SQLCHECK;
	
	{ ECPGtrans(__LINE__, NULL, "commit");}
#line 19 "ecpg.ec"

	return 0;	
}


/* exec sql begin declare section */
	  
	    	 
	
	  
	    	 
		 
	
	  
		 
		 
	
	  
		 
		 
		 
	
struct SQL_q1 { 
#line 26 "ecpg.ec"
 char a_name [ name_len ] ;
 } ; struct SQL_q2 { 
#line 29 "ecpg.ec"
 char r_name [ name_len ] ;
 
#line 30 "ecpg.ec"
 int commission ;
 } ; struct SQL_q3 { 
#line 33 "ecpg.ec"
 char a_name [ name_len ] ;
 
#line 34 "ecpg.ec"
 char address [ name_len ] ;
 } ; struct SQL_q4 { 
#line 37 "ecpg.ec"
 int number ;
 
#line 38 "ecpg.ec"
 char a_name [ name_len ] ;
 
#line 39 "ecpg.ec"
 char r_name [ name_len ] ;
 } ;/* exec sql end declare section */
#line 41 "ecpg.ec"


void fill_table(q1 * q, struct SQL_q1 * sql) {
	if(q != NULL) {
		strncpy(q->a_name, sql->a_name, sizeof(q->a_name));
		q->a_name[ sizeof(sql->a_name) ] = 0;
	}
}

void fill_table2(q2 * q, struct SQL_q2 * sql) {
	if(q != NULL) {
		strncpy(q->r_name, sql->r_name, sizeof(sql->r_name));
		q->r_name[ sizeof(sql->r_name) ] = 0;
		q->commission=sql->commission;
	}
}
void fill_table3(q3 * q, struct SQL_q3 * sql) {
	if(q != NULL) {
		strncpy(q->a_name, sql->a_name, sizeof(q->a_name));
		q->a_name[ sizeof(sql->a_name)] = 0;
		strncpy(q->address, sql->address, sizeof(q->address));
		q->address[ sizeof(sql->address) ] = 0;
	}
}

void fill_table4(q4 * q, struct SQL_q4 * sql) {
	if(q != NULL) {
		q->number=sql->number;
		strncpy(q->a_name, sql->a_name, sizeof(q->a_name));
		q->a_name[ sizeof(sql->a_name) ] = 0;
		strncpy(q->r_name, sql->r_name, sizeof(q->r_name));
		q->r_name[ sizeof(sql->r_name) ] = 0;
	}

}

#define MAX_LEN 1024

int db_get_fil(const table_filter filter, int quer) {
	
	q1 a;
	q2 b;
	q3 c;
	q4 d;
	/* exec sql begin declare section */
		        

		  
		  
		  
		  

		 

		     

		     
		
	
#line 86 "ecpg.ec"
 char query [ MAX_LEN + 1 ] = { 0 } ;
 
#line 88 "ecpg.ec"
 struct SQL_q1 sql_q1 ;
 
#line 89 "ecpg.ec"
 struct SQL_q2 sql_q2 ;
 
#line 90 "ecpg.ec"
 struct SQL_q3 sql_q3 ;
 
#line 91 "ecpg.ec"
 struct SQL_q4 sql_q4 ;
 
#line 93 "ecpg.ec"
 int sql_total ;
 
#line 95 "ecpg.ec"
 char sql_r_name [ name_len ] = { 0 } ;
 
#line 97 "ecpg.ec"
 char sql_location [ location_len ] = { 0 } ;
/* exec sql end declare section */
#line 99 "ecpg.ec"



	if(quer==1)
	{

		strncpy(query, "SELECT DISTINCT ancestor.name FROM ancestor, zakazonconstruction, road_firm WHERE zakazonconstruction.firm=road_firm.id AND zakazonconstruction.ancestor=ancestor.id  AND road_firm.location!=ancestor.address;", MAX_LEN);

		printf("QUERY='%s'\n\n", query);
		
		{ ECPGprepare(__LINE__, NULL, 0, "query", query);}
#line 109 "ecpg.ec"

	
		/* declare db_get_fil cursor for $1 */
#line 112 "ecpg.ec"

		
		SQLCHECK;
	
		{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare db_get_fil cursor for $1", 
	ECPGt_char_variable,(ECPGprepared_statement(NULL, "query", __LINE__)),(long)1,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 116 "ecpg.ec"


		SQLCHECK;
		
		while(1) {
			{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch db_get_fil", ECPGt_EOIT, 
	ECPGt_char,&(sql_q1.a_name),(long)name_len,(long)1,sizeof( struct SQL_q1 ), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 121 "ecpg.ec"

			if(sqlca.sqlcode) {
				break;
			}
			fill_table(&a, &sql_q1);
			printf(">>>  %s\n",  a.a_name);
		}
		{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close db_get_fil", ECPGt_EOIT, ECPGt_EORT);}
#line 128 "ecpg.ec"

		SQLCHECK;
			
		{ ECPGtrans(__LINE__, NULL, "commit");}
#line 131 "ecpg.ec"

	}
	else if(quer==2)
	{
		strncpy(query, "SELECT road_firm.name, road_firm.commission FROM road_firm, zakazonconstruction WHERE zakazonconstruction.firm=road_firm.id AND zakazonconstruction.total>? AND (zakazonconstruction.data LIKE '%2%' OR zakazonconstruction.data LIKE '%3%' OR zakazonconstruction.data LIKE '%4%');", MAX_LEN);

  		sql_total=filter.total;
		printf("QUERY='%s'\n\n", query);
		
		{ ECPGprepare(__LINE__, NULL, 0, "query2", query);}
#line 140 "ecpg.ec"

	
		/* declare db_get_fil2 cursor for $1 */
#line 143 "ecpg.ec"

		
		SQLCHECK;
	
		{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare db_get_fil2 cursor for $1", 
	ECPGt_char_variable,(ECPGprepared_statement(NULL, "query2", __LINE__)),(long)1,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(sql_total),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 147 "ecpg.ec"


		SQLCHECK;
		
		while(1) {
			{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch db_get_fil2", ECPGt_EOIT, 
	ECPGt_char,&(sql_q2.r_name),(long)name_len,(long)1,sizeof( struct SQL_q2 ), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_int,&(sql_q2.commission),(long)1,(long)1,sizeof( struct SQL_q2 ), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 152 "ecpg.ec"

			if(sqlca.sqlcode) {
				break;
			}
			fill_table2(&b, &sql_q2);
			printf(">>>%s %d\n", b.r_name, b.commission);
		}
		{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close db_get_fil2", ECPGt_EOIT, ECPGt_EORT);}
#line 159 "ecpg.ec"

		SQLCHECK;
			
		{ ECPGtrans(__LINE__, NULL, "commit");}
#line 162 "ecpg.ec"

	}

	else if(quer==3)
	{
		strncpy(query, "SELECT DISTINCT ancestor.name, ancestor.address FROM ancestor, zakazonconstruction, road_firm WHERE zakazonconstruction.firm=road_firm.id AND zakazonconstruction.ancestor=ancestor.id AND ancestor.id IN(SELECT zakazonconstruction.ancestor FROM zakazonconstruction GROUP BY zakazonconstruction.ancestor, zakazonconstruction.firm HAVING COUNT(*)>1) AND road_firm.name=?;", MAX_LEN);

		strncpy(sql_r_name, filter.r_name, name_len);
		printf("QUERY='%s'\n\n", query);
	
		{ ECPGprepare(__LINE__, NULL, 0, "query3", query);}
#line 172 "ecpg.ec"

	
		/* declare db_get_fil3 cursor for $1 */
#line 175 "ecpg.ec"

		SQLCHECK;

		{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare db_get_fil3 cursor for $1", 
	ECPGt_char_variable,(ECPGprepared_statement(NULL, "query3", __LINE__)),(long)1,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(sql_r_name),(long)name_len,(long)1,(name_len)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 178 "ecpg.ec"


		SQLCHECK;
		
		while(1) {
			{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch db_get_fil3", ECPGt_EOIT, 
	ECPGt_char,&(sql_q3.a_name),(long)name_len,(long)1,sizeof( struct SQL_q3 ), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(sql_q3.address),(long)name_len,(long)1,sizeof( struct SQL_q3 ), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 183 "ecpg.ec"

			if(sqlca.sqlcode) {
				break;
			}
			fill_table3(&c, &sql_q3);
			printf(">>>%s %s\n", c.a_name, c.address);
		}
		{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close db_get_fil3", ECPGt_EOIT, ECPGt_EORT);}
#line 190 "ecpg.ec"

		SQLCHECK;
			
		{ ECPGtrans(__LINE__, NULL, "commit");}
#line 193 "ecpg.ec"

	}

	else if(quer==4)
	{
	  strncpy(query, "SELECT zakazonconstruction.number, ancestor.name, road_firm.name FROM zakazonconstruction, road_firm, ancestor WHERE zakazonconstruction.firm=road_firm.id AND zakazonconstruction.ancestor=ancestor.id AND road_firm.location =? ORDER BY ancestor.name;", MAX_LEN);
  		strncpy(sql_location, filter.location, location_len);
		printf("QUERY='%s'\n\n", query);
	
		{ ECPGprepare(__LINE__, NULL, 0, "query4", query);}
#line 202 "ecpg.ec"

	
		/* declare db_get_fil4 cursor for $1 */
#line 205 "ecpg.ec"

		SQLCHECK;

		{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare db_get_fil4 cursor for $1", 
	ECPGt_char_variable,(ECPGprepared_statement(NULL, "query4", __LINE__)),(long)1,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,(sql_location),(long)location_len,(long)1,(location_len)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 208 "ecpg.ec"


		SQLCHECK;
		
		while(1) {
			{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch db_get_fil4", ECPGt_EOIT, 
	ECPGt_int,&(sql_q4.number),(long)1,(long)1,sizeof( struct SQL_q4 ), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(sql_q4.a_name),(long)name_len,(long)1,sizeof( struct SQL_q4 ), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_char,&(sql_q4.r_name),(long)name_len,(long)1,sizeof( struct SQL_q4 ), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 213 "ecpg.ec"

			if(sqlca.sqlcode) {
				break;
			}
			fill_table4(&d, &sql_q4);
			printf(">>> %d %s %s\n", d.number,d.a_name,d.r_name);
		}
		{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close db_get_fil4", ECPGt_EOIT, ECPGt_EORT);}
#line 220 "ecpg.ec"

		SQLCHECK;
			
		{ ECPGtrans(__LINE__, NULL, "commit");}
#line 223 "ecpg.ec"

	}
	return 0;
}
