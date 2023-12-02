#include <iostream>
#include <fstream>
#include <ranges>
#include <charconv>
#include <string_view>
#include <iomanip>
#include <algorithm>
#include <unordered_map>
#include <tuple>

void part_a() {
    std::ifstream data("02.input");
    std::string line;
    int sum = 0;
    while(std::getline(data, line)) {
        auto delim = line.find(":");

        int game_num;
        std::from_chars(line.data() + 5,line.data()+ delim , game_num);

        auto valid_game = line
            | std::views::drop(delim + 1) // skip until first number
            | std::views::split(';')
            | std::views::transform([](auto v){
                auto valid = v
                    | std::views::split(',')
                    | std::views::transform([](auto w){
                        auto space = std::find(w.begin() + 1, w.end(), ' ');
                        auto space_ind = std::distance(w.begin(), space);
                        int num;
                        std::from_chars(w.data() + 1,w.data()+ space_ind , num);
                        switch (w.data()[space_ind+1]) {
                            case 'r':
                              return num <= 12;
                            case 'g':
                              return num <= 13;
                            case 'b':
                              return num <= 14;
                            default:
                              std::cout << "\n\n\nfuck\n\n\n";
                              return false;
                        }
                    });
                auto x = std::ranges::any_of(valid, [](auto x) {
                    return !x;
                });
                return !x;
            });

        auto any_invalid = std::ranges::any_of(valid_game, [](bool x) { return !x; });

        if(!any_invalid) {
            sum += game_num;
        }
    }

    std::cout << "a: " << sum << "\n";
}
void part_b() {
    std::ifstream data("02.input");
    std::string line;
    int sum = 0;
    while(std::getline(data, line)) {
        auto delim = line.find(":");

        int game_num;
        std::from_chars(line.data() + 5,line.data()+ delim , game_num);

        auto powers_of_set = line
            | std::views::drop(delim + 1) // skip until first number
            | std::views::split(';')
            | std::views::transform([](auto v){
                auto bla = v
                    | std::views::split(',')
                    | std::views::transform([](auto w){
                        auto space = std::find(w.begin() + 1, w.end(), ' ');
                        auto space_ind = std::distance(w.begin(), space);
                        int num;
                        std::from_chars(w.data() + 1,w.data()+ space_ind , num);
                        std::tuple<char,int> tpl = {w.data()[space_ind+1], num};
                        return tpl;
                    });
                    return bla;
            });

        std::unordered_map<char, int> powers = {
            {'r', 0},
            {'g', 0},
            {'b', 0},
        };

        for (auto subset : powers_of_set) {
            for (auto power : subset) {
                auto color = std::get<0>(power);
                auto num = std::get<1>(power);
                if(powers.at(color) < num) {
                    powers.at(color) = num;
                }
            }
        }

        auto pwr = powers.at('r') * powers.at('g') * powers.at('b');
        sum += pwr;
    }

    std::cout << "b: " << sum << "\n";
}

int main() {
    part_a();
    part_b();
}