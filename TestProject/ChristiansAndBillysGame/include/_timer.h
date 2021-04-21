#ifndef _TIMER_H
#define _TIMER_H

#include<time.h>

class _timer
{
    public:
        _timer();
        virtual ~_timer();

        clock_t startTime;

        bool isStart();
        bool isPaused();
        bool isStopped();

        clock_t getTicks();                 //Get ticks for animation
        void startTimer();                  //Starting the timer
        void pauseTimer();
        void stopTimer();
        void resetTime();                   //Resetting the timer

    protected:

    private:
};

#endif // _TIMER_H
