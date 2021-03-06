// Copyright (c) 2018-2019 Katrina Swales
// Distributed under the Open BSV software license, see the accompanying file LICENSE.

#include <abstractions/timechain/output.hpp>

namespace abstractions::timechain::output {

    const bytes_view serialized::script() const {
        return Data.substr(4);
    }

    satoshi_little serialized::value() const {
        return satoshi_little::as(*(uint32*)(Data.substr(0, 4).data()));
    }

}
