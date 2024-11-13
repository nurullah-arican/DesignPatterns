#include "Adapter.h"

int main() {
    std::unique_ptr<IMediaPlayer> audioPlayer = std::make_unique<AudioPlayer>();

    audioPlayer->play("mp3", "song.mp3");
    audioPlayer->play("mp4", "movie.mp4");
    audioPlayer->play("vlc", "video.vlc");
    audioPlayer->play("avi", "unsupported.avi");

    return 0;
}
