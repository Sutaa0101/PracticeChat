#pragma once

namespace tcpframework {

	//��M�o�b�t�@�T�C�Y
	const size_t RECVSIZE = 65536;
	//Soket��Receive�Ŏ󂯎��o�C�g�z��
	class ByteArray {

		const size_t m_size;
		char* m_bytes;

	public:

		ByteArray(char const*const byte, size_t size) :m_size(size) {
			m_bytes = new char[size];
			for (size_t i = 0; i < size; i++) {
				m_bytes[i] = byte[i];
			}
		}

		ByteArray() :m_size(-1), m_bytes(nullptr) {}

		ByteArray(const ByteArray&) = delete;

		ByteArray(ByteArray&& move) :m_size(move.m_size) {
			m_bytes = move.m_bytes;
			move.m_bytes = nullptr;
		}

		~ByteArray() {
			if (m_bytes != nullptr)
				delete[] m_bytes;
		}

		size_t Size()const noexcept { return m_size; }

		char const * const GetBytes()const noexcept { return m_bytes; }
	};

}