#include <string.h>
#include "ecpg.h"

void do_commit() {
	EXEC SQL COMMIT;
}

#define SQLCHECK if(sqlca.sqlcode) { \
	printf("SQLERROR(%d): '%s' '%.5s' %ld\n", __LINE__, sqlca.sqlerrm.sqlerrmc, sqlca.sqlstate, sqlca.sqlcode);\
	do_commit(); \
	return 1;\
	}

int db_connect() {

	EXEC SQL CONNECT TO variant11 USER andrei;
	SQLCHECK;
	
	EXEC SQL COMMIT;
	return 0;	
}


EXEC SQL BEGIN DECLARE SECTION;
	struct SQL_q1 {
	    	char a_name[name_len];
	};
	struct SQL_q2 {
	    	char r_name[name_len];
		int commission;
	};
	struct SQL_q3 {
		char a_name[name_len];
		char address[name_len];
	};
	struct SQL_q4 {
		int number;
		char a_name[name_len];
		char r_name[name_len];
	};
EXEC SQL END DECLARE SECTION;

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
	EXEC SQL BEGIN DECLARE SECTION;
		char query [MAX_LEN + 1] = { 0 };

		struct SQL_q1 sql_q1;
		struct SQL_q2 sql_q2;
		struct SQL_q3 sql_q3;
		struct SQL_q4 sql_q4;

		int sql_total;

		char sql_r_name[name_len] = { 0 };

		char sql_location[location_len] = { 0 };
		
	EXEC SQL END DECLARE SECTION;


	if(quer==1)
	{

		strncpy(query, "SELECT DISTINCT ancestor.name FROM ancestor, zakazonconstruction, road_firm WHERE zakazonconstruction.firm=road_firm.id AND zakazonconstruction.ancestor=ancestor.id  AND road_firm.location!=ancestor.address;", MAX_LEN);

		printf("QUERY='%s'\n\n", query);
		
		EXEC SQL PREPARE query FROM :query;
	
		EXEC SQL DECLARE db_get_fil CURSOR FOR
					query;
		
		SQLCHECK;
	
		EXEC SQL OPEN db_get_fil;

		SQLCHECK;
		
		while(1) {
			EXEC SQL FETCH db_get_fil INTO :sql_q1;
			if(sqlca.sqlcode) {
				break;
			}
			fill_table(&a, &sql_q1);
			printf(">>>  %s\n",  a.a_name);
		}
		EXEC SQL CLOSE db_get_fil;
		SQLCHECK;
			
		EXEC SQL COMMIT;
	}
	else if(quer==2)
	{
		strncpy(query, "SELECT road_firm.name, road_firm.commission FROM road_firm, zakazonconstruction WHERE zakazonconstruction.firm=road_firm.id AND zakazonconstruction.total>? AND (zakazonconstruction.data LIKE '%2%' OR zakazonconstruction.data LIKE '%3%' OR zakazonconstruction.data LIKE '%4%');", MAX_LEN);

  		sql_total=filter.total;
		printf("QUERY='%s'\n\n", query);
		
		EXEC SQL PREPARE query2 FROM :query;
	
		EXEC SQL DECLARE db_get_fil2 CURSOR FOR
					query2;
		
		SQLCHECK;
	
		EXEC SQL OPEN db_get_fil2 USING :sql_total;

		SQLCHECK;
		
		while(1) {
			EXEC SQL FETCH db_get_fil2 INTO :sql_q2;
			if(sqlca.sqlcode) {
				break;
			}
			fill_table2(&b, &sql_q2);
			printf(">>>%s %d\n", b.r_name, b.commission);
		}
		EXEC SQL CLOSE db_get_fil2;
		SQLCHECK;
			
		EXEC SQL COMMIT;
	}

	else if(quer==3)
	{
		strncpy(query, "SELECT DISTINCT ancestor.name, ancestor.address FROM ancestor, zakazonconstruction, road_firm WHERE zakazonconstruction.firm=road_firm.id AND zakazonconstruction.ancestor=ancestor.id AND ancestor.id IN(SELECT zakazonconstruction.ancestor FROM zakazonconstruction GROUP BY zakazonconstruction.ancestor, zakazonconstruction.firm HAVING COUNT(*)>1) AND road_firm.name=?;", MAX_LEN);

		strncpy(sql_r_name, filter.r_name, name_len);
		printf("QUERY='%s'\n\n", query);
	
		EXEC SQL PREPARE query3 FROM :query;
	
		EXEC SQL DECLARE db_get_fil3 CURSOR FOR
				query3;
		SQLCHECK;

		EXEC SQL OPEN db_get_fil3 USING :sql_r_name;

		SQLCHECK;
		
		while(1) {
			EXEC SQL FETCH db_get_fil3 INTO :sql_q3;
			if(sqlca.sqlcode) {
				break;
			}
			fill_table3(&c, &sql_q3);
			printf(">>>%s %s\n", c.a_name, c.address);
		}
		EXEC SQL CLOSE db_get_fil3;
		SQLCHECK;
			
		EXEC SQL COMMIT;
	}

	else if(quer==4)
	{
	  strncpy(query, "SELECT zakazonconstruction.number, ancestor.name, road_firm.name FROM zakazonconstruction, road_firm, ancestor WHERE zakazonconstruction.firm=road_firm.id AND zakazonconstruction.ancestor=ancestor.id AND road_firm.location =? ORDER BY ancestor.name;", MAX_LEN);
  		strncpy(sql_location, filter.location, location_len);
		printf("QUERY='%s'\n\n", query);
	
		EXEC SQL PREPARE query4 FROM :query;
	
		EXEC SQL DECLARE db_get_fil4 CURSOR FOR
				query4;
		SQLCHECK;

		EXEC SQL OPEN db_get_fil4 USING :sql_location;

		SQLCHECK;
		
		while(1) {
			EXEC SQL FETCH db_get_fil4 INTO :sql_q4;
			if(sqlca.sqlcode) {
				break;
			}
			fill_table4(&d, &sql_q4);
			printf(">>> %d %s %s\n", d.number,d.a_name,d.r_name);
		}
		EXEC SQL CLOSE db_get_fil4;
		SQLCHECK;
			
		EXEC SQL COMMIT;
	}
	return 0;
}
