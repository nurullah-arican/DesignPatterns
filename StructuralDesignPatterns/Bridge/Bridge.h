#ifndef BRIDGE_H
#define BRIDGE_H

#include <iostream>
#include <string>

// Implementor
class IMediaPlayer {
public:
    virtual void play(const std::string& fileName) = 0;
    virtual ~IMediaPlayer() = default;
};

// Concrete Implementors
class AudioPlayer : public IMediaPlayer {
public:
    void play(const std::string& fileName) override {
        std::cout << "Playing audio file: " << fileName << std::endl;
    }
};

class VideoPlayer : public IMediaPlayer {
public:
    void play(const std::string& fileName) override {
        std::cout << "Playing video file: " << fileName << std::endl;
    }
};

// Abstraction
class MediaControl {
protected:
    IMediaPlayer* mediaPlayer;

public:
    explicit MediaControl(IMediaPlayer* player) : mediaPlayer(player) {}
    virtual void playMedia(const std::string& fileName) = 0;
    virtual ~MediaControl() = default;
};

// Refined Abstraction
class AdvancedMediaControl : public MediaControl {
public:
    explicit AdvancedMediaControl(IMediaPlayer* player) : MediaControl(player) {}

    void playMedia(const std::string& fileName) override {
        std::cout << "Using advanced controls..." << std::endl;
        mediaPlayer->play(fileName);
    }
};

#endif // BRIDGE_H
