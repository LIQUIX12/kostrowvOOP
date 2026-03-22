#include <iostream>
#include <string>
using namespace std;

class MusicTrack {
protected:
    string trackName;
    string singerName;
    int trackTime;
    int ratingTrack;

public:
    MusicTrack(string title, string singer, int duration, int rating) {
        trackName = title;
        singerName = singer;
        
        if (duration >= 0) {
            trackTime = duration;
        } else {
            trackTime = 0;
            cout << "Длительность не может быть отрицательной. Установлено 0" << endl;
        }
        
        if (rating >= 1 && rating <= 10) {
            ratingTrack = rating;
        } else {
            ratingTrack = 1;
            cout << "Рейтинг должен быть от 1 до 10 включительно. Установлено 1" << endl;
        }
    }
    
    MusicTrack() {
        trackName = "Без имени";
        singerName = "Неизвестный исполнитель";
        trackTime = 0;
        ratingTrack = 1;
    }
    
    virtual ~MusicTrack() {
        cout << "Трек \"" << trackName << "\" удален" << endl;
    }
    
    void setTrackName(string name) {
        trackName = name;
    }
    
    void setSingerName(string singer) {
        singerName = singer;
    }
    
    void setTrackTime(int duration) {
        if (duration >= 0) {
            trackTime = duration;
        } else {
            trackTime = 0;
            cout << "Длительность не может быть отрицательной. Установлено 0" << endl;
        }
    }
    
    void setRatingTrack(int rating) {
        if (rating >= 1 && rating <= 10) {
            ratingTrack = rating;
        } else {
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
    
    int getRatingTrack() {
        return ratingTrack;
    }
    
    string getFormattedTime() {
        int minutes = trackTime / 60;
        int seconds = trackTime % 60;
        return to_string(minutes) + ":" + (seconds < 10 ? "0" : "") + to_string(seconds);
    }
    
    virtual string getFullTitle() = 0;
    virtual string getQualityDescription() = 0;
    
    virtual void printInfo() {
        cout << "===============================" << endl;
        cout << "Название:     " << trackName << endl;
        cout << "Исполнитель:  " << singerName << endl;
        cout << "Длительность: " << getFormattedTime() << endl;
        cout << "Рейтинг:      " << ratingTrack << "/10" << endl;
    }
};

class StudioTrack : public MusicTrack {
private:
    string albumName;
    int trackNumber;
    
public:
    StudioTrack(string title, string singer, int duration, int rating,
                string album, int number)
        : MusicTrack(title, singer, duration, rating) {
        albumName = album;
        trackNumber = number;
    }
    
    StudioTrack() : MusicTrack() {
        albumName = "Неизвестный альбом";
        trackNumber = 0;
    }
    
    string formatFullTitle() {
        return albumName + " - " + to_string(trackNumber) + " - " + trackName;
    }
    
    string getFullTitle() override {
        return formatFullTitle();
    }
    
    string getQualityDescription() override {
        return "Студийная запись, высокое качество звука, чистовой вариант";
    }
    
    void printInfo() override {
        MusicTrack::printInfo();
        cout << "Альбом:       " << albumName << endl;
        cout << "Номер в альбоме: " << trackNumber << endl;
        cout << "===============================" << endl;
    }
    
    string getAlbumName() { return albumName; }
    int getTrackNumber() { return trackNumber; }
    
    void setAlbumName(string album) { albumName = album; }
    void setTrackNumber(int number) { trackNumber = number; }
};

class LiveTrack : public MusicTrack {
private:
    string concertName;
    string city;
    
public:
    LiveTrack(string title, string singer, int duration, int rating,
              string concert, string cityName)
        : MusicTrack(title, singer, duration, rating) {
        concertName = concert;
        city = cityName;
    }
    
    LiveTrack() : MusicTrack() {
        concertName = "Неизвестный концерт";
        city = "Неизвестный город";
    }
    
    string formatPerformanceDesc() {
        return "\"" + trackName + "\" в исполнении на концерте \"" +
               concertName + "\" (" + city + ")";
    }
    
    string getFullTitle() override {
        return trackName + " (live in " + city + ")";
    }
    
    string getQualityDescription() override {
        return "Концертная запись, живое исполнение, атмосфера мероприятия";
    }
    
    void printInfo() override {
        MusicTrack::printInfo();
        cout << "Концерт:      " << concertName << endl;
        cout << "Город:        " << city << endl;
        cout << "===============================" << endl;
    }
    
    string getConcertName() { return concertName; }
    string getCity() { return city; }
    
    void setConcertName(string concert) { concertName = concert; }
    void setCity(string cityName) { city = cityName; }
};

int main() {
    setlocale(LC_ALL, "RU");
    
    const int SIZE = 5;
    MusicTrack* playlist[SIZE];
    
    playlist[0] = new StudioTrack("Bohemian Rhapsody", "Queen", 354, 10,
                                   "A Night at the Opera", 1);
    
    playlist[1] = new LiveTrack("Hotel California", "Eagles", 391, 10,
                                 "Live at The Forum", "Los Angeles");
    
    playlist[2] = new StudioTrack("Imagine", "John Lennon", 183, 9,
                                   "Imagine", 1);
    
    playlist[3] = new LiveTrack("Smells Like Teen Spirit", "Nirvana", 280, 10,
                                 "Live at Reading", "Reading");
    
    playlist[4] = new StudioTrack("Viva La Vida", "Coldplay", 242, 10,
                                   "Viva La Vida or Death and All His Friends", 2);
    
    cout << "=== 1. ИНФОРМАЦИЯ О ВСЕХ ТРЕКАХ ===" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << "\n--- Трек " << i+1 << " ---" << endl;
        playlist[i]->printInfo();
    }
    
    cout << "\n=== 2. ПОЛНОЕ ОПИСАНИЕ ТРЕКОВ ===" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << "\nТрек " << i+1 << ":" << endl;
        cout << "   Полное название: " << playlist[i]->getFullTitle() << endl;
        cout << "   Описание качества: " << playlist[i]->getQualityDescription() << endl;
    }
    
    cout << "\n=== 3. СПЕЦИФИЧНЫЕ МЕТОДЫ ПРОИЗВОДНЫХ КЛАССОВ ===" << endl;
    
    cout << "\n--- StudioTrack специфичные методы ---" << endl;
    for (int i = 0; i < SIZE; i++) {
        StudioTrack* studioPtr = dynamic_cast<StudioTrack*>(playlist[i]);
        if (studioPtr) {
            cout << "Трек: " << studioPtr->getTrackName() << endl;
            cout << "   Формат названия: " << studioPtr->formatFullTitle() << endl;
            cout << "   Альбом: " << studioPtr->getAlbumName() << endl;
            cout << "   Номер: " << studioPtr->getTrackNumber() << endl;
        }
    }
    
    cout << "\n--- LiveTrack специфичные методы ---" << endl;
    for (int i = 0; i < SIZE; i++) {
        LiveTrack* livePtr = dynamic_cast<LiveTrack*>(playlist[i]);
        if (livePtr) {
            cout << "Трек: " << livePtr->getTrackName() << endl;
            cout << "   Описание выступления: " << livePtr->formatPerformanceDesc() << endl;
            cout << "   Концерт: " << livePtr->getConcertName() << endl;
            cout << "   Город: " << livePtr->getCity() << endl;
        }
    }
    
    
    cout << "\n=== 4. ДЕМОНСТРАЦИЯ ВАЛИДАЦИИ ===" << endl;
    
    StudioTrack testTrack;
    cout << "Пытаемся установить рейтинг 15:" << endl;
    testTrack.setRatingTrack(15);
    
    cout << "\nПытаемся установить отрицательную длительность:" << endl;
    testTrack.setTrackTime(-50);
    
    cout << "\nТекущие значения после валидации:" << endl;
    cout << "  Рейтинг: " << testTrack.getRatingTrack() << "/10" << endl;
    cout << "  Длительность: " << testTrack.getFormattedTime() << endl;
    
    cout << "\n=== 5. КОНСТРУКТОР ПО УМОЛЧАНИЮ ===" << endl;
    LiveTrack defaultLiveTrack;
    defaultLiveTrack.printInfo();
    
    cout << "\n=== 6. ОСВОБОЖДЕНИЕ ПАМЯТИ ===" << endl;
    for (int i = 0; i < SIZE; i++) {
        delete playlist[i];
    }
    
    cout << "\nПрограмма завершена." << endl;
    
    return 0;
}
