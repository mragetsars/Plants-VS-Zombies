#include "setting.hpp"

Setting::Setting(){
    ifstream users_file("Settings");
    string line_temp;
    getline(users_file, line_temp);
    get_sun_setting(line_temp);
    getline(users_file, line_temp);
    get_kernelpult_setting(line_temp);
    getline(users_file, line_temp);
    get_peashooter_setting(line_temp);
    getline(users_file, line_temp);
    get_snowpeashooter_setting(line_temp);
    getline(users_file, line_temp);
    get_sunflower_setting(line_temp);
    getline(users_file, line_temp);
    get_wallnut_setting(line_temp);
    getline(users_file, line_temp);
    get_zombie_setting(line_temp);
    getline(users_file, line_temp);
    get_gargantuar_setting(line_temp);
}

Setting::~Setting(){}

long double Setting::str_to_num(string input)
    {
        long double output;
        char *char_temp;
        char_temp = new char[input.length() + 1];
        strcpy(char_temp, input.c_str());
        output = atof(char_temp);
        return output;
    }

void Setting::get_sun_setting(string line){
    stringstream string_stream(line);
    string string_temp;
    getline(string_stream, string_temp, ' ');
    Sun.Speed = str_to_num(string_temp);
    getline(string_stream, string_temp, ' ');
    Sun.Interval = str_to_num(string_temp);
}

void Setting::get_kernelpult_setting(string line){
    stringstream string_stream(line);
    string string_temp;
    getline(string_stream, string_temp, ' ');
    KernelPult.Damage = str_to_num(string_temp);
    getline(string_stream, string_temp, ' ');
    KernelPult.Health = str_to_num(string_temp);
    getline(string_stream, string_temp, ' ');
    KernelPult.Cooldown = str_to_num(string_temp);
    getline(string_stream, string_temp, ' ');
    KernelPult.Hit_Rate = str_to_num(string_temp);
    getline(string_stream, string_temp, ' ');
    KernelPult.Speed = str_to_num(string_temp);
    getline(string_stream, string_temp, ' ');
    KernelPult.Price = str_to_num(string_temp);
}

void Setting::get_peashooter_setting(string line){
    stringstream string_stream(line);
    string string_temp;
    getline(string_stream, string_temp, ' ');
    PeaShooter.Damage = str_to_num(string_temp);
    getline(string_stream, string_temp, ' ');
    PeaShooter.Health = str_to_num(string_temp);
    getline(string_stream, string_temp, ' ');
    PeaShooter.Cooldown = str_to_num(string_temp);
    getline(string_stream, string_temp, ' ');
    PeaShooter.Hit_Rate = str_to_num(string_temp);
    getline(string_stream, string_temp, ' ');
    PeaShooter.Speed = str_to_num(string_temp);
    getline(string_stream, string_temp, ' ');
    PeaShooter.Price = str_to_num(string_temp);
}

void Setting::get_snowpeashooter_setting(string line){
    stringstream string_stream(line);
    string string_temp;
    getline(string_stream, string_temp, ' ');
    SnowpeaShooter.Damage = str_to_num(string_temp);
    getline(string_stream, string_temp, ' ');
    SnowpeaShooter.Health = str_to_num(string_temp);
    getline(string_stream, string_temp, ' ');
    SnowpeaShooter.Cooldown = str_to_num(string_temp);
    getline(string_stream, string_temp, ' ');
    SnowpeaShooter.Hit_Rate = str_to_num(string_temp);
    getline(string_stream, string_temp, ' ');
    SnowpeaShooter.Speed = str_to_num(string_temp);
    getline(string_stream, string_temp, ' ');
    SnowpeaShooter.Price = str_to_num(string_temp);
}

void Setting::get_sunflower_setting(string line){
    stringstream string_stream(line);
    string string_temp;
    getline(string_stream, string_temp, ' ');
    SunFlower.Damage = str_to_num(string_temp);
    getline(string_stream, string_temp, ' ');
    SunFlower.Health = str_to_num(string_temp);
    getline(string_stream, string_temp, ' ');
    SunFlower.Cooldown = str_to_num(string_temp);
    getline(string_stream, string_temp, ' ');
    SunFlower.Hit_Rate = str_to_num(string_temp);
    getline(string_stream, string_temp, ' ');
    SunFlower.Speed = str_to_num(string_temp);
    getline(string_stream, string_temp, ' ');
    SunFlower.Price = str_to_num(string_temp);
}

void Setting::get_wallnut_setting(string line){
    stringstream string_stream(line);
    string string_temp;
    getline(string_stream, string_temp, ' ');
    Wallnut.Damage = str_to_num(string_temp);
    getline(string_stream, string_temp, ' ');
    Wallnut.Health = str_to_num(string_temp);
    getline(string_stream, string_temp, ' ');
    Wallnut.Cooldown = str_to_num(string_temp);
    getline(string_stream, string_temp, ' ');
    Wallnut.Hit_Rate = str_to_num(string_temp);
    getline(string_stream, string_temp, ' ');
    Wallnut.Speed = str_to_num(string_temp);
    getline(string_stream, string_temp, ' ');
    Wallnut.Price = str_to_num(string_temp);
}

void Setting::get_zombie_setting(string line){
    stringstream string_stream(line);
    string string_temp;
    getline(string_stream, string_temp, ' ');
    Zombie.Damage = str_to_num(string_temp);
    getline(string_stream, string_temp, ' ');
    Zombie.Health = str_to_num(string_temp);
    getline(string_stream, string_temp, ' ');
    Zombie.Hit_Rate = str_to_num(string_temp);
    getline(string_stream, string_temp, ' ');
    Zombie.Speed = str_to_num(string_temp);
}

void Setting::get_gargantuar_setting(string line){
    stringstream string_stream(line);
    string string_temp;
    getline(string_stream, string_temp, ' ');
    Gargantuar.Damage = str_to_num(string_temp);
    getline(string_stream, string_temp, ' ');
    Gargantuar.Health = str_to_num(string_temp);
    getline(string_stream, string_temp, ' ');
    Gargantuar.Hit_Rate = str_to_num(string_temp);
    getline(string_stream, string_temp, ' ');
    Gargantuar.Speed = str_to_num(string_temp);
}
