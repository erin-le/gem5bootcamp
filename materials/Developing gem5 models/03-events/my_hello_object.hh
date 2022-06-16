/*
 * Copyright (c) 2017 Jason Lowe-Power
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met: redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer;
 * redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution;
 * neither the name of the copyright holders nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef __TUTORIAL_MY_HELLO_OBJECT_HH__
#define __TUTORIAL_MY_HELLO_OBJECT_HH__

#include <string>

#include "tutorial/my_goodbye_object.hh"
#include "params/MyHelloObject.hh"
#include "sim/sim_object.hh"

namespace gem5
{

class MyHelloObject : public SimObject
{
  private:
    /**
     * Example function to execute on an event trigger
     */
    void processEvent();

    /// An event that wraps the above function

    /// Pointer to the corresponding GoodbyeObject. Set via Python
    MyGoodbyeObject* goodbye = nullptr;

    /// The name of this object in the Python config file
    const std::string myName;

    /// Latency between calling the event (in ticks)
    const Tick latency = 1000;

    /// Number of times left to fire the event before goodbye
    int timesLeft = 10;

  public:
    PARAMS(MyHelloObject);
    MyHelloObject(const Params &p);

    /**
     * Part of a SimObject's initialization. Startup is called after all
     * SimObjects have been constructed. It is called after the user calls
     * simulate() for the first time.
     */
    void startup();
};

} // namespace gem5

#endif // __TUTORIAL_MY_HELLO_OBJECT_HH__
