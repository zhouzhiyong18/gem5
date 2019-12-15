/** \file L2Cache_State.hh
 *
 * Auto generated C++ code started by /home/zhouzhiyong/gem5/src/mem/slicc/symbols/Type.py:458
 */

#ifndef __L2Cache_State_HH__
#define __L2Cache_State_HH__

#include <iostream>
#include <string>

#include "mem/ruby/protocol/AccessPermission.hh"

// Class definition
/** \enum L2Cache_State
 *  \brief L2 Cache states
 */
enum L2Cache_State {
    L2Cache_State_FIRST,
    L2Cache_State_NP = L2Cache_State_FIRST, /**< Not present in either cache */
    L2Cache_State_SS, /**< L2 cache entry Shared, also present in one or more L1s */
    L2Cache_State_M, /**< L2 cache entry Modified, not present in any L1s */
    L2Cache_State_MT, /**< L2 cache entry Modified in a local L1, assume L2 copy stale */
    L2Cache_State_M_I, /**< L2 cache replacing, have all acks, sent dirty data to memory, waiting for ACK from memory */
    L2Cache_State_MT_I, /**< L2 cache replacing, getting data from exclusive */
    L2Cache_State_MCT_I, /**< L2 cache replacing, clean in L2, getting data or ack from exclusive */
    L2Cache_State_I_I, /**< L2 replacing clean data, need to inv sharers and then drop data */
    L2Cache_State_S_I, /**< L2 replacing dirty data, collecting acks from L1s */
    L2Cache_State_ISS, /**< L2 idle, got single L1_GETS, issued memory fetch, have not seen response yet */
    L2Cache_State_IS, /**< L2 idle, got L1_GET_INSTR or multiple L1_GETS, issued memory fetch, have not seen response yet */
    L2Cache_State_IM, /**< L2 idle, got L1_GETX, issued memory fetch, have not seen response(s) yet */
    L2Cache_State_SS_MB, /**< Blocked for L1_GETX from SS */
    L2Cache_State_MT_MB, /**< Blocked for L1_GETX from MT */
    L2Cache_State_MT_IIB, /**< Blocked for L1_GETS from MT, waiting for unblock and data */
    L2Cache_State_MT_IB, /**< Blocked for L1_GETS from MT, got unblock, waiting for data */
    L2Cache_State_MT_SB, /**< Blocked for L1_GETS from MT, got data,  waiting for unblock */
    L2Cache_State_NUM
};

// Code to convert from a string to the enumeration
L2Cache_State string_to_L2Cache_State(const std::string& str);

// Code to convert state to a string
std::string L2Cache_State_to_string(const L2Cache_State& obj);

// Code to increment an enumeration type
L2Cache_State &operator++(L2Cache_State &e);

// Code to convert the current state to an access permission
AccessPermission L2Cache_State_to_permission(const L2Cache_State& obj);

std::ostream& operator<<(std::ostream& out, const L2Cache_State& obj);

#endif // __L2Cache_State_HH__
