#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <conio.h>
#define PI 3.141593
#define CARPAN PI/180
#include <string>
#include <process.h>
using namespace std;

void Program1()
{
double j=0; 
char inf[10]="INFINITY";
	cout<<"   Problem 1\n";
	cout<<"   ----------------\n";
	cout<<"\n";
	cout<<"   0 Dereceden 90 dereceye kadar açıların onar artanlı olarak sin, cos, tan, cotan, degerlerini içeren bir matrisi         oluşturan C programı\n";
	cout<<"\n";
cout<<"\t Açı: \t Sin: \t\t Cos: \t\t Tan: \t\t Cotan: \t \n";
for(float i=0;i<=90;i+=10)
{
	j=i*CARPAN;
	if(i==0)
	{
		printf("\t %0.0f \t %0.6f \t %0.6f \t %0.6f \t %s \n",i,sin(j),cos(j),tan(j),inf);
	}
	else if(i==90)
	{
		printf("\t %0.0f \t %0.6f \t %0.6f \t %s \t %0.6f \n",i,sin(j),cos(j),inf,1/tan(j));
	}
	else
	{
		printf("\t %0.0f \t %0.6f \t %0.6f \t %0.6f \t %0.6f \n",i,sin(j),cos(j),tan(j),1/tan(j));
	}	
}
	cout<<"\n";
	cout<<"\n";
}
float f(float x)
{
	return pow(x,5)-pow(x,4)-pow(x,3)-2*pow(x,2);
}
float df(float x)
{
	return 5*pow(x,4)-4*pow(x,3)-3*pow(x,2)-4*x;
}

int program4()
{
	cout<<"   Problem 2\n";
	cout<<"   ----------------\n";
	cout<<"\n";
	cout<<"   y=(x^2)/(x+1) ve y=(x^3)/(x^3+2) fonksiyonlarının varsa kesim noktalarından birini bulan C programı\n";
	cout<<"\n";
	int itr,maxitr=1000;
	float h,x0,x1,hata=0.001;
	float sonuc=0;
	cout<<"   X0 Girin: ";
	cin>>x0;
	cout<<"   Epsilon degeri girin: ";
	cin>>hata;
	cout<<"\n";
	for(itr=1;itr<=maxitr;itr++)
	{
		h=f(x0)/df(x0);
		x1=x0-h;
		printf("   Tahmin %3d, Fonk.Değeri= %9.5f \n",itr,x1);
		if(fabs(h)<hata)
		{
			printf("   Newton Raphson metodu %3d tahmin ile sonucu %9.5f olarak buldu \n",itr,x1);
	   		sonuc=f(x1);
			printf("   Bu değer fonksiyonu %f değerine götürüyor.\n",sonuc);
			return 0;
		}
		x0=x1;
	}
	printf("   Gerekli çözüm yakınsamıyor veya tahmin sayısı  yetersiz\n");
	return 1;
	cout<<"\n";
	cout<<"\n";
}

void Program2()
{	
cout<<"   Problem 2\n";
cout<<"   ----------------\n";
cout<<"\n";
cout<<"   y=(x^5+4)/(x^3+2) fonsiyon degerlerini x=(-40,40) aralığı için birer artimla hesaplayan ve bu aralık için\n";
cout<<"   fonksiyonun  maximum ve minimum degerlerini bulan C programı\n";
	cout<<"\n";
	double y=0;
	int x=0;
	double deger[81];
	string secim;
	cout<<" x=(-40,40) Aralığında y degerleri goruntulensin mi? (e/h): ";
	cin>>secim;
	cout<<"\n";
	cout<<" İstenilen aralıkta y değerleri: \n";
	cout<<" -----------------------------------\n";
	for(int i=-40;i<=40;i++)
	{	
			for(i;i<41;i++)
			{
				for(i;i<41;i++)
				{
					y=(pow(i,5)+4)/(pow(i,3)+2);
					deger[x]=y;
					if(secim=="e"||secim=="E")
					{
					//cout<<"\t(X="<<i<<" y="<<deger[x]<<")\t";
					printf("(X=%d y=%0.7f)\t",i,deger[x]);
					}
					x++;	
				}
				cout<<"\n";
				
			double enbuyuk=deger[0];
			double enkucuk=deger[0];
			int n=sizeof(deger)/sizeof(deger[0]);
			for(int ii;ii<n;ii++)
			{
				if(deger[ii]<enkucuk)
				{
					enkucuk=deger[ii];
				}
			}
				for(int ii;ii<n;ii++)
			{
				if(deger[ii]>enbuyuk)
				{
					enbuyuk=deger[ii];
				}
			}
			cout<<"\n";
			cout<<"En buyuk deger X=-40 için =>"<<enbuyuk<<"\n";
			cout<<"En kucuk deger X=1   için =>"<<enkucuk<<"\n";
		}
}
	cout<<"\n";
	cout<<"\n";
	
}

void Program3()
{
	/*Bir kare matrisin esas köşegeni üzerindeki elemanlarının toplamını ve diğer köşegeni üzerindeki
elemanlarının çarpımını en az işlem sayısı ve en az çevrimle hesaplatacak bir C programı yazınız...*/
cout<<"   Problem 3\n";
cout<<"   ----------------\n";
cout<<"\n";
cout<<"   Bir kare matrisin esas köşegeni üzerindeki elemanlarının toplamını ve diğer köşegeni üzerindeki\n";
cout<<"   elemanlarının çarpımını en az işlem sayısı ve en az çevrimle hesaplatacak bir C programı yazınız...\n";

int matris[5][5]={26,18,-3,27,15,66,-46,89,-13,34,76,12,95,82,34,-1,22,-56,13,42,89,90,-83,7,5};
int toplam=0;
int y=4;
int carpim=1;
cout<<"\n";
for(int i=0;i<5;i++)
{
	cout<<"   |\t";
	for(int j=0;j<5;j++)
	{
		cout<<matris[i][j]<<"   \t";			
	}
	toplam+=matris[i][i];
	cout<<"   |\n";
}
cout<<"\n";
for(int x=0;x<5;x++)
{
	carpim*=matris[x][y];
	y--;
}
cout<<"   Matrisi için esas köşegen üzerindeki elemanların toplamı = "<<toplam<<"\n";
cout<<"   Diğer köşegen üzerindeki elemanların çarpımı = "<<carpim<<"\n";
cout<<"\n";
	cout<<"\n";
	
}

float primHesapla(float satismik)
{
	float prim=0;
	if(satismik<=50)
	{
		cout<<"   Satış elemanının yaptığı ilk 50 parçalık kısmı için prim 1.5$\n";
		prim += satismik*1.5;
		printf("   Hesaplanan Prim = %0.6f$",prim);
	}
	else if(satismik<=100)
	{
		cout<<"   Satış elemanının yaptığı ilk 50 parçalık kısmı için prim 1.5$\n";
		prim += 50*1.5+(satismik-50)*2;
		cout<<"   Geri Kalan "<<(satismik-50)<<" Kısmı için ise 2$'dır\n";
		printf("   Hesaplanan Prim = %0.6f$",prim);
		//cout<<"  -> Hesaplanan prim = "<<prim<<"\n";
	}
	else if(satismik >100)
	{
		cout<<"   Satış elemanının yaptığı ilk 50 parçalık kısmı için prim 1.5$\n";
		cout<<"   Geri Kalan "<<"50 Kısım için ise 2$'dır\n";
		if(satismik>50)
		{	
			cout<<"   Geri Kalan "<<(satismik-150)<<" parçalık Kısmı için ise 2.5$'dır\n";
		}
		else
		{
			cout<<"   Geri Kalan "<<(satismik-50)<<" parçalık Kısmı için ise 2$'dır\n";
		}
		prim+= 50*1.5+50*2+(satismik-100)*2.5;
		printf("   Hesaplanan Prim = %0.6f$",prim);	
	}
}

void program5()
{
	float SatisMiktar=0;
	cout<<"   Problem 5\n";
	cout<<"   ----------------\n";
	cout<<"   Bir satış danışmanı aşağıdaki kurallara göre prim almaktadır.\n";
	cout<<"   Satış <= 50 ise Prim = Satış * 1.5$.\n";
	cout<<"   Satış <= 100 ise Prim = 50 * 1.5$ + (Satış - 50) * 2$.\n";
	cout<<"   Satış >100 ise Prim = 50 * 1.5$ + 50 * 2$ + (Satış-100) * 2.5$";
	cout<<"\n";
	cout<<"   Bu kurallara göre satış elemanının alacağı primi hesaplayan C programı...\n";
	cout<<"\n";
	cout<<"\n";
	cout<<"   Hesaplamalar\n";
	cout<<"   -----------------\n";
	cout<<"   Satış Miktarını Girin: ";
	cin>>SatisMiktar;
	cout<<"\n";
	primHesapla(SatisMiktar);
	cout<<"\n";
	cout<<"\n";	
}

main()
{
menu:
system("cls"); 
setlocale(LC_ALL, "Turkish");
int secim=0;
cout<<"\n";
cout<<"\t\t\t\t Gazi Üniversitesi\n";
cout<<"\t\t\t\t---------------------------------------------------------\n";
cout<<"\t\t\t\t|\t\t\tALGORİTMALAR\t\t\t|\n";
cout<<"\t\t\t\t|\t\t\t     ve     \t\t\t|\n";
cout<<"\t\t\t\t|\t     BİGİSAYAR PROGRAMCILIĞINA GİRİŞ\t\t|\n";
cout<<"\t\t\t\t---------------------------------------------------------\n";
cout<<"\n";
cout<<"\n";
cout<<"\n";
cout<<"\n";
cout<<"\t\t\t\t\t\t\t*********\t\t\t\n";
cout<<"\t\t\t\t\t\t\t* PROJE *\t\t\t\n";
cout<<"\t\t\t\t\t\t\t*********\t\t\t\n";
cout<<"\n";
cout<<"\n";
cout<<"\n";
cout<<"\n";
cout<<"\t\t\t\t\t_______Herhangi Bir Tuşa Basınız______\t\t\t\n";

getch();
system("cls");
cout<<"\n";
cout<<"   PROJE MENÜSÜ\n";
cout<<"  ----------------\n";
cout<<"  1< 0 Dereceden 90 dereceye kadar açıların onar artanlı olarak sin, cos, tan, cotan, degerlerini içeren bir matrisi      oluşturan C programı\n";
cout<<"  2< y=(x^5+4)/(x^3+2) fonsiyon degerlerini x=(-40,40) aralığı için birer artimla hesaplayan ve bu aralık için            fonksiyonun  maximum ve minimum degerlerini bulan C programı\n";
cout<<"  3< Bir kare matrisin esas köşegeni üzerindeki elemanların toplamını ve diğer köşegen üzerindeki elemanların çarpımını   en az islem sayısı ve en az cevrimle hesaplayan C programı\n";
cout<<"  4< y=(x^2)/(x+1) ve y=(x^3)/(x^3+2) fonksiyonlarının varsa kesim noktalarından birini bulan C programı\n";
cout<<"  5< Satış elemanı prim hesaplayan C programı\n";
cout<<"  6< Gelistirilen kod ile ilgili aciklamalar\n";
cout<<"  7< Kayıtlı dosyayı goruntule\n";
cout<<"  8< Çıkış\n";
cout<<"\n";
cout<<">>> Seçiminiz.... ";
cin>>secim;
string secim2;
switch(secim){
	
	case 1: 
	{
			program1:
			system("cls"); 
			Program1();
			cout<<"   Seçiminiz (T=Tekrar Hesapla/M=Menü/C=Çıkış.)";
			cin>>secim2;
			if(secim2=="T"||secim2=="t")
			{
				goto program1;
			}
				if(secim2=="M"||secim2=="m")
			{
				goto menu;
			}
				if(secim2=="C"||secim2=="c")
			{
				exit(0);
			}
			break;
	}
	case 2: 
	{
			system("cls"); 
			program2:
			Program2();
			cout<<"   Seçiminiz (T=Tekrar Hesapla/M=Menü/C=Çıkış.)";
			cin>>secim2;
			if(secim2=="T"||secim2=="t")
			{
				goto program2;
			}
				if(secim2=="M"||secim2=="m")
			{
				goto menu;
			}
				if(secim2=="C"||secim2=="c")
			{
				exit(0);
			}
			break;
	}
	case 3: 
	{
			system("cls");
			program3: 
			Program3();
			cout<<"   Seçiminiz (T=Tekrar Hesapla/M=Menü/C=Çıkış.)";
			cin>>secim2;
			if(secim2=="T"||secim2=="t")
			{
				goto program3;
			}
				if(secim2=="M"||secim2=="m")
			{
				goto menu;
			}
				if(secim2=="C"||secim2=="c")
			{
				exit(0);
			}
			break;
	}
		case 4: 
	{
			system("cls"); 
			program4:
			program4();
			cout<<"   Seçiminiz (T=Tekrar Hesapla/M=Menü/C=Çıkış.)";
			cin>>secim2;
			if(secim2=="T"||secim2=="t")
			{
				goto program4;
			}
				if(secim2=="M"||secim2=="m")
			{
				goto menu;
			}
				if(secim2=="C"||secim2=="c")
			{
				exit(0);
			}
			break;
	}
			case 5: 
	{
			system("cls");
			program5:
			program5();
			cout<<"   Seçiminiz (T=Tekrar Hesapla/M=Menü/C=Çıkış.)";
			cin>>secim2;
			if(secim2=="T"||secim2=="t")
			{
				goto program5;
			}
				if(secim2=="M"||secim2=="m")
			{
				goto menu;
			}
				if(secim2=="C"||secim2=="c")
			{
				exit(0);
			}
			break;
	}
		case 6: 
	{
	aciklamamenu:
	system("cls");
	string secim1;
	cout<<"\n";
	cout<<"\n";
	cout<<"\n";
	cout<<"\t\t\t\t ------------ \t ------------ \t ------------\n";
	cout<<"\t\t\t\t | PROBLEM 1 | \t | PROBLEM 2 | \t | PROBLEM 3 | \n";
	cout<<"\t\t\t\t ------------ \t ------------ \t ------------\n";
	cout<<"\n";
	cout<<"\n";
	cout<<"\n";
	cout<<"\t\t\t\t ------------ \t ------------ \t ------------\n";
	cout<<"\t\t\t\t | PROBLEM 4 | \t | PROBLEM 5 | \t | G) GENEL | \n";
	cout<<"\t\t\t\t ------------ \t ------------ \t ------------\n";
	cout<<"\n";
	cout<<"\n";
	cout<<"\n";
	cout<<"\n";
	cout<<"\n";
	cout<<"\n";
	cout<<"\t\t\t LÜTFEN AÇIKLAMASINI GÖRÜNTÜLEMEK İÇİN İSTEDİĞİNİZ BÖLÜMÜ SEÇİNİZ \n";
	cout<<"\t\t\t\t\t   ANA MENÜ İÇİN M GİRİNİZ  \n";
	cin>>secim1;
	if(secim1=="m"||secim1=="M")
	{
		goto menu;
	}
	if(secim1=="1")
	{
				system("cls");
				cout<<"  PROBLEM 1 İÇİN AÇIKLAMALAR\n";
				cout<<"  --------------------------\n";
				cout<<"  Açıklamalar: İstenilen tabloyu oluşturabilmek için double tanımlı j değişkeni tanımlandı.\n";
				cout<<"               Açıları hesaplatabilmek için math.h kütüphanesi programla eklendi.\n";
				cout<<"               For döngüsü kullanılarak 0-90 derece arasında 10 luk artım ile açılar döndürüldü.\n";
				cout<<"               Tabloyu oluşturabilmek için formatlı biçimde karakterler düzenlendi.\n";
				cout<<"               INFINITY ibaresi için string metodu kullanıldı.\n";
				cout<<"\n";
				cout<<"   Seçiminiz (A=Ana Menü/M=Menü/C=Çıkış.)\n";
				cin>>secim2;
			if(secim2=="M"||secim2=="m")
			{
				goto aciklamamenu;
			}
				if(secim2=="A"||secim2=="a")
			{
				goto menu;
			}
				if(secim2=="C"||secim2=="c")
			{
				exit(0);
			}
	}
	if(secim1=="2")
	{
			system("cls");
				cout<<"  PROBLEM 2 İÇİN AÇIKLAMALAR\n";
				cout<<"  --------------------------\n";
				cout<<"  Açıklamalar: Fonksiyonun değerlerini tutan bir double degerler[81] dizisi tanımlandı\n";
				cout<<"               Aralığı hesaplatabilmek için int x değişkeni tanımlandı.\n";
				cout<<"               For döngüsü kullanılarak aralıklar için y değerleri tanımlandı\n";
				cout<<"               Bu y değerleri int y değişkeninde tutuldu.\n";
				cout<<"               son olarak diziye aktardığımız y değerleri yeni bir for dögüsü ile ekrana yazdırırldı.\n";
				cout<<"\n";
				cout<<"   Seçiminiz (A=Ana Menü/M=Menü/C=Çıkış.)\n";
				cin>>secim2;
			if(secim2=="M"||secim2=="m")
			{
				goto aciklamamenu;
			}
				if(secim2=="A"||secim2=="a")
			{
				goto menu;
			}
				if(secim2=="C"||secim2=="c")
			{
				exit(0);
			}
	}
	if(secim1=="3")
	{
			system("cls");
				cout<<"  PROBLEM 3 İÇİN AÇIKLAMALAR\n";
				cout<<"  --------------------------\n";
				cout<<"  Açıklamalar: 5x5 büyüklüğünde int matris tanımlanmıştır\n";
				cout<<"               Bu matrise sayılar programın içine gömülü şekilde eklenmiştir\n";
				cout<<"               2 Adet iç içw For döngüsü kullanılarak bu dizi ekrana yazdırılmıştır.\n";
				cout<<"               Esas köşegendeki sayılar int toplam değişkeni tanımlanarak bu değişkende tutulmuştur.\n";
				cout<<"               Ters köşegendeki çarpımlar ayrı bir for döngüsü içerisinde hesaplanmıştır.\n";
				cout<<"\n";
				cout<<"   Seçiminiz (A=Ana Menü/M=Menü/C=Çıkış.)\n";
				cin>>secim2;
			if(secim2=="M"||secim2=="m")
			{
				goto aciklamamenu;
			}
				if(secim2=="A"||secim2=="a")
			{
				goto menu;
			}
				if(secim2=="C"||secim2=="c")
			{
				exit(0);
			}
	}
	if(secim1=="4")
	{
			system("cls");
				cout<<"  PROBLEM 4 İÇİN AÇIKLAMALAR\n";
				cout<<"  --------------------------\n";
				cout<<"  Açıklamalar: Foksiyonun köklerini bulabilmek için fonk adında bir fonksiyon tanımlanmıştır.\n";
				cout<<"               Bu fonksiyon içerisinde fonksiyonun değerleri hesaplanmıştır.\n";
				cout<<"               Program4 fonksiyonu içerisinde fonk fonksiyonu çağırılmış ve newton raphson metodu uygulanmıştır.\n";
				cout<<"               Kullanıcı başlangıç değeri ve epsilon değerini kendisinin girmesi sağlanmıştır.\n";
				cout<<"               Bu değerler double epsilon x0 değişkenlerinde tutulmuştur.\n";
				cout<<"\n";
				cout<<"   Seçiminiz (A=Ana Menü/M=Menü/C=Çıkış.)\n";
				cin>>secim2;
			if(secim2=="M"||secim2=="m")
			{
				goto aciklamamenu;
			}
				if(secim2=="A"||secim2=="a")
			{
				goto menu;
			}
				if(secim2=="C"||secim2=="c")
			{
				exit(0);
			}
	}
	if(secim1=="5")
	{
			system("cls");
				cout<<"  PROBLEM 5 İÇİN AÇIKLAMALAR\n";
				cout<<"  --------------------------\n";
				cout<<"  Açıklamalar: Kullanıcıdan alınan satış miktarı satiMiktari değişkeninde tutulmuştur.\n";
				cout<<"               Verilen kriterlere uygun prim miktarını hesaplayan float PrimHesala fonksiyonu yaratılmıştır.\n";
				cout<<"               Kullanıcıdan alınanv verilere göre prim hesaplamak için bu fonsiyon program5 fonskiyonu içerisinde çağırılmıştır.\n";
				cout<<"               Son olarak hesaplanan prim miktarı ekrana yazdırılmıştır.\n";
				cout<<"\n";
				cout<<"   Seçiminiz (A=Ana Menü/M=Menü/C=Çıkış.)\n";
				cin>>secim2;
			if(secim2=="M"||secim2=="m")
			{
				goto aciklamamenu;
			}
				if(secim2=="A"||secim2=="a")
			{
				goto menu;
			}
				if(secim2=="C"||secim2=="c")
			{
				exit(0);
			}
	}
	if(secim1=="G"||secim1=="g")
	{
			system("cls");
				cout<<"  GENEL AÇIKLAMALAR\n";
				cout<<"  --------------------------\n";
				cout<<"  -------->>>: Programın genelinde her problem ayrı bir fonksiyon olarak ana programın içerisinde çağırılmıştır.\n";
				cout<<"               Seçimler switch case yapısı kullanılarak kontrol edilmiştir.\n";
				cout<<"               Bu programda C++ ve C komutları karışık kullanılmıştır.\n";
				cout<<"\n";
				cout<<"   Seçiminiz (A=Ana Menü/M=Menü/C=Çıkış.)\n";
				cin>>secim2;
			if(secim2=="M"||secim2=="m")
			{
				goto aciklamamenu;
			}
				if(secim2=="A"||secim2=="a")
			{
				goto menu;
			}
				if(secim2=="C"||secim2=="c")
			{
				exit(0);
			}
	}	
			break;
}
}
}
