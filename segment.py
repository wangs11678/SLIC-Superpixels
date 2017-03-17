import ctypes
dll=ctypes.cdll.LoadLibrary
lib=dll("./libsegment.so") #in windows use dll
lib.segment("lena.jpg")
