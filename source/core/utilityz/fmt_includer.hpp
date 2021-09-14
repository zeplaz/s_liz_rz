//fmt_includer.hpp

/*
 Includer for 3rd party fmt formate output.. likely give alot better profrmance
 on debug code well splicing it in espclay across multithreads. and ya cool colorus and etc.. 
 folder with includes, and documents+. etc.
the libary and its sorce code are Copyright (c) 2012 - present, Victor Zverovich
see license file for detals.

*/
#ifndef SLIZERZ_FTM_INCLUDER_2021_HPP
#define SLIZERZ_FTM_INCLUDER_2021_HPP

#include "../../3rd_party/fmt/include/fmt/core.h"
#include "../../3rd_party/fmt/include/fmt/color.h"
#include "../../3rd_party/fmt/include/fmt/ranges.h"
#include "../../3rd_party/fmt/include/fmt/chrono.h"

#endif

//test examples/
/*
  EXPECT_EQ(fmt::format(fg(fmt::rgb(255, 20, 30)), "rgb(255,20,30)"),
            "\x1b[38;2;255;020;030mrgb(255,20,30)\x1b[0m");

  EXPECT_EQ(fmt::format(fmt::emphasis::bold, "bold"), "\x1b[1mbold\x1b[0m");
  EXPECT_EQ(fmt::format(fmt::emphasis::faint, "faint"), "\x1b[2mfaint\x1b[0m");
  EXPECT_EQ(fmt::format(fmt::emphasis::italic, "italic"),
            "\x1b[3mitalic\x1b[0m");
  EXPECT_EQ(fmt::format(fmt::emphasis::underline, "underline"),
            "\x1b[4munderline\x1b[0m");
  EXPECT_EQ(fmt::format(fmt::emphasis::blink, "blink"), "\x1b[5mblink\x1b[0m");
  EXPECT_EQ(fmt::format(fmt::emphasis::reverse, "reverse"),
            "\x1b[7mreverse\x1b[0m");
  EXPECT_EQ(fmt::format(fmt::emphasis::conceal, "conceal"),
            "\x1b[8mconceal\x1b[0m");
  EXPECT_EQ(fmt::format(fmt::emphasis::strikethrough, "strikethrough"),
            "\x1b[9mstrikethrough\x1b[0m");


            EXPECT_EQ(fmt::format(fg(fmt::terminal_color::bright_green), "tbgreen"),
            "\x1b[92mtbgreen\x1b[0m");
  EXPECT_EQ(fmt::format(bg(fmt::terminal_color::bright_magenta), "tbmagenta"),
            "\x1b[105mtbmagenta\x1b[0m");

            
See the `documentation <https://fmt.dev>`_ for more details.

Examples
--------

**Print to stdout** (`run <https://godbolt.org/z/Tevcjh>`_)

.. code:: c++

    #include <fmt/core.h>
    
    int main() {
      fmt::print("Hello, world!\n");
    }

**Format a string** (`run <https://godbolt.org/z/oK8h33>`_)

.. code:: c++

    std::string s = fmt::format("The answer is {}.", 42);
    // s == "The answer is 42."

**Format a string using positional arguments** (`run <https://godbolt.org/z/Yn7Txe>`_)

.. code:: c++

    std::string s = fmt::format("I'd rather be {1} than {0}.", "right", "happy");
    // s == "I'd rather be happy than right."

**Print chrono durations** (`run <https://godbolt.org/z/K8s4Mc>`_)

.. code:: c++

    #include <fmt/chrono.h>

    int main() {
      using namespace std::literals::chrono_literals;
      fmt::print("Default format: {} {}\n", 42s, 100ms);
      fmt::print("strftime-like format: {:%H:%M:%S}\n", 3h + 15min + 30s);
    }

Output::

    Default format: 42s 100ms
    strftime-like format: 03:15:30

**Print a container** (`run <https://godbolt.org/z/MjsY7c>`_)

.. code:: c++

    #include <vector>
    #include <fmt/ranges.h>

    int main() {
      std::vector<int> v = {1, 2, 3};
      fmt::print("{}\n", v);
    }

Output::

    [1, 2, 3]

**Check a format string at compile time**

.. code:: c++

    std::string s = fmt::format("{:d}", "I am not a number");

This gives a compile-time error in C++20 because ``d`` is an invalid format
specifier for a string.

**Write a file from a single thread**

.. code:: c++

    #include <fmt/os.h>

    int main() {
      auto out = fmt::output_file("guide.txt");
      out.print("Don't {}", "Panic");
    }

This can be `5 to 9 times faster than fprintf
<http://www.zverovich.net/2020/08/04/optimal-file-buffer-size.html>`_.

**Print with colors and text styles**

.. code:: c++

    #include <fmt/color.h>

    int main() {
      fmt::print(fg(fmt::color::crimson) | fmt::emphasis::bold,
                 "Hello, {}!\n", "world");
      fmt::print(fg(fmt::color::floral_white) | bg(fmt::color::slate_gray) |
                 fmt::emphasis::underline, "Hello, {}!\n", "мир");
      fmt::print(fg(fmt::color::steel_blue) | fmt::emphasis::italic,
                 "Hello, {}!\n", "世界");
    }

  */