#include <math.h>
#include <stdio.h>
#include <wiringPi.h>

#define DUST 4

int main()
{
	unsigned long duration, starttime, pasttime;
	unsigned long sampletime = 10000, lowpulseoccupancy = 0;
	float ratio = 0, concentration = 0, ugm3 = 0;

	if(wiringPiSetupGpio() == -1) return 1;

	pinMode(DUST, INPUT);
	starttime = millis();

	while(1)
	{
		pasttime = micros();
		if(digitalRead(DUST) == LOW)
			lowpulseoccupancy += (micros() - pasttime);

		if((millis() - starttime) > sampletime)
		{
			ratio = lowpulseoccupancy / (sampletime*10.0);
			concentration = (1.1 * pow(ratio, 3)) - (3.8 * pow(ratio, 2)) + (520 * ratio) + 0.62;
			ugm3 = concentration / 130;

			printf("concentration = %f pcs/0.01cf\n", concentration);
			printf("ugm3 = %f ug/m^3\n\n", ugm3);

			lowpulseoccupancy = 0;
			starttime = millis();
		}
	}

	return 0;
}
