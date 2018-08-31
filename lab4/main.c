#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "ecpg.h" 

int main(int argc, char **argv){
  int status;
  status = db_connect();
  if (status){
    fprintf(stderr, "Ошибка подключения к базе данных\n");
    return 1;
  }
  
  int a;
  table_filter filter;
  while(1){
    printf("1 - запрос 7.a\n");  
    printf("2 - запрос 7.b\n");
    printf("3 - запрос 7.c\n");
    printf("4 - запрос 7.d\n");
    printf("0 - выход\n");
    printf("Введите номер запроса: ");
    scanf("%d",&a);
    system("clear");
    switch(a){
    	case 1:{
    			getchar();
			status = db_get_fil(filter, 1);
			if (status){
				fprintf(stderr, "Возникла ошибка, попробуйте еще раз. \n");
				return 1;
			}
			break;
		}

		case 2:{
			getchar();
			printf("Введите total: ");
			scanf("%d" ,&filter.total);
			status = db_get_fil(filter, 2);
			if (status){
				fprintf(stderr, "Возникла ошибка, попробуйте еще раз. \n");
			   	return 1;
			}
			break;
		}
		case 3:{
			getchar();
			printf("Введите название фирмы: ");
			scanf("%s", filter.r_name);
			status = db_get_fil(filter, 3);
			if (status){
				fprintf(stderr, "Возникла ошибка, попробуйте еще раз. \n");
			    	return 1;
			}
			break;
		}

		case 4:{
		  	getchar();
			printf("Введите  расположение фирмы: ");
			scanf("%s", filter.location);
			status = db_get_fil(filter, 4);
			if (status){
				fprintf(stderr, "Возникла ошибка, попробуйте еще раз. \n");
			    	return 1;
			}
			break;
		}

		case 0:{
			return 0;
		}
	}
  }
}
