from tkinter import *

root = Tk ()
title = Label (root, text = "Wpisz równanie:", padx = 5, pady = 5).grid (row = 0, column = 0)

textArea = Entry (root, width = 70)
textArea.grid (row = 1, column = 0, columnspan = 2)

def sendData ():
    print (textArea.get())

button = Button (root, text = "Wprowadź", padx = 20, pady = 2, command = sendData).grid (row = 2, column = 1)

root.mainloop ()