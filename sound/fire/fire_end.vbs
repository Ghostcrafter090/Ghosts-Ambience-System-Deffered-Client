Set Sound = CreateObject("WMPlayer.OCX.7") 
Sound.URL = "fire_end.wav"
Sound.Settings.Volume = 10
Sound.Controls.play 
do while Sound.currentmedia.duration = 0 
wscript.sleep 100 
loop 
wscript.sleep (int(Sound.currentmedia.duration)+1)*1000 
