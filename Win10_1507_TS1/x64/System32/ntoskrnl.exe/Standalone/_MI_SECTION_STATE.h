typedef struct _EX_PUSH_LOCK
{
  union
  {
    struct /* bitfield */
    {
      /* 0x0000 */ unsigned __int64 Locked : 1; /* bit position: 0 */
      /* 0x0000 */ unsigned __int64 Waiting : 1; /* bit position: 1 */
      /* 0x0000 */ unsigned __int64 Waking : 1; /* bit position: 2 */
      /* 0x0000 */ unsigned __int64 MultipleShared : 1; /* bit position: 3 */
      /* 0x0000 */ unsigned __int64 Shared : 60; /* bit position: 4 */
    }; /* bitfield */
    /* 0x0000 */ unsigned __int64 Value;
    /* 0x0000 */ void* Ptr;
  }; /* size: 0x0008 */
} EX_PUSH_LOCK, *PEX_PUSH_LOCK; /* size: 0x0008 */

typedef struct _RTL_AVL_TREE
{
  /* 0x0000 */ struct _RTL_BALANCED_NODE* Root;
} RTL_AVL_TREE, *PRTL_AVL_TREE; /* size: 0x0008 */

typedef struct _MMSUBSECTION_FLAGS
{
  struct /* bitfield */
  {
    /* 0x0000 */ unsigned short SubsectionAccessed : 1; /* bit position: 0 */
    /* 0x0000 */ unsigned short Protection : 5; /* bit position: 1 */
    /* 0x0000 */ unsigned short StartingSector4132 : 10; /* bit position: 6 */
  }; /* bitfield */
  struct /* bitfield */
  {
    /* 0x0002 */ unsigned short SubsectionStatic : 1; /* bit position: 0 */
    /* 0x0002 */ unsigned short GlobalMemory : 1; /* bit position: 1 */
    /* 0x0002 */ unsigned short DirtyPages : 1; /* bit position: 2 */
    /* 0x0002 */ unsigned short OnDereferenceList : 1; /* bit position: 3 */
    /* 0x0002 */ unsigned short SectorEndOffset : 12; /* bit position: 4 */
  }; /* bitfield */
} MMSUBSECTION_FLAGS, *PMMSUBSECTION_FLAGS; /* size: 0x0004 */

typedef struct _SUBSECTION
{
  /* 0x0000 */ struct _CONTROL_AREA* ControlArea;
  /* 0x0008 */ struct _MMPTE* SubsectionBase;
  /* 0x0010 */ struct _SUBSECTION* NextSubsection;
  union
  {
    /* 0x0018 */ struct _MI_FILE_EXTENTS* FileExtents;
    /* 0x0018 */ struct _RTL_AVL_TREE GlobalPerSessionHead;
    /* 0x0018 */ struct _MI_PER_SESSION_PROTOS* SessionDriverProtos;
  }; /* size: 0x0008 */
  union
  {
    union
    {
      /* 0x0020 */ unsigned long LongFlags;
      /* 0x0020 */ struct _MMSUBSECTION_FLAGS SubsectionFlags;
    }; /* size: 0x0004 */
  } /* size: 0x0004 */ u;
  /* 0x0024 */ unsigned long StartingSector;
  /* 0x0028 */ unsigned long NumberOfFullSectors;
  /* 0x002c */ unsigned long PtesInSubsection;
  union
  {
    /* 0x0030 */ unsigned long NumberOfChildViews;
  } /* size: 0x0004 */ u1;
  union
  {
    /* 0x0034 */ unsigned long UnusedPtes;
    /* 0x0034 */ unsigned long AlignmentNoAccessPtes;
  }; /* size: 0x0004 */
} SUBSECTION, *PSUBSECTION; /* size: 0x0038 */

typedef struct _RTL_BALANCED_NODE
{
  union
  {
    /* 0x0000 */ struct _RTL_BALANCED_NODE* Children[2];
    struct
    {
      /* 0x0000 */ struct _RTL_BALANCED_NODE* Left;
      /* 0x0008 */ struct _RTL_BALANCED_NODE* Right;
    }; /* size: 0x0010 */
  }; /* size: 0x0010 */
  union
  {
    /* 0x0010 */ unsigned char Red : 1; /* bit position: 0 */
    /* 0x0010 */ unsigned char Balance : 2; /* bit position: 0 */
    /* 0x0010 */ unsigned __int64 ParentValue;
  }; /* size: 0x0008 */
} RTL_BALANCED_NODE, *PRTL_BALANCED_NODE; /* size: 0x0018 */

typedef struct _LIST_ENTRY
{
  /* 0x0000 */ struct _LIST_ENTRY* Flink;
  /* 0x0008 */ struct _LIST_ENTRY* Blink;
} LIST_ENTRY, *PLIST_ENTRY; /* size: 0x0010 */

typedef struct _MSUBSECTION
{
  /* 0x0000 */ struct _SUBSECTION Core;
  /* 0x0038 */ struct _RTL_BALANCED_NODE SubsectionNode;
  /* 0x0050 */ struct _LIST_ENTRY DereferenceList;
  /* 0x0060 */ unsigned __int64 NumberOfMappedViews;
  /* 0x0068 */ unsigned __int64 NumberOfPfnReferences;
} MSUBSECTION, *PMSUBSECTION; /* size: 0x0070 */

typedef struct _MMSECTION_FLAGS
{
  struct /* bitfield */
  {
    /* 0x0000 */ unsigned int BeingDeleted : 1; /* bit position: 0 */
    /* 0x0000 */ unsigned int BeingCreated : 1; /* bit position: 1 */
    /* 0x0000 */ unsigned int BeingPurged : 1; /* bit position: 2 */
    /* 0x0000 */ unsigned int NoModifiedWriting : 1; /* bit position: 3 */
    /* 0x0000 */ unsigned int FailAllIo : 1; /* bit position: 4 */
    /* 0x0000 */ unsigned int Image : 1; /* bit position: 5 */
    /* 0x0000 */ unsigned int Based : 1; /* bit position: 6 */
    /* 0x0000 */ unsigned int File : 1; /* bit position: 7 */
    /* 0x0000 */ unsigned int AttemptingDelete : 1; /* bit position: 8 */
    /* 0x0000 */ unsigned int PrefetchCreated : 1; /* bit position: 9 */
    /* 0x0000 */ unsigned int PhysicalMemory : 1; /* bit position: 10 */
    /* 0x0000 */ unsigned int CopyOnWrite : 1; /* bit position: 11 */
    /* 0x0000 */ unsigned int Reserve : 1; /* bit position: 12 */
    /* 0x0000 */ unsigned int Commit : 1; /* bit position: 13 */
    /* 0x0000 */ unsigned int NoChange : 1; /* bit position: 14 */
    /* 0x0000 */ unsigned int WasPurged : 1; /* bit position: 15 */
    /* 0x0000 */ unsigned int UserReference : 1; /* bit position: 16 */
    /* 0x0000 */ unsigned int GlobalMemory : 1; /* bit position: 17 */
    /* 0x0000 */ unsigned int DeleteOnClose : 1; /* bit position: 18 */
    /* 0x0000 */ unsigned int FilePointerNull : 1; /* bit position: 19 */
    /* 0x0000 */ unsigned int PreferredNode : 6; /* bit position: 20 */
    /* 0x0000 */ unsigned int GlobalOnlyPerSession : 1; /* bit position: 26 */
    /* 0x0000 */ unsigned int UserWritable : 1; /* bit position: 27 */
    /* 0x0000 */ unsigned int SystemVaAllocated : 1; /* bit position: 28 */
    /* 0x0000 */ unsigned int PreferredFsCompressionBoundary : 1; /* bit position: 29 */
    /* 0x0000 */ unsigned int UsingFileExtents : 1; /* bit position: 30 */
    /* 0x0000 */ unsigned int Spare : 1; /* bit position: 31 */
  }; /* bitfield */
} MMSECTION_FLAGS, *PMMSECTION_FLAGS; /* size: 0x0004 */

typedef struct _MMSECTION_FLAGS2
{
  struct /* bitfield */
  {
    /* 0x0000 */ unsigned long PartitionId : 10; /* bit position: 0 */
    /* 0x0000 */ unsigned long NumberOfChildViews : 22; /* bit position: 10 */
  }; /* bitfield */
} MMSECTION_FLAGS2, *PMMSECTION_FLAGS2; /* size: 0x0004 */

typedef struct _EX_FAST_REF
{
  union
  {
    /* 0x0000 */ void* Object;
    /* 0x0000 */ unsigned __int64 RefCnt : 4; /* bit position: 0 */
    /* 0x0000 */ unsigned __int64 Value;
  }; /* size: 0x0008 */
} EX_FAST_REF, *PEX_FAST_REF; /* size: 0x0008 */

typedef struct _CONTROL_AREA
{
  /* 0x0000 */ struct _SEGMENT* Segment;
  /* 0x0008 */ struct _LIST_ENTRY ListHead;
  /* 0x0018 */ unsigned __int64 NumberOfSectionReferences;
  /* 0x0020 */ unsigned __int64 NumberOfPfnReferences;
  /* 0x0028 */ unsigned __int64 NumberOfMappedViews;
  /* 0x0030 */ unsigned __int64 NumberOfUserReferences;
  union
  {
    union
    {
      /* 0x0038 */ unsigned long LongFlags;
      /* 0x0038 */ struct _MMSECTION_FLAGS Flags;
    }; /* size: 0x0004 */
  } /* size: 0x0004 */ u;
  union
  {
    union
    {
      /* 0x003c */ unsigned long LongFlags;
      /* 0x003c */ struct _MMSECTION_FLAGS2 Flags;
    }; /* size: 0x0004 */
  } /* size: 0x0004 */ u1;
  /* 0x0040 */ struct _EX_FAST_REF FilePointer;
  /* 0x0048 */ volatile long ControlAreaLock;
  /* 0x004c */ unsigned long ModifiedWriteCount;
  /* 0x0050 */ struct _MI_CONTROL_AREA_WAIT_BLOCK* WaitList;
  union
  {
    struct
    {
      union
      {
        /* 0x0058 */ unsigned long NumberOfSystemCacheViews;
        /* 0x0058 */ unsigned long ImageRelocationStartBit;
      }; /* size: 0x0004 */
      union
      {
        /* 0x005c */ volatile long WritableUserReferences;
        struct /* bitfield */
        {
          /* 0x005c */ unsigned long ImageRelocationSizeIn64k : 16; /* bit position: 0 */
          /* 0x005c */ unsigned long Unused : 9; /* bit position: 16 */
          /* 0x005c */ unsigned long SystemImage : 1; /* bit position: 25 */
          /* 0x005c */ unsigned long StrongCode : 2; /* bit position: 26 */
          /* 0x005c */ unsigned long CantMove : 1; /* bit position: 28 */
          /* 0x005c */ unsigned long BitMap : 2; /* bit position: 29 */
          /* 0x005c */ unsigned long ImageActive : 1; /* bit position: 31 */
        }; /* bitfield */
      }; /* size: 0x0004 */
      union
      {
        /* 0x0060 */ unsigned long FlushInProgressCount;
        /* 0x0060 */ unsigned long NumberOfSubsections;
        /* 0x0060 */ struct _MI_IMAGE_SECURITY_REFERENCE* SeImageStub;
      }; /* size: 0x0008 */
    } /* size: 0x0010 */ e2;
  } /* size: 0x0010 */ u2;
  /* 0x0068 */ volatile unsigned __int64 LockedPages;
  /* 0x0070 */ struct _EX_PUSH_LOCK FileObjectLock;
} CONTROL_AREA, *PCONTROL_AREA; /* size: 0x0078 */

typedef struct _MI_CROSS_PARTITION_CHARGES
{
  /* 0x0000 */ unsigned __int64 CurrentCharges;
  /* 0x0008 */ unsigned __int64 ChargeFailures;
  /* 0x0010 */ unsigned __int64 ChargePeak;
  /* 0x0018 */ unsigned __int64 ChargeMinimum;
  /* 0x0020 */ unsigned __int64 ChargeMaximum;
} MI_CROSS_PARTITION_CHARGES, *PMI_CROSS_PARTITION_CHARGES; /* size: 0x0028 */

typedef struct _RTL_BITMAP
{
  /* 0x0000 */ unsigned long SizeOfBitMap;
  /* 0x0008 */ unsigned long* Buffer;
} RTL_BITMAP, *PRTL_BITMAP; /* size: 0x0010 */

typedef struct _MI_SECTION_STATE
{
  /* 0x0000 */ volatile long SegmentListLock;
  /* 0x0040 */ volatile long SectionObjectPointersLock;
  /* 0x0048 */ struct _EX_PUSH_LOCK SectionExtendLock;
  /* 0x0050 */ struct _EX_PUSH_LOCK SectionExtendSetLock;
  /* 0x0058 */ struct _RTL_AVL_TREE SectionBasedRoot;
  /* 0x0060 */ struct _EX_PUSH_LOCK SectionBasedLock;
  /* 0x0068 */ unsigned __int64 UnusedSubsectionPagedPool;
  /* 0x0070 */ unsigned long UnusedSegmentForceFree;
  /* 0x0074 */ unsigned long DataSectionProtectionMask;
  /* 0x0078 */ void* HighSectionBase;
  /* 0x0080 */ struct _MSUBSECTION PhysicalSubsection;
  /* 0x00f0 */ struct _CONTROL_AREA PhysicalControlArea;
  /* 0x0168 */ struct _RTL_AVL_TREE PageFileSectionHead;
  /* 0x0170 */ volatile long PageFileSectionListSpinLock;
  /* 0x0178 */ struct _MI_CROSS_PARTITION_CHARGES SharedSegmentCharges;
  /* 0x01a0 */ struct _MI_CROSS_PARTITION_CHARGES SharedPageCombineCharges;
  /* 0x01c8 */ unsigned long ImageBias;
  /* 0x01d0 */ struct _EX_PUSH_LOCK RelocateBitmapsLock;
  /* 0x01d8 */ struct _RTL_BITMAP ImageBitMap;
  /* 0x01e8 */ unsigned long ImageBias64Low;
  /* 0x01ec */ unsigned long ImageBias64High;
  /* 0x01f0 */ struct _RTL_BITMAP ImageBitMap64Low;
  /* 0x0200 */ struct _RTL_BITMAP ImageBitMap64High;
  /* 0x0210 */ struct _RTL_BITMAP ImageBitMapWow64Dll;
  /* 0x0220 */ void* ApiSetSection;
  /* 0x0228 */ void* ApiSetSchema;
  /* 0x0230 */ unsigned __int64 ApiSetSchemaSize;
  /* 0x0238 */ unsigned long LostDataFiles;
  /* 0x023c */ unsigned long LostDataPages;
  /* 0x0240 */ unsigned long ImageFailureReason;
  /* 0x0248 */ struct _SECTION* CfgBitMapSection32;
  /* 0x0250 */ struct _CONTROL_AREA* CfgBitMapControlArea32;
  /* 0x0258 */ struct _SECTION* CfgBitMapSection64;
  /* 0x0260 */ struct _CONTROL_AREA* CfgBitMapControlArea64;
  /* 0x0268 */ unsigned long ImageCfgFailure;
  /* 0x026c */ volatile long ImageValidationFailed;
  /* 0x0270 */ long __PADDING__[4];
} MI_SECTION_STATE, *PMI_SECTION_STATE; /* size: 0x0280 */

