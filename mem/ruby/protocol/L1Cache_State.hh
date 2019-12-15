/** \file L1Cache_State.hh
 *
 * Auto generated C++ code started by /home/zhouzhiyong/gem5/src/mem/slicc/symbols/Type.py:458
 */

#ifndef __L1Cache_State_HH__
#define __L1Cache_State_HH__

#include <iostream>
#include <string>

#include "mem/ruby/protocol/AccessPermission.hh"

// Class definition
/** \enum L1Cache_State
 *  \brief Cache states
 */
enum L1Cache_State {
    L1Cache_State_FIRST,
    L1Cache_State_I = L1Cache_State_FIRST, /**< a L1 cache entry Idle */
    L1Cache_State_S, /**< a L1 cache entry Shared */
    L1Cache_State_SS, /**< a L1 cache entry Shared */
    L1Cache_State_E, /**< a L1 cache entry Exclusive */
    L1Cache_State_EE, /**< a L1 cache entry Exclusive */
    L1Cache_State_M, /**< a L1 cache entry Modified */
    L1Cache_State_MM, /**< a L1 cache entry Modified */
    L1Cache_State_IS, /**< L1 idle, issued GETS, have not seen response yet */
    L1Cache_State_IM, /**< L1 idle, issued GETX, have not seen response yet */
    L1Cache_State_SM, /**< L1 idle, issued GETX, have not seen response yet */
    L1Cache_State_IS_I, /**< L1 idle, issued GETS, saw Inv before data because directory doesn't block on GETS hit */
    L1Cache_State_M_I, /**< L1 replacing, waiting for ACK */
    L1Cache_State_SINK_WB_ACK, /**< This is to sink WB_Acks from L2 */
    L1Cache_State_S_IL0, /**< No description avaliable */
    L1Cache_State_E_IL0, /**< No description avaliable */
    L1Cache_State_M_IL0, /**< No description avaliable */
    L1Cache_State_MM_IL0, /**< No description avaliable */
    L1Cache_State_SM_IL0, /**< No description avaliable */
    L1Cache_State_NUM
};

// Code to convert from a string to the enumeration
L1Cache_State string_to_L1Cache_State(const std::string& str);

// Code to convert state to a string
std::string L1Cache_State_to_string(const L1Cache_State& obj);

// Code to increment an enumeration type
L1Cache_State &operator++(L1Cache_State &e);

// Code to convert the current state to an access permission
AccessPermission L1Cache_State_to_permission(const L1Cache_State& obj);

std::ostream& operator<<(std::ostream& out, const L1Cache_State& obj);

#endif // __L1Cache_State_HH__
