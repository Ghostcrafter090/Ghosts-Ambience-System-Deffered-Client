import modules.pyvban as pyvban
import threading

t = pyvban.utils.VBAN_Sender(receiver_ip="192.168.2.30", receiver_port=6983, stream_name="test", sample_rate=48000, channels=2, device_index=17)

r = pyvban.utils.VBAN_Receiver(
    sender_ip="192.168.2.30",
    port=6983,
    stream_name="test",
    device_index=33
)

t2 = pyvban.utils.VBAN_Sender(receiver_ip="192.168.2.30", receiver_port=6984, stream_name="test2", sample_rate=48000, channels=2, device_index=21)
r2 = pyvban.utils.VBAN_Receiver(
    sender_ip="192.168.2.30",
    port=6984,
    stream_name="test2",
    device_index=43
)

#receiver.run()
threading.Thread(target=t.run).start()
threading.Thread(target=r.run).start()
threading.Thread(target=t2.run).start()
threading.Thread(target=r2.run).start()

