/** \file Directory_Entry.hh
 *
 *
 * Auto generated C++ code started by /home/zhouzhiyong/gem5/src/mem/slicc/symbols/Type.py:205
 */

#ifndef __Directory_Entry_HH__
#define __Directory_Entry_HH__

#include <iostream>

#include "mem/ruby/slicc_interface/RubySlicc_Util.hh"

#include "mem/ruby/protocol/Directory_State.hh"
#include "mem/ruby/protocol/MachineID.hh"
#include "mem/ruby/protocol/AbstractCacheEntry.hh"
class Directory_Entry :  public AbstractCacheEntry
{
  public:
    Directory_Entry
()
		{
        m_DirectoryState = Directory_State_I; // default value of Directory_State
        // m_Owner has no default
    }
    Directory_Entry(const Directory_Entry&other)
        : AbstractCacheEntry(other)
    {
        m_DirectoryState = other.m_DirectoryState;
        m_Owner = other.m_Owner;
    }
    Directory_Entry(const Directory_State& local_DirectoryState, const MachineID& local_Owner)
        : AbstractCacheEntry()
    {
        m_DirectoryState = local_DirectoryState;
        m_Owner = local_Owner;
    }
    Directory_Entry*
    clone() const
    {
         return new Directory_Entry(*this);
    }
    // Const accessors methods for each field
    /** \brief Const accessor method for DirectoryState field.
     *  \return DirectoryState field
     */
    const Directory_State&
    getDirectoryState() const
    {
        return m_DirectoryState;
    }
    /** \brief Const accessor method for Owner field.
     *  \return Owner field
     */
    const MachineID&
    getOwner() const
    {
        return m_Owner;
    }
    // Non const Accessors methods for each field
    /** \brief Non-const accessor method for DirectoryState field.
     *  \return DirectoryState field
     */
    Directory_State&
    getDirectoryState()
    {
        return m_DirectoryState;
    }
    /** \brief Non-const accessor method for Owner field.
     *  \return Owner field
     */
    MachineID&
    getOwner()
    {
        return m_Owner;
    }
    // Mutator methods for each field
    /** \brief Mutator method for DirectoryState field */
    void
    setDirectoryState(const Directory_State& local_DirectoryState)
    {
        m_DirectoryState = local_DirectoryState;
    }
    /** \brief Mutator method for Owner field */
    void
    setOwner(const MachineID& local_Owner)
    {
        m_Owner = local_Owner;
    }
    void print(std::ostream& out) const;
  //private:
    /** Directory state */
    Directory_State m_DirectoryState;
    MachineID m_Owner;
};
inline std::ostream&
operator<<(std::ostream& out, const Directory_Entry& obj)
{
    obj.print(out);
    out << std::flush;
    return out;
}

#endif // __Directory_Entry_HH__
