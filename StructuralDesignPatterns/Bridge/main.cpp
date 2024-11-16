#include "Bridge.h"

int main()
{
    // Ses oynatıcı ile medya kontrolü
    IMediaPlayer* audioPlayer = new AudioPlayer();
    MediaControl* audioControl = new AdvancedMediaControl(audioPlayer);
    audioControl->playMedia("song.mp3");

    // Video oynatıcı ile medya kontrolü
    IMediaPlayer* videoPlayer = new VideoPlayer();
    MediaControl* videoControl = new AdvancedMediaControl(videoPlayer);
    videoControl->playMedia("movie.mp4");

    // Bellek temizliği
    delete audioControl;
    delete audioPlayer;
    delete videoControl;
    delete videoPlayer;

    return 0;
}
