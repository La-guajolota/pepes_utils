import math 
import matplotlib.pyplot as plt
import numpy as np

w = 2*math.pi #velocidad angular
resolucion =  2**12-1

class senoidal:

    #Variables
    muestras = []
    rad = []

    def __init__(self,A,f,theta,dc): #constructor 
        self.A = A #Amplitud Volts
        self.f = f #Frecuencia Hz
        self.theta = theta #desfase radianes
        self.dc = dc #off set component Volts

    def __str__(self):
        return f"Amplitud: {self.A} volts\nFrecuencia: {self.f} hz\ntheta: {self.theta}\ndc: {self.dc}"
    
    def samples(self, muestras):
        #niquish muestas = 25*self.f 
        periodo = 2/self.f
        self.rad = np.linspace(0,periodo,num=muestras, dtype=float)
        self.muestas = [(self.A*math.sin(w*self.f*n)+self.dc) for n in self.rad]

class signal_AM:
    
    m = 0
    Fbls = 0
    Fbli = 0
    BW = 0
    Pt = 0
    Ps = 0

    def __init__(self, A_c,f_c,theta_c,dc_c,A_m,f_m,theta_m,dc_m):
        #PORTADORA
        self.A_c = A_c
        self.f_c = f_c
        self.theta_c = theta_c
        self.dc_c = dc_c
        #MODULADORA
        self.A_m = A_m
        self.f_m = f_m
        self.theta_m = theta_m
        self.dc_m =dc_m

    def __str__(self):
        return f"m: {self.m}\nFbls: {self.Fbls} hz\nFbli: {self.Fbli} hz\nBW: {self.BW}\n pt: {self.Pt}\n ps: {self.Ps}"
    
    def cal_parametros(self):
        self.Fbls = self.f_c + self.f_m
        self.Fbli = self.f_c - self.f_m
        self.BM = self.Fbls -self.Fbli

    def modualtion(self):

        muestras = resolucion
        periodo = 2/self.f_m

        v = []
        m = np.linspace(0,periodo,muestras, dtype=float)
        for t in m:
            v.append(self.A_c*math.sin(w*self.f_c*t)+((self.A_m*math.sin(w*self.f_m*t))*(math.sin(w*self.f_c*t))))
        
        return v,m        