#include "../../wcxhead.h"

// File Attributes
#define FA_READONLY         0x1     //Read-only file
#define FA_HIDDEN           0x2     //Hidden file
#define FA_SYSTEM           0x4     //System file
#define FA_VOLUME_ID        0x8     //Volume ID file
#define FA_DIRECTORY        0x10    //Directory
#define FA_ARCHIVE          0x20    //Archive file
#define FA_ANY              0x3F    //Any file

// modified by TrePe
extern HANDLE __stdcall ISO_OpenArchive( tOpenArchiveData* ArchiveData );
extern int __stdcall ISO_ReadHeaderEx( HANDLE hArcData, tHeaderDataEx* HeaderData );
extern int __stdcall ISO_ProcessFile(HANDLE hArcData);
extern int __stdcall ISO_CloseArchive( HANDLE hArcData );