/** \file L0Cache_State.hh
 *
 * Auto generated C++ code started by /home/zhouzhiyong/gem5/src/mem/slicc/symbols/Type.py:458
 */

#ifndef __L0Cache_State_HH__
#define __L0Cache_State_HH__

#include <iostream>
#include <string>

#include "mem/ruby/protocol/AccessPermission.hh"

// Class definition
/** \enum L0Cache_State
 *  \brief Cache states
 */
enum L0Cache_State {
    L0Cache_State_FIRST,
    L0Cache_State_I = L0Cache_State_FIRST, /**< No description avaliable */
    L0Cache_State_S, /**< No description avaliable */
    L0Cache_State_E, /**< No description avaliable */
    L0Cache_State_M, /**< No description avaliable */
    L0Cache_State_Inst_IS, /**< No description avaliable */
    L0Cache_State_IS, /**< No description avaliable */
    L0Cache_State_IM, /**< No description avaliable */
    L0Cache_State_SM, /**< No description avaliable */
    L0Cache_State_NUM
};

// Code to convert from a string to the enumeration
L0Cache_State string_to_L0Cache_State(const std::string& str);

// Code to convert state to a string
std::string L0Cache_State_to_string(const L0Cache_State& obj);

// Code to increment an enumeration type
L0Cache_State &operator++(L0Cache_State &e);

// Code to convert the current state to an access permission
AccessPermission L0Cache_State_to_permission(const L0Cache_State& obj);

std::ostream& operator<<(std::ostream& out, const L0Cache_State& obj);

#endif // __L0Cache_State_HH__
