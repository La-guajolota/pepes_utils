import am_utils as AM
import matplotlib.pyplot as plt

sig_modulada = AM.senoidal(1,1,0,0)
sig_carrier = AM.senoidal(1,25,0,0)

signal_sent = AM.signal_AM(sig_carrier.A,sig_carrier.f,sig_carrier.theta,sig_carrier.dc,sig_modulada.A,sig_modulada.f,sig_modulada.theta,sig_modulada.dc)
v,m = signal_sent.modualtion()

#mostramos las senoidales
sig_modulada.samples(100)
plt.plot(m, v, label = "out")
plt.plot(sig_modulada.rad,sig_modulada.muestas, label = "modulada")

plt.xlabel('segs')
plt.ylabel('volts')
 
# giving a title to my graph
plt.title('señales')
 
# function to show the plot
plt.show()