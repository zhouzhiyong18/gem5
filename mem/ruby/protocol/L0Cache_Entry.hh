/** \file L0Cache_Entry.hh
 *
 *
 * Auto generated C++ code started by /home/zhouzhiyong/gem5/src/mem/slicc/symbols/Type.py:205
 */

#ifndef __L0Cache_Entry_HH__
#define __L0Cache_Entry_HH__

#include <iostream>

#include "mem/ruby/slicc_interface/RubySlicc_Util.hh"

#include "mem/ruby/protocol/L0Cache_State.hh"
#include "mem/ruby/protocol/DataBlock.hh"
#include "mem/ruby/protocol/AbstractCacheEntry.hh"
class L0Cache_Entry :  public AbstractCacheEntry
{
  public:
    L0Cache_Entry
()
		{
        m_CacheState = L0Cache_State_I; // default value of L0Cache_State
        // m_DataBlk has no default
        m_Dirty = false; // default for this field
    }
    L0Cache_Entry(const L0Cache_Entry&other)
        : AbstractCacheEntry(other)
    {
        m_CacheState = other.m_CacheState;
        m_DataBlk = other.m_DataBlk;
        m_Dirty = other.m_Dirty;
    }
    L0Cache_Entry(const L0Cache_State& local_CacheState, const DataBlock& local_DataBlk, const bool& local_Dirty)
        : AbstractCacheEntry()
    {
        m_CacheState = local_CacheState;
        m_DataBlk = local_DataBlk;
        m_Dirty = local_Dirty;
    }
    L0Cache_Entry*
    clone() const
    {
         return new L0Cache_Entry(*this);
    }
    // Const accessors methods for each field
    /** \brief Const accessor method for CacheState field.
     *  \return CacheState field
     */
    const L0Cache_State&
    getCacheState() const
    {
        return m_CacheState;
    }
    /** \brief Const accessor method for DataBlk field.
     *  \return DataBlk field
     */
    const DataBlock&
    getDataBlk() const
    {
        return m_DataBlk;
    }
    /** \brief Const accessor method for Dirty field.
     *  \return Dirty field
     */
    const bool&
    getDirty() const
    {
        return m_Dirty;
    }
    // Non const Accessors methods for each field
    /** \brief Non-const accessor method for CacheState field.
     *  \return CacheState field
     */
    L0Cache_State&
    getCacheState()
    {
        return m_CacheState;
    }
    /** \brief Non-const accessor method for DataBlk field.
     *  \return DataBlk field
     */
    DataBlock&
    getDataBlk()
    {
        return m_DataBlk;
    }
    /** \brief Non-const accessor method for Dirty field.
     *  \return Dirty field
     */
    bool&
    getDirty()
    {
        return m_Dirty;
    }
    // Mutator methods for each field
    /** \brief Mutator method for CacheState field */
    void
    setCacheState(const L0Cache_State& local_CacheState)
    {
        m_CacheState = local_CacheState;
    }
    /** \brief Mutator method for DataBlk field */
    void
    setDataBlk(const DataBlock& local_DataBlk)
    {
        m_DataBlk = local_DataBlk;
    }
    /** \brief Mutator method for Dirty field */
    void
    setDirty(const bool& local_Dirty)
    {
        m_Dirty = local_Dirty;
    }
    void print(std::ostream& out) const;
  //private:
    /** cache state */
    L0Cache_State m_CacheState;
    /** data for the block */
    DataBlock m_DataBlk;
    /** data is dirty */
    bool m_Dirty;
};
inline std::ostream&
operator<<(std::ostream& out, const L0Cache_Entry& obj)
{
    obj.print(out);
    out << std::flush;
    return out;
}

#endif // __L0Cache_Entry_HH__
