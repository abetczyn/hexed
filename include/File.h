#pragma once
#include <Windows.h>
class File
{
    public:
        File();
		~File();
        
        bool Open(const char* path);
        void Close();
        long long GetSize() const;
        void Seek(long long position);
        void Read(unsigned char byte);
        void Read(void *buffer, unsigned int nBytes);
		void Write(unsigned char byte);
        bool IsOpen() const;
		bool IsReadOnly() const;
		const char* GetFullPath() const;
		const char* GetFileName() const;

    private:
        char* m_filename;
		char* m_fullPath;
        LARGE_INTEGER m_filesize;
        void* m_handle;
		bool m_readOnly;
};

inline long long File::GetSize() const
{
    return m_filesize.QuadPart;
}

inline bool File::IsReadOnly() const
{
	return m_readOnly;
}

inline const char* File::GetFullPath() const
{
	return m_fullPath;
}

inline const char* File::GetFileName() const
{
	return m_filename;
}
