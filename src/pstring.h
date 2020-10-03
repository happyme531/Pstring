#pragma once
#include <string>
#include "psram_allocator.hpp"

//Just use them as regular as std::string and std::wstring. 
namespace Pstring{
    using pstring = std::basic_string<char,std::char_traits<char>,psram_allocator<char>>;
    using pwstring = std::basic_string<wchar_t,std::char_traits<wchar_t>,psram_allocator<wchar_t>>;
};