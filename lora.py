#importing lora module libraries ans bmp sensor module
from LoRaRF import SX127x
LoRa=SX127x()
import Adafruit_BMP.BMP085 as BMP085

#setting bmp sensor
Adafruit_BMP085 bmp

#setting lora module
LoRa.setSPI(0,0,7800000)  #(bus id, cs id, speed 7.8Mhz)
LoRa.begin()

#read bmp sensor
temp=bmp.readTemperature()
tempList=list(temp)

#transmit operation
for i in range(0,len(tempList)):
    tempList[i]=ord(tempList[i])
    counter=0  # forreading data in single byte

    LoRa.beginPacket()
    LoRa.write(temp, sizeof(temp))  #reading data in multiple bytes
    LoRa.write(counter)
    LoRa.endPacket()
    LoRa.wait()

    counter+=1

#receive operation

LoRa.request()
LoRa.wait()

temp=""
while LoRa.available()>1:
  temp += chr(LoRa.read())
counter = LoRa.read()  

