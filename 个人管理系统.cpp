#include <stdio.h>
#include <time.h>
#include <stdlib.h>
float money;//�ܽ��
int n; //����ѡ��˵�

void init();//��ʼ����
void shouru();//���뺯��
void display();//��ʾ���˵�
void zhichu();//֧������
void display1();
void mid();


void main(){//������
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
	display();//��ʾ���˵�
	printf("��ѡ��ҵ������:");
	scanf("%d",&n);
	while(1){
		switch(n){
		case 1:
			system("cls");//����
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
			printf("лл����ʹ��,�ټ�!");
			break;
		default:
			system("cls");
			printf("�������,����������:\n");
			init();
			break;
		}
	}	
}
void shouru(){
	float d;
	char c;
//	printf("%6.2f\n", money);
	printf("��������������:");
	scanf("%f",&d);
	printf("%6.2f\n",d);
	money += d;
	printf("����ɹ�!!!");
	printf("\n���ڵ��ܽ��Ϊ:%6.2f\n",money);
	printf("�Ƿ��������:(y/n)\n");
	getchar();
	c = getchar();
	if (c == 'y'){
		shouru();
	}else if(c == 'n'){
		system("cls");
		init();
	}else{
		printf("�������,����������!!");
	}
}
void display(){
	printf("����������������������������������������\n");
	printf("��          1.������Ϣ���            ��\n");
	printf("��          2.֧����Ϣ���            ��\n");
	printf("��          3.��ѯ������Ϣ            ��\n");
	printf("��          4.�˳�                    ��\n");
	printf("����������������������������������������\n");
}
void display1(){
	printf("����������������������������������������\n");
	printf("��          1.�����ѯ                ��\n");
	printf("��          2.���²�ѯ                ��\n");
	printf("��          3.���ղ�ѯ                ��\n");
	printf("��          4.�˳�                    ��\n");
	printf("����������������������������������������\n");
}
void zhichu(){
	float d;
	char c;
	printf("%6.2f\n",money);
	printf("����������֧��:");
	scanf("%f",&d);
	printf("%6.2f\n",d);
	money -= d;
	printf("����ɹ�!!!");
	printf("\n���ڵ��ܽ��Ϊ:%6.2f\n",money);
	printf("�Ƿ��������:(y/n)\n");
	getchar();
	c = getchar();
	if (c == 'y'){
		zhichu();
	}else if(c == 'n'){
		system("cls");
		init();
	}else{
		printf("�������,����������!!");
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
			system("cls");//����
			init();
			break;
		default:
			system("cls");
			printf("�������,����������!!!\n");
			mid();
			break;
		}
	}
}