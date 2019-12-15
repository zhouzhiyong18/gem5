/** \file ResponseMsg.cc
 *
 * Auto generated C++ code started by /home/zhouzhiyong/gem5/src/mem/slicc/symbols/Type.py:412
 */

#include <iostream>
#include <memory>

#include "mem/ruby/protocol/ResponseMsg.hh"
#include "mem/ruby/system/RubySystem.hh"

using namespace std;
/** \brief Print the state of this object */
void
ResponseMsg::print(ostream& out) const
{
    out << "[ResponseMsg: ";
    out << "addr = " << printAddress(m_addr) << " ";
    out << "Type = " << m_Type << " ";
    out << "Sender = " << m_Sender << " ";
    out << "Destination = " << m_Destination << " ";
    out << "DataBlk = " << m_DataBlk << " ";
    out << "Dirty = " << m_Dirty << " ";
    out << "AckCount = " << m_AckCount << " ";
    out << "MessageSize = " << m_MessageSize << " ";
    out << "]";
}
bool
ResponseMsg::functionalWrite(Packet* param_pkt)
{
return (testAndWrite(m_addr, m_DataBlk, param_pkt));

}
bool
ResponseMsg::functionalRead(Packet* param_pkt)
{
    if ((((m_Type == CoherenceResponseType_DATA) || (m_Type == CoherenceResponseType_DATA_EXCLUSIVE)) || (m_Type == CoherenceResponseType_MEMORY_DATA))) {
        return (testAndRead(m_addr, m_DataBlk, param_pkt));
    }
    return (false);

}
