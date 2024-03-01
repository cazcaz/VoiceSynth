#ifndef LITTLE_ENDIAN_H
#define LITTLE_ENDIAN_H

#include <fstream>

class LittleEndian {
    public:
        LittleEndian() = default;
        ~LittleEndian() = default;
        template <typename Word>
            static std::ostream& write_word(std::ostream& outs, Word value, unsigned size = sizeof( Word ) )
            {
                for (; size; --size, value >>= 8)
                outs.put( static_cast <char> (value & 0xFF) );
                return outs;
            };
};

#endif