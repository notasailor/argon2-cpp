// Copyright (c) 2019, Zpalmtree
//
// Please see the included LICENSE file for more information.

#pragma once

#include <cstdint>

#include <string>

#include <vector>

class Blake2b
{
    public:
        Blake2b();

        void Init(
            const std::vector<uint8_t> key = {},
            const uint8_t outputHashLength = 64);

        void Update(const std::vector<uint8_t> &data);
        void Update(const uint8_t *data, size_t len);

        std::vector<uint8_t> Finalize();

        static std::vector<uint8_t> Hash(const std::vector<uint8_t> &message);
        static std::vector<uint8_t> Hash(const std::string &message);

    private:
        void compress(const bool finalChunk);

        /* Working hash */
        std::vector<uint64_t> m_hash;

        /* Chunk of data to process */
        std::vector<uint64_t> m_chunk;

        /* Bytes we've processed so far */
        size_t m_bytesCompressed = 0;

        /* Size of chunk to process */
        size_t m_chunkSize = 0;

        /* Length of output hash in bytes */
        uint8_t m_outputHashLength = 64;
};
