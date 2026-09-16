import time
import random

def log_sensor_data():
    print("Sensör veri kaydı başlatıldı...")
    with open("sensor_log.txt", "a") as f:
        for i in range(5):
            temp = round(random.uniform(20.0, 30.0), 2)
            entry = f"Okuma {i+1}: Sıcaklık = {temp} C\n"
            f.write(entry)
            print(entry.strip())
            time.sleep(1)

if __name__ == "__main__":
    log_sensor_data()