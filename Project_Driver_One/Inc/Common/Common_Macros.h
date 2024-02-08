/*
 * Common_Macros.h
 *
 *  Created on: Feb 5, 2024
 *      Author: Aya Ali
 */

#ifndef COMMON_COMMON_MACROS_H_
#define COMMON_COMMON_MACROS_H_

#define SET_BIT(REG,BIT)      (REG |= BIT)
#define CLEAR_BIT(REG,BIT)    (REG &=~ BIT)
#define TOGGLE_BIT(REG,BIT)   (REG ^= BIT)
#define READ_BIT(REG, BIT)    ((REG) & (BIT))

#define READ_REG(REG)         ((REG))
#define WRITE_REG(REG,VAL)    ((REG) = (VAL))
#define MODIFY_REG(REG, CLEARMASK, SETMASK) WRITE_REG((REG), (((READ_REG(REG)) & (~(CLEARMASK))) | (SETMASK)))
#endif /* COMMON_COMMON_MACROS_H_ */
