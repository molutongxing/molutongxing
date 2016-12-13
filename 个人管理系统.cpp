#include <stdio.h>
#include <time.h>
#include <stdlib.h>
float money;//总金额
int n; //用于选择菜单

void init();//初始函数
void shouru();//收入函数
void display();//显示主菜单
void zhichu();//支出函数
void display1();
void mid();


void main(){//主函数
/*	FILE *fp;
	char s[80];
	int a ;
	if ((fp = fopen("G://File//data.txt","r+")) != NULL)
	{
		fgets(s,10,fp);
		a = (int) s;
		money = (float)a;
	}*/
	init();
}
void init(){
	display();//显示主菜单
	printf("请选择业务类型:");
	scanf("%d",&n);
	while(1){
		switch(n){
		case 1:
			system("cls");//清屏
			shouru();
			break;
		case 2:
			system("cls");
			zhichu();
			break;
		case 3:
			system("cls");
			mid();
			break;
		case 4:
			exit(0);
			printf("谢谢您的使用,再见!");
			break;
		default:
			system("cls");
			printf("输入错误,请重新输入:\n");
			init();
			break;
		}
	}	
}
void shouru(){
	float d;
	char c;
//	printf("%6.2f\n", money);
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
		system("cls");
		init();
	}else{
		printf("出入错误,请重新输入!!");
	}
}
void display(){
	printf("┌──────────────────┐\n");
	printf("│          1.收入信息添加            │\n");
	printf("│          2.支出信息添加            │\n");
	printf("│          3.查询财务信息            │\n");
	printf("│          4.退出                    │\n");
	printf("└──────────────────┘\n");
}
void display1(){
	printf("┌──────────────────┐\n");
	printf("│          1.按年查询                │\n");
	printf("│          2.按月查询                │\n");
	printf("│          3.按日查询                │\n");
	printf("│          4.退出                    │\n");
	printf("└──────────────────┘\n");
}
void zhichu(){
	float d;
	char c;
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
		system("cls");
		init();
	}else{
		printf("出入错误,请重新输入!!");
	}
}
void mid(){
	display1();
	int n;
	scanf("%d",&n);
	while(1){
		switch(n){
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			system("cls");//清屏
			init();
			break;
		default:
			system("cls");
			printf("输入错误,请重新输入!!!\n");
			mid();
			break;
		}
	}
}