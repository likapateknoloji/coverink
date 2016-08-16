/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#include "pigpio.h"

#define GPIO 25
#define PI 3.1416
#define SPI_FLAGS 192
#define BAUD_RATE 7800000
#define SPI_CH 1

//pervasive

void islem_led(){
  int i;
  gpioSetMode(GPIO, PI_OUTPUT);
  for( i = 0; i < 10; i++ ){
    gpioWrite(GPIO, PI_HIGH);
    gpioDelay(1000000);
    gpioWrite(GPIO, PI_LOW);
    gpioDelay(1000000);
  }
}

void islem_pwm(){
  int i;
  double x;
  gpioSetMode(GPIO, PI_OUTPUT);
  for( i = 0; i < 5; i++ ){
    for( x = 0; x < 256; x++ ){
      gpioPWM(GPIO, (unsigned) (255 * sin(PI*(x / 255))));
      gpioDelay(4000);
    }
    for( x = 255; 0 <= x; x-- ){
      gpioPWM(GPIO, (unsigned) (255 * sin(PI*(x / 255))));
      gpioDelay(4000);
    }
  }
}



int main(){
  if (gpioInitialise() < 0)
    {
       // pigpio initialisation failed.
    }
  else
    {
       // pigpio initialised okay.
    }
  int i, h;
  char a1 = 'n';
  char a2 = 'n';
  char *buf1 = &a1;
  char *buf2 = &a2;
  
  unsigned count = 1;
  
  
  h = spiOpen(SPI_CH, BAUD_RATE, SPI_FLAGS);
  
  for(i=0;i<5;i++){
	  printf("Enter Number: ");
	  scanf("%c", buf1);
	  if(*buf1 == 'x'){break;}
	  
	  else{
      spiXfer(h, buf1, buf2, count);
		  //spiWrite(h, buf1, count);
		  //spiRead(h, buf1, count);
		  printf("\n%c", *buf2);
	  }
  }
 
  
  
  spiClose(h);
  gpioTerminate();
  return 0;  
}*/

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <ctype.h>
//#include <math.h>
//
//#include "pigpio.h"
//
////#define SPIN 18
//#define SPIFLAGS 192
//#define BAUDE 2000000
//#define SPICH 1
//
//
//int main(){
//	/*if (gpioInitialise() < 0){
//       // pigpio initialisation failed.
//    }
//	else{
//       // pigpio initialised okay.
//    }*/
//	gpioInitialise();
//	//int count = 1;
//	char c;
//  int i;
//	//char c1;
//	//char c2;
//	char *buf1 = NULL;
//	char *buf2 = NULL;
// 
//  char pos1[8] =  "vurkiri\n" ;
//	char pos2[8] =  "0000000\n" ;
//  
//  //char *pos = buf1;
//  
//  for (i = 0;i < 8; i++){
//    *(buf1 + i) = pos1[i];
//  }
//  for (i = 0;i < 8; i++){
//    *(buf2 + i) = pos2[i];
//  }
//  
//  printf("%s",*buf1);
//	gpioSetMode(18, PI_OUTPUT);
//	gpioWrite(18, PI_HIGH);
//  gpioDelay(1000000);
//	int h = spiOpen(1, 500000, 192);
//	
//	printf("Start?: ");
//	scanf("%c", &c);
//	
//	gpioWrite(18, PI_LOW);
//  gpioDelay(1000000);
//	
//	//spiXfer(h, buf1, buf2, sizeof(buf1)/sizeof(buf1[0]););
//	spiXfer(h, buf1, buf2, 8);
//	
//	/*
//	for (const char * p1 = buf1; c1 = *p1; p1++){
//		for(const char * p2 = buf2; c2 = *p2; p2++){
//			spiXfer(h, p1, p2, count);
//		}
//	}
//	*/
//	gpioWrite(18, PI_HIGH);
//	
// printf("%s/n", buf1);
// for (i = 0; i < 7; i++ ){
//   printf("%c",buf1[i]);
// }
//	/*for (const char * p = buf2; c = *p; p++){
//        printf("%c",c);
//	printf("\n");*/
//	gpioDelay(5000000);
//     
//	spiClose(h);
//	gpioTerminate();
//	return 0;  
//}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <unistd.h>
#include <sys/select.h>

#include "pigpio.h"

#define BDRT 9600

int inputAvailable()
{
    struct timeval tv;
    fd_set fds;
    tv.tv_sec = 0;
    tv.tv_usec = 0;
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds); //STDIN_FILENO is 0
    select(STDIN_FILENO+1, &fds, NULL, NULL, &tv);
    return FD_ISSET(STDIN_FILENO, &fds);
}

int main(){
	gpioInitialise();
	
	char device[] = "/dev/ttyAMA0";
	char buf1[] = "deneme\n";
	char buf2[] = "000000\n";
	int e[2];
	
	int h;
	//unsigned i = 0;
 
	h = serOpen(device, BDRT, 0);
	
	printf("%d\n",h);
	while(!inputAvailable()){
		e[0] = serWrite(h, buf1, strlen(buf1));
    gpioDelay(1000000);
		e[1] = serRead(h, buf2, strlen(buf2)+1);
    gpioDelay(1000000);
    printf("%d - %d\n",e[0],e[1]);
		printf("%s\n",buf2);
	}
	
	serClose(h);
	gpioTerminate();
	return 0;  
}