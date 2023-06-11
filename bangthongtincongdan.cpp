#include <stdio.h> //dung chuc nang printf,scanf
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h> //hoat dong chuoi

COORD coord = {0,0};

//chuc nang:di chuyen vi tri con tro den toa do cot x hang y
void gotoxy(int x,int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

int main()
{
    FILE *fp, *ft; 
    char another, choice;

 
    struct emp
    {
    	char ho[15];
    	char tendem[15];
        char ten[15];
        int ngaysinh;
    	int thangsinh;
    	int namsinh;
        char nhommau[2];
        char gioitinh[10];
        char tinhtranghonnhan[15];
        char noidangkykhaisinh[20];
        char quequan[40];
        char dantoc[10];
        char quoctich[15];
        char tongiao[10];
        float scmnd;
        char noiothuongtru[40];
        char noiohientai[40];
        
    };

    struct emp e;

    char empname[40];

    long int recsize;

    fp = fopen("EMP.DAT","rb+");
    if(fp == NULL)
    {
        fp = fopen("EMP.DAT","wb+");
        if(fp == NULL)
        {
            printf("Khong the mo tep");
            exit(1);
        }
    }

    recsize = sizeof(e);

    while(1)
    {
        system("cls");
        gotoxy(30,7);
        printf("Thong tin cong dan trong khu vuc phuong Tan Thoi Nhat");
        gotoxy(1,10);
        printf("1. Nhap thong tin cua cong dan.");
        gotoxy(1,12);
        printf("2. Danh sach thong tin cua ca nhan.");
        gotoxy(1,14);
        printf("3. Chinh sua thong tin trong danh sach.");
        gotoxy(1,16);
        printf("4. Xoa danh sach.");
        gotoxy(1,18);
        printf("5. Thoat.");
        gotoxy(1,20);
        printf("Xin chon yeu cau cua ban: ");
        fflush(stdin);
        choice  = getche();
        switch(choice)
        {
        case '1':
            system("cls");
            fseek(fp,0,SEEK_END);
            
            another = 'y';
            while(another == 'y')
            {
                printf("\nNhap ho: ");
                scanf("%s",&e.ho);
                
                printf("Nhap ten dem: ");
                scanf("%s", &e.tendem);
                
                printf("Nhap ten: ");
                scanf("%s", &e.ten);

				printf("\nNhap ngay sinh: ");
				scanf("%d",&e.ngaysinh);
				printf("Nhap thang sinh: ");
				scanf("%d",&e.thangsinh);
				printf("Nhap nam sinh: ");
				scanf("%d",&e.namsinh);
				
				printf("\nNhap nhom mau: ");
				scanf("%s",&e.nhommau);
				
				printf("\nNhap gioi tinh: ");
				scanf("%s",&e.gioitinh);
				
				printf("\nNhap Tinh trang hon nhan:");
				scanf("%s",&e.tinhtranghonnhan);
				
				printf("\nNhap noi dang ky khai sinh: ");
				scanf("%s",&e.noidangkykhaisinh);
				
				printf("\nNhap que quan: ");
				scanf("%s",&e.quequan);
				
				printf("\nNhap dan toc: ");
				scanf("%s",&e.dantoc);
				
				printf("\nNhap quoc tich : ");
				scanf("%s",&e.quoctich);
				
				printf("\nNhap ton giao: ");
				scanf("%s",&e.tongiao);
				
				printf("\nNhap so chung minh nhan dan: ");
				scanf("%f",&e.scmnd);
				
				printf("\nNhap noi thuong tru: ");
				scanf("%s",&e.noiothuongtru);
				
				printf("\nNhap noi o hien tai: ");
				scanf("%s",&e.noiohientai);
				
                fwrite(&e,recsize,1,fp);

                printf("\nAdd another record(y/n) ");
                fflush(stdin);
                another = getche();
            }
            break;
    		 case '2':
            system("cls");
            rewind(fp);
            while(fread(&e,recsize,1,fp)==1)
            {
            	
                printf("\n\n\n1.Ho,ten dem va ten:%s %s %s",e.ho,e.tendem,e.ten);
            	printf("\n\n2.Ngay/thang/nam sinh: %d/ %d/ %d		3.Nhom mau: %s",e.ngaysinh,e.thangsinh,e.namsinh,e.nhommau);
            	printf("\n\n4.Gioi tinh: %s 				5.Tinh trang hon nhan: %s",e.gioitinh,e.tinhtranghonnhan);
            	printf("\n6.Noi dang ky khai sinh: %s",e.noidangkykhaisinh);
            	printf("\n\n7.Que quan: %s",e.quequan);
            	printf("\n\n8.Dan toc: %s					9.Quoc tich: %s",e.dantoc,e.quoctich);
            	printf("\n\n10.Ton giao: %s				11.So chung minh nhan dan: %.0f",e.tongiao,e.scmnd);
            	printf("\n\n12.Noi thuong tru: %s",e.noiothuongtru);
            	printf("\n\n13.Noi o hien tai: %s",e.noiohientai);
			}
            getch();
            break;

        case '3': 
            system("cls");
            another = 'y';
            while(another == 'y')
            {
                printf("\nNhap ten cua cong dan can chinh sua: ");
                scanf("%s", empname);
                rewind(fp);
                while(fread(&e,recsize,1,fp)==1) 
                {
                    if(strcmp(e.ten,empname) == 0)
                    {
                       printf("\nNhap ho can thay doi: ");
                scanf("%s",&e.ho);
                
                printf("Nhap ten dem can thay doi: ");
                scanf("%s", &e.tendem);
                
                printf("Nhap ten can thay doi: ");
                scanf("%s", &e.ten);

				printf("\nNhap ngay sinh muon can doi: ");
				scanf("%d",&e.ngaysinh);
				printf("Nhap thang sinh muon can doi: ");
				scanf("%d",&e.thangsinh);
				printf("Nhap nam sinh muon can doi: ");
				scanf("%d",&e.namsinh);
				
				printf("\nNhap nhom mau muon can doi: ");
				scanf("%s",&e.nhommau);
				
				printf("\nNhap gioi tinh muon can doi: ");
				scanf("%s",&e.gioitinh);
				
				printf("\nNhap Tinh trang hon nhan can thay doi:");
				scanf("%s",&e.tinhtranghonnhan);
				
				printf("\nNhap noi dang ky khai sinh can thay doi: ");
				scanf("%s",&e.noidangkykhaisinh);
				
				printf("\nNhap que quan can thay doi: ");
				scanf("%s",&e.quequan);
				
				printf("\nNhap dan toc can thay doi: ");
				scanf("%s",&e.dantoc);
				
				printf("\nNhap quoc tich can thay doi: ");
				scanf("%s",&e.quoctich);
				
				printf("\nNhap ton giao can thay doi: ");
				scanf("%s",&e.tongiao);
				
				printf("\nNhap so chung minh nhan dan: ");
				scanf("%f",&e.scmnd);
				
				printf("\nNhap noi thuong tru can thay doi: ");
				scanf("%s",&e.noiothuongtru);
				
				printf("\nNhap noi o hien tai can thay doi: ");
				scanf("%s",&e.noiohientai);
				
                        fseek(fp,-recsize,SEEK_CUR);
                        fwrite(&e,recsize,1,fp);
                        break;
                    }
                }
                printf("\nTiep tuc chinh sua thong tin cua cong dan (y/n):");
                fflush(stdin);
                another = getche();
            }
            break;
        case '4':
            system("cls");
            another = 'y';
            while(another == 'y')
            {
                printf("\nNhap ten cong dan can xoa: ");
                scanf("%s",empname);
                ft = fopen("Temp.dat","wb"); 
                rewind(fp);
                while(fread(&e,recsize,1,fp) == 1)
                {
                    if(strcmp(e.ten,empname) != 0)
                    {
                        fwrite(&e,recsize,1,ft);
                    }
                }
                fclose(fp);
                fclose(ft);
                remove("EMP.DAT");
                rename("Temp.dat","EMP.DAT");
                fp = fopen("EMP.DAT", "rb+");
                printf("Tiep tuc xoa thong tin cua cong dan(y/n):");
                fflush(stdin);
                another = getche();
            }
            break;
        case '5':
            fclose(fp);
            exit(0);
        }
    }
    return 0;
}
