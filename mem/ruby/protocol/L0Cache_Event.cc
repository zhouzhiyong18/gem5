/** \file L0Cache_Event.hh
 *
 * Auto generated C++ code started by /home/zhouzhiyong/gem5/src/mem/slicc/symbols/Type.py:566
 */

#include <cassert>
#include <iostream>
#include <string>

#include "base/logging.hh"
#include "mem/ruby/protocol/L0Cache_Event.hh"

using namespace std;

// Code for output operator
ostream&
operator<<(ostream& out, const L0Cache_Event& obj)
{
    out << L0Cache_Event_to_string(obj);
    out << flush;
    return out;
}

// Code to convert state to a string
string
L0Cache_Event_to_string(const L0Cache_Event& obj)
{
    switch(obj) {
      case L0Cache_Event_Load:
        return "Load";
      case L0Cache_Event_Ifetch:
        return "Ifetch";
      case L0Cache_Event_Store:
        return "Store";
      case L0Cache_Event_Inv:
        return "Inv";
      case L0Cache_Event_L0_Replacement:
        return "L0_Replacement";
      case L0Cache_Event_Fwd_GETX:
        return "Fwd_GETX";
      case L0Cache_Event_Fwd_GETS:
        return "Fwd_GETS";
      case L0Cache_Event_Fwd_GET_INSTR:
        return "Fwd_GET_INSTR";
      case L0Cache_Event_Data:
        return "Data";
      case L0Cache_Event_Data_Exclusive:
        return "Data_Exclusive";
      case L0Cache_Event_Data_Stale:
        return "Data_Stale";
      case L0Cache_Event_Ack:
        return "Ack";
      case L0Cache_Event_Ack_all:
        return "Ack_all";
      case L0Cache_Event_WB_Ack:
        return "WB_Ack";
      default:
        panic("Invalid range for type L0Cache_Event");
    }
}

// Code to convert from a string to the enumeration
L0Cache_Event
string_to_L0Cache_Event(const string& str)
{
    if (str == "Load") {
        return L0Cache_Event_Load;
    } else if (str == "Ifetch") {
        return L0Cache_Event_Ifetch;
    } else if (str == "Store") {
        return L0Cache_Event_Store;
    } else if (str == "Inv") {
        return L0Cache_Event_Inv;
    } else if (str == "L0_Replacement") {
        return L0Cache_Event_L0_Replacement;
    } else if (str == "Fwd_GETX") {
        return L0Cache_Event_Fwd_GETX;
    } else if (str == "Fwd_GETS") {
        return L0Cache_Event_Fwd_GETS;
    } else if (str == "Fwd_GET_INSTR") {
        return L0Cache_Event_Fwd_GET_INSTR;
    } else if (str == "Data") {
        return L0Cache_Event_Data;
    } else if (str == "Data_Exclusive") {
        return L0Cache_Event_Data_Exclusive;
    } else if (str == "Data_Stale") {
        return L0Cache_Event_Data_Stale;
    } else if (str == "Ack") {
        return L0Cache_Event_Ack;
    } else if (str == "Ack_all") {
        return L0Cache_Event_Ack_all;
    } else if (str == "WB_Ack") {
        return L0Cache_Event_WB_Ack;
    } else {
        panic("Invalid string conversion for %s, type L0Cache_Event", str);
    }
}

// Code to increment an enumeration type
L0Cache_Event&
operator++(L0Cache_Event& e)
{
    assert(e < L0Cache_Event_NUM);
    return e = L0Cache_Event(e+1);
}
