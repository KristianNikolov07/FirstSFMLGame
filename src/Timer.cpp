#include "Timer.h"
#include <iostream>


Timer::~Timer() {

}


void Timer::update(float delta) {
    int time = clock.getElapsedTime().asMilliseconds();
    int minutes = time / 60000;
    time -= minutes * 60000;
    int seconds = time / 1000;
    time -= seconds * 1000;
    time /= 10;

    std::string minutesStr;
    if (minutes < 10) {
        minutesStr = "0" + std::to_string(minutes);
    }
    else {
        minutesStr = std::to_string(minutes);
    }

    std::string secondsStr;
    if (seconds < 10) {
        secondsStr = "0" + std::to_string(seconds);
    }
    else {
        secondsStr = std::to_string(seconds);
    }

    std::string timeStr;
    if (time < 10) {
        timeStr = "0" + std::to_string(time);
    }
    else {
        timeStr = std::to_string(time);
    }

    setString(minutesStr + ":" + secondsStr + "." + timeStr);
}
