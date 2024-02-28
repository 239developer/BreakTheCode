#pragma once

class Input
{
    private:
        static int pressed[];
    public:
        static void resetKeys();
        static void resetKey(int);
        static void setKey(int);
        static bool getKeyDown(int);
        Input() = delete;
};