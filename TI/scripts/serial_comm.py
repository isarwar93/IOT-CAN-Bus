import serial
import time

def send_bytes(serial_port, data):
     for j in range(0, len(data)):
          serial_port.write(bytearray([data[j]]))


# 4800, 9600, 19200, 38400, 57600, 115200, 230400, 460800, 921600.
ser = serial.Serial('/dev/ttyUSB1', 115200, timeout=8)
old_num = 0
reconstructed_num = 0
# while True:
#      data = ser.read(10)
#      # Print data in hexadecimal
#      hex_data = ' '.join(f'0x{byte:02X}' for byte in data)
#      old_num = reconstructed_num
#      for i in range(0,4):
#           # reconstructed_num = (data[3] << 24) | (data[2] << 16) | (data[1] << 8) | data[0]
#           reconstructed_num = (data[0] << 24) | (data[1] << 16) | (data[2] << 8) | data[3]
     # old_num = reconstructed_num/200
     
     # print(f"Reconstructed 32-bit integer: {(reconstructed_num)/200}")
     # reconstructed_num_div = reconstructed_num/200
     # print(f"Time passed: {(old_num - reconstructed_num)}")
     # # old_num = reconstructed_num/200
     # print("Hexadecimal:", hex_data)
     # print("ASCII:", data)


a = 0
# while True:
a +=1
values = bytearray([a])
data = b""
bytesArray = bytearray(8)
bytesArray[0] = 0xf0#0xf0
for j in range(1,8):
     bytesArray[j] = 0x0f#0x0f#0x1f#0x2f#0x3f
for i in range(1,len(data)+1):
     bytesArray[i] = data[i-1]
# else:
#      chunk[i] = 0x00  # Pad with zeros if data runs out
print(bytesArray)
send_bytes(ser, bytesArray)


data = ser.read(10)
# Print data in hexadecimal
hex_data = ' '.join(f'0x{byte:02X}' for byte in data)
print("Hexadecimal:", hex_data)
print("ASCII:", data)
