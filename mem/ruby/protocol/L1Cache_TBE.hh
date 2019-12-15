/** \file L1Cache_TBE.hh
 *
 *
 * Auto generated C++ code started by /home/zhouzhiyong/gem5/src/mem/slicc/symbols/Type.py:205
 */

#ifndef __L1Cache_TBE_HH__
#define __L1Cache_TBE_HH__

#include <iostream>

#include "mem/ruby/slicc_interface/RubySlicc_Util.hh"

#include "mem/ruby/protocol/L1Cache_State.hh"
#include "mem/ruby/protocol/DataBlock.hh"
class L1Cache_TBE
{
  public:
    L1Cache_TBE
()
		{
        // m_addr has no default
        m_TBEState = L1Cache_State_I; // default value of L1Cache_State
        // m_DataBlk has no default
        m_Dirty = false; // default for this field
        m_pendingAcks = 0; // default for this field
    }
    L1Cache_TBE(const L1Cache_TBE&other)
    {
        m_addr = other.m_addr;
        m_TBEState = other.m_TBEState;
        m_DataBlk = other.m_DataBlk;
        m_Dirty = other.m_Dirty;
        m_pendingAcks = other.m_pendingAcks;
    }
    L1Cache_TBE(const Addr& local_addr, const L1Cache_State& local_TBEState, const DataBlock& local_DataBlk, const bool& local_Dirty, const int& local_pendingAcks)
    {
        m_addr = local_addr;
        m_TBEState = local_TBEState;
        m_DataBlk = local_DataBlk;
        m_Dirty = local_Dirty;
        m_pendingAcks = local_pendingAcks;
    }
    L1Cache_TBE*
    clone() const
    {
         return new L1Cache_TBE(*this);
    }
    // Const accessors methods for each field
    /** \brief Const accessor method for addr field.
     *  \return addr field
     */
    const Addr&
    getaddr() const
    {
        return m_addr;
    }
    /** \brief Const accessor method for TBEState field.
     *  \return TBEState field
     */
    const L1Cache_State&
    getTBEState() const
    {
        return m_TBEState;
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
    /** \brief Const accessor method for pendingAcks field.
     *  \return pendingAcks field
     */
    const int&
    getpendingAcks() const
    {
        return m_pendingAcks;
    }
    // Non const Accessors methods for each field
    /** \brief Non-const accessor method for addr field.
     *  \return addr field
     */
    Addr&
    getaddr()
    {
        return m_addr;
    }
    /** \brief Non-const accessor method for TBEState field.
     *  \return TBEState field
     */
    L1Cache_State&
    getTBEState()
    {
        return m_TBEState;
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
    /** \brief Non-const accessor method for pendingAcks field.
     *  \return pendingAcks field
     */
    int&
    getpendingAcks()
    {
        return m_pendingAcks;
    }
    // Mutator methods for each field
    /** \brief Mutator method for addr field */
    void
    setaddr(const Addr& local_addr)
    {
        m_addr = local_addr;
    }
    /** \brief Mutator method for TBEState field */
    void
    setTBEState(const L1Cache_State& local_TBEState)
    {
        m_TBEState = local_TBEState;
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
    /** \brief Mutator method for pendingAcks field */
    void
    setpendingAcks(const int& local_pendingAcks)
    {
        m_pendingAcks = local_pendingAcks;
    }
    void print(std::ostream& out) const;
  //private:
    /** Physical address for this TBE */
    Addr m_addr;
    /** Transient state */
    L1Cache_State m_TBEState;
    /** Buffer for the data block */
    DataBlock m_DataBlk;
    /** data is dirty */
    bool m_Dirty;
    /** number of pending acks */
    int m_pendingAcks;
};
inline std::ostream&
operator<<(std::ostream& out, const L1Cache_TBE& obj)
{
    obj.print(out);
    out << std::flush;
    return out;
}

#endif // __L1Cache_TBE_HH__
