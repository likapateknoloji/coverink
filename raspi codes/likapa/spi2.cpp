//Likapa SPI Raspi Kodu
#include <sys/ioctl.h>
#include <linux/spi/spidev.h>
#include <fcntl.h>
#include <cstring>
#include <iostream>
#include <unistd.h>
using namespace std;


int fd;
unsigned char hello1[] = {'B','i','r','i','n','c','i','D','i','z','i','d','a','h','a','u','z','u','n','\n'};                          
unsigned char hello2[] = {'I','k','i','n','c','i',' ','D','i','z','i','\n'};                           
unsigned char hello3[] = {'U','c','u','n','c','u',' ','D','i','z','i','\n'};                           
unsigned char hello4[] = {};
unsigned char result;
unsigned int sayi=0;
int istek=0;
int spiTxRx(unsigned char txDat);
int oku(int x);
int yolla(char dizi[]);

int oku(int x)
{

	unsigned char result;
	
	for (int i = 0; i < x; i++)
      {
			result = spiTxRx(hello4[i]); // endless loop içinde sürekli bitleri alarak hello'ya atıyoruz
			cout << result;
			usleep (1000);
      }
      return 0;
}

int yolla(unsigned char *dizi)
{
	int spiTxRx(unsigned char txDat);

      for (unsigned int i = 0; i < 100; i++)
{

			result = spiTxRx(dizi[i]); // endless loop içinde sürekli bitleri alarak hello'ya atıyoruz
			//cout << dizi[i];
			usleep (1000);
			if(dizi[i]=='\n'){break;}
      }
      cout << "Gonderildi\n";
    return 0;
}

int spiTxRx(unsigned char txDat) // haberleşmeyi sağlayan fonksiyon
{
 
  unsigned char rxDat;

  struct spi_ioc_transfer spi;

  memset (&spi, 0, sizeof (spi));

  spi.tx_buf        = (unsigned long)&txDat;
  spi.rx_buf        = (unsigned long)&rxDat;
  spi.len           = 1;

  ioctl (fd, SPI_IOC_MESSAGE(1), &spi);// bit bit sürekli mesaj alıyor shifting yapıyor

  return rxDat;
}

int main (void)
{
   
	fd = open("/dev/spidev0.0", O_RDWR); // Klasörü açarak cihazı okuma yazmaya hazırlar

   unsigned int speed = 1000000; // hız ayarı
   ioctl (fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed); //hız ayarı
	cout << "Gondermek istenen diziyi secin(1-2-3) veya dizi okumak istiyorsaniz (4)" << endl;
	cin >> istek;
   if(istek==1)
   {

		yolla(hello1);
   }
   if(istek==2)
   {
		yolla(hello2);
		
   }
   if(istek==3)
   {

    yolla(hello3);

   }
      if(istek==4)
   {
	cout << "Okumak istediginiz byte sayisini giriniz" << endl;
	cin >> sayi;
	oku(sayi);
	
  
   }

}

