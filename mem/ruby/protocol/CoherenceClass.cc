/** \file CoherenceClass.hh
 *
 * Auto generated C++ code started by /home/zhouzhiyong/gem5/src/mem/slicc/symbols/Type.py:566
 */

#include <cassert>
#include <iostream>
#include <string>

#include "base/logging.hh"
#include "mem/ruby/protocol/CoherenceClass.hh"

using namespace std;

// Code for output operator
ostream&
operator<<(ostream& out, const CoherenceClass& obj)
{
    out << CoherenceClass_to_string(obj);
    out << flush;
    return out;
}

// Code to convert state to a string
string
CoherenceClass_to_string(const CoherenceClass& obj)
{
    switch(obj) {
      case CoherenceClass_GETX:
        return "GETX";
      case CoherenceClass_UPGRADE:
        return "UPGRADE";
      case CoherenceClass_GETS:
        return "GETS";
      case CoherenceClass_GET_INSTR:
        return "GET_INSTR";
      case CoherenceClass_INV:
        return "INV";
      case CoherenceClass_PUTX:
        return "PUTX";
      case CoherenceClass_WB_ACK:
        return "WB_ACK";
      case CoherenceClass_INV_DATA:
        return "INV_DATA";
      case CoherenceClass_INV_ACK:
        return "INV_ACK";
      case CoherenceClass_DATA:
        return "DATA";
      case CoherenceClass_DATA_EXCLUSIVE:
        return "DATA_EXCLUSIVE";
      case CoherenceClass_ACK:
        return "ACK";
      case CoherenceClass_STALE_DATA:
        return "STALE_DATA";
      default:
        panic("Invalid range for type CoherenceClass");
    }
}

// Code to convert from a string to the enumeration
CoherenceClass
string_to_CoherenceClass(const string& str)
{
    if (str == "GETX") {
        return CoherenceClass_GETX;
    } else if (str == "UPGRADE") {
        return CoherenceClass_UPGRADE;
    } else if (str == "GETS") {
        return CoherenceClass_GETS;
    } else if (str == "GET_INSTR") {
        return CoherenceClass_GET_INSTR;
    } else if (str == "INV") {
        return CoherenceClass_INV;
    } else if (str == "PUTX") {
        return CoherenceClass_PUTX;
    } else if (str == "WB_ACK") {
        return CoherenceClass_WB_ACK;
    } else if (str == "INV_DATA") {
        return CoherenceClass_INV_DATA;
    } else if (str == "INV_ACK") {
        return CoherenceClass_INV_ACK;
    } else if (str == "DATA") {
        return CoherenceClass_DATA;
    } else if (str == "DATA_EXCLUSIVE") {
        return CoherenceClass_DATA_EXCLUSIVE;
    } else if (str == "ACK") {
        return CoherenceClass_ACK;
    } else if (str == "STALE_DATA") {
        return CoherenceClass_STALE_DATA;
    } else {
        panic("Invalid string conversion for %s, type CoherenceClass", str);
    }
}

// Code to increment an enumeration type
CoherenceClass&
operator++(CoherenceClass& e)
{
    assert(e < CoherenceClass_NUM);
    return e = CoherenceClass(e+1);
}
