/** \file L1Cache_State.hh
 *
 * Auto generated C++ code started by /home/zhouzhiyong/gem5/src/mem/slicc/symbols/Type.py:566
 */

#include <cassert>
#include <iostream>
#include <string>

#include "base/logging.hh"
#include "mem/ruby/protocol/L1Cache_State.hh"

using namespace std;

// Code to convert the current state to an access permission
AccessPermission L1Cache_State_to_permission(const L1Cache_State& obj)
{
    switch(obj) {
      case L1Cache_State_I:
        return AccessPermission_Invalid;
      case L1Cache_State_S:
        return AccessPermission_Read_Only;
      case L1Cache_State_SS:
        return AccessPermission_Read_Only;
      case L1Cache_State_E:
        return AccessPermission_Read_Only;
      case L1Cache_State_EE:
        return AccessPermission_Read_Write;
      case L1Cache_State_M:
        return AccessPermission_Maybe_Stale;
      case L1Cache_State_MM:
        return AccessPermission_Read_Write;
      case L1Cache_State_IS:
        return AccessPermission_Busy;
      case L1Cache_State_IM:
        return AccessPermission_Busy;
      case L1Cache_State_SM:
        return AccessPermission_Read_Only;
      case L1Cache_State_IS_I:
        return AccessPermission_Busy;
      case L1Cache_State_M_I:
        return AccessPermission_Busy;
      case L1Cache_State_SINK_WB_ACK:
        return AccessPermission_Busy;
      case L1Cache_State_S_IL0:
        return AccessPermission_Busy;
      case L1Cache_State_E_IL0:
        return AccessPermission_Busy;
      case L1Cache_State_M_IL0:
        return AccessPermission_Busy;
      case L1Cache_State_MM_IL0:
        return AccessPermission_Read_Write;
      case L1Cache_State_SM_IL0:
        return AccessPermission_Busy;
      default:
        panic("Unknown state access permission converstion for L1Cache_State");
    }
}

// Code for output operator
ostream&
operator<<(ostream& out, const L1Cache_State& obj)
{
    out << L1Cache_State_to_string(obj);
    out << flush;
    return out;
}

// Code to convert state to a string
string
L1Cache_State_to_string(const L1Cache_State& obj)
{
    switch(obj) {
      case L1Cache_State_I:
        return "I";
      case L1Cache_State_S:
        return "S";
      case L1Cache_State_SS:
        return "SS";
      case L1Cache_State_E:
        return "E";
      case L1Cache_State_EE:
        return "EE";
      case L1Cache_State_M:
        return "M";
      case L1Cache_State_MM:
        return "MM";
      case L1Cache_State_IS:
        return "IS";
      case L1Cache_State_IM:
        return "IM";
      case L1Cache_State_SM:
        return "SM";
      case L1Cache_State_IS_I:
        return "IS_I";
      case L1Cache_State_M_I:
        return "M_I";
      case L1Cache_State_SINK_WB_ACK:
        return "SINK_WB_ACK";
      case L1Cache_State_S_IL0:
        return "S_IL0";
      case L1Cache_State_E_IL0:
        return "E_IL0";
      case L1Cache_State_M_IL0:
        return "M_IL0";
      case L1Cache_State_MM_IL0:
        return "MM_IL0";
      case L1Cache_State_SM_IL0:
        return "SM_IL0";
      default:
        panic("Invalid range for type L1Cache_State");
    }
}

// Code to convert from a string to the enumeration
L1Cache_State
string_to_L1Cache_State(const string& str)
{
    if (str == "I") {
        return L1Cache_State_I;
    } else if (str == "S") {
        return L1Cache_State_S;
    } else if (str == "SS") {
        return L1Cache_State_SS;
    } else if (str == "E") {
        return L1Cache_State_E;
    } else if (str == "EE") {
        return L1Cache_State_EE;
    } else if (str == "M") {
        return L1Cache_State_M;
    } else if (str == "MM") {
        return L1Cache_State_MM;
    } else if (str == "IS") {
        return L1Cache_State_IS;
    } else if (str == "IM") {
        return L1Cache_State_IM;
    } else if (str == "SM") {
        return L1Cache_State_SM;
    } else if (str == "IS_I") {
        return L1Cache_State_IS_I;
    } else if (str == "M_I") {
        return L1Cache_State_M_I;
    } else if (str == "SINK_WB_ACK") {
        return L1Cache_State_SINK_WB_ACK;
    } else if (str == "S_IL0") {
        return L1Cache_State_S_IL0;
    } else if (str == "E_IL0") {
        return L1Cache_State_E_IL0;
    } else if (str == "M_IL0") {
        return L1Cache_State_M_IL0;
    } else if (str == "MM_IL0") {
        return L1Cache_State_MM_IL0;
    } else if (str == "SM_IL0") {
        return L1Cache_State_SM_IL0;
    } else {
        panic("Invalid string conversion for %s, type L1Cache_State", str);
    }
}

// Code to increment an enumeration type
L1Cache_State&
operator++(L1Cache_State& e)
{
    assert(e < L1Cache_State_NUM);
    return e = L1Cache_State(e+1);
}
