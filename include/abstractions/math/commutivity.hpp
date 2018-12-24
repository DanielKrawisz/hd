#ifndef ABSTRACTIONS_MATH_COMMUTIVITY_HPP
#define ABSTRACTIONS_MATH_COMMUTIVITY_HPP

#include <abstractions/math/contradiction.hpp>

namespace abstractions {
    
    namespace math {
        
        namespace commutative {
    
            template <typename X>
            struct times {
                void commutivity(X a, X b) const {
                    equal<X>{a * b, b * a};
                }
            };
    
            template <typename X>
            struct plus {
                void commutivity(X a, X b) const {
                    equal<X>{a + b, b + a};
                }
            };
            
        }
    
    }
    
}

#endif
