#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <wiringSerial.h>
#include <wiringPi.h>

int main()
{
	int fd;
	int count;
	unsigned int nextTime;

	if((fd = serialOpen("/dev/ttyACM0", 9600)) < 0)
	{
		fprintf(stderr, "Unable to open serial device:%s\n", strerror(errno));
		return 1;
	}

	if(wiringPiSetupGpio() == -1) return 1;
	while(1)
	{
		while(serialDataAvail(fd))
		{
			printf("%c", serialGetchar(fd));
			fflush(stdout);
		}
	}

	return 0;
}
