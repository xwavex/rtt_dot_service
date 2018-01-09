/******************************************************************************
*                           OROCOS dot service                                *
*                                                                             *
*                         (C) 2011 Steven Bellens                             *
*                     steven.bellens@mech.kuleuven.be                         *
*                    Department of Mechanical Engineering,                    *
*                   Katholieke Universiteit Leuven, Belgium.                  *
*                                                                             *
*       You may redistribute this software and/or modify it under either the  *
*       terms of the GNU Lesser General Public License version 2.1 (LGPLv2.1  *
*       <http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html>) or (at your *
*       discretion) of the Modified BSD License:                              *
*       Redistribution and use in source and binary forms, with or without    *
*       modification, are permitted provided that the following conditions    *
*       are met:                                                              *
*       1. Redistributions of source code must retain the above copyright     *
*       notice, this list of conditions and the following disclaimer.         *
*       2. Redistributions in binary form must reproduce the above copyright  *
*       notice, this list of conditions and the following disclaimer in the   *
*       documentation and/or other materials provided with the distribution.  *
*       3. The name of the author may not be used to endorse or promote       *
*       products derived from this software without specific prior written    *
*       permission.                                                           *
*       THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  *
*       IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED        *
*       WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE    *
*       ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,*
*       INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES    *
*       (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS       *
*       OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) *
*       HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,   *
*       STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING *
*       IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE    *
*       POSSIBILITY OF SUCH DAMAGE.                                           *
*                                                                             *
*******************************************************************************/
/* @Description:
 * @brief OROCOS dot service
 * @Author: Steven Bellens
 */
#ifndef DOT_SERVICE_HPP
#define DOT_SERVICE_HPP

#include <rtt/plugin/ServicePlugin.hpp>
#include <rtt/base/ExecutableInterface.hpp>
#include <rtt/RTT.hpp>

using namespace RTT;

class Dot : public RTT::Service, public RTT::base::ExecutableInterface {
  public:
    // Constructor
    Dot(TaskContext* owner);
    std::string getOwnerName();

    /** \brief Generate DOT file for the current deployment configuration
     *
     *  The method iterates over all peer components and generates and writes out a DOT file giving an overview of the current deployment configuration. The file currently displays all peer components, colored according to their taskstate, all component ports, names and connections to other components.
     */
    bool execute();
    bool executeMinimal();

    /// @name Properties
    //@{
    /// Name of the DOT file to write the deployment configuration to
    std::string m_dot_file;
    /// Name of the DOT file to write the deployment configuration to
    std::string m_dot_file_minimal;
    /// Additional arguments to pass to the component drawings
    std::string m_comp_args;
    /// Additional arguments to pass to the connection drawings
    std::string m_conn_args;
    /// Additional arguments to pass to the channel drawings
    std::string m_chan_args;
    //@}
  private:
    std::stringstream m_dot;
    std::string mpeer;
    std::string quote(std::string const& name);
    void scanService(std::string path, Service::shared_ptr sv);
    void scanServiceMinimal(std::string path, Service::shared_ptr sv);
};
#endif
