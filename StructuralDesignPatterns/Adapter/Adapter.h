#include <iostream>
#include <string>
#include <memory>

class IMediaPlayer {
public:
    virtual void play(const std::string& audioType, const std::string& fileName) = 0;
    virtual ~IMediaPlayer() = default;
};

class Mp3Player : public IMediaPlayer {
public:
    void play(const std::string& audioType, const std::string& fileName) override {
        if (audioType == "mp3") {
            std::cout << "Playing mp3 file. Name: " << fileName << std::endl;
        }
        else {
            std::cout << "Invalid media. mp3 format supported only." << std::endl;
        }
    }
};

class AdvancedMediaPlayer {
public:
    void playMp4(const std::string& fileName) {
        std::cout << "Playing mp4 file. Name: " << fileName << std::endl;
    }

    void playVlc(const std::string& fileName) {
        std::cout << "Playing vlc file. Name: " << fileName << std::endl;
    }
};

class MediaAdapter : public IMediaPlayer {
private:
    std::unique_ptr<AdvancedMediaPlayer> advancedMediaPlayer;
    std::string audioType;

public:
    MediaAdapter(const std::string& type) : audioType(type) {
        advancedMediaPlayer = std::make_unique<AdvancedMediaPlayer>();
    }

    void play(const std::string& audioType, const std::string& fileName) override {
        if (audioType == "mp4") {
            advancedMediaPlayer->playMp4(fileName);
        }
        else if (audioType == "vlc") {
            advancedMediaPlayer->playVlc(fileName);
        }
    }
};

class AudioPlayer : public IMediaPlayer {
private:
    std::unique_ptr<MediaAdapter> mediaAdapter;

public:
    void play(const std::string& audioType, const std::string& fileName) override {
        if (audioType == "mp3") {
            std::cout << "Playing mp3 file. Name: " << fileName << std::endl;
        }
        else if (audioType == "mp4" || audioType == "vlc") {
            mediaAdapter = std::make_unique<MediaAdapter>(audioType);
            mediaAdapter->play(audioType, fileName);
        }
        else {
            std::cout << "Invalid media. " << audioType << " format not supported." << std::endl;
        }
    }
};
