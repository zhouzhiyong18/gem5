/** \file CoherenceMsg.hh
 *
 *
 * Auto generated C++ code started by /home/zhouzhiyong/gem5/src/mem/slicc/symbols/Type.py:205
 */

#ifndef __CoherenceMsg_HH__
#define __CoherenceMsg_HH__

#include <iostream>

#include "mem/ruby/slicc_interface/RubySlicc_Util.hh"

#include "mem/ruby/protocol/CoherenceClass.hh"
#include "mem/ruby/protocol/RubyAccessMode.hh"
#include "mem/ruby/protocol/MachineID.hh"
#include "mem/ruby/protocol/MachineID.hh"
#include "mem/ruby/protocol/MessageSizeType.hh"
#include "mem/ruby/protocol/DataBlock.hh"
#include "mem/ruby/protocol/Message.hh"
class CoherenceMsg :  public Message
{
  public:
    CoherenceMsg
(Tick curTime) : Message(curTime) {
        // m_addr has no default
        m_Class = CoherenceClass_NUM; // default value of CoherenceClass
        m_AccessMode = RubyAccessMode_User; // default value of RubyAccessMode
        // m_Sender has no default
        // m_Dest has no default
        m_MessageSize = MessageSizeType_NUM; // default value of MessageSizeType
        // m_DataBlk has no default
        m_Dirty = false; // default for this field
    }
    CoherenceMsg(const CoherenceMsg&other)
        : Message(other)
    {
        m_addr = other.m_addr;
        m_Class = other.m_Class;
        m_AccessMode = other.m_AccessMode;
        m_Sender = other.m_Sender;
        m_Dest = other.m_Dest;
        m_MessageSize = other.m_MessageSize;
        m_DataBlk = other.m_DataBlk;
        m_Dirty = other.m_Dirty;
    }
    CoherenceMsg(const Tick curTime, const Addr& local_addr, const CoherenceClass& local_Class, const RubyAccessMode& local_AccessMode, const MachineID& local_Sender, const MachineID& local_Dest, const MessageSizeType& local_MessageSize, const DataBlock& local_DataBlk, const bool& local_Dirty)
        : Message(curTime)
    {
        m_addr = local_addr;
        m_Class = local_Class;
        m_AccessMode = local_AccessMode;
        m_Sender = local_Sender;
        m_Dest = local_Dest;
        m_MessageSize = local_MessageSize;
        m_DataBlk = local_DataBlk;
        m_Dirty = local_Dirty;
    }
    MsgPtr
    clone() const
    {
         return std::shared_ptr<Message>(new CoherenceMsg(*this));
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
    /** \brief Const accessor method for Class field.
     *  \return Class field
     */
    const CoherenceClass&
    getClass() const
    {
        return m_Class;
    }
    /** \brief Const accessor method for AccessMode field.
     *  \return AccessMode field
     */
    const RubyAccessMode&
    getAccessMode() const
    {
        return m_AccessMode;
    }
    /** \brief Const accessor method for Sender field.
     *  \return Sender field
     */
    const MachineID&
    getSender() const
    {
        return m_Sender;
    }
    /** \brief Const accessor method for Dest field.
     *  \return Dest field
     */
    const MachineID&
    getDest() const
    {
        return m_Dest;
    }
    /** \brief Const accessor method for MessageSize field.
     *  \return MessageSize field
     */
    const MessageSizeType&
    getMessageSize() const
    {
        return m_MessageSize;
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
    /** \brief Non-const accessor method for addr field.
     *  \return addr field
     */
    Addr&
    getaddr()
    {
        return m_addr;
    }
    /** \brief Non-const accessor method for Class field.
     *  \return Class field
     */
    CoherenceClass&
    getClass()
    {
        return m_Class;
    }
    /** \brief Non-const accessor method for AccessMode field.
     *  \return AccessMode field
     */
    RubyAccessMode&
    getAccessMode()
    {
        return m_AccessMode;
    }
    /** \brief Non-const accessor method for Sender field.
     *  \return Sender field
     */
    MachineID&
    getSender()
    {
        return m_Sender;
    }
    /** \brief Non-const accessor method for Dest field.
     *  \return Dest field
     */
    MachineID&
    getDest()
    {
        return m_Dest;
    }
    /** \brief Non-const accessor method for MessageSize field.
     *  \return MessageSize field
     */
    MessageSizeType&
    getMessageSize()
    {
        return m_MessageSize;
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
    /** \brief Mutator method for addr field */
    void
    setaddr(const Addr& local_addr)
    {
        m_addr = local_addr;
    }
    /** \brief Mutator method for Class field */
    void
    setClass(const CoherenceClass& local_Class)
    {
        m_Class = local_Class;
    }
    /** \brief Mutator method for AccessMode field */
    void
    setAccessMode(const RubyAccessMode& local_AccessMode)
    {
        m_AccessMode = local_AccessMode;
    }
    /** \brief Mutator method for Sender field */
    void
    setSender(const MachineID& local_Sender)
    {
        m_Sender = local_Sender;
    }
    /** \brief Mutator method for Dest field */
    void
    setDest(const MachineID& local_Dest)
    {
        m_Dest = local_Dest;
    }
    /** \brief Mutator method for MessageSize field */
    void
    setMessageSize(const MessageSizeType& local_MessageSize)
    {
        m_MessageSize = local_MessageSize;
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
    /** Physical address of the cache block */
    Addr m_addr;
    /** Type of message (GetS, GetX, PutX, etc) */
    CoherenceClass m_Class;
    /** user/supervisor access type */
    RubyAccessMode m_AccessMode;
    /** What component sent this message */
    MachineID m_Sender;
    /** What machine receives this message */
    MachineID m_Dest;
    /** size category of the message */
    MessageSizeType m_MessageSize;
    /** Data for the cache line (if PUTX) */
    DataBlock m_DataBlk;
    /** Dirty bit */
    bool m_Dirty;
    bool functionalWrite(Packet* param_pkt);
    bool functionalRead(Packet* param_pkt);
};
inline std::ostream&
operator<<(std::ostream& out, const CoherenceMsg& obj)
{
    obj.print(out);
    out << std::flush;
    return out;
}

#endif // __CoherenceMsg_HH__
