#include <iostream>
#include <string>
using namespace std;

class MusicTrack {
    
private:
    string trackName;
    string singerName;
    int trackTime;
    int ratingTrack;
    
public:
    MusicTrack(string title, string singer, int duration, int rating) {
        trackName = title;
        singerName = singer;
        trackTime = duration;
        if (duration >= 0) {
            trackTime = duration;
        }
        else {
            trackTime = 0;
            cout << "Длительность не может быть отрицательной. Установлено 0" << endl;
            
        }
        ratingTrack = rating;
        if (rating  >= 1 && rating <= 10) {
            ratingTrack = rating;
        }
        else {
            ratingTrack = 1;
            cout << "Рейтинг должен быть от 1 до 10 включительно. Установлено 1" << endl;
        }
    }
    MusicTrack(){
        trackName = "Без имени";
        singerName = "Неизвестный исполнитель";
        trackTime = 0;
        ratingTrack = 1;
    }
    /*~MusicTrack() {
        cout << "Трек " << trackName << " удален" << endl;
    }*/
    
    void setTrackName (string name) {
        trackName = name;
    }
    void setSingerName (string singer) {
        singerName = singer;
    }
    void setTrackTime (int duration) {
        if (duration >= 0) {
            trackTime = duration;
        }
        else {
            trackTime = 0;
            cout << "Длительность не может быть отрицательной. Установлено 0" << endl;
        }
    }
    void setRatingTrack (int rating) {
        if (rating >= 1 && rating <=10) {
            ratingTrack = rating;
        }
        else {
            ratingTrack = 1;
            cout << "Рейтинг должен быть от 1 до 10 включительно. Установлено 1" << endl;
        }
    }
    
    string getTrackName() {
        return trackName;
    }
    string getSingerName() {
        return singerName;
    }
    int getTrackTime() {
        return trackTime;
    }
    int getRatingTrack(){
        return ratingTrack;
    }
    
    string getFormattedTime(){
        int minutes = trackTime / 60;
        int seconds = trackTime % 60;
        return to_string(minutes) + ":" + (seconds < 10 ? "0" : "") + to_string(seconds);
    }
    void printInfo() {
        cout << "===============================" << endl;
        cout << "Название:   " << trackName << endl;
        cout << "Исполнитель: " << singerName << endl;
        cout << "Длительность: " << getFormattedTime() << endl;
        cout << "Рейтинг:      " << ratingTrack << "/10" << endl;
        cout << "===============================" << endl;
    }
};

int main(){
    setlocale(LC_ALL, "RU");
    MusicTrack track1("Возьми телефон детка", "Toxis", 186, 8);
    MusicTrack track2("TSM", "MACAN", 168, 9);
    MusicTrack track3("Fix You", "Coldplay", 201, 10);
    MusicTrack track4;
    
    track4.setTrackName("Viva La Vida");
    track4.setSingerName("Coldplay");
    track4.setTrackTime(200);
    track4.setRatingTrack(10);
    
    cout << "My collection: " << endl;
    
    cout << "----Track 1----" << endl;
    track1.printInfo();
    cout << "----Track 2----" << endl;
    track2.printInfo();
    cout << "----Track 3----" << endl;
    track3.printInfo();
    cout << "----Track 4----" << endl;
    track4.printInfo();
    
    cout << "++++++Демонстрация геттеров++++++" << endl;
    cout << "Название track1: " << track1.getTrackName() << endl;
    cout << "Артист track2: " << track2.getSingerName() << endl;
    cout << "Длительность track3: " << track3.getFormattedTime() << endl;
    cout << "Рейтинг track4: " << track4.getRatingTrack() << endl;
    
    return 0;
}
