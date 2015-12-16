// This file is part of MLDB. Copyright 2015 Datacratic. All rights reserved.

/* event_loop_impl.cc
   Wolfgang Sourdeau, September 2015
   Copyright (c) 2015 Datacratic.  All rights reserved.
*/

#include "mldb/http/event_loop.h"
#include "event_loop_impl.h"

using namespace std;
using namespace boost;
using namespace Datacratic;


/****************************************************************************/
/* EVENT LOOP IMPL                                                          */
/****************************************************************************/

void
EventLoopImpl::
run()
{
    work_.reset(new asio::io_service::work(ioService_));
    ioService_.run();
}

void
EventLoopImpl::
terminate()
{
    auto clearFn = [&] {
        work_.reset();
    };
    ioService_.post(clearFn);
    ioService_.stop();
    ioService_.reset();
}
