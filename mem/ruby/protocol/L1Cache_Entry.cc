/** \file L1Cache_Entry.cc
 *
 * Auto generated C++ code started by /home/zhouzhiyong/gem5/src/mem/slicc/symbols/Type.py:412
 */

#include <iostream>
#include <memory>

#include "mem/ruby/protocol/L1Cache_Entry.hh"
#include "mem/ruby/system/RubySystem.hh"

using namespace std;
/** \brief Print the state of this object */
void
L1Cache_Entry::print(ostream& out) const
{
    out << "[L1Cache_Entry: ";
    out << "CacheState = " << m_CacheState << " ";
    out << "DataBlk = " << m_DataBlk << " ";
    out << "Dirty = " << m_Dirty << " ";
    out << "]";
}
