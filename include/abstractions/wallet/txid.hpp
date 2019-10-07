// Copyright (c) 2018-2019 Daniel Krawisz
// Distributed under the Open BSV software license, see the accompanying file LICENSE.

#ifndef ABSTRACTIONS_WALLET_TXID
#define ABSTRACTIONS_WALLET_TXID

#include <data/crypto/sha256.hpp>
#include <abstractions/abstractions.hpp>

namespace abstractions {
    
    namespace bitcoin {
        
        struct txid : public data::sha256::digest {
            using parent = data::sha256::digest;
            using parent::digest;
            
            bool operator==(const txid& a) const;
            bool operator!=(const txid& a) const;
            
            txid& operator=(const txid& a);
            
            explicit txid(hex s);
            explicit txid(string hex_string);
            
            explicit operator timechain::digest() const;
            explicit operator bytes() const;
            
            txid(bytes&);
            txid(parent p);
        };
        
        inline txid::txid(parent p) : parent{p} {}
        
        inline txid::txid(hex s) : txid{} {
            if (s.valid()) *this = data::sha256::digest{(bytes)(s)}; 
        }
        
        inline txid::txid(string hex_string) : txid{hex{hex_string}} {}
        
        inline bool txid::operator==(const txid& a) const {
            return data::sha256::digest::operator==(static_cast<const data::sha256::digest&>(a));
        }
        
        inline bool txid::operator!=(const txid& a) const {
            return data::sha256::digest::operator!=(static_cast<const data::sha256::digest&>(a));
        }
        
        inline txid& txid::operator=(const txid& a) {
            data::sha256::digest::operator=(static_cast<const data::sha256::digest&>(a));
            return *this;
        }
        
    }
    
} 

#endif
