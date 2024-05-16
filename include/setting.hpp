#include "global.hpp"

struct ZOMBIE
{
    int Damage;
    int Health;
    int Hit_Rate;
    int Speed;
};

struct PLANT
{
    int Damage;
    int Health;
    int Cooldown;
    int Hit_Rate;
    int Speed;
    int Price;
};

struct SUN
{
    int Speed;
    int Interval;
};

class Setting{
public:
    Setting();
    ~Setting();
    SUN Sun;
    PLANT KernelPult;
    PLANT PeaShooter;
    PLANT SnowpeaShooter;
    PLANT SunFlower;
    PLANT Wallnut;
    ZOMBIE Zombie;
    ZOMBIE Gargantuar;
private:
    long double str_to_num(string input);
    void get_sun_setting(string line);
    void get_kernelpult_setting(string line);
    void get_peashooter_setting(string line);
    void get_snowpeashooter_setting(string line);
    void get_sunflower_setting(string line);
    void get_wallnut_setting(string line);
    void get_zombie_setting(string line);
    void get_gargantuar_setting(string line);
};