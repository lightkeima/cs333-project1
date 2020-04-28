#define REG_SIZE 1 // register size: 1 byte
#define NUM_CTRL_REGS 1 // number of control registers
#define NUM_STS_REGS 5 //number of status registers
#define NUM_DATA_REGS 11 //number of data registers, here we choose elevens because all numbers generated by getrandombytes() does not take more than 11 characters to represent
#define NUM_DEV_REGS (NUM_CTRL_REGS + NUM_STS_REGS + NUM_DATA_REGS) // total number of registers

/****************** Status Registers: START ******************/
/*
 * High and low registers for read counting [READ_COUNT_H_REG:READ_COUNT_L_REG]:
 * Initial value: 0x00
 */

#define READ_COUNT_H_REG 0
#define READ_COUNT_L_REG 1

/*
 * High and low registers for write counting [WRITE_COUNT_H_REG:WRITE_COUNT_L_REG]:
 * Initial value: 0x00
 */
#define WRITE_COUNT_H_REG 2
#define WRITE_COUNT_L_REG 3

/*
 * Register for the device status:
 * Intial value: 0x03
 * - The meaning of the bit, if the value of the bit is 1, the condition is true, otherwise 0:
 *   bit 0: whether the registers are ready for read
 *   bit 1: whether the registers are ready for write
 *   bit 2: whether the registers have been modified
 */
#define DEVICE_STATUS_REG 4

#define STS_READ_ACCESS_BIT (1 << 0)
#define STS_WRITE_ACCESS_BIT (1 << 1)
#define STS_DATAREGS_OVERFLOW_BIT (1 << 2)

#define READY 1
#define NOT_READY 0
#define OVERFLOW 1
#define NOT_OVERFLOW 0
/****************** Status Registers: END ******************/


/****************** Control Registers: START ******************/
/*
 * CONTROL_ALCCESS_REG register:
 * Contains the bit controlling reading and writing data to the data registers
 * Initial value: 0x03
 * bit 0: whether to allow reading the data registers
 * bit 1: whether to allow writing on the data registers
 */
#define CONTROL_ACCESS_REG 0

#define CTRL_READ_DATA_BIT (1 << 0)
#define CTRL_WRITE_DATA_BIT (1 << 1)

#define ENABLED 1
#define DISABLED 0
/****************** Control Registers: END ******************/