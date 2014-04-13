/*
  Copyright © 2014 Jesse 'Jeaye' Wilkerson
  See licensing in LICENSE file, or at:
    http://www.opensource.org/licenses/MIT

  File: exception.hpp
  Author: Jesse 'Jeaye' Wilkerson
*/

#pragma once

#include <iostream>
#include <string>
#include <stdexcept>

class helper
{
  public:
    helper() = default;
    helper(std::string const &prog)
      : prog_(prog)
    { }

    virtual void help() const
    {
      std::cout
          << "Usage: " + prog_ + " [OPTION...] FILE" << std::endl
          << "Usage: " + prog_ + " [-h|--help]" << std::endl
          << "Usage: " + prog_ + " [-v|--version]" << std::endl << std::endl
          << "Generate man pages from cppreference html." << std::endl
          << std::endl
          << "Options:" << std::endl
          << "  -o, --output\t\tSpecify output file" << std::endl
          << "  -h, --help\t\tShow this help page and quit" << std::endl
          << "  -v, --version\t\tShow the version number and quit" << std::endl
          << std::endl
          << "Issues/bugs/questions visit https://github.com/jeaye/cppman" << std::endl;
    }

  private:
    std::string prog_{ "cppman" };
};

class invalid_cmdline : public helper
{
  public:
    invalid_cmdline() = delete;
    invalid_cmdline(std::string const &prog, std::string const &err)
      : helper(prog), err_(err)
    { }

    void help() const override
    {
      if(err_.size())
      { std::cout << "error: " << err_ << std::endl << std::endl; }
      helper::help();
    }

  private:
    std::string err_;
};

struct early_exit{};
