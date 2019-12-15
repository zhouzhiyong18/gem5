/** \file L2Cache_Event.hh
 *
 * Auto generated C++ code started by /home/zhouzhiyong/gem5/src/mem/slicc/symbols/Type.py:566
 */

#include <cassert>
#include <iostream>
#include <string>

#include "base/logging.hh"
#include "mem/ruby/protocol/L2Cache_Event.hh"

using namespace std;

// Code for output operator
ostream&
operator<<(ostream& out, const L2Cache_Event& obj)
{
    out << L2Cache_Event_to_string(obj);
    out << flush;
    return out;
}

// Code to convert state to a string
string
L2Cache_Event_to_string(const L2Cache_Event& obj)
{
    switch(obj) {
      case L2Cache_Event_L1_GET_INSTR:
        return "L1_GET_INSTR";
      case L2Cache_Event_L1_GETS:
        return "L1_GETS";
      case L2Cache_Event_L1_GETX:
        return "L1_GETX";
      case L2Cache_Event_L1_UPGRADE:
        return "L1_UPGRADE";
      case L2Cache_Event_L1_PUTX:
        return "L1_PUTX";
      case L2Cache_Event_L1_PUTX_old:
        return "L1_PUTX_old";
      case L2Cache_Event_L2_Replacement:
        return "L2_Replacement";
      case L2Cache_Event_L2_Replacement_clean:
        return "L2_Replacement_clean";
      case L2Cache_Event_Mem_Data:
        return "Mem_Data";
      case L2Cache_Event_Mem_Ack:
        return "Mem_Ack";
      case L2Cache_Event_WB_Data:
        return "WB_Data";
      case L2Cache_Event_WB_Data_clean:
        return "WB_Data_clean";
      case L2Cache_Event_Ack:
        return "Ack";
      case L2Cache_Event_Ack_all:
        return "Ack_all";
      case L2Cache_Event_Unblock:
        return "Unblock";
      case L2Cache_Event_Exclusive_Unblock:
        return "Exclusive_Unblock";
      case L2Cache_Event_MEM_Inv:
        return "MEM_Inv";
      default:
        panic("Invalid range for type L2Cache_Event");
    }
}

// Code to convert from a string to the enumeration
L2Cache_Event
string_to_L2Cache_Event(const string& str)
{
    if (str == "L1_GET_INSTR") {
        return L2Cache_Event_L1_GET_INSTR;
    } else if (str == "L1_GETS") {
        return L2Cache_Event_L1_GETS;
    } else if (str == "L1_GETX") {
        return L2Cache_Event_L1_GETX;
    } else if (str == "L1_UPGRADE") {
        return L2Cache_Event_L1_UPGRADE;
    } else if (str == "L1_PUTX") {
        return L2Cache_Event_L1_PUTX;
    } else if (str == "L1_PUTX_old") {
        return L2Cache_Event_L1_PUTX_old;
    } else if (str == "L2_Replacement") {
        return L2Cache_Event_L2_Replacement;
    } else if (str == "L2_Replacement_clean") {
        return L2Cache_Event_L2_Replacement_clean;
    } else if (str == "Mem_Data") {
        return L2Cache_Event_Mem_Data;
    } else if (str == "Mem_Ack") {
        return L2Cache_Event_Mem_Ack;
    } else if (str == "WB_Data") {
        return L2Cache_Event_WB_Data;
    } else if (str == "WB_Data_clean") {
        return L2Cache_Event_WB_Data_clean;
    } else if (str == "Ack") {
        return L2Cache_Event_Ack;
    } else if (str == "Ack_all") {
        return L2Cache_Event_Ack_all;
    } else if (str == "Unblock") {
        return L2Cache_Event_Unblock;
    } else if (str == "Exclusive_Unblock") {
        return L2Cache_Event_Exclusive_Unblock;
    } else if (str == "MEM_Inv") {
        return L2Cache_Event_MEM_Inv;
    } else {
        panic("Invalid string conversion for %s, type L2Cache_Event", str);
    }
}

// Code to increment an enumeration type
L2Cache_Event&
operator++(L2Cache_Event& e)
{
    assert(e < L2Cache_Event_NUM);
    return e = L2Cache_Event(e+1);
}