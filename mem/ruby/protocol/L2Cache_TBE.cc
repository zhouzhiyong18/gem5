/** \file L2Cache_TBE.cc
 *
 * Auto generated C++ code started by /home/zhouzhiyong/gem5/src/mem/slicc/symbols/Type.py:412
 */

#include <iostream>
#include <memory>

#include "mem/ruby/protocol/L2Cache_TBE.hh"
#include "mem/ruby/system/RubySystem.hh"

using namespace std;
/** \brief Print the state of this object */
void
L2Cache_TBE::print(ostream& out) const
{
    out << "[L2Cache_TBE: ";
    out << "addr = " << printAddress(m_addr) << " ";
    out << "TBEState = " << m_TBEState << " ";
    out << "DataBlk = " << m_DataBlk << " ";
    out << "Dirty = " << m_Dirty << " ";
    out << "L1_GetS_IDs = " << m_L1_GetS_IDs << " ";
    out << "L1_GetX_ID = " << m_L1_GetX_ID << " ";
    out << "pendingAcks = " << m_pendingAcks << " ";
    out << "]";
}
