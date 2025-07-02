#ifndef RTC_REGISTER_H_
#define RTC_REGISTER_H_

typedef struct{
	union {
		volatile unsigned int TSR_REGISTER;
		struct{
			volatile unsigned int TSR: 32;
		}TSR;
	};
	union {
		volatile unsigned int TPR_REGISTER;
		struct{
			volatile unsigned int TPR: 16;
			volatile const unsigned int RESERVED: 16;
		}TPR;
	};
	union {
		volatile unsigned int TAR_REGISTER;
		struct{
			volatile unsigned int TAR: 32;
		}TAR;
	};
   union {
        volatile unsigned int TCR_REGISTER; // Time Compensation Register
        struct {
            volatile unsigned int TCR: 8;   // Time Compensation Register
            volatile unsigned int CIR: 8;   // Compensation Interval Register
            volatile const unsigned int TCV: 8;   // Time Compensation Value
            volatile const unsigned int CIC: 8;   // Compensation Interval Counter
        }TCR;
    };
    union {
        volatile unsigned int CR_REGISTER; // Control Register
        struct {
            volatile unsigned int SWR: 1;    // Software Reset
            volatile const unsigned int RESERVED1: 1; // Reserved
            volatile unsigned int SUP: 1;    // Supervisor Access
            volatile unsigned int UM: 1;     // Update Mode
            volatile const unsigned int RESERVED2: 1; // Reserved
            volatile unsigned int CPS: 1;    // Clock Pin Select
            volatile const unsigned int RESERVED3: 1; // Reserved
            volatile unsigned int LPOS: 1;   // LPO Select
            volatile const unsigned int RESERVED4: 1; // Reserved
            volatile unsigned int CLKO: 1;   // Clock Output
            volatile const unsigned int RESERVED5: 14; // Reserved
            volatile unsigned int CPE: 1;    // Clock Pin Enable
            volatile const unsigned int RESERVED6: 7; // Reserved
        }CR;
    };
		union {
        volatile unsigned int SR_REGISTER; // Status Register
        struct {
            volatile const unsigned int TIF: 1;   // Time Invalid Flag
            volatile const unsigned int TOF: 1;   // Time Overflow Flag
            volatile const unsigned int TAF: 1;   // Time Alarm Flag
            volatile const unsigned int RESERVED1: 1; // Reserved
            volatile unsigned int TCE: 1;   // Time Counter Enable
            volatile const unsigned int RESERVED2: 27; // Reserved
        }SR;
    };
    union {
        volatile unsigned int LR_REGISTER; // Lock Register
        struct {
            volatile const unsigned int RESERVED1: 3; // Reserved
            volatile unsigned int TCL: 1;   // Time Compensation Lock
            volatile unsigned int CRL: 1;   // Control Register Lock
            volatile unsigned int SRL: 1;   // Status Register Lock
            volatile unsigned int LRL: 1;   // Lock Register Lock
            volatile const unsigned int RESERVED2: 25; // Reserved
        }LR;
    };
    union {
        volatile unsigned int IER_REGISTER; // Interrupt Enable Register
        struct {
            volatile unsigned int TIIE: 1;   // Time Invalid Interrupt Enable
            volatile unsigned int TOIE: 1;   // Time Overflow Interrupt Enable
            volatile unsigned int TAIE: 1;   // Time Alarm Interrupt Enable
            volatile const unsigned int RESERVED1: 1; // Reserved
            volatile unsigned int TSIE: 1;   // Time Seconds Interrupt Enable
            volatile const unsigned int RESERVED2: 3; // Reserved
            volatile const unsigned int RESERVED3: 8; // Reserved
            volatile unsigned int TSIC: 3;   // Timer Seconds Interrupt Configuration
            volatile const unsigned int RESERVED4: 13; // Reserved
        }IER;
    };
}RTC_t;

#define RTC_BASE (0X4003D000)
#define RTC ((RTC_t *) RTC_BASE)

#endif
