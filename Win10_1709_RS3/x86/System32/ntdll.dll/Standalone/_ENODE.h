typedef struct _GROUP_AFFINITY
{
  /* 0x0000 */ unsigned long Mask;
  /* 0x0004 */ unsigned short Group;
  /* 0x0006 */ unsigned short Reserved[3];
} GROUP_AFFINITY, *PGROUP_AFFINITY; /* size: 0x000c */

typedef struct _flags
{
  struct /* bitfield */
  {
    /* 0x0000 */ unsigned char Removable : 1; /* bit position: 0 */
    /* 0x0000 */ unsigned char GroupAssigned : 1; /* bit position: 1 */
    /* 0x0000 */ unsigned char GroupCommitted : 1; /* bit position: 2 */
    /* 0x0000 */ unsigned char GroupAssignmentFixed : 1; /* bit position: 3 */
    /* 0x0000 */ unsigned char Fill : 4; /* bit position: 4 */
  }; /* bitfield */
} flags, *Pflags; /* size: 0x0001 */

typedef struct _KHETERO_PROCESSOR_SET
{
  /* 0x0000 */ unsigned long IdealMask;
  /* 0x0004 */ unsigned long PreferredMask;
  /* 0x0008 */ unsigned long AvailableMask;
} KHETERO_PROCESSOR_SET, *PKHETERO_PROCESSOR_SET; /* size: 0x000c */

typedef struct _KNODE
{
  /* 0x0000 */ unsigned long IdleNonParkedCpuSet;
  /* 0x0004 */ unsigned long IdleSmtSet;
  /* 0x0008 */ unsigned long IdleCpuSet;
  /* 0x0040 */ unsigned long DeepIdleSet;
  /* 0x0044 */ unsigned long IdleConstrainedSet;
  /* 0x0048 */ unsigned long NonParkedSet;
  /* 0x004c */ long ParkLock;
  /* 0x0050 */ unsigned long Seed;
  /* 0x0080 */ unsigned long SiblingMask;
  union
  {
    /* 0x0084 */ struct _GROUP_AFFINITY Affinity;
    struct
    {
      /* 0x0084 */ unsigned char AffinityFill[6];
      /* 0x008a */ unsigned short NodeNumber;
      /* 0x008c */ unsigned short PrimaryNodeNumber;
      /* 0x008e */ unsigned char Stride;
      /* 0x008f */ unsigned char Spare0;
    }; /* size: 0x000c */
  }; /* size: 0x000c */
  /* 0x0090 */ unsigned long SharedReadyQueueLeaders;
  /* 0x0094 */ unsigned long ProximityId;
  /* 0x0098 */ unsigned long Lowest;
  /* 0x009c */ unsigned long Highest;
  /* 0x00a0 */ unsigned char MaximumProcessors;
  /* 0x00a1 */ struct _flags Flags;
  /* 0x00a2 */ unsigned char Spare10;
  /* 0x00a4 */ struct _KHETERO_PROCESSOR_SET HeteroSets[5];
  /* 0x00e0 */ unsigned long PpmConfiguredQosSets[3];
  /* 0x00ec */ long __PADDING__[5];
} KNODE, *PKNODE; /* size: 0x0100 */

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

typedef struct _ENODE
{
  /* 0x0000 */ struct _KNODE Ncb;
  /* 0x0100 */ struct _WORK_QUEUE_ITEM HotAddProcessorWorkItem;
  /* 0x0110 */ long __PADDING__[12];
} ENODE, *PENODE; /* size: 0x0140 */

