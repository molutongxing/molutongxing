#include <stdio.h>
#include <time.h>
#include <stdlib.h>
char c; struct money{int month; int day;int hour; int min;float m; char information[20];};
int n; //����ѡ��˵�

void init();//��ʼ����
void shouru();//���뺯��
void display();//��ʾ���˵�
void zhichu();//֧������
void display1();//��ѯ�Ӳ˵�
void query_year();//�����ѯ����
void query_month();//���²�ѯ����
void query_day();//�����ѯ����
void mid();
void write_file(struct money mm){	
	FILE *fp;
	if((fp=fopen("person.txt","a"))==NULL)
	{
		printf("open File error");
		getchar();
		exit(1);
	}
	fprintf(fp,"%d.%d.%d.%d.%6.2f.%s\r\n",mm.month,mm.day,mm.hour,mm.min,mm.m,mm.information);
	fclose(fp);
}
void read_file_mon(struct money *mm,int i){
	FILE *fp;int x=1;
	if((fp=fopen("person.txt","r"))==NULL)
	{
		printf("open File error");
		getchar();
		exit(1);
	}
	while(!feof(fp)){
		fscanf(fp,"%d.%d.%d.%d.%f.%s  ",&mm->month,&mm->day,&mm->hour,&mm->min,&mm->m,&mm->information);

		if(mm->month == i){
			printf("��%d��:",x++);
			printf("%d��%d�� %d:%d %6.2f %s\n",mm->month,mm->day,mm->hour,mm->min,mm->m,mm->information);
		}
	}
}
void read_file_day(struct money *mm,int i,int j){
	FILE *fp;int x=1;
	if((fp=fopen("person.txt","r"))==NULL)
	{
		printf("open File error");
		getchar();
		exit(1);
	}
	while(!feof(fp)){
		fscanf(fp,"%d.%d.%d.%d.%f.%s  ",&mm->month,&mm->day,&mm->hour,&mm->min,&mm->m,&mm->information);
		if(mm->month ==j&&mm->day == i){
			printf("��%d��:",x++);
			printf("%d��%d�� %d:%d %6.2f %s\n",mm->month,mm->day,mm->hour,mm->min,mm->m,mm->information);
		}
	}
}
void main(){//������
	init();	
}
void init(){  //��ʼ����������ʾ������
	display();//��ʾ���˵�
	char *wday[]={"��","һ","��","��","��","��","��"};
    time_t t;struct tm *p;time(&t);
//	p=ctime(&t) ;
	p=localtime(&t) ; /*ȡ�õ���ʱ��*/
	printf ("%d��%d��%d�� ", (1900+p->tm_year),( 1+p->tm_mon), p->tm_mday);
	printf("����%s ʱ��:%d:%d:%d\n", wday[p->tm_wday],p->tm_hour, p->tm_min, p->tm_sec);
	printf("��ѡ��ҵ������:");
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
			printf("лл����ʹ��,�ټ�!\n"); exit(0); break;
		default:
			printf("�������,����������:\n");init();break;
		}
	}	
}
void display(){//���˵�
	printf("����������������������������������������\n");
	printf("��          1.������Ϣ���            ��\n");
	printf("��          2.֧����Ϣ���            ��\n");
	printf("��          3.��ѯ������Ϣ            ��\n");
	printf("��          4.�˳�                    ��\n");
	printf("����������������������������������������\n");
}
void display1(){//��ѯ�˵�
	printf("����������������������������������������\n");
	printf("��          1.���²�ѯ                ��\n");
	printf("��          2.���ղ�ѯ                ��\n");
	printf("��          3.�������˵�              ��\n");
	printf("����������������������������������������\n");
}
void shouru(){//���뺯��������Լ����������
	float d;char ch;struct money mm;time_t timep;struct tm *p;time(&timep);p=localtime(&timep);
	do{
	printf("��������������:");scanf("%f",&d);
	fflush(stdin);printf("��ע:");scanf("%s",mm.information);fflush(stdin);
	printf("\n����Ϊ:%6.2f$,��Դ:%s\n",d,mm.information);
	mm.month=(p->tm_mon+1);mm.day=p->tm_mday;mm.hour=p->tm_hour;mm.min=p->tm_min;mm.m=d;
	write_file(mm);
	printf("�Ƿ��������:(y/n)\n");
	ch=getchar();getchar();
	}while(ch =='Y'||ch == 'y');
	printf("�ѻص����˵�!!!\n");init();
}
void zhichu(){//֧������
	float d;char ch;struct money mm;time_t timep;struct tm *p;time(&timep);p=localtime(&timep);
	do{
	printf("����������֧��:");scanf("%f",&d);
	fflush(stdin);printf("��ע:");scanf("%s",mm.information);fflush(stdin);
	printf("\n֧��Ϊ:%6.2f$,����%s\n",d,mm.information);
	mm.month=(p->tm_mon+1);mm.day=p->tm_mday;mm.hour=p->tm_hour;mm.min=p->tm_min;mm.m=-d;
	write_file(mm);
	printf("�Ƿ��������:(y/n)\n");
	ch=getchar();getchar();
	}while(ch =='Y'||ch == 'y');
	printf("�ѻص����˵�!!!\n");init();
}
void mid(){//��ѯ�˵�ѡ��
	display1();//��ʾ��ѯ����
	int n;printf("��ѡ��ҵ������:");
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
			printf("�������,����������!!!\n");mid();break;
		}
	}
}
int funmonth(char c,int a) {
	time_t timep;struct tm *p;time(&timep);p=localtime(&timep);struct money mm;
	switch(c){
        case 'a':
			if(a>1) {printf("�鿴%d����Ϣ\n",(a-1));read_file_mon(&mm,a-1);  a-=1;}
			else{	printf("���Ѿ���һ����!!!\n");} break;
         case 'd':
			 if(a<12) { printf("�鿴%d����Ϣ\n",(a+1));read_file_mon(&mm,a+1); a+=1; }
		   else{	printf("���Ѿ���ʮ������!!!\n");} break; 
		 case '0':
			 mid();break;
		 default:
			 printf("�������!!!\n");break;
     } 
	return a;
}

void query_month(){
	struct money mm;
	time_t timep;struct tm *p;time(&timep);p=localtime(&timep);
	int flag=1, a=(1+p->tm_mon);
	printf("������%d��,������Ϣ����:\n",(1+p->tm_mon));
	read_file_mon(&mm,a);
	do{
	printf("��a��dѡ��鿴ǰһ���»��ߺ�һ������Ϣ,��0������һ��\n");
	fflush(stdin);
	c = getchar();
	a=funmonth(c,a);
	printf("�����鿴ô��yes/no (����0���˳�):");
	scanf("%d",&flag);
	fflush(stdin);
	}while(flag);
}
int funday(char c,int a) {
	time_t timep;struct tm *p;time(&timep);p=localtime(&timep);struct money mm;int b=(p->tm_mon+1);
	switch(c){
        case 'a':
			if(a>1) {printf("�鿴%d����Ϣ\n",(a-1));read_file_day(&mm,a,b); a-=1;}
			else{	printf("���Ѿ���һ����!!!\n");} break;
         case 'd':
			 if(a<31) { printf("�鿴%d����Ϣ\n",(a+1));read_file_day(&mm,a,b); a+=1; }
		   else{	printf("���Ѿ��Ǳ������һ����!!!\n");} break; 
		 case '0':
			 mid();break;
		 default:
			 printf("�������!!!\n");break;
     } 
	return a;
}
void query_day(){
	time_t timep;struct tm *p;time(&timep);p=localtime(&timep);struct money mm;
	int flag=1, a=p->tm_mday,b=(p->tm_mon+1);
	printf("������%d��\n",p->tm_mday);
	read_file_day(&mm,a,b);
	do{
		printf("��a��dѡ��鿴ǰһ����ߺ�һ����Ϣ,��0������һ��\n");
		fflush(stdin);
		c = getchar();
		a=funday(c,a);
		printf("�����鿴ô��yes/no (����0���˳�):");
		scanf("%d",&flag);
		fflush(stdin);
	}while(flag);
}