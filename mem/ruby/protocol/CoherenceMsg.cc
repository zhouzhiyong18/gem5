/** \file CoherenceMsg.cc
 *
 * Auto generated C++ code started by /home/zhouzhiyong/gem5/src/mem/slicc/symbols/Type.py:412
 */

#include <iostream>
#include <memory>

#include "mem/ruby/protocol/CoherenceMsg.hh"
#include "mem/ruby/system/RubySystem.hh"

using namespace std;
/** \brief Print the state of this object */
void
CoherenceMsg::print(ostream& out) const
{
    out << "[CoherenceMsg: ";
    out << "addr = " << printAddress(m_addr) << " ";
    out << "Class = " << m_Class << " ";
    out << "AccessMode = " << m_AccessMode << " ";
    out << "Sender = " << m_Sender << " ";
    out << "Dest = " << m_Dest << " ";
    out << "MessageSize = " << m_MessageSize << " ";
    out << "DataBlk = " << m_DataBlk << " ";
    out << "Dirty = " << m_Dirty << " ";
    out << "]";
}
bool
CoherenceMsg::functionalWrite(Packet* param_pkt)
{
return (testAndWrite(m_addr, m_DataBlk, param_pkt));

}
bool
CoherenceMsg::functionalRead(Packet* param_pkt)
{
    if ((m_Class == CoherenceClass_PUTX)) {
        return (testAndRead(m_addr, m_DataBlk, param_pkt));
    }
    return (false);

}
