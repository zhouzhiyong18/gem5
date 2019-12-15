/** \file Directory_State.hh
 *
 * Auto generated C++ code started by /home/zhouzhiyong/gem5/src/mem/slicc/symbols/Type.py:458
 */

#ifndef __Directory_State_HH__
#define __Directory_State_HH__

#include <iostream>
#include <string>

#include "mem/ruby/protocol/AccessPermission.hh"

// Class definition
/** \enum Directory_State
 *  \brief Directory states
 */
enum Directory_State {
    Directory_State_FIRST,
    Directory_State_I = Directory_State_FIRST, /**< dir is the owner and memory is up-to-date, all other copies are Invalid */
    Directory_State_ID, /**< Intermediate state for DMA_READ when in I */
    Directory_State_ID_W, /**< Intermediate state for DMA_WRITE when in I */
    Directory_State_M, /**< memory copy may be stale, i.e. other modified copies may exist */
    Directory_State_IM, /**< Intermediate State I>M */
    Directory_State_MI, /**< Intermediate State M>I */
    Directory_State_M_DRD, /**< Intermediate State when there is a dma read */
    Directory_State_M_DRDI, /**< Intermediate State when there is a dma read */
    Directory_State_M_DWR, /**< Intermediate State when there is a dma write */
    Directory_State_M_DWRI, /**< Intermediate State when there is a dma write */
    Directory_State_NUM
};

// Code to convert from a string to the enumeration
Directory_State string_to_Directory_State(const std::string& str);

// Code to convert state to a string
std::string Directory_State_to_string(const Directory_State& obj);

// Code to increment an enumeration type
Directory_State &operator++(Directory_State &e);

// Code to convert the current state to an access permission
AccessPermission Directory_State_to_permission(const Directory_State& obj);

std::ostream& operator<<(std::ostream& out, const Directory_State& obj);

#endif // __Directory_State_HH__
