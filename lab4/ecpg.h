#ifndef TABLE_H
#define TABLE_H

#define name_len 30
#define location_len 30

int db_connect();

typedef struct{ 
	int total;
	char r_name[name_len];
	char location[location_len];
} table_filter;

int db_get_fil(const table_filter filter, int quer);

typedef struct q1_ {
	char a_name[name_len];
} q1;

typedef struct q2_ {
	char r_name[name_len];
	int commission;
} q2;

typedef struct q3_ {
	char a_name[name_len];
	char address[name_len];
} q3;

typedef struct q4_ {
	int number;
	char a_name[name_len];
	char r_name[name_len];
} q4;


#endif 


