#pragma once

#include "Window.h"
#include "File.h"

class HexView : public Window
{
    public:
        HexView(File* file);
        ~HexView();

        virtual void OnWindowRefreshed();
        virtual void OnWindowResized(int newWidth, int newHeight);
        virtual void OnKeyEvent(KeyEvent& keyEvent);

        unsigned long long GetSelectedOffset();
        unsigned long long GetFileSize();

    private:
		void UpdateCursor();
        void CacheFile(bool resizeBuffer = false);
		void WriteBytes(unsigned char ascii);
		void WriteChar(unsigned char ascii);

        unsigned long long GetSelectedLine();
        unsigned long long GetLastLine();
        unsigned long long GetBottomLine();

        unsigned char* m_buffer;
        unsigned int m_bufferSize;
        unsigned long long m_topLine;
        unsigned long long m_selected;
        unsigned long long m_fileSize;

		File* m_file;

		enum EditMode
		{
			EditMode_None,
			EditMode_Byte,
			EditMode_Char
		};

		EditMode m_editMode;
		int m_nibbleIndex;
};

inline unsigned long long HexView::GetSelectedLine()
{
    return m_selected >> 4;
}

inline unsigned long long HexView::GetLastLine()
{
    return m_fileSize >> 4;
}

inline unsigned long long HexView::GetBottomLine()
{
    return m_topLine + m_height - 1;
}

inline unsigned long long HexView::GetSelectedOffset()
{
    return m_selected;
}

inline unsigned long long HexView::GetFileSize()
{
    return m_fileSize;
}
