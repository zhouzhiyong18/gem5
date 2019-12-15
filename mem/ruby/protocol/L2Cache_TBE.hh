/** \file L2Cache_TBE.hh
 *
 *
 * Auto generated C++ code started by /home/zhouzhiyong/gem5/src/mem/slicc/symbols/Type.py:205
 */

#ifndef __L2Cache_TBE_HH__
#define __L2Cache_TBE_HH__

#include <iostream>

#include "mem/ruby/slicc_interface/RubySlicc_Util.hh"

#include "mem/ruby/protocol/L2Cache_State.hh"
#include "mem/ruby/protocol/DataBlock.hh"
#include "mem/ruby/protocol/NetDest.hh"
#include "mem/ruby/protocol/MachineID.hh"
class L2Cache_TBE
{
  public:
    L2Cache_TBE
()
		{
        // m_addr has no default
        m_TBEState = L2Cache_State_NP; // default value of L2Cache_State
        // m_DataBlk has no default
        m_Dirty = false; // default for this field
        // m_L1_GetS_IDs has no default
        // m_L1_GetX_ID has no default
        m_pendingAcks = 0; // default value of int
    }
    L2Cache_TBE(const L2Cache_TBE&other)
    {
        m_addr = other.m_addr;
        m_TBEState = other.m_TBEState;
        m_DataBlk = other.m_DataBlk;
        m_Dirty = other.m_Dirty;
        m_L1_GetS_IDs = other.m_L1_GetS_IDs;
        m_L1_GetX_ID = other.m_L1_GetX_ID;
        m_pendingAcks = other.m_pendingAcks;
    }
    L2Cache_TBE(const Addr& local_addr, const L2Cache_State& local_TBEState, const DataBlock& local_DataBlk, const bool& local_Dirty, const NetDest& local_L1_GetS_IDs, const MachineID& local_L1_GetX_ID, const int& local_pendingAcks)
    {
        m_addr = local_addr;
        m_TBEState = local_TBEState;
        m_DataBlk = local_DataBlk;
        m_Dirty = local_Dirty;
        m_L1_GetS_IDs = local_L1_GetS_IDs;
        m_L1_GetX_ID = local_L1_GetX_ID;
        m_pendingAcks = local_pendingAcks;
    }
    L2Cache_TBE*
    clone() const
    {
         return new L2Cache_TBE(*this);
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
    const L2Cache_State&
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
    /** \brief Const accessor method for L1_GetS_IDs field.
     *  \return L1_GetS_IDs field
     */
    const NetDest&
    getL1_GetS_IDs() const
    {
        return m_L1_GetS_IDs;
    }
    /** \brief Const accessor method for L1_GetX_ID field.
     *  \return L1_GetX_ID field
     */
    const MachineID&
    getL1_GetX_ID() const
    {
        return m_L1_GetX_ID;
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
    L2Cache_State&
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
    /** \brief Non-const accessor method for L1_GetS_IDs field.
     *  \return L1_GetS_IDs field
     */
    NetDest&
    getL1_GetS_IDs()
    {
        return m_L1_GetS_IDs;
    }
    /** \brief Non-const accessor method for L1_GetX_ID field.
     *  \return L1_GetX_ID field
     */
    MachineID&
    getL1_GetX_ID()
    {
        return m_L1_GetX_ID;
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
    setTBEState(const L2Cache_State& local_TBEState)
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
    /** \brief Mutator method for L1_GetS_IDs field */
    void
    setL1_GetS_IDs(const NetDest& local_L1_GetS_IDs)
    {
        m_L1_GetS_IDs = local_L1_GetS_IDs;
    }
    /** \brief Mutator method for L1_GetX_ID field */
    void
    setL1_GetX_ID(const MachineID& local_L1_GetX_ID)
    {
        m_L1_GetX_ID = local_L1_GetX_ID;
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
    L2Cache_State m_TBEState;
    /** Buffer for the data block */
    DataBlock m_DataBlk;
    /** Data is Dirty */
    bool m_Dirty;
    /** Set of the internal processors that want the block in shared state */
    NetDest m_L1_GetS_IDs;
    /** ID of the L1 cache to forward the block to once we get a response */
    MachineID m_L1_GetX_ID;
    /** number of pending acks for invalidates during writeback */
    int m_pendingAcks;
};
inline std::ostream&
operator<<(std::ostream& out, const L2Cache_TBE& obj)
{
    obj.print(out);
    out << std::flush;
    return out;
}

#endif // __L2Cache_TBE_HH__
