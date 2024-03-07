import matplotlib.pyplot as plt
import numpy as np
from math import pi

plt.close()

Fs = 2000; n = np.arange(0,2,1/Fs)

Fc= 50
Ac = 1
c = Ac*np.cos(2*pi*Fc*n) #carrier wave



#generate message signal
Fm = 2
Am = 0.5
m = Am*np.sin(2*pi*Fm*n)
#Amplitud modulated signal
s= c* (1+ m/Ac)
#plot
plt.subplot(3,1,1)
plt.plot(n,s,'b'); plt.title('Undermodulation Case')
plt.xlabel('Time(s)'); plt.ylabel('Amplitud')

#full modulation
Am= 1
m = Am*np.sin(2*pi*Fm*n)
#Amplitud modulated signal
s= c* (1+ m/Ac)
#plot
plt.subplot(3,1,2)
plt.plot(n,s,'g'); plt.title('Full modulation Case')
plt.xlabel('Time(s)'); plt.ylabel('Amplitud')



#Over modulation
Am= 1.5
m = Am*np.sin(2*pi*Fm*n)
#Amplitud modulated signal
s= c* (1+ m/Ac)
#plot
plt.subplot(3,1,3)
plt.plot(n,s,'r'); plt.title('Over modulation Case')
plt.xlabel('Time(s)'); plt.ylabel('Amplitud')


plt.tight_layout()
plt.show()