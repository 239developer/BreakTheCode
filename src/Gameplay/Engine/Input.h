#pragma once

class Input
{
    private:
        static int pressed[];
        static bool anythingDown;
    public:
        static void resetKeys();
        static void resetKey(int);
        static void setKey(int);
        static bool getKeyDown(int);
        static bool getAnyKeyDown();
        Input() = delete;
};