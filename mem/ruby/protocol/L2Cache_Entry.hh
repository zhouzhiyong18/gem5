/** \file L2Cache_Entry.hh
 *
 *
 * Auto generated C++ code started by /home/zhouzhiyong/gem5/src/mem/slicc/symbols/Type.py:205
 */

#ifndef __L2Cache_Entry_HH__
#define __L2Cache_Entry_HH__

#include <iostream>

#include "mem/ruby/slicc_interface/RubySlicc_Util.hh"

#include "mem/ruby/protocol/L2Cache_State.hh"
#include "mem/ruby/protocol/NetDest.hh"
#include "mem/ruby/protocol/MachineID.hh"
#include "mem/ruby/protocol/DataBlock.hh"
#include "mem/ruby/protocol/AbstractCacheEntry.hh"
class L2Cache_Entry :  public AbstractCacheEntry
{
  public:
    L2Cache_Entry
()
		{
        m_CacheState = L2Cache_State_NP; // default value of L2Cache_State
        // m_Sharers has no default
        // m_Exclusive has no default
        // m_DataBlk has no default
        m_Dirty = false; // default for this field
    }
    L2Cache_Entry(const L2Cache_Entry&other)
        : AbstractCacheEntry(other)
    {
        m_CacheState = other.m_CacheState;
        m_Sharers = other.m_Sharers;
        m_Exclusive = other.m_Exclusive;
        m_DataBlk = other.m_DataBlk;
        m_Dirty = other.m_Dirty;
    }
    L2Cache_Entry(const L2Cache_State& local_CacheState, const NetDest& local_Sharers, const MachineID& local_Exclusive, const DataBlock& local_DataBlk, const bool& local_Dirty)
        : AbstractCacheEntry()
    {
        m_CacheState = local_CacheState;
        m_Sharers = local_Sharers;
        m_Exclusive = local_Exclusive;
        m_DataBlk = local_DataBlk;
        m_Dirty = local_Dirty;
    }
    L2Cache_Entry*
    clone() const
    {
         return new L2Cache_Entry(*this);
    }
    // Const accessors methods for each field
    /** \brief Const accessor method for CacheState field.
     *  \return CacheState field
     */
    const L2Cache_State&
    getCacheState() const
    {
        return m_CacheState;
    }
    /** \brief Const accessor method for Sharers field.
     *  \return Sharers field
     */
    const NetDest&
    getSharers() const
    {
        return m_Sharers;
    }
    /** \brief Const accessor method for Exclusive field.
     *  \return Exclusive field
     */
    const MachineID&
    getExclusive() const
    {
        return m_Exclusive;
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
    L2Cache_State&
    getCacheState()
    {
        return m_CacheState;
    }
    /** \brief Non-const accessor method for Sharers field.
     *  \return Sharers field
     */
    NetDest&
    getSharers()
    {
        return m_Sharers;
    }
    /** \brief Non-const accessor method for Exclusive field.
     *  \return Exclusive field
     */
    MachineID&
    getExclusive()
    {
        return m_Exclusive;
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
    setCacheState(const L2Cache_State& local_CacheState)
    {
        m_CacheState = local_CacheState;
    }
    /** \brief Mutator method for Sharers field */
    void
    setSharers(const NetDest& local_Sharers)
    {
        m_Sharers = local_Sharers;
    }
    /** \brief Mutator method for Exclusive field */
    void
    setExclusive(const MachineID& local_Exclusive)
    {
        m_Exclusive = local_Exclusive;
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
    L2Cache_State m_CacheState;
    /** tracks the L1 shares on-chip */
    NetDest m_Sharers;
    /** Exclusive holder of block */
    MachineID m_Exclusive;
    /** data for the block */
    DataBlock m_DataBlk;
    /** data is dirty */
    bool m_Dirty;
};
inline std::ostream&
operator<<(std::ostream& out, const L2Cache_Entry& obj)
{
    obj.print(out);
    out << std::flush;
    return out;
}

#endif // __L2Cache_Entry_HH__
