typedef struct _GUID
{
  /* 0x0000 */ unsigned long Data1;
  /* 0x0004 */ unsigned short Data2;
  /* 0x0006 */ unsigned short Data3;
  /* 0x0008 */ unsigned char Data4[8];
} GUID, *PGUID; /* size: 0x0010 */

typedef struct _LIST_ENTRY
{
  /* 0x0000 */ struct _LIST_ENTRY* Flink;
  /* 0x0004 */ struct _LIST_ENTRY* Blink;
} LIST_ENTRY, *PLIST_ENTRY; /* size: 0x0008 */

typedef struct _WORK_QUEUE_ITEM
{
  /* 0x0000 */ struct _LIST_ENTRY List;
  /* 0x0008 */ void* WorkerRoutine /* function */;
  /* 0x000c */ void* Parameter;
} WORK_QUEUE_ITEM, *PWORK_QUEUE_ITEM; /* size: 0x0010 */

typedef struct _POP_FX_WORK_ORDER
{
  /* 0x0000 */ struct _WORK_QUEUE_ITEM WorkItem;
  /* 0x0010 */ long WorkCount;
} POP_FX_WORK_ORDER, *PPOP_FX_WORK_ORDER; /* size: 0x0014 */

typedef union _POP_FX_COMPONENT_FLAGS
{
  union
  {
    struct
    {
      /* 0x0000 */ long Value;
      /* 0x0004 */ long Value2;
    }; /* size: 0x0008 */
    struct
    {
      struct /* bitfield */
      {
        /* 0x0000 */ unsigned long RefCount : 30; /* bit position: 0 */
        /* 0x0000 */ unsigned long Idling : 1; /* bit position: 30 */
        /* 0x0000 */ unsigned long Active : 1; /* bit position: 31 */
      }; /* bitfield */
      struct /* bitfield */
      {
        /* 0x0004 */ unsigned long CriticalIdleOverride : 1; /* bit position: 0 */
        /* 0x0004 */ unsigned long ResidentOverride : 1; /* bit position: 1 */
        /* 0x0004 */ unsigned long Reserved : 30; /* bit position: 2 */
      }; /* bitfield */
    }; /* size: 0x0008 */
  }; /* size: 0x0008 */
} POP_FX_COMPONENT_FLAGS, *PPOP_FX_COMPONENT_FLAGS; /* size: 0x0008 */

typedef struct _DISPATCHER_HEADER
{
  union
  {
    struct
    {
      /* 0x0000 */ unsigned char Type;
      union
      {
        /* 0x0001 */ unsigned char TimerControlFlags;
        struct /* bitfield */
        {
          /* 0x0001 */ unsigned char Absolute : 1; /* bit position: 0 */
          /* 0x0001 */ unsigned char Wake : 1; /* bit position: 1 */
          /* 0x0001 */ unsigned char EncodedTolerableDelay : 6; /* bit position: 2 */
        }; /* bitfield */
        /* 0x0001 */ unsigned char Abandoned;
        struct
        {
          /* 0x0001 */ unsigned char Signalling;
          union
          {
            /* 0x0002 */ unsigned char ThreadControlFlags;
            struct /* bitfield */
            {
              /* 0x0002 */ unsigned char CycleProfiling : 1; /* bit position: 0 */
              /* 0x0002 */ unsigned char CounterProfiling : 1; /* bit position: 1 */
              /* 0x0002 */ unsigned char GroupScheduling : 1; /* bit position: 2 */
              /* 0x0002 */ unsigned char AffinitySet : 1; /* bit position: 3 */
              /* 0x0002 */ unsigned char Reserved : 4; /* bit position: 4 */
            }; /* bitfield */
            /* 0x0002 */ unsigned char Hand;
            struct
            {
              /* 0x0002 */ unsigned char Size;
              union
              {
                /* 0x0003 */ unsigned char TimerMiscFlags;
                struct /* bitfield */
                {
                  /* 0x0003 */ unsigned char Index : 1; /* bit position: 0 */
                  /* 0x0003 */ unsigned char Processor : 5; /* bit position: 1 */
                  /* 0x0003 */ unsigned char Inserted : 1; /* bit position: 6 */
                  /* 0x0003 */ volatile unsigned char Expired : 1; /* bit position: 7 */
                }; /* bitfield */
                /* 0x0003 */ unsigned char DebugActive;
                /* 0x0003 */ unsigned char DpcActive;
              }; /* size: 0x0001 */
            }; /* size: 0x0002 */
          }; /* size: 0x0002 */
        }; /* size: 0x0003 */
      }; /* size: 0x0003 */
    }; /* size: 0x0004 */
    /* 0x0000 */ volatile long Lock;
    /* 0x0000 */ long LockNV;
  }; /* size: 0x0004 */
  /* 0x0004 */ long SignalState;
  /* 0x0008 */ struct _LIST_ENTRY WaitListHead;
} DISPATCHER_HEADER, *PDISPATCHER_HEADER; /* size: 0x0010 */

typedef struct _KEVENT
{
  /* 0x0000 */ struct _DISPATCHER_HEADER Header;
} KEVENT, *PKEVENT; /* size: 0x0010 */

typedef struct _POP_FX_COMPONENT
{
  /* 0x0000 */ struct _GUID Id;
  /* 0x0010 */ unsigned long Index;
  /* 0x0014 */ struct _POP_FX_WORK_ORDER WorkOrder;
  /* 0x0028 */ struct _POP_FX_DEVICE* Device;
  /* 0x002c */ volatile union _POP_FX_COMPONENT_FLAGS Flags;
  /* 0x0034 */ volatile long Resident;
  /* 0x0038 */ struct _KEVENT ActiveEvent;
  /* 0x0048 */ unsigned long IdleLock;
  /* 0x004c */ volatile long IdleConditionComplete;
  /* 0x0050 */ volatile long IdleStateComplete;
  /* 0x0058 */ unsigned __int64 IdleStamp;
  /* 0x0060 */ volatile unsigned long CurrentIdleState;
  /* 0x0064 */ unsigned long IdleStateCount;
  /* 0x0068 */ struct _POP_FX_IDLE_STATE* IdleStates;
  /* 0x006c */ unsigned long DeepestWakeableIdleState;
  /* 0x0070 */ unsigned long ProviderCount;
  /* 0x0074 */ struct _POP_FX_PROVIDER* Providers;
  /* 0x0078 */ unsigned long IdleProviderCount;
  /* 0x007c */ unsigned long DependentCount;
  /* 0x0080 */ struct _POP_FX_DEPENDENT* Dependents;
  /* 0x0084 */ long __PADDING__[1];
} POP_FX_COMPONENT, *PPOP_FX_COMPONENT; /* size: 0x0088 */

