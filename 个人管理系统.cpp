#include <stdio.h>
#include <time.h>
#include <stdlib.h>
float money=0;//总金额
char c; 
int n; //用于选择菜单

void init();//初始函数
void shouru();//收入函数
void display();//显示主菜单
void zhichu();//支出函数
void display1();//查询子菜单
void query_year();//按年查询函数
void query_month();//按月查询函数
void query_day();//按天查询函数
void mid();


void main(){//主函数
	init();
}
void init(){  //初始化函数，显示主界面
	display();//显示主菜单
    char *wday[]={"日","一","二","三","四","五","六"};
    time_t timep;
	struct tm *p;
	time(&timep);
	p=localtime(&timep); /*取得当地时间*/
	printf ("%d年%d月%d日 ", (1900+p->tm_year),( 1+p->tm_mon), p->tm_mday);
	printf("星期%s 时间:%d:%d:%d\n", wday[p->tm_wday],p->tm_hour, p->tm_min, p->tm_sec);
	printf("请选择业务类型:");
	scanf("%d",&n);
	while(1){
		switch(n){
		case 1:
			shouru();break;
		case 2:
			zhichu();	break;
		case 3:
			mid();	break;
		case 4:
			printf("谢谢您的使用,再见!\n"); exit(0); break;
		default:
			printf("输入错误,请重新输入:\n");init();break;
		}
	}	
}
void shouru(){//收入函数，添加自己今天的收入
	float d;
	printf("请输入今天的收入:");
	scanf("%f",&d);
	printf("%6.2f\n",d);
	money += d;
	printf("保存成功!!!");
	printf("\n现在的总金额为:%6.2f\n",money);
	printf("是否继续输入:(y/n)\n");
	getchar();
	c = getchar();
	if (c == 'y'){
		shouru();
	}else if(c == 'n'){
		init();
	}else{
		printf("出入错误,已回到主菜单!!\n");
		init();
	}
}
void display(){//主菜单
	printf("┌──────────────────┐\n");
	printf("│          1.收入信息添加            │\n");
	printf("│          2.支出信息添加            │\n");
	printf("│          3.查询财务信息            │\n");
	printf("│          4.退出                    │\n");
	printf("└──────────────────┘\n");
}
void display1(){//查询菜单
	printf("┌──────────────────┐\n");
	printf("│          1.按月查询                │\n");
	printf("│          2.按日查询                │\n");
	printf("│          3.返回主菜单              │\n");
	printf("└──────────────────┘\n");
}
void zhichu(){//支出函数
	float d;
	printf("%6.2f\n",money);
	printf("请输入今天的支出:");
	scanf("%f",&d);
	printf("%6.2f\n",d);
	money -= d;
	printf("保存成功!!!");
	printf("\n现在的总金额为:%6.2f\n",money);
	printf("是否继续输入:(y/n)\n");
	getchar();
	c = getchar();
	if (c == 'y'){
		zhichu();
	}else if(c == 'n'){
		init();
	}else{
		printf("出入错误，已回到主菜单!!\n");
		init();
	}
}
void mid(){//查询菜单选择
	display1();//显示查询界面
	int n;
	scanf("%d",&n);
	while(1){
		switch(n){
		case 1:
              query_month();	break;
		case 2:
			query_day();	break;
		case 3:
			init();	break;
		default:
			printf("输入错误,请重新输入!!!\n");mid();break;
		}
	}
}
int funmonth(char c,int a) {
	switch(c){
        case 'a':
			if(a>1) {printf("查看%d月信息  ",(a-1)); a-=1;}
			else{	printf("这已经是一月啦!!!\n");} break;
         case 'd':
			 if(a<12) { printf("查看%d月信息、",(a+1)); a+=1; }
		   else{	printf("这已经是十二月啦!!!\n");} break; 
		 case '0':
			 mid();break;
		 default:
			 printf("输入错误!!!\n");break;
     } 
	return a;
}

void query_month(){
	time_t timep;
	struct tm *p;
	time(&timep);
	p=localtime(&timep);
	int flag=1, a=(1+p->tm_mon);
	printf("现在是%d月\n",(1+p->tm_mon));
	do{
	printf("按a、d选择查看前一个月或者后一个月信息,按0返回上一级\n");
	fflush(stdin);
	c = getchar();
	a=funmonth(c,a);
	printf("继续查看么？yes/no (输入0则退出):");
	scanf("%d",&flag);
	fflush(stdin);
	}while(flag);
}
int funday(char c,int a) {
	switch(c){
        case 'a':
			if(a>1) {printf("查看%d号信息  ",(a-1)); a-=1;}
			else{	printf("这已经是一号啦!!!\n");} break;
         case 'd':
			 if(a<31) { printf("查看%d号信息、",(a+1)); a+=1; }
		   else{	printf("这已经是本月最后一天啦!!!\n");} break; 
		 case '0':
			 mid();break;
		 default:
			 printf("输入错误!!!\n");break;
     } 
	return a;
}
void query_day(){
	time_t timep;
	struct tm *p;
	time(&timep);
	p=localtime(&timep);
	int flag=1, a=p->tm_mday;
	printf("现在是%d号",p->tm_mday);
	do{
		printf("按a、d选择查看前一天或者后一天信息,按0返回上一级\n");
		fflush(stdin);
		c = getchar();
		a=funday(c,a);
		printf("继续查看么？yes/no (输入0则退出):");
		scanf("%d",&flag);
		fflush(stdin);
	}while(flag);
}