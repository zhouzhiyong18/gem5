/** \file L2Cache_Entry.cc
 *
 * Auto generated C++ code started by /home/zhouzhiyong/gem5/src/mem/slicc/symbols/Type.py:412
 */

#include <iostream>
#include <memory>

#include "mem/ruby/protocol/L2Cache_Entry.hh"
#include "mem/ruby/system/RubySystem.hh"

using namespace std;
/** \brief Print the state of this object */
void
L2Cache_Entry::print(ostream& out) const
{
    out << "[L2Cache_Entry: ";
    out << "CacheState = " << m_CacheState << " ";
    out << "Sharers = " << m_Sharers << " ";
    out << "Exclusive = " << m_Exclusive << " ";
    out << "DataBlk = " << m_DataBlk << " ";
    out << "Dirty = " << m_Dirty << " ";
    out << "]";
}
