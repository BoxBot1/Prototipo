import serial
import time
from tkinter import *

serial_speed = 9600
serial_port = '/dev/tty.BoxBotnny-SPPDev'

def Traer_caja():
    ser.write(b'1')

def Devolver_caja():
    ser.write(b'2')

def Reposo():
    ser.write(b'3')

print("Conectando al serial")
ser = serial.Serial(serial_port, serial_speed, timeout=1)

master = Tk()

texto = Label(master, text = "BoxBot 1.0",height=1, width=15 )
texto.pack()
texto.place(x=400, y=10)

caja1 = Label(master, text = "Caja 1")
caja1.pack()
caja1.place(x=25, y=50)

nombre1 = Entry(master)
nombre1.place(x=100, y=50)

boton1 = Button(master, text = "Traer caja", height=1, width=15, command=Traer_caja)
boton1.place(x=225, y=50)

var1 = IntVar()
c1 = Checkbutton(master, text = "Desactivar", variable=var1)
c1.place(x=300, y=50)

caja2 = Label(master, text = "Caja 2")
caja2.place(x=25, y=80)

nombre2 = Entry(master)
nombre2.place(x=100, y=80)

boton2 = Button(master, text = "Traer caja", height=1, width=15, command=Traer_caja)
boton2.place(x=225, y=80)

var2 = IntVar()
c2 = Checkbutton(master, text = "Desactivar", variable=var2)
c2.place(x=300, y=80)

caja3 = Label(self, text = "Caja 3")
caja3.place(x=60, y=40)

nombre3 = Entry(self)
nombre3.place(x=60, y=40)

boton3 = Button(self, text = "Traer caja", height=1, width=15, command=Traer_caja)
boton3.place(x=60, y=40)

var3 = IntVar()
c3 = Checkbutton(self, text = "Desactivar", variable=var3)
c3.place(x=60, y=40)

caja4 = Label(self, text = "Caja 4")
scaja4.place(x=60, y=40)

nombre4 = Entry(self)
nombre4.place(x=60, y=40)

boton4 = Button(self, text = "Traer caja", height=1, width=15, command=Traer_caja)
boton4.place(x=60, y=40)

var4 = IntVar()
c4 = Checkbutton(self, text = "Desactivar", variable=var4)
c4.place(x=60, y=40)

caja5 = Label(self, text = "Caja 5")
caja5.place(x=60, y=40)

nombre5 = Entry(self)
nombre5.place(x=60, y=40)

boton5 = Button(self, text = "Traer caja", height=1, width=15, command=Traer_caja)
boton5.place(x=60, y=40)

var5 = IntVar()
c5 = Checkbutton(self, text = "Desactivar", variable=var5)
c5.place(x=60, y=40)

caja6 = Label(self, text = "Caja 6")
caja6.place(x=60, y=40)

nombre6 = Entry(self)
nombre6.place(x=60, y=40)

boton6 = Button(self, text = "Traer caja", height=1, width=15, command=Traer_caja)
boton6.place(x=60, y=40)

var6 = IntVar()
c6 = Checkbutton(self, text = "Desactivar", variable=var6)
c6.place(x=60, y=40)

caja7 = Label(self, text = "Caja 7")
caja7.place(x=60, y=40)

nombre7 = Entry(self)
nombre7.place(x=60, y=40)

boton7 = Button(self, text = "Traer caja", height=1, width=15, command=Traer_caja)
boton7.place(x=60, y=40)

var7 = IntVar()
c7 = Checkbutton(self, text = "Desactivar", variable=var7)
c7.place(x=60, y=40)

caja8 = Label(self, text = "Caja 8")
caja8.place(x=60, y=40)

nombre8 = Entry(self)
nombre8.place(x=60, y=40)

boton8 = Button(self, text = "Traer caja", height=1, width=15, command=Traer_caja)
boton8.place(x=60, y=40)

var8 = IntVar()
c8 = Checkbutton(self, text = "Desactivar", variable=var8)
c8.place(x=60, y=40)

master.geometry("900x400")
master.mainloop()
