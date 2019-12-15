/** \file L1Cache_Event.hh
 *
 * Auto generated C++ code started by /home/zhouzhiyong/gem5/src/mem/slicc/symbols/Type.py:566
 */

#include <cassert>
#include <iostream>
#include <string>

#include "base/logging.hh"
#include "mem/ruby/protocol/L1Cache_Event.hh"

using namespace std;

// Code for output operator
ostream&
operator<<(ostream& out, const L1Cache_Event& obj)
{
    out << L1Cache_Event_to_string(obj);
    out << flush;
    return out;
}

// Code to convert state to a string
string
L1Cache_Event_to_string(const L1Cache_Event& obj)
{
    switch(obj) {
      case L1Cache_Event_Load:
        return "Load";
      case L1Cache_Event_Store:
        return "Store";
      case L1Cache_Event_WriteBack:
        return "WriteBack";
      case L1Cache_Event_L0_DataAck:
        return "L0_DataAck";
      case L1Cache_Event_Inv:
        return "Inv";
      case L1Cache_Event_L0_Invalidate_Own:
        return "L0_Invalidate_Own";
      case L1Cache_Event_L0_Invalidate_Else:
        return "L0_Invalidate_Else";
      case L1Cache_Event_L1_Replacement:
        return "L1_Replacement";
      case L1Cache_Event_Fwd_GETX:
        return "Fwd_GETX";
      case L1Cache_Event_Fwd_GETS:
        return "Fwd_GETS";
      case L1Cache_Event_Data:
        return "Data";
      case L1Cache_Event_Data_Exclusive:
        return "Data_Exclusive";
      case L1Cache_Event_DataS_fromL1:
        return "DataS_fromL1";
      case L1Cache_Event_Data_all_Acks:
        return "Data_all_Acks";
      case L1Cache_Event_L0_Ack:
        return "L0_Ack";
      case L1Cache_Event_Ack:
        return "Ack";
      case L1Cache_Event_Ack_all:
        return "Ack_all";
      case L1Cache_Event_WB_Ack:
        return "WB_Ack";
      default:
        panic("Invalid range for type L1Cache_Event");
    }
}

// Code to convert from a string to the enumeration
L1Cache_Event
string_to_L1Cache_Event(const string& str)
{
    if (str == "Load") {
        return L1Cache_Event_Load;
    } else if (str == "Store") {
        return L1Cache_Event_Store;
    } else if (str == "WriteBack") {
        return L1Cache_Event_WriteBack;
    } else if (str == "L0_DataAck") {
        return L1Cache_Event_L0_DataAck;
    } else if (str == "Inv") {
        return L1Cache_Event_Inv;
    } else if (str == "L0_Invalidate_Own") {
        return L1Cache_Event_L0_Invalidate_Own;
    } else if (str == "L0_Invalidate_Else") {
        return L1Cache_Event_L0_Invalidate_Else;
    } else if (str == "L1_Replacement") {
        return L1Cache_Event_L1_Replacement;
    } else if (str == "Fwd_GETX") {
        return L1Cache_Event_Fwd_GETX;
    } else if (str == "Fwd_GETS") {
        return L1Cache_Event_Fwd_GETS;
    } else if (str == "Data") {
        return L1Cache_Event_Data;
    } else if (str == "Data_Exclusive") {
        return L1Cache_Event_Data_Exclusive;
    } else if (str == "DataS_fromL1") {
        return L1Cache_Event_DataS_fromL1;
    } else if (str == "Data_all_Acks") {
        return L1Cache_Event_Data_all_Acks;
    } else if (str == "L0_Ack") {
        return L1Cache_Event_L0_Ack;
    } else if (str == "Ack") {
        return L1Cache_Event_Ack;
    } else if (str == "Ack_all") {
        return L1Cache_Event_Ack_all;
    } else if (str == "WB_Ack") {
        return L1Cache_Event_WB_Ack;
    } else {
        panic("Invalid string conversion for %s, type L1Cache_Event", str);
    }
}

// Code to increment an enumeration type
L1Cache_Event&
operator++(L1Cache_Event& e)
{
    assert(e < L1Cache_Event_NUM);
    return e = L1Cache_Event(e+1);
}
