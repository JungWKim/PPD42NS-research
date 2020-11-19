from pyfirmata import util, Arduino
from datetime import datetime
import time

print("measuring start")
board = Arduino('/dev/ttyACM0')
sensor = board.get_pin('d:7:i')

it = util.Iterator(board)
it.start()
sensor.enable_reporting()

nothing = 0
sampletime = 10
starttime = time.time()
lowpulseoccupancy = 0
ratio = 0
concentration = 0
ugm3 = 0

while True:
	pasttime = time.time()*1000000

	if sensor.read() == 0:
		nothing = 0

	lowpulseoccupancy += (time.time()*1000000 - pasttime)

	if(time.time() - starttime) > sampletime:
		ratio = lowpulseoccupancy / (sampletime*10000.0)
		concentration = (1.1 * pow(ratio, 3)) - (3.8 * pow(ratio, 2)) + (520 * ratio) + 0.62
		ugm3 = concentration / 130

		print("concentration =", concentration, "pcs/0.01cf")
		print("ugm3 =", ugm3, "ug/m^3")
		print("")

		lowpulseoccupancy = 0
		starttime = time.time()
