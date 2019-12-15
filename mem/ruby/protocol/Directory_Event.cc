/** \file Directory_Event.hh
 *
 * Auto generated C++ code started by /home/zhouzhiyong/gem5/src/mem/slicc/symbols/Type.py:566
 */

#include <cassert>
#include <iostream>
#include <string>

#include "base/logging.hh"
#include "mem/ruby/protocol/Directory_Event.hh"

using namespace std;

// Code for output operator
ostream&
operator<<(ostream& out, const Directory_Event& obj)
{
    out << Directory_Event_to_string(obj);
    out << flush;
    return out;
}

// Code to convert state to a string
string
Directory_Event_to_string(const Directory_Event& obj)
{
    switch(obj) {
      case Directory_Event_Fetch:
        return "Fetch";
      case Directory_Event_Data:
        return "Data";
      case Directory_Event_Memory_Data:
        return "Memory_Data";
      case Directory_Event_Memory_Ack:
        return "Memory_Ack";
      case Directory_Event_DMA_READ:
        return "DMA_READ";
      case Directory_Event_DMA_WRITE:
        return "DMA_WRITE";
      case Directory_Event_CleanReplacement:
        return "CleanReplacement";
      default:
        panic("Invalid range for type Directory_Event");
    }
}

// Code to convert from a string to the enumeration
Directory_Event
string_to_Directory_Event(const string& str)
{
    if (str == "Fetch") {
        return Directory_Event_Fetch;
    } else if (str == "Data") {
        return Directory_Event_Data;
    } else if (str == "Memory_Data") {
        return Directory_Event_Memory_Data;
    } else if (str == "Memory_Ack") {
        return Directory_Event_Memory_Ack;
    } else if (str == "DMA_READ") {
        return Directory_Event_DMA_READ;
    } else if (str == "DMA_WRITE") {
        return Directory_Event_DMA_WRITE;
    } else if (str == "CleanReplacement") {
        return Directory_Event_CleanReplacement;
    } else {
        panic("Invalid string conversion for %s, type Directory_Event", str);
    }
}

// Code to increment an enumeration type
Directory_Event&
operator++(Directory_Event& e)
{
    assert(e < Directory_Event_NUM);
    return e = Directory_Event(e+1);
}
