// Copyright (c) 2019 Daniel Krawisz
// Distributed under the Open BSV software license, see the accompanying file LICENSE.

#ifndef ABSTRACTIONS_CRYPTO_HASH_SHA256
#define ABSTRACTIONS_CRYPTO_HASH_SHA256

#include <data/crypto/sha256.hpp>
#include <abstractions/abstractions.hpp>

namespace abstractions {
    
    namespace sha256 {
        using digest = data::sha256::digest;
        
        inline digest hash(const bytes& b) {
            return data::sha256::hash(b);
        }
        
        template <N n>
        inline digest hash(const std::array<byte, n>& b) {
            return data::sha256::hash<n>(b);
        }
        
        inline digest double_hash(const bytes& b);
        
        template <N n>
        inline digest double_hash(const std::array<byte, n>& b);
    }

}

#endif

