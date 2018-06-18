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


class Application(Frame):
    def __init__(self, master):
        Frame.__init__(self, master)
        self.grid()
        self.create_widgets()

    def create_widgets(self):
        self.texto = Label(self, text = "Boxbotnny")
        self.texto.grid()

        self.boton1 = Button(self, text = "Traer caja", height=1, width=15, command=Traer_caja)
        self.boton1.grid()

        self.boton2 = Button(self, text = "Devolver caja", height=1, width=15, command=Devolver_caja)
        self.boton2.grid()

        self.boton3 = Button(self, text = "Poner en reposo", height=1, width=15, command=Reposo)
        self.boton3.grid()

root = Tk()
root.title("Controlador de robot")
root.geometry("500x300")
app = Application(root)
root.mainloop()
