import serial

def send_bytes(serial_port, data):
     for j in range(0, len(data)):
          serial_port.write(bytearray([data[j]]))


# 4800, 9600, 19200, 38400, 57600, 115200, 230400, 460800, 921600.
ser = serial.Serial('/dev/ttyUSB1', 115200, timeout=8)


bytesArray = bytearray(8)
bytesArray[0] = 0xf0#0xf0
#1f -> information, 3f-> Change bank, 4f-> cpu comm
bytesArray[1] = 0x4f#0x0f#0x1f#0x3f#0x4f
for j in range(2,8):
     # bytesArray[j] = 0x0f#For flashing
     bytesArray[j] = j#0x0f#0x1f#0x3f#0x4f

print("Byte sent:")
print(bytesArray)
send_bytes(ser, bytesArray)

print("Byte receive:")
dataRec = ser.read(10)
# Print data in hexadecimal
hex_data = ' '.join(f'0x{byte:02X}' for byte in dataRec)
print("Hexadecimal:", hex_data)
print("ASCII:", dataRec)