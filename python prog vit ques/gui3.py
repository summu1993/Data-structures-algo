import tkinter as tk
from tkinter import *
from tkinter.ttk import *

class Form():
    
    def abc():
        
        a=tk.Tk()
        a.title("IT Desk")
        x=tk.Label(a,text="REGISTRATION FORM",font=('Arial',20),fg=("red"),bg=("yellow"))
        x.grid(row=0, column=1)
        a.geometry("600x600")
        
        b=tk.Label(a,text="name")
        b.grid(row=1, column=0)
        
        c=tk.Entry(a,text="name")
        c.grid(row=1, column=1)
        
        d=tk.Label(a,text="e mail")
        d.grid(row=2, column=0)
        
        e=tk.Entry(a,text="e mail")
        e.grid(row=2, column=1)
        
        f=tk.Label(a,text="contact")
        f.grid(row=3, column=0)
        
        g=tk.Entry(a,text="contact")
        g.grid(row=3, column=1)

        h=tk.Label(a, text="gender")
        h.grid(row=4, column=0)

        i=Radiobutton(a, text="male",value=1 )
        i.grid(row=4,column=1)

        j=Radiobutton(a, text="female",value =2)
        j.grid(row=4, column=2)

        k=tk.Label(a, text="state")
        k.grid(row=5,column=0)

        combo=Combobox(a)
        combo['value']=("bihar","mp","up","uk")
        combo.current(0)
        combo.grid(row=5, column=1)
        
        def click():
           print("saved successfully")
        btn=Button(a,text="Save",command=click)
        btn.grid(row=7,column=1)
        
##        list1=["bihar","mp","up","uk"]
##        z=StringVar()
##        droplist=OptionMenu(a,z,*list1)
##        droplist.config(width=15)
##        z.set("select state")
##        l=droplist.k
##        l.grid(row=4, column=0)

        

obj=Form.abc()