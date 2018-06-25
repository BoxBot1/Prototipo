import serial
import time
from tkinter import *

serial_speed = 9600
serial_port = '/dev/tty.BoxBotnny-SPPDev'

def Traer_caja():
    ser.write(b'1')

print("Conectando al serial")
ser = serial.Serial(serial_port, serial_speed, timeout=1)

master = Tk()

texto = Label(master, text = "BoxBot 1.0",height=1, width=15 , font="Times 40")
texto.pack()
texto.place(x=150, y=10)

caja1 = Label(master, text = "Caja 1:")
caja1.pack()
caja1.place(x=25, y=100)

nombre1 = Entry(master)
nombre1.place(x=75, y=100)

boton1 = Button(master, text = "Traer caja", height=1, width=15, command=Traer_caja)
boton1.place(x=275, y=100)

var1 = IntVar()
c1 = Checkbutton(master, text = "Desactivar", variable=var1)
c1.place(x=450, y=100)

caja2 = Label(master, text = "Caja 2:")
caja2.place(x=25, y=140)

nombre2 = Entry(master)
nombre2.place(x=75, y=140)

boton2 = Button(master, text = "Traer caja", height=1, width=15, command=Traer_caja)
boton2.place(x=275, y=140)

var2 = IntVar()
c2 = Checkbutton(master, text = "Desactivar", variable=var2)
c2.place(x=450, y=140)

caja3 = Label(master, text = "Caja 3:")
caja3.place(x=25, y=180)

nombre3 = Entry(master)
nombre3.place(x=75, y=180)

boton3 = Button(master, text = "Traer caja", height=1, width=15, command=Traer_caja)
boton3.place(x=275, y=180)

var3 = IntVar()
c3 = Checkbutton(master, text = "Desactivar", variable=var3)
c3.place(x=450, y=180)

caja4 = Label(master, text = "Caja 4:")
caja4.place(x=25, y=220)

nombre4 = Entry(master)
nombre4.place(x=75, y=220)

boton4 = Button(master, text = "Traer caja", height=1, width=15, command=Traer_caja)
boton4.place(x=275, y=220)

var4 = IntVar()
c4 = Checkbutton(master, text = "Desactivar", variable=var4)
c4.place(x=450, y=220)

caja5 = Label(master, text = "Caja 5:")
caja5.place(x=25, y=260)

nombre5 = Entry(master)
nombre5.place(x=75, y=260)

boton5 = Button(master, text = "Traer caja", height=1, width=15, command=Traer_caja)
boton5.place(x=275, y=260)

var5 = IntVar()
c5 = Checkbutton(master, text = "Desactivar", variable=var5)
c5.place(x=450, y=260)

caja6 = Label(master, text = "Caja 6:")
caja6.place(x=25, y=300)

nombre6 = Entry(master)
nombre6.place(x=75, y=300)

boton6 = Button(master, text = "Traer caja", height=1, width=15, command=Traer_caja)
boton6.place(x=275, y=300)

var6 = IntVar()
c6 = Checkbutton(master, text = "Desactivar", variable=var6)
c6.place(x=450, y=300)

caja7 = Label(master, text = "Caja 7:")
caja7.place(x=25, y=340)

nombre7 = Entry(master)
nombre7.place(x=75, y=340)

boton7 = Button(master, text = "Traer caja", height=1, width=15, command=Traer_caja)
boton7.place(x=275, y=340)

var7 = IntVar()
c7 = Checkbutton(master, text = "Desactivar", variable=var7)
c7.place(x=450, y=340)

caja8 = Label(master, text = "Caja 8:")
caja8.place(x=25, y=380)

nombre8 = Entry(master)
nombre8.place(x=75, y=380)

boton8 = Button(master, text = "Traer caja", height=1, width=15, command=Traer_caja)
boton8.place(x=275, y=380)

var8 = IntVar()
c8 = Checkbutton(master, text = "Desactivar", variable=var8)
c8.place(x=450, y=380)

"""Bloque1 = Label(master, width=75, height = 75, bg = "white", relief="solid")
Bloque1.place(x = 550, y = 150)

Bloque2 = Label(master, width=75, height = 75, bg = "black", relief="solid")
Bloque2.place(x = 625, y = 150)

Bloque3 = Label(master, width=75, height = 75, bg = "white", relief="solid")
Bloque3.place(x = 700, y = 150)

Bloque4 = Label(master, width=75, height = 75, bg = "white", relief="solid")
Bloque4.place(x = 550, y = 225)

Bloque5 = Label(master, width=75, height = 75, bg = "white", relief="solid")
Bloque5.place(x = 625, y = 225)

Bloque6 = Label(master, width=75, height = 75, bg = "white", relief="solid")
Bloque6.place(x = 700, y = 225)

Bloque7 = Label(master, width=75, height = 75, bg = "white", relief="solid")
Bloque7.place(x = 550, y = 300)

Bloque8 = Label(master, width=75, height = 75, bg = "white", relief="solid")
Bloque8.place(x = 625, y = 300)

Bloque9 = Label(master, width=75, height = 75, bg = "white", relief="solid")
Bloque9.place(x = 700, y = 300)"""

master.mainloop()
