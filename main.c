#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//FERHAT KAPLAN
//OTOPARK OTOMASYON SİSTEMİ
void AraclariListele();
int FiyatHesapla(int arabaDizi[10][4],int plaka)
{
	int i,j;
	int fiyat;
	for(i=0;i<10;i++)
	{
		if(arabaDizi[i][0]==plaka)
		     break;
    }

	int saat;
	if(arabaDizi[i][1]==1)
	{
		saat=arabaDizi[i][3]-arabaDizi[i][2];
		fiyat=5+(saat*1);
	}

	if(arabaDizi[i][1]==2)
	{
		saat=arabaDizi[i][3]-arabaDizi[i][2];
		fiyat=5+(saat*2);
    }

	if(arabaDizi[i][1]==3)
	{
		saat=arabaDizi[i][3]-arabaDizi[i][2];
		fiyat=5+(saat*3);
	}

	return fiyat;

}

int MaksFiyatBul(int fiyatDizi[10])
{
	int maks=fiyatDizi[0];
	int i,j;
	for(i=1;i<10;i++)
	{
		if(fiyatDizi[i]>maks)
		{
			maks=fiyatDizi[i];
		}
	}
	return maks;
}
int MinFiyatBul(int fiyatDizi[10])
{
	int min=fiyatDizi[0];
	int i,j;
	for(i=1;i<10;i++)
	{
		if(fiyatDizi[i]!=0)
		{
			if(fiyatDizi[i]<min)
			{
				min=fiyatDizi[i];
			}
		}

	}
	return min;
}
int arabaDizi[10][4]={{0,0,0,0},
                      {0,0,0,0},
                      {0,0,0,0},
                      {0,0,0,0},
                      {0,0,0,0},
                      {0,0,0,0},
                      {0,0,0,0},
                      {0,0,0,0},
                      {0,0,0,0},
                      {0,0,0,0}};
int main(int dizi, char *dizi_1[])
 {
	printf("\n\t>>>>>>| OTOPARK OTOMASYON SISTEMI|<<<<<< \t\n\n");
	int islemnumarasi=1;
	while(islemnumarasi!=0)
	{
		printf("\n(1)---> Arac ekle \n");
		printf("(2)---> Araclari listele \n");
		printf("(3)---> Arac fiyatini goruntule \n");
		printf("(4)---> Otoparktaki max ve min tutarli araclari goruntule\n\n");
		printf("Yapmak istediginiz islemin numarasini giriniz:");
		scanf("%d",&islemnumarasi);
		int yervarmi=0;
		int fiyatDizi[10];
		int x,i,j;
		if(islemnumarasi==1)
		{
			for(i=0;i<=9;i++)
			{
				if(arabaDizi[i][0]==0)
				{
					x=i;
					yervarmi=1;
					break;
                }
			}
			if(yervarmi==1)
			{
				printf("\nplakanizi giriniz:");
				scanf("%d",&arabaDizi[x][0]);
				printf("\nAracinizin tipini giriniz(1(otomobil)-2(minibus)-3(kamyonet)):");
				scanf("%d",&arabaDizi[x][1]);
				while(arabaDizi[x][1]<=0 || arabaDizi[x][1]>3)
				{
					printf("\nHATA=  ARAC TIPI 1,2 YA DA 3 OLABILIR\n");
					printf("\nAracinizin tipini giriniz(1(otomobil)-2(minibus)-3(kamyonet)):");
					scanf("%d",&arabaDizi[x][1]);
				}
				printf("\nAracin giris saati:");
				scanf("%d",&arabaDizi[x][2]);
				int kontrol=0;
				while(kontrol==0)
				{
					printf("\nAracin cikis saati:");
					scanf("%d",&arabaDizi[x][3]);
					if(arabaDizi[x][2]>arabaDizi[x][3])
					{
						kontrol=0;
						printf("\nCikis saati giris saatinden once olamaz !!");
					}
					else
					{
						kontrol=1;
					}
				}
				printf("\n**ARAC KAYDI ALINMISTIR.**\n\n");

			}
			else
			{
				printf("\nUZGUNUZ;Otopark kapasitesi dolmuþtur.");
			}
		}
		if(islemnumarasi==2)
		{
			printf("\n\nPLAKA\t    ARAC TIPI \t      GIRIS \t       CIKIS\n");
			printf("-------------------------------------------------------\n");
			i=0;j=0;

			while(arabaDizi[i][0]!=0)
			{
				for(j=0;j<4;j++)
				{
					printf("%d",arabaDizi[i][j]);
					printf(" \t\t");
				}
				printf("\n");
				i++;
				if(i==10)
				break;

			}

		}
		if(islemnumarasi==3)
		{
			int plaka;
			printf("\nplakanizi giriniz:");
			scanf("%d",&plaka);
			i=0;
			j=0;
			int bulunuyormu=1;
			while(bulunuyormu==1)
			{
				for(i=0;i<10;i++)
				{
					if(arabaDizi[i][0]!=plaka)
					{
						printf("\nBu plakaya sahip arac yok.Plakanizi tekrar giriniz. \n");
						printf("\nPlakinizi giriniz:");
						scanf("%d",&plaka);
						bulunuyormu=1;
					}
					else
					{
						bulunuyormu=0;
						break;
					}
				}

				printf("\n");
			}
			printf("ODENECEK TUTAR== %d",FiyatHesapla(arabaDizi,plaka));
		}
		if(islemnumarasi==4)
		{
			for(i=0;i<10;i++)
			{
				fiyatDizi[i]=FiyatHesapla(arabaDizi,arabaDizi[i][0]);
			}
			printf("\nMAX FIYATLI ARAC==%d",MaksFiyatBul(fiyatDizi));
			printf("\nMIN FIYATLI ARAC== %d",MinFiyatBul(fiyatDizi));

		}
	}

	return 0;
}
