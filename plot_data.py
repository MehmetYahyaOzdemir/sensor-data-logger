import csv
import matplotlib.pyplot as plt

ids = []
raw_temps = []
filtered_temps = []

# C++'in urettigi CSV dosyasini oku
with open("data/sensor_data.csv", mode="r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        ids.append(int(row["ReadingID"]))
        raw_temps.append(float(row["RawTemperature"]))
        filtered_temps.append(float(row["FilteredTemperature"]))

# Grafigi ciz
plt.figure(figsize=(10, 5))
plt.plot(ids, raw_temps, label="Ham Veri (Raw)", color="red", linestyle="--", marker="o")
plt.plot(ids, filtered_temps, label="Hareketli Ortalama (Filtered)", color="blue", linewidth=2)

plt.title("Sensor Veri Filtreleme Sonuclari")
plt.xlabel("Okuma ID")
plt.ylabel("Sicaklik (°C)")
plt.grid(True)
plt.legend()

# Grafigi hem kaydet hem goster
plt.savefig("data/sensor_plot.png")
print("Grafik 'data/sensor_plot.png' olarak kaydedildi.")
plt.show()