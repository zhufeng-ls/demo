#include "SDL2/SDL.h"
#include <iostream>
#include <string>

using namespace std;

void playsound(string path)
{
    // Initialize SDL.
    if (SDL_Init(SDL_INIT_AUDIO) < 0)
    {
        cerr << "error sdl init" << endl;
        cerr << SDL_GetError() << endl;
        return;
    }
    // local variables
    Uint32 wav_length; // length of our sample
    Uint8 *wav_buffer; // buffer containing our audio file
    SDL_AudioSpec wav_spec;
    if (SDL_LoadWAV(path.c_str(), &wav_spec, &wav_buffer, &wav_length) == NULL)
    {
        cerr << "error load wav" << endl;
        return;
    }
    SDL_AudioDeviceID deviceId =
        SDL_OpenAudioDevice(NULL, 0, &wav_spec, NULL, 0);
    SDL_QueueAudio(deviceId, wav_buffer, wav_length);
    SDL_PauseAudioDevice(deviceId, 0);
    SDL_Delay(1000 * 1);
    cout << "begin close" << endl;
    SDL_CloseAudioDevice(deviceId);
    SDL_FreeWAV(wav_buffer);
    SDL_Quit();
}

int main(int argc, char *argv[])
{
    std::string path = "1.mp3";
    if (argc > 1)
    {
        path = argv[1];
    }
    cout << "path: " << path << endl;

    playsound(path);
}