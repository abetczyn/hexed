#pragma once

class File
{
    public:
        File();
		~File();
        
        bool Open(const char* path);
        void Close();
        unsigned long long GetSize() const;
        void Seek(unsigned long long position);
        void Read(unsigned char byte);
        void Read(void *buffer, unsigned long long size);
		void Write(unsigned char byte);
        bool IsOpen() const;
		bool IsReadOnly() const;
		const char* GetFullPath() const;
		const char* GetFileName() const;

    private:
        char* m_filename;
		char* m_fullPath;
        unsigned long long m_filesize;
        void* m_handle;
		bool m_readOnly;
};

inline unsigned long long File::GetSize() const
{
    return m_filesize;
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
