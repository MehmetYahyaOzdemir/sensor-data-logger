#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>

struct SensorReading {
    int id;
    double raw_temp;
    double filtered_temp;
};

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::ofstream file("data/sensor_data.csv");

    if (!file.is_open()) {
        std::cerr << "Hata: CSV dosyasi olusturulamadi! 'data' klasorunun varligindan emin olun." << std::endl;
        return 1;
    }

    // CSV Basligi
    file << "ReadingID,RawTemperature,FilteredTemperature\n";

    std::cout << "Sensor Data Logger (C++) Baslatildi...\n";
    std::cout << std::setw(5) << "ID" 
              << std::setw(12) << "Ham (C)" 
              << std::setw(15) << "Filtreli (C)\n";
    std::cout << "------------------------------------\n";

    double running_sum = 0.0;
    const int WINDOW_SIZE = 3;
    std::vector<double> window;

    for (int i = 1; i <= 10; ++i) {
        // 20.0 - 30.0 derece arasi sahte sensor verisi
        double raw = 20.0 + static_cast<double>(std::rand() % 1000) / 100.0;

        window.push_back(raw);
        running_sum += raw;

        if (window.size() > WINDOW_SIZE) {
            running_sum -= window.front();
            window.erase(window.begin());
        }

        double filtered = running_sum / window.size();

        std::cout << std::setw(5) << i 
                  << std::setw(12) << std::fixed << std::setprecision(2) << raw 
                  << std::setw(15) << filtered << "\n";

        file << i << "," << raw << "," << filtered << "\n";
    }

    file.close();
    std::cout << "\nVeriler 'data/sensor_data.csv' dosyasina basariyla kaydedildi.\n";
    return 0;
}