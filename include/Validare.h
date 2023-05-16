#pragma once
#include <regex>
bool validare_Nr_telefon(const char t[])
{
    std::regex telefon_regex(R"(0+[0-9]{9})");
    return std::regex_match(t, telefon_regex);
}

bool validare_Cnp(const char t[])
{
    std::regex cnp_regex(R"([0-9]{13})");
    return std::regex_match(t, cnp_regex);
}

bool validare_Email(const char t[])
{
    std::regex email_regex(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
    return std::regex_match(t, email_regex);
}

bool validare_Prenume(const char t[])
{
    std::regex prenume_regex(R"([a-zA-Z]+)");
    return std::regex_match(t, prenume_regex);
}
