#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void hosgeldinizFonksiyonu()
{
	printf("Bilgi yarismasina hosgeldiniz asagidaki kurallari okuyunuz\n"
		   "Yarismamiz puan sistemlidir\n"
		   "Lutfen kullanici adinizi dogru giriniz kayitli degilseniz kayit olunuz");
}
int secimFonksiyonu()
{
	int secim;
	printf("\nLutfen asagidaki seceneklerden birini seciniz\n[1]Giris Yap\n[2]Kayit Ol\n");
	scanf("%d", &secim);
	return secim;
}
int girisYapFonksiyonu(char isim[200], char sifre[200])
{
	char isimVeri[200];
	char sifreVeri[200];
	bool kontrol = false;
	while (kontrol == false)
	{

		printf("\nLutfen adinizi yaziniz=");
		scanf("%s", isimVeri);
		printf("\nLutfen parolanizi giriniz=");
		scanf("%s", sifreVeri);
		if (strcmp(isim, isimVeri) == 0 && strcmp(sifre, sifreVeri) == 0)
		{
			printf("\nSisteme hosgeldiniz");
			kontrol = true;
		}
		else
		{
			printf("\nHatali giris yaptiniz");
		}
	}
}
int kayitOlFonksiyonu()
{
	char isim[200];
	char sifre[200];
	printf("Lutfen bir isim giriniz=");
	scanf("%s", isim);
	printf("\nLutfen bir parola giriniz=");
	scanf("%s", sifre);
	printf("Basarili bir sekilde kayit oldunuz.");
	printf("\nGiris ekran�na y�nlendiriliyorsunuz....");
	girisYapFonksiyonu(isim, sifre);
}
int bilgiYarismasi()
{
	char cevap[2];
	int puan = 0;
	int can = 3;
	printf("\nYarisma basladi\n");
	printf("\nPuaniniz=%d", puan);

	while (can != 0)
	{

		if (puan == 0)
		{
			printf("\n[Soru-1]Asagidakilerden hangisi Turkiye Cumhuriyetinin baskentidir?\na-)Istanbul\nb-)Ankara\nc-)Izmir\nd-)Antakya\n");
			scanf("%s", cevap);
			if (strcmp(cevap, "b") == 0)
			{
				printf("\nDogru cevap\n");
				puan += 10,
					printf("\nPuaniniz=%d", puan);
			}
			else
			{
				printf("Hatali cevap,dogru cevap b sikkidir");
				printf("\nPuaniniz=%d", puan);
				can = can - 1;
				printf("\nCanininiz=%d", can);
			}
		}
		if (puan == 10)
		{

			printf("\n[Soru-2]Asagidakilerden hangisi Rusya baskentidir?\na-)Moskova\nb-)Ankara\nc-)Paris\nd-)Antakya\n");
			scanf("%s", cevap);
			if (strcmp(cevap, "a") == 0)
			{
				printf("\nDogru cevap\n");
				puan += 10,
					printf("\nPuaniniz=%d", puan);
			}
			else
			{
				printf("Hatali cevap,dogru cevap b sikkidir");
				printf("\nPuaniniz=%d", puan);
				can = can - 1;
				printf("\nCanininiz=%d", can);
			}
		}
		if (puan == 20)
		{

			printf("\n[Soru-3]Asagidakilerden hangisi T�rkiyededir?\na-)Moskova\nb-)Ankara\nc-)Paris\nd-)Amsterdam\n");
			scanf("%s", cevap);
			if (strcmp(cevap, "b") == 0)
			{
				printf("\nDogru cevap\n");
				puan += 10,
					printf("Puaniniz=%d", puan);
				can = 0;
			}
			else
			{
				printf("Hatali cevap,dogru cevap b sikkidir");
				printf("\nPuaniniz=%d", puan);
				can = can - 1;
				printf("\nCanininiz=%d", can);
			}
		}
	}
	return puan;
}
int yarismaSon(int puan)
{
	printf("\nYarismamiz sona ermistir.\nGuncel skorunuz=%d", puan);
}
int main()
{
	char isim[200] = "recep";
	char sifre[200] = "furkan";
	hosgeldinizFonksiyonu();
	int secim = secimFonksiyonu();
	if (secim == 1)
	{
		girisYapFonksiyonu(isim, sifre);
	}
	else if (secim == 2)
	{
		kayitOlFonksiyonu();
	}
	int skor = bilgiYarismasi();
	yarismaSon(skor);
	return 0;
}
